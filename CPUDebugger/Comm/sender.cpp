#include "Comm/sender.h"
#include "QSerialPort"
#include "QTime"

SenderThread::SenderThread(QObject *parent) : QThread(parent){}

void SenderThread::transaction(const QString &portName, int baudRate, int waitTimeout, const QByteArray &data, bool hasResponse)
{
    const QMutexLocker locker(&mutex);
    this->portName = portName;
    this->baudRate = baudRate;
    this->waitTimeout = waitTimeout;
    this->data = data;
    this->hasResponse = hasResponse;
    this->stopFlag = false;
    if (!isRunning())
        start();
    else
        cond.wakeOne();
}

void SenderThread::stop(){
    const QMutexLocker locker(&mutex);
    stopFlag = true;
    if(isRunning())
        cond.wakeOne();
}

void SenderThread::run(){
    bool currentPortNameChanged = false;

    mutex.lock();
    QString currentPortName;
    if (currentPortName != portName) {
        currentPortName = portName;
        currentPortNameChanged = true;
    }
    int currentBaudRate = baudRate;
    int currentWaitTimeout = waitTimeout;
    QByteArray currentData = data;
    bool currentHasResponse = hasResponse;
    mutex.unlock();

    QSerialPort serial;
    if (currentPortName.isEmpty()) {
        emit error(tr("No port name specified"));
        return;
    }

    while (!stopFlag) {
        mutex.lock();
        serial.setPortName(currentPortName);
        serial.setBaudRate(currentBaudRate);
        if (!serial.open(QIODevice::ReadWrite)) {
            emit error(tr("Can't open %1, error code %2").arg(currentPortName).arg(serial.error()));
            return;
        }

        // Write request
        serial.write(currentData);
        if (!serial.waitForBytesWritten(currentWaitTimeout))
            emit timeout(tr("Wait write request timeout %1").arg(QTime::currentTime().toString()));
        emit finishSending();
        if (currentHasResponse){
            // Read response
            if (serial.waitForReadyRead(currentWaitTimeout)) {
                QByteArray responseData = serial.readAll();
                while (serial.waitForReadyRead(10))
                    responseData += serial.readAll();
                emit this->response(responseData);
            } else {
                emit timeout(tr("Wait read response timeout %1").arg(QTime::currentTime().toString()));
            }
        }
        serial.close();
        cond.wait(&mutex);
        currentBaudRate = baudRate;
        currentWaitTimeout = waitTimeout;
        currentData = data;
        currentHasResponse = hasResponse;
        mutex.unlock();
    }
    quit();
}

SenderThread::~SenderThread(){
    stop();
    wait();
}
