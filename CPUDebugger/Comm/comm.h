#include "QSerialPort"
#include "QSerialPortInfo"
#include "QObject"
#include "Comm/sender.h"

#ifndef COMM_H
#define COMM_H

class UartCommunicator : public QObject{

private:
    static QList<QSerialPortInfo> getAvailableSerialPorts();

public:
    explicit UartCommunicator(QObject *parent = nullptr);
    ~UartCommunicator();
    bool connectCPU(const QString &portName);
    bool autoConnectCPU();
    bool disconnectCPU();
    bool sendPacket(const unsigned char* packet, int length);
    bool receivePacket(unsigned char* packet, int length);
    bool sendPause();
    bool sendResume();
    bool sendNext();
    bool sendProgram(const char* asmFile);

private:
    QString cpuPortName;
    SenderThread *worker;
};

#endif // COMM_H
