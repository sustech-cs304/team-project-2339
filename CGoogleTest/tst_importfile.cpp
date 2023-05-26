#include "FileController.h"
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <compile/PreProcessor.h>
#include <compile/compiler.h>
#include <FileUtil.h>
#include <verilog_driver.hpp>

using namespace testing;

class CompilerTest : public ::testing::Test
{
protected:

    virtual void SetUp() {
        projPath = QDir::currentPath()+"/..";
        dirPath = projPath + "/examples/module_files";
        destPath = projPath + "/examples/target";
        tokenPath = projPath + "/examples/token.txt";
        qDebug() << "Compiler test begin";
    }

    virtual void TearDown() {
        qDebug() << "Compiler test end";
    }
public:
    QString projPath;
    QString dirPath;
    QString destPath;
    QString tokenPath;
};

TEST_F(CompilerTest, GenGraph) {
    FileController *c = new FileController();
    c->genGraph(destPath);
    delete c;
}

TEST_F(CompilerTest, PreProcess) {
    PreProcessor *p = new PreProcessor();
    p->clear();
    ASSERT_EQ(p->getMarcoMap().size(), 0);
    p->process(dirPath+"/definitions.v", tokenPath);
    ASSERT_GE(p->getMarcoMap().size(), 0);
    p->replace(dirPath+"/top.v", destPath+"/top.v", true);
    p->replace(dirPath+"/definitions.v", destPath+"/definitions.v", false);
    p->clear();
    delete p;
}

TEST_F(CompilerTest, ExportSignals) {
    FileController *c = new FileController();
    QString url = QString::fromStdString("file:///"+dirPath.toStdString());
    c->import(url);
    QList<CPUSignal> sigs = c->getSignalList();
    for (const CPUSignal& sig: sigs) {
        qDebug() << "Signal: " << sig.name << sig.lBound << " " << sig.rBound << " " << sig.rawWidth << " " << sig.width;
    }
//    QList<QString> ss = c->getStringSignals();
//    qDebug() << ss;
//    ASSERT_GE(ss.size(), 0);
    ASSERT_EQ(c->getSvgPath(), QUrl::fromLocalFile(QString(QDir::tempPath()+"/tmp/show.svg")).url());
    delete c;
}

TEST(SignalTest, FilterSignals) {
    FileController *c = new FileController();
    QList<QString> ss;
    ss.append("Andy");
    ss.append("Bob");
    ss.append("Apple");
    ss.append("Cindy");
    ss.append("Andrew");
    qDebug() << ss;
    c->filter(ss, "A");
    qDebug() << ss;
    c->genGraph("E:/debug/basicmodules");
}
