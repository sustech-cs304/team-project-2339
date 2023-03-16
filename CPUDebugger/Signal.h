#ifndef SIGNAL_H
#define SIGNAL_H
#include <QString>
#include <QBitArray>
enum SignalState {
    ON=1, OFF=0
};

class Signal {
private:
    QString name;
    QBitArray bitVal;
    bool isFlagged;
};

#endif // SIGNAL_H
