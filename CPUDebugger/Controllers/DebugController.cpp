#include "DebugController.h"

std::shared_ptr<QString> DebugController::step()
{
    int diff = PreDebugStore::getAsmFile()->getNextBreakPointDiff(DebugStore::curLine);
    return step(diff);
}

std::shared_ptr<QString> DebugController::step(int lineNum)
{
    DebugStore::curLine += lineNum;
    return UartSimulator::step(lineNum);
}

std::shared_ptr<QString> DebugController::run()
{
    return UartSimulator::run();
}

std::shared_ptr<struct PauseSignal> DebugController::pause()
{
    return UartSimulator::pause();
}

