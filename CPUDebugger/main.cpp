#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QScreen>
#include "myobject1.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QQmlContext* context = engine.rootContext();
//    QScreen *screen = QGuiApplication::primaryScreen();
//    context->setContextProperty("MyObject1",MyObject1::getInstance());
    qmlRegisterType<MyObject1>("MyObj",1,0,"MyObject1");
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

//    auto list = engine.rootObjects();
//    auto objName = list.first()->objectName();
//    qDebug()<<objName;
//    auto model = list.first()->findChild<QObject *>("myModel41");

//    QVariant myVariant = QVariant::fromValue(MyObject1::getInstance()->items1());

//    qDebug()<<"a";

//    qDebug()<<myVariant;
//    model->setProperty("model", myVariant);



    return app.exec();
}
