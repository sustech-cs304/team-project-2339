#include <QtTest>
#include <compile/MAlex.h>
#include <iostream>
#include <private/qzipreader_p.h>
#include "FileUtil.h"
#include "compile/PreProcessor.h"
#include "verilog_driver.hpp"
// add necessary includes here

// A custom parser struct
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

class model : public QObject
{
    Q_OBJECT

public:
    QMessageLogger *logger;
    QString dirPath;
    QString destPath;
    model();
    ~model();

private slots:
    void test_preprocess();
    void test_case2();
    void test_case3();
    void test_case4();
};

model::model()
{
    logger = new QMessageLogger();
    dirPath = "E:/DebugCore/module_files";
    destPath = "E:/";
}

model::~model()
{

}

void model::test_preprocess()
{
    QDir dir(destPath);
    if (!dir.exists()) {
        bool ismkdir = dir.mkpath(destPath);
        if (!ismkdir) {
            QFAIL("Create directory fail");
        }
        else
            qDebug() << "Create directory success";
    }
    qDebug() << "Directory: " << FileUtil::getDirList(dirPath);
    QStringList entries = FileUtil::getDirList(dirPath);
    PreProcessor *p = new PreProcessor();
    for (QString entryPath: entries) {
        p->process(entryPath);
    }
    for (QString entryPath: entries) {
        QFileInfo info(entryPath);
        p->replace(entryPath, destPath+info.fileName());
    }
}

void model::test_case2()
{
    QSKIP("Skip this case now");
    QString path = "E:/DebugCore/module_files/definitions.v";
    QString path1 = "E:/DebugCore/module_files/top.v";
    QString dest = "E:/dest.v";
    std::cout << QDir::currentPath().toStdString() << std::endl;
    PreProcessor *p = new PreProcessor();
    p->process(path);
    p->replace(path1, dest);
}

void model::test_case3()
{
    QString absolutePath = "file:///E:/zlib1213.zip";
    QString TMP = "tmp/";
    QString cleanPath = QUrl(absolutePath).toLocalFile();
    QZipReader r(cleanPath);
    QFileInfo *fileInfo = new QFileInfo(cleanPath);
    QString tmpPath = fileInfo->path()+TMP;
    QDir *dirInfo = new QDir(tmpPath);
    qDebug() << "Clean path " << cleanPath;
    qDebug() << "Tmp path" << tmpPath;
    r.extractAll(tmpPath);
    QStringList dirList = dirInfo->entryList(QDir::Dirs);
    qDebug() << dirList;
    for (const QString &d: dirList) {
        QFile f(tmpPath+d);
        QFileInfo fInfo(tmpPath+d);
        qDebug() << "Suffix info" << fInfo.suffix();
        if (!fInfo.suffix().compare(".v")) {
            qDebug() << "OK";
        }
    }
    dirInfo->removeRecursively();
}

void model::test_case4()
{
    SampleParser parser;
    qDebug() << std::filesystem::current_path();
    QStringList entries = FileUtil::getDirList(destPath+"/pre");
    for (const QString &entry: entries) {
        parser.read(entry.toStdString());
    }
}

QTEST_APPLESS_MAIN(model)

#include "tst_model.moc"
