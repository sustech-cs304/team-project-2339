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
    QString   name;         // name of the CPU's signal
    size_t    width;        // the width after byte alignment
    size_t    rawWidth;     // the original width without byte alignment
    QBitArray bitVal;       // value of the signal
    bool      isFlagged;
};


class ASMLine {
    size_t  index;          // index of the instruction in the program
    QString line;           // the instruction line
    bool    isCurrent;      // whether the CPU paused on this instruction
    bool    isBreakPoint;   // whether the this is a breakpoint
    bool    isInstruction;  // false for any labels or data
};

#endif // CPUSIGNAL_H
