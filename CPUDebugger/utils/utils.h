#ifndef UTILS_H
#define UTILS_H
#include <QtCore>
#include <memory>

struct UartSignal
{
    std::shared_ptr<QString> stringPtr;
    int lineIdx;
};




#endif // UTILS_H
