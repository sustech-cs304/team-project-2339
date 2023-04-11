#include "QSerialPort"
#include "QSerialPortInfo"
#include "QObject"

#ifndef COMM_H
#define COMM_H

class UartCommunicator : public QObject{
private:
    static QList<QSerialPortInfo> getAvailableSerialPorts();

public:
    explicit UartCommunicator(QObject *parent = nullptr);
    ~UartCommunicator();
    bool connect(const char* port);
    bool disconnect();
    bool sendPacket(const unsigned char* packet, int length);
    bool receivePacket(unsigned char* packet, int length);
    bool sendPause();
    bool sendResume();
    bool sendNext();
    bool sendProgram(const char* asmFile);
private:
    QString targetSerialPortName;
};

#endif // COMM_H
