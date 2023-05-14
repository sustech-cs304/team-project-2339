
#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


//#include "uart/comm.h"

//int main()
//{
//    UartCommunicator comm();
//}

//#include <QtCore>
//#include "Controllers/PreDebugController.h"
//#include "Controllers/DebugController.h"

//int main()
//{
//    qDebug() << "Test Start";
//    PreDebugController::uploadFile("/Users/zitong/Library/CloudStorage/OneDrive-Personal/2023_Spring/CS304 Software Engineering/team-project-2339/CPUDebugger/test.asm");
//    qDebug() << "OK";
////    PreDebugController::setBreakPoint(1);
////    qDebug() << "OK1";
////    PreDebugController::setBreakPoint(3);
////    qDebug() << "OK2";
////    PreDebugController::setBreakPoint(7);
////    qDebug() << "OK3";
////    PreDebugController::setBreakPoint(10);
////    qDebug() << "OK4";
////    PreDebugController::setBreakPoint(13);
////    qDebug() << "OK5";
//    PreDebugController::compileAsm();
//    qDebug() << "OK6";

//    QFile file("/Users/zitong/Library/CloudStorage/OneDrive-Personal/2023_Spring/CS304 Software Engineering/team-project-2339/CPUDebugger/result.txt");
//    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
//    {
//        QTextStream out(&file);
//        out << DebugController::getBin();
//        file.close();
//    }
//    qDebug() << "OK7";


//    qDebug() << DebugController::step();
//    qDebug() << "OK8";
//    qDebug() << DebugController::pause();
//    qDebug() << "OK9";
//    //    DebugController::next();

//}
