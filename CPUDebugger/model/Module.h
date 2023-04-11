#ifndef MODULE_H
#define MODULE_H
#include <QString>
#include <QList>
#include <QException>
#include "MySignal.h"
class Module {
public:
    void addSignal(MySignal sig, SType st);
private:
    QString name;
    QList<MySignal> inSignals;
    QList<MySignal> outSignals;
};

inline void Module::addSignal(MySignal sig, SType st)
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
