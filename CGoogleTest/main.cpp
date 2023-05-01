

#include "myobject1.h"
#include "qguiapplication.h"
#include <gtest/gtest.h>
#include <QQmlApplicationEngine>
#include <QQmlContext>

QGuiApplication *app;

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    app = new QGuiApplication(argc, argv);
    QQmlApplicationEngine engine;
    qmlRegisterType<MyObject1>("MyObj", 1, 0, "MyObject1");
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
