#include "DebugController.h"

UartCommunicator uartCommunicator;

std::optional<QByteArray> DebugController::resume()
{
    checkStore();
    QByteArray cpuResponse;
    bool result = uartCommunicator.sendResume(cpuResponse, DebugStore::binCurLine);
    if (!result)
        return nullptr;
    int asmPC = cpuResponse.left(4).toInt();
    DebugStore::setPC_Asm(asmPC);
    qDebug() << cpuResponse;
    return cpuResponse;
}

std::optional<QByteArray> DebugController::step()
{
    checkStore();
    QByteArray cpuResponse;
    bool result = uartCommunicator.sendStep(cpuResponse);

    if (!result)
        return nullptr;

    int asmPC = cpuResponse.left(4).toInt();
    DebugStore::setPC_Asm(asmPC);
    qDebug() << cpuResponse;
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
//    return result;
    return true;
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
    QByteArray cpuResponse;
    bool result = uartCommunicator.sendProgram(fileBytes, cpuResponse);
    if (!result)
        return nullptr;
    int asmPC = cpuResponse.left(4).toInt();
    DebugStore::setPC_Asm(asmPC);
    qDebug() << cpuResponse;
    return cpuResponse;
}

int DebugController::compileAsm()
{
    std::shared_ptr<QFile> filePtr = PreDebugStore::file;
    if (filePtr == nullptr)
        throw std::invalid_argument("Select .asm file first!");
    std::shared_ptr<AsmFile> asmFilePtr = std::make_shared<AsmFile>(*filePtr);
    PreDebugStore::asmFile = asmFilePtr;
    //    asmFilePtr->setBreakPoints(PreDebugStore::breakPoints);
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
