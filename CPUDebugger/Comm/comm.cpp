#include "Comm/comm.h"

QList<QSerialPortInfo> UartCommunicator::getAvailableSerialPorts(){
    return QSerialPortInfo::availablePorts();
}

UartCommunicator::UartCommunicator(QObject *parent) : QObject(parent){

}

UartCommunicator::~UartCommunicator(){
//    this->disconnect();
}
