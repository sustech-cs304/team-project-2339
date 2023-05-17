#include "DebugController.h"

extern UartCommunicator communicator;

int DebugController::resume()
{
    QByteArray cpuResponse;
    bool result = communicator.sendResume(cpuResponse,286331153);
    qDebug() << "resume:" << result << " " << cpuResponse;
    return 0;
}

int DebugController::step()
{
    QByteArray cpuResponse;
    bool result = communicator.sendStep(cpuResponse);
    qDebug() << "step:" << result << " " << cpuResponse;
    return 0;
}
int DebugController::pause()
{
    communicator.sendPause();
    qDebug() << "pause" << Qt::endl;
    return 0;
}

// TODO: Delete it4
QByteArray DebugController::getBin()
{
    checkStore();
    return DebugStore::asmFilePtr->getBin();
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
