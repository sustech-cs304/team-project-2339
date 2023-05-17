#ifndef UARTSIMULATOR_H
#define UARTSIMULATOR_H

#include <QtCore>
#include <memory>

class UartSimulator
{
public:
    static std::shared_ptr<QString> step(int line_num);
    static std::shared_ptr<QString> run();
    static std::shared_ptr<struct PauseSignal> pause();
};

#endif // UARTSIMULATOR_H
