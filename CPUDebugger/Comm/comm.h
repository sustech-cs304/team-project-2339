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
    bool connectCPU(const QString &portName, double packetWaitingSeconds=1.0, double totWaitingSeconds=3.0, int pingNum=3);
    bool autoConnectCPU(double packetWaitingSeconds=1.0, double totWaitingSeconds=3.0, int pingNum=3);
    bool sendPause(double packetWaitingSeconds=1.0, double totWaitingSeconds=1.5);
    bool sendResume();
    bool sendNext(double packetWaitingSeconds=1.0, double totWaitingSeconds=1.5);
    bool sendProgram(const char* asmFile);

private:
    bool noResponseSend(const QByteArray &packet, double packetWaitingSeconds, double totWaitingSeconds);
    QString *cpuPortName;
    SenderThread *worker;
};

#endif // COMM_H
