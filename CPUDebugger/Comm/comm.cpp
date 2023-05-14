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
    // 0 -> no Response, 1 -> success, -1 -> format failed
    int responseResult = 0;
    bool packetTimeout = false, packetError = false;
    auto pingSlot = [&](const QByteArray& data) ->void {
        if (data.size() == 1 && data.at(0) == 0x02)
            responseResult = 1;
        else
            responseResult = -1;
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
            if (packetTimeout || packetError || responseResult != 0){
                packetTimeout = false;
                packetError = false;
                break;
            }
            QCoreApplication::processEvents();
        }
        if (responseResult == 1)
            break;
        responseResult = 0;
    }
    // Diconnect the signals.
    disconnect(c1);
    disconnect(c2);
    disconnect(c3);
    if (responseResult == 1)
        cpuPortName = new QString(portName);
    return responseResult == 1;
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

void UartCommunicator::sendPause(){
    this->worker->pause();
}

bool UartCommunicator::sendPausePacket(QByteArray& cpuResponse, double packetWaitingSeconds, double totWaitingSeconds){
    // Protocol down
    const QByteArray PAUSE = QByteArray(1, 0x04);
    // 0 -> no Response, 1 -> success, -1 -> format failed
    int responseResult = 0;
    bool packetTimeout = false, packetError = false;
    auto responseSlot = [&](const QByteArray& data) ->void {
        if(data.size() >= 1 && data.at(0) == 0x01){
            cpuResponse.clear();
            if (data.size() > 1)
                cpuResponse.append(data.mid(1));
            responseResult = 1;
        } else
            responseResult = -1;
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
        if (packetTimeout || packetError || responseResult != 0)
            break;
        QCoreApplication::processEvents();
    }
    // Diconnect the signals.
    disconnect(c1);
    disconnect(c2);
    disconnect(c3);
    return responseResult == 1;
}

bool UartCommunicator::sendStep(QByteArray& cpuResponse, double packetWaitingSeconds, double totWaitingSeconds){
    // Protocol down
    const QByteArray NEXT = QByteArray(1, 0x06);
    // 0 -> no Response, 1 -> success, -1 -> format failed
    int responseResult = 0;
    bool packetTimeout = false, packetError = false;
    auto responseSlot = [&](const QByteArray& data) ->void {
        if(data.size() >= 1 && data.at(0) == 0x01){
            cpuResponse.clear();
            if (data.size() > 1)
                cpuResponse.append(data.mid(1));
            responseResult = 1;
        } else
            responseResult = -1;
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
        if (packetTimeout || packetError || responseResult != 0)
            break;
        QCoreApplication::processEvents();
    }
    // Diconnect the signals.
    disconnect(c1);
    disconnect(c2);
    disconnect(c3);
    return responseResult == 1;
}

bool UartCommunicator::sendResume(QByteArray& cpuResponse, int nextPC, double packetWaitingSeconds, double totWaitingSeconds){
    // Protocol down
    const QByteArray PAUSE = QByteArray(1, 0x04);
    QByteArray RESUME;
    QDataStream stream(&RESUME, QIODevice::ReadWrite);
    stream << quint8(0x05) << quint32(nextPC);
    bool packetTimeout = false, packetError = false;
    // 0 -> no Response, 1 -> success, -1 -> format failed
    int responseResult = 0;
    auto responseSlot = [&](const QByteArray& data) ->void {
        if(data.size() >= 1 && data.at(0) == 0x01){
            cpuResponse.clear();
            if (data.size() > 1)
                cpuResponse.append(data.mid(1));
            responseResult = 1;
        } else
            responseResult = -1;
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
    // Should wait infinitely when `sendResume(.)` is called
    worker->transaction(*(this->cpuPortName), this->serialBaudRate, std::numeric_limits<int>::max(), RESUME, true);
    bool isPaused = false;
    while (!packetError && responseResult == 0){
        QCoreApplication::processEvents();
        isPaused = this->worker->isPaused();
        if (isPaused) break;
    }
    if (isPaused){
        responseResult = 0;
        packetTimeout = false;
        packetError = false;
        QElapsedTimer timer;
        timer.start();
        worker->transaction(*(this->cpuPortName), this->serialBaudRate, (int)(packetWaitingSeconds*1000), PAUSE, true);
        while (timer.elapsed() < (int)(totWaitingSeconds*1000)){
            if (packetTimeout || packetError || responseResult != 0)
                break;
            QCoreApplication::processEvents();
        }
    }
    // Diconnect the signals.
    disconnect(c1);
    disconnect(c2);
    return responseResult == 1;
}

bool UartCommunicator::sendProgram(const QByteArray& asmFile, double packetWaitingSeconds, double totWaitingSeconds){
    const QByteArray ASM = QByteArray(1, 0x07).append(asmFile);
    return this->noResponseSend(ASM, packetWaitingSeconds, totWaitingSeconds);
}

void UartCommunicator::setBaudRate(int baudRate){
    this->serialBaudRate = baudRate;
}
