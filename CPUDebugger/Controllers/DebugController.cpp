#include "DebugController.h"

int DebugController::step()
{
    checkStore();
    QByteArray cpuResponse;
//    UartSimulator::sendStep(cpuResponse);

    //获取cpuResponse的前4个Byte，将他们右移两位之后转为int返回
//    int PC = DebugController::extractPC(cpuResponse);
//    DebugController::setPC(FileType::Bin, PC);
    
//    return PC;
}

int DebugController::next()
{
    checkStore();
    qWarning() << "next is not implement now";
    return 1;
}

int DebugController::pause()
{
//    checkStore();
//    QByteArray cpuResponse;
//    UartSimulator::sendPause(cpuResponse);
//    int PC = DebugController::extractPC(cpuResponse);
//    DebugController::setPC(FileType::Bin, PC);
//    return PC;
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
