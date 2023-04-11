#include "UartSimulator.h"

std::shared_ptr<QString> UartSimulator::step(int line_num)
{
    std::shared_ptr<QString> string_ptr = std::make_shared<QString>("step to next breakline.");
    return string_ptr;
}

std::shared_ptr<QString> UartSimulator::run()
{
    std::shared_ptr<QString> string_ptr = std::make_shared<QString>("running...");
    return string_ptr;
}

std::shared_ptr<struct PauseSignal> UartSimulator::pause()
{
    std::shared_ptr<struct PauseSignal> signal = std::make_shared<struct PauseSignal>();
    signal->stringPtr = std::make_shared<QString>("Pause.");
    signal->lineIdx = 15;
    return signal;
}
