#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "Controllers/PreDebugController.h"


using namespace testing;

//是否可以上传
TEST(uploadTest_Test, case1)
{
    QString filePath = "/Users/zitong/Library/CloudStorage/OneDrive-Personal/2023_Spring/CS304 Software Engineering/team-project-2339/CPUDebugger/test.asm";
    PreDebugController::uploadFile(filePath);
    ASSERT_FALSE(PreDebugController::getFile() == nullptr);
    PreDebugController::clear();
    ASSERT_TRUE(PreDebugController::getFile() == nullptr);
}

// 上传的结果是否正确
TEST(uploadTest_Test, case2)
{
    QString filePath = "/Users/zitong/Library/CloudStorage/OneDrive-Personal/2023_Spring/CS304 Software Engineering/team-project-2339/CPUDebugger/test.asm";
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
TEST(uploadTest_Test, case3)
{
    QString old_filePath = "/Users/zitong/Library/CloudStorage/OneDrive-Personal/2023_Spring/CS304 Software Engineering/team-project-2339/CPUDebugger/test.asm";
    PreDebugController::uploadFile(old_filePath);
    PreDebugController::clear();
    QString filePath = "/Users/zitong/Library/CloudStorage/OneDrive-Personal/2023_Spring/CS304 Software Engineering/team-project-2339/CPUDebugger/test2.asm";
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

// 错误路径能否正确处理
TEST(upload_null_test, case1)
{
    QString strange_path = "???";
    EXPECT_THROW(PreDebugController::uploadFile(strange_path), std::invalid_argument);
}


