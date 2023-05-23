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

TEST_F(CompilerTest, ExportSignals) {
    FileController *c = new FileController();
    QString url = QString::fromStdString("file:///"+dirPath.toStdString());
    c->import(url);
    QList<QString> ss = c->getSignals();
    ASSERT_GE(ss.size(), 0);
    delete c;
}
