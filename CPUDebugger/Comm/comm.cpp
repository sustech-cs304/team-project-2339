#include "Comm/comm.h"
#include "QCoreApplication"
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

bool UartCommunicator::connectCPU(const QString &portName, double packetWaitingSeconds, double totWaitingSeconds, int pingNum){
    QSerialPort serial;
    serial.setPortName(portName);
    // Port down
    if (!serial.open(QIODevice::ReadWrite))
        return false;
    // Protocol down
    const QByteArray PING = QByteArray(1, 0x03);
    bool pingResult = false, packetTimeout = false, packetError = false;
    auto pingSlot = [&](const QByteArray& data) ->void {
        if (data.size() == 1 && data.at(0) == 0x03)
            pingResult = true;
    };
    auto timeoutSlot = [&](const QByteArray& data) ->void {
            packetTimeout = true;
    };
    auto errorSlot = [&](const QByteArray& data) ->void {
            packetError = true;
    };
    QMetaObject::Connection c1 = connect(worker, &SenderThread::response, pingSlot);
    QMetaObject::Connection c2 = connect(worker, &SenderThread::error, errorSlot);
    QMetaObject::Connection c3 = connect(worker, &SenderThread::timeout, timeoutSlot);
    QElapsedTimer timer;
    timer.start();
    for (int i = 0; i < pingNum; i++){
        worker->transaction(portName, (int)(packetWaitingSeconds*1000), PING, true);
        while (timer.elapsed() < totWaitingSeconds){
            if (packetTimeout || packetError || pingResult){
                packetTimeout = false;
                packetError = false;
                break;
            }
            QCoreApplication::processEvents();
        }
        if (pingResult)
            break;
    }
    // please diconnect the signals.
    disconnect(c1);
    disconnect(c2);
    disconnect(c3);
    if (pingResult)
        cpuPortName = new QString(portName);
    return pingResult;
}

bool UartCommunicator::autoConnectCPU(double packetWaitingSeconds, double totWaitingSeconds, int pingNum){
    QList<QSerialPortInfo> ports = UartCommunicator::getAvailableSerialPorts();
    bool portFound = false;
    for (const QSerialPortInfo &port : ports) {
        portFound = connectCPU(port.portName(), packetWaitingSeconds, totWaitingSeconds, pingNum);
        if(portFound)
            return portFound;
    }
    return false;
}
