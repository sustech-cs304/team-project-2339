#include "DebugController.h"

std::shared_ptr<QString> DebugController::step()
{
    int diff = PreDebugStore::getCoeFile()->getNextBreakPointDiff(DebugStore::coeCurLine);
    return step(diff);
}

std::shared_ptr<QString> DebugController::step(int lineNum)
{
    DebugStore::coeCurLine += lineNum;
    DebugStore::asmCurLine = PreDebugStore::getCoeFile()->coeToAsmMap[DebugStore::coeCurLine];
    return UartSimulator::step(lineNum);
}

std::shared_ptr<QString> DebugController::run()
{
    return UartSimulator::run();
}

std::shared_ptr<struct PauseSignal> DebugController::pause()
{
    std::shared_ptr<struct PauseSignal> pauseSignal = UartSimulator::pause();
    DebugStore::coeCurLine = pauseSignal->lineIdx;
    DebugStore::asmCurLine = PreDebugStore::getCoeFile()->coeToAsmMap[DebugStore::coeCurLine];
    return pauseSignal;
}

