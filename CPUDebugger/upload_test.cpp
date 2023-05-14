#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "Controllers/PreDebugController.h"


using namespace testing;

TEST(uploadTest_Test, case1)
{
    QString filePath = "/Users/zitong/Library/CloudStorage/OneDrive-Personal/2023_Spring/CS304 Software Engineering/team-project-2339/CPUDebugger/test.asm";
    PreDebugController::uploadFile(filePath);
    ASSERT_FALSE(PreDebugController::getFile() == nullptr);

}

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
}



