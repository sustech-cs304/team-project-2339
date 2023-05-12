//
// Created by David Li on 4/26/23.
//

#include <QtTest>
#include <iostream>
#include <CPUDebugger/File/AsmFile.h>
// add necessary includes here

class Testbench : public QObject {
Q_OBJECT
private slots:

    void parseASM();
};

void Testbench::parseASM() {
    QFile   top(QDir::currentPath().append("/test.asm"));
    AsmFile asmFile(top);
}

//class Testbench : public QObject {
//Q_OBJECT
//
//public:
//    QMessageLogger *logger;
//    QString        dirPath;
//    QString        destPath;
//
//    Testbench();
//
//    ~Testbench();
//
//private slots:
//
//    void test_preprocess();
//
//    void test_case2();
//
//    void test_case3();
//
//    void test_case4();
//};
//
//Testbench::Testbench() {
//    logger   = new QMessageLogger();
//    dirPath  = "E:/DebugCore/module_files";
//    destPath = "E:/";
//}
//
//Testbench::~Testbench() {
//}
//
//void Testbench::test_preprocess() {
//    QFAIL("Create directory fail");
//}
//
//void Testbench::test_case2() {
//    QSKIP("Skip case 2");
//}
//
//void Testbench::test_case3() {
//    qDebug() << "case3";
//}
//
//void Testbench::test_case4() {
//    qDebug() << "case4";
//}

QTEST_APPLESS_MAIN(Testbench)

#include "david_testbench.moc"
