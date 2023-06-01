#ifndef SENDER_H
#define SENDER_H

#include "QObject"
#include "QThread"
#include "QMutex"
#include "QWaitCondition"
#include "QSerialPort"
#include "QTime"

/**
    @brief A thread class used for sending and receiving data packets to and from the CPU.
*/
class SenderThread : public QThread{
    Q_OBJECT

public:
    /**
        @brief Construct a new SenderThread object.
        @param parent Parent object. Default is nullptr.
    */
    explicit SenderThread(QObject *parent = nullptr);
    ~SenderThread();
    /**
        @brief Send and receive data packets to and from the CPU.
        @param portName The name of the serial port to which the CPU is connected.
        @param baudRate The baud rate used for serial communication.
        @param waitTimeout The maximum waiting time for a response from the CPU.
        @param data The data packet to be sent to the CPU.
        @param hasResponse Whether or not the sent data packet requires a response from the CPU.
    */
    void transaction(const QString &portName, int baudRate, int waitTimeout, const QByteArray &data, bool hasResponse);
    /**
        @brief Stop the woker's thread.
    */
    void stop();

    /**
        @brief Pause the sending and receiving of data packets.
    */
    void pause();

    /**
        @brief Check whether the `pause` variable is true or not.
        @return Whether the `pause` variable is true or not.
    */
    bool isPaused();

signals:
    /**
        @brief Signal emitted when the sending of data packets is completed.
    */
    void finishSending();
    /**
        @brief Signal emitted when a response is received from the CPU.
        @param s The response data packet received from the CPU.
    */
    void response(const QByteArray &s);
    /**
        @brief Signal emitted when an error occurs during the sending and receiving of data packets.
        @param s The error message.
    */
    void error(const QString &s);
    /**
        @brief Signal emitted when the waiting time for a response from the CPU exceeds the maximum waiting time.
        @param s The error message.
    */
    void timeout(const QString &s);

private:
    void run() override;

    // Shared properties
    QString portName;
    QByteArray data;
    int waitTimeout = 0;
    int baudRate = 0;
    bool hasResponse;

    // Multithreading related
    QMutex mutex;
    QWaitCondition cond;

    // Special flag controlls the whole thread
    bool stopFlag = false;

    // Special flag controlls the response waiting process
    bool pauseFlag = false;
};

#endif // SENDER_H
