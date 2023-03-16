#ifndef MODULE_H
#define MODULE_H
#include <QString>
#include <QList>
#include "Signal.h"
class Module {
private:
    QString name;
    QList<Signal> inputSignals;
    QList<Signal> outputSignals;
};

#endif // MODULE_H
