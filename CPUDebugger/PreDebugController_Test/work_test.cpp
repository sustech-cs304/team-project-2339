#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

TEST(work_test, case1)
{
    ASSERT_TRUE(1 == 1);
    ASSERT_EQ(1, 1);
    ASSERT_NO_THROW(int a = 1);
}
