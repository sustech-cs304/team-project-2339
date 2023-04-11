#ifndef UTILS_H
#define UTILS_H
#include <QtCore>
#include <memory>

struct PauseSignal
{
    std::shared_ptr<QString> stringPtr;
    int lineIdx;
};
#endif // UTILS_H
