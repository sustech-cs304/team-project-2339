#ifndef CPUSIGNAL_H
#define CPUSIGNAL_H

#include <QString>
#include <QBitArray>

class CPUSignal {
private:
    QString   name;         // name of the CPU's signal
    size_t    width;        // the width after byte alignment
    size_t    rawWidth;     // the original width without byte alignment
    QBitArray bitVal;       // value of the signal
    enum SignalType {
        INPUT = 1, OUTPUT = 0
    }         type;         // the type of the CPU's signal (input or output)
    bool      isFlagged;
};

#endif // CPUSIGNAL_H
