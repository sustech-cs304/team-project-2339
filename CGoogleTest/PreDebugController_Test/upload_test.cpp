#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "Controllers/PreDebugController.h"

#include <QSettings>

using namespace testing;

static QSettings settings("test_conf.ini", QSettings::IniFormat);
static QString root_path = settings.value("Debugger/root_path").toString();

static QString filePath = root_path + "test.asm";
static QString new_filePath = root_path + "test2.asm";

//是否可以上传
TEST(upload, case1)
{
    PreDebugController::uploadFile(filePath);
    ASSERT_FALSE(PreDebugController::getFile() == nullptr);
    PreDebugController::clear();
    ASSERT_TRUE(PreDebugController::getFile() == nullptr);
}

// 上传的结果是否正确
TEST(upload, case2)
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
TEST(upload, case3)
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
TEST(upload, case4)
{
    QString strange_path = "???";
    EXPECT_THROW(PreDebugController::uploadFile(strange_path), std::invalid_argument);
}


