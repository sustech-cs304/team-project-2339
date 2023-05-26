//
// Created by David Li on 4/26/23.
//

#include <QtTest>
#include <iostream>
#include <CPUDebugger/File/AsmFile.h>
#include <CPUDebugger/model/CPUSignal.h>
#include <CPUDebugger/uart/CoreGenerator.h>
// add necessary includes here

class Testbench : public QObject {
Q_OBJECT
private slots:

    void parseASM();

    void generate();
};

void Testbench::parseASM() {
    QFile   top(QDir::currentPath().append("/../examples/asm_files/test.asm"));
    AsmFile asmFile(top);

    QString s = ".text\n"
                "main:\n"
                "\tmove $a1, $v0 # load positive integer as second argument\n"
                "\tjal bin_length # call get length function\n"
                "\n"
                "\tmove $a0, $s0 # load length as first argument\n"
                "\tjal bin_reverse # call the reverse function\n"
                "\n"
                "\tjal hex_length\n"
                "\n"
                "\tmove $a0, $s0\n"
                "\tjal main\n"
                "\n"
                "bin_length:\n"
                "\tli $a2, 1 # load bit width of base as third argument\n"
                "\tj length\n"
                "bin_reverse:\n"
                "\tli $a2, 1 # load bit width of base as third argument\n"
                "\tj reverse\n"
                "\n"
                "hex_length:\n"
                "\tli $a2, 4\n"
                "\tj length\n"
                "hex_reverse:\n"
                "\tli $a2, 4\n"
                "\tj reverse\n"
                "\n"
                "# a1: positive integer\n"
                "# a2: bit width of base\n"
                "# t0: remaining number value\n"
                "# s0: length of number\n"
                "length:\n"
                "\tmove $t0, $a1\n"
                "\tli $s0, 0\n"
                "\n"
                "length_loop:\n"
                "\tsrlv $t0, $t0, $a2\n"
                "\taddu $s0, $s0, 1\n"
                "\tbnez $t0, length_loop\n"
                "\n"
                "\tjr $ra\n"
                "\n"
                "# a0: length of number\n"
                "# a1: positive integer\n"
                "# a2: bit width of base\n"
                "# t0: remaining number\n"
                "# t1: mask for digit\n"
                "# t2: current digit value\n"
                "# s0: reversed number\n"
                "reverse:\n"
                "\tmove $t0, $a1\n"
                "\tli $t1, 1\n"
                "\tli $s0, 0\n"
                "\tsllv $t1, $t1, $a2 # shift left\n"
                "\tsubu $t1, $t1, 1 # subtract by 1 to obtain the mask\n"
                "\n"
                "reverse_loop:\n"
                "\tand $t2, $t0, $t1\n"
                "\tsrlv $t0, $t0, $a2\n"
                "\tsllv $s0, $s0, $a2\n"
                "\tor $s0, $s0, $t2\n"
                "\tbnez $t0, reverse_loop\n"
                "\n"
                "\tjr $ra\n"
                "\n"
                "\tsyscall";

    asmFile.updateAsmFile(s);
}

void Testbench::generate() {
    QList<CPUSignal> list{
            CPUSignal{"instruction_1", 0, 31},
            CPUSignal{"another_instruction", 0, 31}
    };
//    qDebug("%s", insertInput(list).toLocal8Bit().constData());
//    qDebug("%s", insertBytes(list).toLocal8Bit().constData());
//    qDebug("%s", insertWidth(list).toLocal8Bit().constData());
//    qDebug("%s", insertSignals(list).toLocal8Bit().constData());

    generateCore(QDir::currentPath().append("/../CPUDebugger/uart/assets/top.v"),
                 QDir::currentPath().append("/../CPUDebugger/uart/assets/"),
                 list);
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
