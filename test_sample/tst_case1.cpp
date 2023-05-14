
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <vector>
using namespace testing;

TEST(sampleClass, case1)
{
    std::vector<int> x;
    std::vector<int> y;
    x.push_back(1);
//    y.push_back(1);
    y.push_back(2);
    ASSERT_EQ(x.size(), y.size()) << "Vectors x and y are of unequal length";

    for (int i = 0; i < x.size(); ++i) {
        EXPECT_EQ(x[i], y[i]) << "Vectors x and y differ at index " << i;
    }
}

