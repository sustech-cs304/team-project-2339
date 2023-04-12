#include <CPUDebugger/controller/FileController.h>
#include <QtTest>
#include <compile/MAlex.h>
#include <iostream>
#include <private/qzipreader_p.h>
#include "TopVFileInputFactory.h"
#include "Module.h"
// add necessary includes here

class model : public QObject
{
    Q_OBJECT

public:
    QMessageLogger *logger;
    model();
    ~model();

private slots:
    void test_case1();
    void test_case2();
    void test_case3();
};

model::model()
{
    logger = new QMessageLogger();
}

model::~model()
{

}

void model::test_case1()
{
    MAlex *alex = new MAlex();
    assert(alex->is_range('('));
    assert(alex->is_key("module"));
    assert(alex->is_operator('-'));
}

void model::test_case2()
{
    QFile *file = new QFile("CDebuggerTest/top.v");
    TopVFileInputFactory *factory = new TopVFileInputFactory();
    std::cout << QDir::currentPath().toStdString() << std::endl;
    factory->fileInput(file);
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

QTEST_APPLESS_MAIN(model)

#include "tst_model.moc"
