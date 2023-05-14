#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "Controllers/PreDebugController.h"

using namespace testing;

QString file_path = "/Users/zitong/Library/CloudStorage/OneDrive-Personal/2023_Spring/CS304 Software Engineering/team-project-2339/CPUDebugger/test.asm";
QString new_file_path = "/Users/zitong/Library/CloudStorage/OneDrive-Personal/2023_Spring/CS304 Software Engineering/team-project-2339/CPUDebugger/test2.asm";

// 是否可以正常编译
TEST(compiler_test, case1)
{
    PreDebugController::uploadFile(file_path);
    ASSERT_FALSE(PreDebugController::getFile() == nullptr);
    PreDebugController::compileAsm();
    ASSERT_FALSE(PreDebugController::getAsm() == nullptr);
}

// 上传文件后clear，进行编译是否可以正常抛出异常
TEST(null_compiler_test, case1)
{
    PreDebugController::uploadFile(file_path);
    PreDebugController::clear();
    EXPECT_THROW(PreDebugController::compileAsm(), std::invalid_argument);
}

//TEST(null_compiler_test, case2)
//{
//    PreDebugController::uploadFile(file_path);
//    PreDebugController::compileAsm();
//    PreDebugController::clear();
//    PreDebugController::uploadFile(new_file_path);
//}
