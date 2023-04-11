#ifndef DEBUGCONTROLLER_H
#define DEBUGCONTROLLER_H

#include <QtCore>
#include <memory>

#include "Stores/PreDebugStore.h"
#include "Stores/DebugStore.h"
#include "uart/UartSimulator.h"
#include "utils/utils.h"

class DebugController
{
public:
    static std::shared_ptr<QString> step();
    static std::shared_ptr<QString> step(int lineNum);
    static std::shared_ptr<QString> run();
    static std::shared_ptr<QString> pause();
};

#endif // DEBUGCONTROLLER_H
