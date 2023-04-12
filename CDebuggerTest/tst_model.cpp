#include <QtTest>
#include <compile/MAlex.h>
#include "TopVFileInputFactory.h"
#include "VFile.h"
#include "FFile.h"
#include "Module.h"
// add necessary includes here

class model : public QObject
{
    Q_OBJECT

public:
    model();
    ~model();

private slots:
    void test_case1();
    void test_case2();
};

model::model()
{
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
    QFile *file = new QFile("CDebuggerTest/top1.v");
    Module module;
    TopVFileInputFactory *factory = new TopVFileInputFactory();
    std::cout << QDir::currentPath().toStdString() << std::endl;
    factory->fileInput(new VFile(file));
}

QTEST_APPLESS_MAIN(model)

#include "tst_model.moc"
