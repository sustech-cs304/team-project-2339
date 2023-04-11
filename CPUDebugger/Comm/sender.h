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

    void transaction(const QString &portName, int waitTimeout, const char *data);

signals:
    void response(const QString &s);
    void error(const QString &s);
    void timeout(const QString &s);

private:
    void run() override;

    QString portName;
    const char* data;
    int waitTimeout = 0;
    QMutex mutex;
    QWaitCondition cond;
    bool quit = false;
};

#endif // SENDER_H
