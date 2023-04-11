#ifndef MYSIGNAL_H
#define MYSIGNAL_H
#include <QString>
#include <QBitArray>
typedef int SType;
#define SIG_IN 0
#define SIG_OUT 1

enum SignalState {
    ON=1, OFF=0
};

class MySignal {
private:
    QString name;
    QBitArray bitVal;
    bool isFlagged;
};

#endif // MYSIGNAL_H
