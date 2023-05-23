//#ifndef COMM_FAKE_H
//#define COMM_FAKE_H

//#include "QSerialPort"
//#include "QSerialPortInfo"
//#include "QObject"



//class UartCommunicator_fake : public QObject
//{
//public:
//    explicit UartCommunicator(QObject *parent = nullptr);
//    ~UartCommunicator();
//    bool connectCPU(const QString &portName, double packetWaitingSeconds=1.0, double totWaitingSeconds=3.0, int pingNum=3);
//    bool autoConnectCPU(double packetWaitingSeconds=1.0, double totWaitingSeconds=3.0, int pingNum=3);
//    bool sendResume(QByteArray& cpuResponse, int nextPC, double packetWaitingSeconds=1.0, double totWaitingSeconds=1.5);
//    bool sendPausePacket(QByteArray& cpuResponse, double packetWaitingSeconds=1.0, double totWaitingSeconds=1.5);
//    void sendPause();
//    bool sendStep(QByteArray& cpuResponse, double packetWaitingSeconds=1.0, double totWaitingSeconds=1.5);
//    bool sendProgram(const QByteArray& asmFile, double packetWaitingSeconds=2.0, double totWaitingSeconds=3.0);

//    void setBaudRate(int baudRate);
//}
//#endif // COMM_FAKE_H
