#include "Comm/comm.h"
#include "QCoreApplication"
QList<QSerialPortInfo> UartCommunicator::getAvailableSerialPorts(){
    return QSerialPortInfo::availablePorts();
}

UartCommunicator::UartCommunicator(QObject *parent) : QObject(parent){
    this->worker = new SenderThread(this);
}

UartCommunicator::~UartCommunicator(){
    delete worker;
    if (cpuPortName != NULL)
        delete cpuPortName;
}

bool UartCommunicator::connectCPU(const QString &portName, double packetWaitingSeconds, double totWaitingSeconds, int pingNum){
    QSerialPort serial;
    serial.setPortName(portName);
    // Port down
    if (!serial.open(QIODevice::ReadWrite))
        return false;
    serial.close();
    // Protocol down
    const QByteArray PING = QByteArray(1, 0x03);
    bool pingResult = false, packetTimeout = false, packetError = false;
    auto pingSlot = [&](const QByteArray& data) ->void {
        if (data.size() == 1 && data.at(0) == 0x02)
            pingResult = true;
    };
    auto timeoutSlot = [&](const QString &msg) ->void {
        packetTimeout = true;
    };
    auto errorSlot = [&](const QString &msg) ->void {
        packetError = true;
    };
    QMetaObject::Connection c1 = connect(worker, &SenderThread::response, pingSlot);
    QMetaObject::Connection c2 = connect(worker, &SenderThread::error, errorSlot);
    QMetaObject::Connection c3 = connect(worker, &SenderThread::timeout, timeoutSlot);
    QElapsedTimer timer;
    timer.start();
    for (int i = 0; i < pingNum; i++){
        worker->transaction(portName, this->serialBaudRate, (int)(packetWaitingSeconds*1000), PING, true);
        while (timer.elapsed() < (int)(totWaitingSeconds*1000)){
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
    // Diconnect the signals.
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
            return true;
    }
    return false;
}

bool UartCommunicator::noResponseSend(const QByteArray &packet, double packetWaitingSeconds, double totWaitingSeconds){
    bool finishSending = false, timeout = false, error = false;
    auto finishSendingSlot = [&]() ->void {
            finishSending = true;
    };
    auto timeoutSlot = [&](const QString &msg) ->void {
            timeout = true;
    };
    auto errorSlot = [&](const QString &msg) ->void {
            error = true;
    };
    QMetaObject::Connection c1 = connect(worker, &SenderThread::finishSending, finishSendingSlot);
    QMetaObject::Connection c2 = connect(worker, &SenderThread::error, errorSlot);
    QMetaObject::Connection c3 = connect(worker, &SenderThread::timeout, timeoutSlot);
    QElapsedTimer timer;
    timer.start();
    worker->transaction(*(this->cpuPortName), this->serialBaudRate, (int)(packetWaitingSeconds*1000), packet, false);
    while (timer.elapsed() < (int)(totWaitingSeconds*1000)){
        if (finishSending || timeout || error)
            break;
        QCoreApplication::processEvents();
    }
    disconnect(c1);
    disconnect(c2);
    disconnect(c3);
    return finishSending;
}

//bool UartCommunicator::sendPause(double packetWaitingSeconds, double totWaitingSeconds){
//    const QByteArrays PAUSE = QByteArray(1, 0x04);
//    return this->noResponseSend(PAUSE, packetWaitingSeconds, totWaitingSeconds);
//}

bool UartCommunicator::sendPause(QByteArray& cpuResponse, double packetWaitingSeconds, double totWaitingSeconds){
    QSerialPort serial;
    serial.setPortName(*(this->cpuPortName));
    // Port down
    if (!serial.open(QIODevice::ReadWrite))
        return false;
    serial.close();
    // Protocol down
    const QByteArray PAUSE = QByteArray(1, 0x04);
    bool responseResult, packetTimeout = false, packetError = false;
    auto responseSlot = [&](const QByteArray& data) ->void {
        if(data.size() >= 1 && data.at(0) == 0x01){
            cpuResponse.clear();
            if (data.size() > 1)
                cpuResponse.append(data.mid(1));
            responseResult = true;
        }
    };
    auto timeoutSlot = [&](const QString &msg) ->void {
        packetTimeout = true;
    };
    auto errorSlot = [&](const QString &msg) ->void {
        packetError = true;
    };
    QMetaObject::Connection c1 = connect(worker, &SenderThread::response, responseSlot);
    QMetaObject::Connection c2 = connect(worker, &SenderThread::error, errorSlot);
    QMetaObject::Connection c3 = connect(worker, &SenderThread::timeout, timeoutSlot);
    QElapsedTimer timer;
    timer.start();
    worker->transaction(*(this->cpuPortName), this->serialBaudRate, (int)(packetWaitingSeconds*1000), PAUSE, true);
    while (timer.elapsed() < (int)(totWaitingSeconds*1000)){
        if (packetTimeout || packetError || responseResult)
            break;
        QCoreApplication::processEvents();
    }
    // Diconnect the signals.
    disconnect(c1);
    disconnect(c2);
    disconnect(c3);
    return responseResult;
}

//bool UartCommunicator::sendNext(double packetWaitingSeconds, double totWaitingSeconds){
//    const QByteArray NEXT = QByteArray(1, 0x06);
//    return this->noResponseSend(NEXT, packetWaitingSeconds, totWaitingSeconds);
//}

bool UartCommunicator::sendStep(QByteArray& cpuResponse, double packetWaitingSeconds, double totWaitingSeconds){
    QSerialPort serial;
    serial.setPortName(*(this->cpuPortName));
    // Port down
    if (!serial.open(QIODevice::ReadWrite))
        return false;
    serial.close();
    // Protocol down
    const QByteArray NEXT = QByteArray(1, 0x06);
    bool responseResult, packetTimeout = false, packetError = false;
    auto responseSlot = [&](const QByteArray& data) ->void {
        if(data.size() >= 1 && data.at(0) == 0x01){
            cpuResponse.clear();
            if (data.size() > 1)
                cpuResponse.append(data.mid(1));
            responseResult = true;
        }
    };
    auto timeoutSlot = [&](const QString &msg) ->void {
        packetTimeout = true;
    };
    auto errorSlot = [&](const QString &msg) ->void {
        packetError = true;
    };
    QMetaObject::Connection c1 = connect(worker, &SenderThread::response, responseSlot);
    QMetaObject::Connection c2 = connect(worker, &SenderThread::error, errorSlot);
    QMetaObject::Connection c3 = connect(worker, &SenderThread::timeout, timeoutSlot);
    QElapsedTimer timer;
    timer.start();
    worker->transaction(*(this->cpuPortName), this->serialBaudRate, (int)(packetWaitingSeconds*1000), NEXT, true);
    while (timer.elapsed() < (int)(totWaitingSeconds*1000)){
        if (packetTimeout || packetError || responseResult)
            break;
        QCoreApplication::processEvents();
    }
    // Diconnect the signals.
    disconnect(c1);
    disconnect(c2);
    disconnect(c3);
    return responseResult;
}

bool UartCommunicator::sendProgram(const QByteArray& asmFile, double packetWaitingSeconds, double totWaitingSeconds){
    const QByteArray ASM = QByteArray(1, 0x07).append(asmFile);
    return this->noResponseSend(ASM, packetWaitingSeconds, totWaitingSeconds);
}

void UartCommunicator::setBaudRate(int baudRate){
    this->serialBaudRate = baudRate;
}
