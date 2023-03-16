#ifndef MYSIGNAL_H
#define MYSIGNAL_H
#include <QString>
#include <QBitArray>
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
