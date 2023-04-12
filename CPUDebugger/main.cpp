#include <QtCore>
#include "Controllers/DebugController.h"
#include "Controllers/PreDebugController.h"
#include "File/DebugFile.h"
#include "File/AsmFile.h"
#include "File/CoeFile.h"
#include "Stores/PreDebugStore.h"
#include "Stores/DebugStore.h"
#include "Comm/comm.h"

int main()
{
//    QString filePath = "/Users/zitong/Downloads/test.asm";
//    std::shared_ptr<QFile> file = PreDebugController::uploadFile(filePath);
//    // 打开文件
//    if (file->open(QIODevice::ReadOnly | QIODevice::Text))
//    {
//        // 输出文件所有内容
//        QTextStream in(file.get());
//        while (!in.atEnd())
//        {
//            QString line = in.readLine();
//            qDebug() << line;
//        }
//    }

//    PreDebugController::setBreakPoint(1);
//    PreDebugController::setBreakPoint(4);
//    PreDebugController::setBreakPoint(6);
//    PreDebugController::setBreakPoint(8);
//    PreDebugController::setBreakPoint(11);
//    PreDebugController::setBreakPoint(16);
//    PreDebugController::setBreakPoint(20);

//    qDebug() << *(DebugController::step());
//    qDebug() << DebugStore::asmCurLine;
//    qDebug() << *(DebugController::step());
//    qDebug() << DebugStore::asmCurLine;
//    qDebug() << *(DebugController::step());
//    qDebug() << DebugStore::asmCurLine;
//    qDebug() << *(DebugController::step());
//    qDebug() << DebugStore::asmCurLine;

//    qDebug() << *(DebugController::run());
//    qDebug() << *(DebugController::pause()->stringPtr);
//    qDebug() << DebugStore::asmCurLine;
//    UartCommunicator uartCommunicator = UartCommunicator();
//    qDebug() << 111;
//    QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
//    for (const QSerialPortInfo &port : ports) {
//        QString portName = port.portName();
//        qDebug() << port.standardBaudRates();
//        QSerialPort serial;
//        serial.setPortName(portName);
//        // Port down
//        if (!serial.open(QIODevice::ReadWrite))
//            qDebug() << false;
//        // Protocol down
//        const QByteArray *PING = new QByteArray(1, 0x03);
//        serial.setPortName(portName);
//        serial.setBaudRate(115200);
//        // Write request
//        serial.write(*PING);
//        if (!serial.waitForBytesWritten(1000000))
//            qDebug() << "Wait write response timeout";
//        else qDebug() << "Write Success";
//        // Read response
//        if (true) {
//            QByteArray responseData = serial.readAll();
//            while (serial.waitForReadyRead(10))
//                responseData += serial.readAll();
//        } else {
//            qDebug() << "Wait read response timeout";
//        }
//    }
    UartCommunicator* communicator = new UartCommunicator();
    qDebug() << communicator->autoConnectCPU(1000, 1000, 3);
    qDebug() << communicator->sendNext(1000, 1000);
    bool pause_result = communicator->sendPause(1000, 1000);
    qDebug() << pause_result;


}
