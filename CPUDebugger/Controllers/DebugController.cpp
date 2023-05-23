#include "DebugController.h"

UartCommunicator uartCommunicator;

std::optional<QByteArray> DebugController::resume()
{
    checkStore();
    QByteArray cpuResponse;
    bool result = uartCommunicator.sendResume(cpuResponse, DebugStore::binCurLine);
    if (!result)
        return nullptr;

    int asmPC = cpuResponse.toInt() >> 2;
    DebugStore::setPC_Asm(asmPC);

    return cpuResponse;
}

std::optional<QByteArray> DebugController::step()
{
    checkStore();
    QByteArray cpuResponse;
    bool result = uartCommunicator.sendStep(cpuResponse);

    if (!result)
        return nullptr;

    int asmPC = cpuResponse.toInt() >> 2;
    DebugStore::setPC_Asm(asmPC);

    return cpuResponse;
}

int DebugController::pause()
{
    checkStore();
    uartCommunicator.sendPause();
    return 0;
}

int DebugController::detect()
{
    //checkStore();
    bool result = uartCommunicator.autoConnectCPU();
    qDebug() << result << Qt::endl;
    return 0;
}

// TODO: Delete it4
QByteArray DebugController::getBin()
{
    checkStore();
    return DebugStore::asmFilePtr->getBin();
}

int DebugController::sendPrograme()
{
    QByteArray fileBytes = DebugController::getBin();
    qDebug() << fileBytes;
    QByteArray cpuResponse;
    uartCommunicator.sendProgram(fileBytes, cpuResponse);
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

int DebugController::extractPC(QByteArray& cpuResponse)
{
    QByteArray responseCopy = cpuResponse;
    return ((responseCopy[0] << 24) | (responseCopy[1] << 16) | (responseCopy[2] << 8) | responseCopy[3]) >> 2;
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
