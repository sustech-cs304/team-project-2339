#include "comm.h"
#include <QCoreApplication>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

void test_serial_ports(){
    QSerialPort serialPort;
    QList<QSerialPortInfo> serialPorts = QSerialPortInfo::availablePorts();
    qDebug() << "Now scanning ports";
    foreach (const QSerialPortInfo &serialPortInfo, serialPorts) {
        serialPort.setPort(serialPortInfo);
        if (serialPort.open(QIODevice::ReadWrite)) {
            qDebug() << "Connected to" << serialPort.portName();
            serialPort.close();
        }
    }
}
