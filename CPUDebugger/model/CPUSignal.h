#ifndef CPUSIGNAL_H
#define CPUSIGNAL_H
#include <QString>
#include <QBitArray>
typedef int SType;
#define SIG_IN 0
#define SIG_OUT 1

enum SignalState {
    ON=1, OFF=0
};

class CPUSignal {
public:
    CPUSignal(QString signalName);
private:
    QString name;
    QBitArray bitVal;
    bool isFlagged;
};

inline CPUSignal::CPUSignal(QString signalName)
{
    this->name = signalName;
}

#endif // CPUSIGNAL_H
