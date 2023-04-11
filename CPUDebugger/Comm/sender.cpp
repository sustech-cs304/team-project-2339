#include "Comm/sender.h"

void SenderThread::transaction(const QString &portName, int waitTimeout, const char* data)
{
    const QMutexLocker locker(&mutex);
    this->portName = portName;
    this->waitTimeout = waitTimeout;
    this->data = data;
    if (!isRunning())
        start();
    else
        cond.wakeOne();
}
