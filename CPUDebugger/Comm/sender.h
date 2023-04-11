#include "QObject"
#include "QThread"
#include "QMutex"
#include "QWaitCondition"

#ifndef SENDER_H
#define SENDER_H

class SenderThread : public QThread{
    Q_OBJECT

public:
    explicit SenderThread(QObject *parent = nullptr);
    ~SenderThread();

    void transaction(const QString &portName, int waitTimeout, const QByteArray &data, bool hasResponse);
    void stop();

signals:
    void response(const QByteArray &s);
    void error(const QString &s);
    void timeout(const QString &s);

private:
    void run() override;

    // Shared properties
    QString portName;
    int waitTimeout = 0;
    QByteArray data;
    bool hasResponse;

    // Multithreading related
    QMutex mutex;
    QWaitCondition cond;

    // Special flag controlling all started
    bool stopFlag = false;
};

#endif // SENDER_H
