#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "Controllers/PreDebugController.h"

#include <QSettings>

using namespace testing;

class UploadTest : public ::testing::Test
{
protected:

    virtual void SetUp() {
        root_path = QDir::currentPath()+"/../examples/debugger_files";
        filePath = root_path + "/test.asm";
        new_filePath = root_path + "/test2.asm";
        qDebug() << "ASM file upload test begin";
    }

    virtual void TearDown() {
        qDebug() << "ASM file upload test end";
    }
public:
    QString root_path;
    QString filePath;
    QString new_filePath;
};



//是否可以上传
TEST_F(UploadTest, case1)
{
    PreDebugController::uploadFile(filePath);
    ASSERT_FALSE(PreDebugController::getFile() == nullptr);
    PreDebugController::clear();
    ASSERT_TRUE(PreDebugController::getFile() == nullptr);
}

// 上传的结果是否正确
TEST_F(UploadTest, case2)
{
    PreDebugController::uploadFile(filePath);
    QFile file2(filePath);
    std::shared_ptr<QFile> file_ptr = PreDebugController::getFile();
    ASSERT_TRUE((*file_ptr).exists() && file2.exists());
    ASSERT_TRUE((*file_ptr).size() == file2.size());
    ASSERT_TRUE((*file_ptr).open(QIODevice::ReadOnly) && file2.open(QIODevice::ReadOnly));
    QByteArray data1 = (*file_ptr).readAll();
    QByteArray data2 = file2.readAll();
    EXPECT_EQ(data1, data2);
    (*file_ptr).close();
    file2.close();
    PreDebugController::clear();
    ASSERT_TRUE(PreDebugController::getFile() == nullptr);
}

// 上传后clear，再次上传是否正确
TEST_F(UploadTest, case3)
{
    PreDebugController::uploadFile(filePath);
    PreDebugController::clear();
    PreDebugController::uploadFile(new_filePath);
    QFile file2(new_filePath);
    std::shared_ptr<QFile> file_ptr = PreDebugController::getFile();
    ASSERT_TRUE((*file_ptr).exists() && file2.exists());
    ASSERT_TRUE((*file_ptr).size() == file2.size());
    ASSERT_TRUE((*file_ptr).open(QIODevice::ReadOnly) && file2.open(QIODevice::ReadOnly));
    QByteArray data1 = (*file_ptr).readAll();
    QByteArray data2 = file2.readAll();
    EXPECT_EQ(data1, data2);
    (*file_ptr).close();
    file2.close();
    PreDebugController::clear();
    ASSERT_TRUE(PreDebugController::getFile() == nullptr);
}

// 错误路径能否正确处理
TEST_F(UploadTest, case4)
{
    QString strange_path = "???";
    EXPECT_THROW(PreDebugController::uploadFile(strange_path), std::invalid_argument);
}

// 测试上传有效文件路径时是否返回非空文件指针
TEST_F(UploadTest, UploadFile_WithValidFilePath_ReturnsNonNullFilePointer)
{
    QString filePath = root_path + "valid.asm";
    std::shared_ptr<QFile> filePtr = PreDebugController::uploadFile(filePath);
    ASSERT_NE(filePtr, nullptr);
}

// 测试上传无效文件路径时是否抛出无效参数异常
TEST_F(UploadTest, UploadFile_WithInvalidFilePath_ThrowsInvalidArgument)
{
    QString filePath = root_path + "???.txt";
    ASSERT_THROW(PreDebugController::uploadFile(filePath), std::invalid_argument);
}

// 测试上传非.asm文件时是否抛出无效参数异常
TEST_F(UploadTest, UploadFile_WithNonAsmFile_ThrowsInvalidArgument)
{
    QString filePath = root_path + "invalid.txt";
    ASSERT_THROW(PreDebugController::uploadFile(filePath), std::invalid_argument);
}

// 测试清除操作是否清除了文件和汇编文件
TEST_F(UploadTest, Clear_ClearsFileAndAsmFile)
{
    QString filePath = root_path + "valid.asm";
    std::shared_ptr<QFile> filePtr = PreDebugController::uploadFile(filePath);
    ASSERT_NE(PreDebugStore::file, nullptr);

    PreDebugController::clear();
    ASSERT_EQ(PreDebugStore::file, nullptr);
}

// 测试在已上传文件的情况下编译汇编是否成功，并设置断点
TEST_F(UploadTest, CompileAsm_WithUploadedFile_CompilesAsmAndSetsBreakPoints)
{
    QString filePath =  root_path + "valid.asm";
    std::shared_ptr<QFile> filePtr = PreDebugController::uploadFile(filePath);
    PreDebugController::setBreakPoint(10);
    PreDebugController::setBreakPoint(20);

    ASSERT_NE(PreDebugStore::asmFile, nullptr);
    ASSERT_EQ(PreDebugStore::asmFile->getBreakPoints().count(10), 1);
    ASSERT_EQ(PreDebugStore::asmFile->getBreakPoints().count(20), 1);
}

// 测试设置已存在断点的行号时是否移除断点
TEST_F(UploadTest, SetBreakPoint_WithExistingLineIndex_RemovesBreakPoint)
{
    int lineIdx = 10;
    PreDebugController::setBreakPoint(lineIdx);
    ASSERT_EQ(PreDebugStore::breakPoints.count(lineIdx), 1);

    PreDebugController::setBreakPoint(lineIdx);
    ASSERT_EQ(PreDebugStore::breakPoints.count(lineIdx), 0);
}

// 测试设置不存在断点的行号时是否添加断点
TEST_F(UploadTest, SetBreakPoint_WithNonExistingLineIndex_AddsBreakPoint)
{
    int lineIdx = 10;
    ASSERT_EQ(PreDebugStore::breakPoints.count(lineIdx), 0);

    PreDebugController::setBreakPoint(lineIdx);
    ASSERT_EQ(PreDebugStore::breakPoints.count(lineIdx), 1);
}

// 测试获取汇编文件指针是否返回正确的指针
TEST_F(UploadTest, GetAsm_ReturnsAsmFilePointer)
{
    ASSERT_EQ(PreDebugController::getAsm(), PreDebugStore::asmFile);
}

// 测试获取文件指针是否返回正确的指针
TEST_F(UploadTest, GetFile_ReturnsFilePointer)
{
    ASSERT_EQ(PreDebugController::getFile(), PreDebugStore::file);
}

