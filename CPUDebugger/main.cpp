#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QScreen>
#include "view/myobject1.h"
#include <QImageReader>
#include "worker1.h"

QList<CPUSignal> mysignals;

int main(int argc, char *argv[]) {
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QQmlContext *context = engine.rootContext();
    QImageReader::setAllocationLimit(0);
    qmlRegisterType<MyObject1>("MyObj", 1, 0, "MyObject1");
    Worker1 worker1;
    engine.rootContext()->setContextProperty("theworker1", &worker1);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
                if (!obj && url == objUrl)
                    QCoreApplication::exit(-1);
            }, Qt::QueuedConnection);
    engine.load(url);
    return app.exec();
}
