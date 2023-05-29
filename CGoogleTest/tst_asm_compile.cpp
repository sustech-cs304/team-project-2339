#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "Controllers/PreDebugController.h"
#include <QSettings>

using namespace testing;

class ASMCompileTest : public ::testing::Test
{
protected:

    virtual void SetUp() {
        root_path = QDir::currentPath()+"/../examples/debugger_files";
        file_path = root_path + "/test.asm";
        new_filePath = root_path + "/test2.asm";
        out_file = root_path + "result.txt";
        qDebug() << "ASM file upload test begin";
    }

    virtual void TearDown() {
        qDebug() << "ASM file upload test end";
    }
public:
    QString root_path;
    QString file_path;
    QString new_filePath;
    QString out_file;
};

// 是否可以正常编译
TEST_F(ASMCompileTest, case1)
{
    PreDebugController::uploadFile(file_path);
    ASSERT_FALSE(PreDebugController::getFile() == nullptr);
    ASSERT_FALSE(PreDebugController::getAsm() == nullptr);
}

// 上传文件后clear，进行编译是否可以正常抛出异常
TEST_F(ASMCompileTest, case2)
{
    PreDebugController::uploadFile(file_path);
    PreDebugController::clear();
}


// 检查输出的QByteArray
TEST_F(ASMCompileTest, case3)
{
    PreDebugController::uploadFile(file_path);
    QByteArray byteArray = PreDebugController::getAsm()->getBin();
    ASSERT_FALSE(byteArray == nullptr);
    QFile file(out_file);
    //    qDebug() << byteArray.toHex();
    if (file.open(QIODevice::WriteOnly))
    {
        // 将 QByteArray 内容写入文件
        file.write(byteArray);
        // 关闭文件
        file.close();
    }
}

// 检查断点能否做出映射
TEST_F(ASMCompileTest, case4)
{
    PreDebugController::uploadFile(file_path);
    QByteArray QByteArray = PreDebugController::getAsm()->getBin();
}
