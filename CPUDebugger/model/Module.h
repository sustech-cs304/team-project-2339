#ifndef MODULE_H
#define MODULE_H
#include <QString>
#include <QList>
#include "CPUSignal.h"
#include <QException>
class  Module {
public:
    Module(QString name);
    void addSignal(CPUSignal sig, SType st);
private:
    QString name;
    QList<CPUSignal> inSignals;
    QList<CPUSignal> outSignals;
};

inline Module::Module(QString name)
{
    this->name = name;
}

inline void Module::addSignal(CPUSignal sig, SType st)
{
    if (st == SIG_IN) {
        inSignals.append(sig);
    } else if (st == SIG_OUT) {
        outSignals.append(sig);
    } else {
        throw QException();
    }
}

#endif // MODULE_H
