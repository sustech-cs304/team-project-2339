
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "main.cpp"
#include <QTest>
using namespace testing;

TEST(UartTest, AddUart) {
    ASSERT_TRUE(true);
}

TEST(GUITest, Main) {
    QList<QWindow*> windows = app->allWindows();
    qDebug() << windows;
    QTest::mouseClick(windows[0], Qt::LeftButton);
}
