#include "DebugController.h"

std::shared_ptr<QString> DebugController::step(int lineNum)
{
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

