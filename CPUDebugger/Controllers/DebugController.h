#ifndef DEBUGCONTROLLER_H
#define DEBUGCONTROLLER_H

#include <QtCore>
#include <memory>

#include "uart/UartSimulator.h"
#include "utils/utils.h"

class DebugController
{
public:
    static std::shared_ptr<QString> step(int lineNum);
    static std::shared_ptr<QString> run();
    static std::shared_ptr<struct PauseSignal> pause();
    static void test();
};

#endif // DEBUGCONTROLLER_H
