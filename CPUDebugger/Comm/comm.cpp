#include "Comm/comm.h"

QList<QSerialPortInfo> UartCommunicator::getAvailableSerialPorts(){
    return QSerialPortInfo::availablePorts();
}

UartCommunicator::UartCommunicator(QObject *parent) : QObject(parent){
    this->worker = new SenderThread(this);
}

UartCommunicator::~UartCommunicator(){
    delete this->worker;
    this->worker = nullptr;
}

bool UartCommunicator::connectCPU(const QString &portName){
    QSerialPort serial;
    serial.setPortName(portName);
    // Port down
    if (!serial.open(QIODevice::ReadWrite))
        return false;
    // Protocol down
    const QByteArray PING = QByteArray(1, 0x02);
    worker->transaction(portName, 1000, PING, true);

}

bool UartCommunicator::autoConnectCPU(){
    QList<QSerialPortInfo> ports = UartCommunicator::getAvailableSerialPorts();
    bool portFound = false;
    for (const QSerialPortInfo &port : ports) {
        portFound = connectCPU(port.portName());
        if(portFound)
            return portFound;
    }
    return false;
}
