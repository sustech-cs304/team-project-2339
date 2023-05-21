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
        projPath = qApp->applicationDirPath()+"/../..";
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

TEST_F(CompilerTest, GenTokens)
{
    GTEST_SKIP();
    PreProcessor *p = new PreProcessor();
    p->process("E:/alu.v", tokenPath);
    qDebug() << QCoreApplication::applicationDirPath();
}

TEST_F(CompilerTest, ImportFile)
{
    GTEST_SKIP();
    QDir dir(destPath);
    if (!dir.exists()) {
        bool ismkdir = dir.mkpath(destPath);
        if (!ismkdir) {
            qDebug() << "Create directory fail";
        }else
            qDebug() << "Create directory success";
    }
    PreProcessor *p = new PreProcessor();
    QStringList entries = FileUtil::getDirList(dirPath, "v", true);
    for (const QString &entryPath: entries) {
        qDebug() << "Process file: " << entryPath;
        p->process(entryPath, std::nullopt);
    }
    for (const QString &entryPath: entries) {
        qDebug() << "Replace file: " << entryPath;
        QFileInfo info(entryPath);
        if (!info.fileName().compare("top.v"))
            p->replace(entryPath, destPath+"/"+info.fileName(), false);
        else
            p->replace(entryPath, destPath+"/"+info.fileName(), true);
    }
    delete p;
}

TEST_F(CompilerTest, GenGraph) {
    FileController *c = new FileController;
    c->genGraph(destPath);
    delete c;
}

TEST_F(CompilerTest, ExportSignals) {
    GTEST_SKIP();
    FileController *c = new FileController();
    QString url = QString::fromStdString("file:///"+dirPath.toStdString());
    c->import(url);
    QList<CPUSignal> signalList = c->getSignalList();
    for (CPUSignal& sig: signalList) {
        qDebug() << sig.name << " [" << sig.lBound << ", " << sig.rBound << "]";
    }
    delete c;
}
