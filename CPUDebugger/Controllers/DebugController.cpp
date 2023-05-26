#include "DebugController.h"

UartCommunicator uartCommunicator;

std::optional<QByteArray> DebugController::resume()
{
    checkStore();
    std::shared_ptr<AsmFile> asmFilePtr = DebugStore::asmFilePtr;
    QByteArray cpuResponse;

    int PC;
    if(DebugStore::asmFilePtr->binBreakPoints.size() > 0)
    {
        for (int i : DebugStore::asmFilePtr->binBreakPoints)
        {
            int binCurLine = DebugStore::binCurLine;
            if (i > DebugStore::binCurLine)
            {
                PC = i;
                break;
            }
        }
    }
    qDebug() << "target pc" << PC;
    bool result = uartCommunicator.sendResume(cpuResponse, PC);
    if (!result)
        return nullptr;
    int binPC = (static_cast<unsigned int>(cpuResponse[0]) & 0xFF)
             + ((static_cast<unsigned int>(cpuResponse[1]) & 0xFF) << 8)
            + ((static_cast<unsigned int>(cpuResponse[2]) & 0xFF) << 16)
            + ((static_cast<unsigned int>(cpuResponse[3]) & 0xFF) << 24);
    DebugStore::setPC_Bin(binPC);
//    qDebug() << cpuResponse.toHex();
    qDebug() << "response pc" << binPC;
    return cpuResponse;
}

std::optional<QByteArray> DebugController::step()
{
    checkStore();
    QByteArray cpuResponse;
    bool result = uartCommunicator.sendStep(cpuResponse);

    if (!result)
        return nullptr;

    int binPC = (static_cast<unsigned int>(cpuResponse[0]) & 0xFF)
             + ((static_cast<unsigned int>(cpuResponse[1]) & 0xFF) << 8)
            + ((static_cast<unsigned int>(cpuResponse[2]) & 0xFF) << 16)
            + ((static_cast<unsigned int>(cpuResponse[3]) & 0xFF) << 24);
    DebugStore::setPC_Bin(binPC);
    qDebug() << "response pc" << binPC;
    return cpuResponse;
}

int DebugController::pause()
{
    checkStore();
    uartCommunicator.sendPause();
    return 1;
}

int DebugController::detect()
{
    //checkStore();
    bool result = uartCommunicator.autoConnectCPU();
    qDebug() << result << Qt::endl;
    return result;
}

// TODO: Delete it4
QByteArray DebugController::getBin()
{
    checkStore();
    return DebugStore::asmFilePtr->getBin();
}

std::optional<QByteArray> DebugController::sendPrograme()
{
    compileAsm();
    QByteArray fileBytes = DebugController::getBin();
    QByteArray cpuResponse, tmpResumeResponse;
    bool result = uartCommunicator.sendProgram(fileBytes, cpuResponse, 20, 30);
    if (!result)
        return nullptr;
    int binPC = (static_cast<unsigned int>(cpuResponse[0]) & 0xFF)
             + ((static_cast<unsigned int>(cpuResponse[1]) & 0xFF) << 8)
            + ((static_cast<unsigned int>(cpuResponse[2]) & 0xFF) << 16)
            + ((static_cast<unsigned int>(cpuResponse[3]) & 0xFF) << 24);
    DebugStore::setPC_Bin(binPC);
    qDebug() << cpuResponse;

    uartCommunicator.sendResume(cpuResponse, 0);
    return cpuResponse;
}

int DebugController::compileAsm()
{
    std::shared_ptr<QFile> filePtr = PreDebugStore::file;
    if (filePtr == nullptr)
        throw std::invalid_argument("Select .asm file first!");
    std::shared_ptr<AsmFile> asmFilePtr = std::make_shared<AsmFile>(*filePtr);
    PreDebugStore::asmFile = asmFilePtr;
    asmFilePtr->setBreakPoints(PreDebugStore::breakPoints);
    asmFilePtr->binBreakPoints.insert(INT_MAX);
    initialize(asmFilePtr);
    return 0;
}

void DebugController::checkStore()
{
    if (DebugStore::asmFilePtr == nullptr)
    {
        throw std::invalid_argument("compile your asm file first");
    }
}

void DebugController::initialize(std::shared_ptr<AsmFile> asmFilePtr)
{
    DebugStore::asmFilePtr = asmFilePtr;
    DebugStore::asmCurLine = 0;
    DebugStore::binCurLine = 0;
}

void DebugController::clear()
{
    DebugStore::asmFilePtr = nullptr;
    DebugStore::asmCurLine = 0;
    DebugStore::binCurLine = 0;
}

int DebugController::setPC(FileType fileType, int PC)
{
    switch (fileType) {
    case FileType::Asm:
        break;
    case FileType::Bin:
        DebugStore::binCurLine = PC;
        DebugStore::asmCurLine = DebugStore::asmFilePtr->getAsmLine(PC);
        break;
    default:
        break;
    }
    return 0;
}
