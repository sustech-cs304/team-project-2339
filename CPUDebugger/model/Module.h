#ifndef MODULE_H
#define MODULE_H
#include <QString>
#include <QList>
#include "MySignal.h"
class Module {
private:
    QString name;
    QList<MySignal> inputSignals;
    QList<MySignal> outputSignals;
};

#endif // MODULE_H
