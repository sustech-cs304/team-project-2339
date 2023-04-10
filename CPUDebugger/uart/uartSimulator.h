#ifndef UARTSIMULATOR_H
#define UARTSIMULATOR_H

#include <QString>
#include <memory>

struct PauseSignal
{
    std::shared_ptr<QString> stringPtr;
    int lineNum;
};

class UartSimulator
{
public:
    static std::shared_ptr<QString> step(int line_num);
    static std::shared_ptr<QString> run();
    static std::shared_ptr<struct PauseSignal> pause();
};

#endif // UARTSIMULATOR_H
