#ifndef COMM_H
#define COMM_H

#include "QSerialPort"
#include "QSerialPortInfo"
#include "QObject"
#include "uart/sender.h"
#include "QCoreApplication"

/**
    @brief This is the core class responsible for communicating with the CPU Uart module.
    It encapsulates all the methods used to interact with the Uart module on the CPU.
    @note: Please avoid instantiating this class multiple times and calling methods of different objects,
    as this may result in unpredictable results!
*/
class UartCommunicator : public QObject{

private:
    static QList<QSerialPortInfo> getAvailableSerialPorts();
public:
    explicit UartCommunicator(QObject *parent = nullptr);
    ~UartCommunicator();
    /**
        @brief Attempt to connect to the CPU on the development board based on the given serial port name portName.
        This method sends a PING packet to the serial port according to the interaction protocol specified in the development documentation and blocks waiting for a response.
        packetWaitingSeconds is the waiting time for a single packet, totWaitingSeconds is the total waiting time that can be accepted, and pingNum is the maximum number of ping attempts allowed.
        @note: This method is not recommended to be called! Please call the autoConnectCPU method as much as possible to avoid explicitly specifying the serial port name!
        @warning: This is a blocking communication method, but it will call QCoreApplication::processEvents() to avoid UI interaction failure.
        @param portName The name of the serial port to connect to the CPU.
        @param packetWaitingSeconds The waiting time for a single packet. Default is 1.0 seconds.
        @param totWaitingSeconds The total waiting time that can be accepted. Default is 3.0 seconds.
        @param pingNum The maximum number of ping attempts allowed. Default is 3.
        @return Whether the connection to the CPU was successful.
    */
    bool connectCPU(const QString &portName, double packetWaitingSeconds=1.0, double totWaitingSeconds=3.0, int pingNum=3);
    /**
        @brief This method automatically scans all available serial ports on the computer and attempts to send PING data packets according to the protocol specified in the development documentation.
        This method automatically calls the connectCPU method to avoid explicitly specifying the serial port name.
        @warning: This is a blocking communication method, but it will call QCoreApplication::processEvents() to avoid UI interaction failure.
        @param packetWaitingSeconds The waiting time for a single packet. Default is 1.0 seconds.
        @param totWaitingSeconds The total waiting time that can be accepted. Default is 3.0 seconds.
        @param pingNum The maximum number of ping attempts allowed. Default is 3.
        @return Whether the connection to the CPU was successful.
    */
    bool autoConnectCPU(double packetWaitingSeconds=1.0, double totWaitingSeconds=3.0, int pingNum=3);
    /**
        @brief Send a RESUME data packet to the CPU on the development board according to the protocol specified in the development documentation, in order to make the CPU continuously execute instructions in the ASM file until the value of the PC register in the CPU is equal to the nextPC value in the input parameter.
        @warning 1: This is a blocking communication method, but it will call QCoreApplication::processEvents() to avoid UI interaction failure.
        @warning 2: There may be an infinite loop in the ASM code, which may cause this method to never return! Therefore, please be sure to bind a slot function to the sendPause() method to allow the user to interrupt the execution of this method and return the result.
        @note: Please judge the validity of cpuResponse based on the return value of this method. If this method returns true, then cpuResponse is valid and can be further called.
        @param cpuResponse The response data packet received from the CPU.
        @param nextPC The value of the PC register to be reached in the CPU.
        @param packetWaitingSeconds The waiting time for a single packet. Default is 1.0 seconds.
        @param totWaitingSeconds The total waiting time that can be accepted. Default is 1.5 seconds.
        @return Whether the RESUME data packet was sent successfully and cpuResponse is valid.
    */
    bool sendResume(QByteArray& cpuResponse, int nextPC, double packetWaitingSeconds=1.0, double totWaitingSeconds=1.5);
    /**
        @brief Send a PAUSE data packet to the CPU according to the transmission protocol specified in the development documentation to interrupt the pipeline execution of the CPU.
        @warning 1: It is strongly NOT recommended to call this method explicitly. Under normal circumstances, users do not need to interrupt the pipeline execution of the CPU. When there is an infinite loop in the user's ASM code and it gets stuck in sendResume, please call the sendPause method! After sendPause is called, this method will be automatically and correctly called in sendResume.
        @warning 2: This is a blocking communication method, but it will call QCoreApplication::processEvents() to avoid UI interaction failure.
        @param cpuResponse The response data packet received from the CPU.
        @param packetWaitingSeconds The waiting time for a single packet. Default is 1.0 seconds.
        @param totWaitingSeconds The total waiting time that can be accepted. Default is 1.5 seconds.
        @return Whether the PAUSE data packet was sent successfully and cpuResponse is valid.
    */
    bool sendPausePacket(QByteArray& cpuResponse, double packetWaitingSeconds=1.0, double totWaitingSeconds=1.5);
    /**
        @brief Automatically interrupt the worker's waiting response process of this object and the waiting response process of the sendResume method. Please bind a slot function to this method to provide users with the pause function when the CPU enters an infinite loop.
    */
    void sendPause();
    /**

        @brief Send a NEXT data packet to the CPU on the development board according to the protocol specified in the development documentation to make the CPU execute the next instruction in the ASM file.
        @warning: This is a blocking communication method, but it will call QCoreApplication::processEvents() to avoid UI interaction failure.
        @note 1: Although this is a blocking method, the response speed of this method should be very fast and should not get stuck. If it does, please check the implementation of the CPU.
        @note 2: Please judge the validity of cpuResponse based on the return value of this method. If this method returns true, then cpuResponse is valid and can be further called.
        @param cpuResponse The response data packet received from the CPU.
        @param packetWaitingSeconds The waiting time for a single packet. Default is 1.0 seconds.
        @param totWaitingSeconds The total waiting time that can be accepted. Default is 1.5 seconds.
        @return Whether the NEXT data packet was sent successfully and cpuResponse is valid.
    */
    bool sendStep(QByteArray& cpuResponse, double packetWaitingSeconds=1.0, double totWaitingSeconds=1.5);
    /**
        @brief Send a PROGRAM data packet to the CPU on the development board according to the protocol specified in the development documentation. This data packet carries all the instructions and data compiled from the ASM file.
        @warning 1: This is a blocking communication method, but it will call QCoreApplication::processEvents() to avoid UI interaction failure.
        @warning 2: This is a blocking communication method, and depending on the size of the ASM file, the sending time may be quite long! Please pay attention to the settings of the packetWaitingSeconds and totWaitingSeconds parameters.
        @param asmFile The ASM file to be sent to the CPU.
        @param cpuResponse The response data packet received from the CPU.
        @param packetWaitingSeconds The waiting time for a single packet. Default is 2.0 seconds.
        @param totWaitingSeconds The total waiting time that can be accepted. Default is 3.0 seconds.
        @return Whether the PROGRAM data packet was sent successfully and cpuResponse is valid.
    */
    bool sendProgram(const QByteArray& asmFile, QByteArray& cpuResponse, double packetWaitingSeconds=2.0, double totWaitingSeconds=3.0);
    /**
        @brief Set the baud rate for the serial communication.
        @param baudRate The baud rate to be set.
    */
    void setBaudRate(int baudRate);

private:
    /**
        @brief Send a data packet to the CPU on the development board without waiting for a response.
        @param packet The data packet to be sent.
        @param packetWaitingSeconds The waiting time for a single packet.
        @param totWaitingSeconds The total waiting time that can be accepted.
        @return Whether the data packet was sent successfully.
    */
    bool noResponseSend(const QByteArray &packet, double packetWaitingSeconds, double totWaitingSeconds);
    /**
        @brief Pointer to a QString object that stores the name of the serial port to which the CPU is connected.
    */
    QString *cpuPortName;
    /**
        @brief The baud rate used for serial communication. Default is 115200.
    */
    int serialBaudRate = 115200;
    /**
        @brief A pointer to the SenderThread object that is responsible for sending and receiving data packets to and from the CPU.
    */
    SenderThread *worker;
};

#endif // COMM_H
