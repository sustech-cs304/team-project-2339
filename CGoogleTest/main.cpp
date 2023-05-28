#include "CPUSignal.h"
#include <gtest/gtest.h>

QList<CPUSignal> mysignals;

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
