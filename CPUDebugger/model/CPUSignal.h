#ifndef CPUSIGNAL_H
#define CPUSIGNAL_H
#include "qdebug.h"
#include "verilog_data.hpp"
#include <QString>
#include <QBitArray>
typedef int SType;
#define SIG_IN 0
#define SIG_OUT 1

enum SignalState {
    ON=1, OFF=0
};

/**
 * @brief The CPUSignal class
 *
 * @attention The signal is no net-range if lBound=-1 and rBound=-1.
 */
class CPUSignal {
public:
    CPUSignal(QString name, int lBound, int rBound): name(name), lBound(lBound), rBound(rBound) {
        rawWidth = rBound - lBound + 1;
        width = (rawWidth + 7) & (!7);
    }
    static CPUSignal createInstance(verilog::NetConcat &net) {
        switch (net.index()) {
        case 0: {
            return CPUSignal(QString::fromStdString(std::get<0>(net)), -1, -1);
        }
        case 1: {
            verilog::NetBit netBit = std::get<1>(net);
            return CPUSignal(QString::fromStdString(netBit.name), netBit.bit, netBit.bit);
        }
        case 2: {
            verilog::NetRange netRange = std::get<2>(net);
            return CPUSignal(QString::fromStdString(netRange.name), netRange.beg, netRange.end);
        }
        case 3: {
            verilog::Constant constant = std::get<3>(net);
            return CPUSignal("NULL", -1, -1);
        }
        default:
            return CPUSignal("NULL", -1, -1);
        }
    }
    QString   name;         // name of the CPU's signal
    int    lBound;       // left bound of signal
    int    rBound;       // right bound of signal
    int    width;        // the width after byte alignment
    int    rawWidth;     // the original width without byte alignment
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
