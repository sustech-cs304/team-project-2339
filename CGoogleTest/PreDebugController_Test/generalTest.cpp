#include <gtest/gtest.h>
#include "Controllers/PreDebugController.h"

#include <QSettings>

QSettings settings("test_conf.ini", QSettings::IniFormat);
QString root_path = settings.value("root_path");


// 测试上传有效文件路径时是否返回非空文件指针
TEST(PreDebugControllerTest, UploadFile_WithValidFilePath_ReturnsNonNullFilePointer)
{
    QString filePath = root_path + "valid.asm";
    std::shared_ptr<QFile> filePtr = PreDebugController::uploadFile(filePath);
    ASSERT_NE(filePtr, nullptr);
}

// 测试上传无效文件路径时是否抛出无效参数异常
TEST(PreDebugControllerTest, UploadFile_WithInvalidFilePath_ThrowsInvalidArgument)
{
    QString filePath = root_path + "???.txt";
    ASSERT_THROW(PreDebugController::uploadFile(filePath), std::invalid_argument);
}

// 测试上传非.asm文件时是否抛出无效参数异常
TEST(PreDebugControllerTest, UploadFile_WithNonAsmFile_ThrowsInvalidArgument)
{
    QString filePath = root_path + "invalid.txt";
    ASSERT_THROW(PreDebugController::uploadFile(filePath), std::invalid_argument);
}

// 测试清除操作是否清除了文件和汇编文件
TEST(PreDebugControllerTest, Clear_ClearsFileAndAsmFile)
{
    QString filePath = root_path + "valid.asm";
    std::shared_ptr<QFile> filePtr = PreDebugController::uploadFile(filePath);
    ASSERT_NE(PreDebugStore::file, nullptr);

    PreDebugController::clear();
    ASSERT_EQ(PreDebugStore::file, nullptr);
}

// 测试在未上传文件的情况下编译汇编是否抛出无效参数异常
TEST(PreDebugControllerTest, CompileAsm_WithNoUploadedFile_ThrowsInvalidArgument)
{
    ASSERT_THROW(PreDebugController::compileAsm(), std::invalid_argument);
}

// 测试在已上传文件的情况下编译汇编是否成功，并设置断点
TEST(PreDebugControllerTest, CompileAsm_WithUploadedFile_CompilesAsmAndSetsBreakPoints)
{
    QString filePath =  root_path + "valid.asm";
    std::shared_ptr<QFile> filePtr = PreDebugController::uploadFile(filePath);
    PreDebugController::setBreakPoint(10);
    PreDebugController::setBreakPoint(20);

    ASSERT_NO_THROW(PreDebugController::compileAsm());
    ASSERT_NE(PreDebugStore::asmFile, nullptr);
    ASSERT_EQ(PreDebugStore::asmFile->getBreakPoints().count(10), 1);
    ASSERT_EQ(PreDebugStore::asmFile->getBreakPoints().count(20), 1);
}

// 测试设置已存在断点的行号时是否移除断点
TEST(PreDebugControllerTest, SetBreakPoint_WithExistingLineIndex_RemovesBreakPoint)
{
    int lineIdx = 10;
    PreDebugController::setBreakPoint(lineIdx);
    ASSERT_EQ(PreDebugStore::breakPoints.count(lineIdx), 1);

    PreDebugController::setBreakPoint(lineIdx);
    ASSERT_EQ(PreDebugStore::breakPoints.count(lineIdx), 0);
}

// 测试设置不存在断点的行号时是否添加断点
TEST(PreDebugControllerTest, SetBreakPoint_WithNonExistingLineIndex_AddsBreakPoint)
{
    int lineIdx = 10;
    ASSERT_EQ(PreDebugStore::breakPoints.count(lineIdx), 0);

    PreDebugController::setBreakPoint(lineIdx);
    ASSERT_EQ(PreDebugStore::breakPoints.count(lineIdx), 1);
}

// 测试获取汇编文件指针是否返回正确的指针
TEST(PreDebugControllerTest, GetAsm_ReturnsAsmFilePointer)
{
    ASSERT_EQ(PreDebugController::getAsm(), PreDebugStore::asmFile);
}

// 测试获取文件指针是否返回正确的指针
TEST(PreDebugControllerTest, GetFile_ReturnsFilePointer)
{
    ASSERT_EQ(PreDebugController::getFile(), PreDebugStore::file);
}
