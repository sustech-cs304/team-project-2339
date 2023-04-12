#ifndef CPUSIGNAL_H
#define CPUSIGNAL_H
#include <QString>
#include <QBitArray>
typedef int SType;
#define SIG_IN 0
#define SIG_OUT 1

class CPUSignal {
public:
    CPUSignal(QString signalName);
private:
    QString   name;         // name of the CPU's signal
    size_t    width;        // the width after byte alignment
    size_t    rawWidth;     // the original width without byte alignment
    QBitArray bitVal;       // value of the signal
    bool      isFlagged;
};

inline CPUSignal::CPUSignal(QString signalName)
{
    this->name = signalName;
}

#endif // CPUSIGNAL_H
