

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <compile/PreProcessor.h>
#include <compile/compiler.h>
#include <FileUtil.h>
#include <verilog_driver.hpp>

using namespace testing;
struct SampleParser : public verilog::ParserVerilogInterface {
    virtual ~SampleParser(){}

    void add_module(std::string&& name){
        std::cout << "Module name = " << name << '\n';
    }

    void add_port(verilog::Port&& port) {
        std::cout << "Port: " << port << '\n';
        ports.push_back(std::move(port));
    }

    void add_net(verilog::Net&& net) {
        std::cout << "Net: " << net << '\n';
        nets.push_back(std::move(net));
    }

    void add_assignment(verilog::Assignment&& ast) {
        std::cout << "Assignment: " << ast << '\n';
        assignments.push_back(std::move(ast));
    }

    void add_instance(verilog::Instance&& inst) {
        std::cout << "Instance: " << inst << '\n';
        insts.push_back(std::move(inst));
    }

    std::vector<verilog::Port> ports;
    std::vector<verilog::Net> nets;
    std::vector<verilog::Assignment> assignments;
    std::vector<verilog::Instance> insts;
};

class CompilerTest : public ::testing::Test
{
protected:

    virtual void SetUp() {
        dirPath = "E:/DebugCore/module_files";
        destPath = "E:/";
        tokenPath = "E:/token.txt";
        qDebug() << "Compiler test begin";
    }

    virtual void TearDown() {
        qDebug() << "Compiler test end";
    }
public:
    QString dirPath;
    QString destPath;
    QString tokenPath;
};

TEST_F(CompilerTest, GenTokens)
{
    PreProcessor p;
    p.process("E:/alu.v", tokenPath);
}

TEST_F(CompilerTest, ImportFile)
{
    Compiler c;
    QDir dir(destPath);
    if (!dir.exists()) {
        bool ismkdir = dir.mkpath(destPath);
        if (!ismkdir) {
            qDebug() << "Create directory fail";
        }else
            qDebug() << "Create directory success";
    }

    QStringList entries = FileUtil::getDirList(dirPath, "v", true);
    PreProcessor *p = new PreProcessor();
    for (const QString &entryPath: entries) {
        qDebug() << "Process file: " << entryPath;
        p->process(entryPath, std::nullopt);
    }
    for (const QString &entryPath: entries) {
        qDebug() << "Replace file: " << entryPath;
        QFileInfo info(entryPath);
        if (!info.fileName().compare("top.v"))
            p->replace(entryPath, destPath+"ddd/"+info.fileName(), false);
        else
            p->replace(entryPath, destPath+"ddd/"+info.fileName(), true);
    }
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}

TEST_F(CompilerTest, Parser) {
    SampleParser parser;
    qDebug() << std::filesystem::current_path();
    QStringList entries = FileUtil::getDirList(destPath+"/pre");
    for (const QString &entry: entries) {
        QFileInfo info(entry);
        if (!info.fileName().compare("top1.v")) {
            qDebug() << entry;
            parser.read(entry.toStdString());
        }
    }
}
