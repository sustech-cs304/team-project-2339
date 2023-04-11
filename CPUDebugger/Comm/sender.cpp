#include "Comm/sender.h"
#include "QSerialPort"
#include "QTime"
void SenderThread::transaction(const QString &portName, int waitTimeout, const QByteArray &data, bool hasResponse)
{
    const QMutexLocker locker(&mutex);
    this->portName = portName;
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
    stopFlag = true;
    cond.wakeAll();
}

void SenderThread::run(){
    bool currentPortNameChanged = false;

    mutex.lock();
    QString currentPortName;
    if (currentPortName != portName) {
        currentPortName = portName;
        currentPortNameChanged = true;
    }

    int currentWaitTimeout = waitTimeout;
    const char* currentData = data;
    bool currentHasResponse = hasResponse;
    bool currentQuit = stopFlag;
    mutex.unlock();

    QSerialPort serial;

    if (currentPortName.isEmpty()) {
        emit error(tr("No port name specified"));
        return;
    }

    while (!currentQuit) {
        if (currentPortNameChanged) {
            serial.close();
            serial.setPortName(currentPortName);

            if (!serial.open(QIODevice::ReadWrite)) {
                emit error(tr("Can't open %1, error code %2").arg(portName).arg(serial.error()));
                return;
            }
        }

        // write request
        serial.write(currentData);
        if (!serial.waitForBytesWritten(waitTimeout))
            emit timeout(tr("Wait write request timeout %1").arg(QTime::currentTime().toString()));

        if (currentHasResponse){
            // read response
            if (serial.waitForReadyRead(currentWaitTimeout)) {
                QByteArray responseData = serial.readAll();
                while (serial.waitForReadyRead(10))
                    responseData += serial.readAll();
                emit this->response(responseData);
            } else {
                emit timeout(tr("Wait read response timeout %1").arg(QTime::currentTime().toString()));
            }
        }
        mutex.lock();
        cond.wait(&mutex);
        if (currentPortName != portName) {
            currentPortName = portName;
            currentPortNameChanged = true;
        } else {
            currentPortNameChanged = false;
        }
        currentWaitTimeout = waitTimeout;
        currentData = data;
        currentQuit = stopFlag;
        mutex.unlock();
    }
    quit();
}

SenderThread::~SenderThread(){
    stop();
    wait();
}
