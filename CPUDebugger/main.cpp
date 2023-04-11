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
    UartCommunicator uartCommunicator = UartCommunicator();
    qDebug() << "uartCommunicator created";

}
