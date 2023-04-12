#include <QtCore>
#include "Controllers/DebugController.h"
#include "Controllers/PreDebugController.h"
#include "File/DebugFile.h"
#include "File/AsmFile.h"
#include "File/CoeFile.h"
#include "Stores/PreDebugStore.h"
#include "Stores/DebugStore.h"

int main()
{
    QString filePath = "/Users/zitong/Downloads/session.asm";
    std::shared_ptr<QFile> file = PreDebugController::uploadFile(filePath);
    // 打开文件
    if (file->open(QIODevice::ReadOnly | QIODevice::Text)) 
    {
        // 输出文件所有内容
        QTextStream in(file.get());
        while (!in.atEnd()) 
        {
            QString line = in.readLine();
            qDebug() << line;
        }
    }

    PreDebugController::setBreakPoint(1);
    PreDebugController::setBreakPoint(4);
    PreDebugController::setBreakPoint(6);
    PreDebugController::setBreakPoint(8);
    PreDebugController::setBreakPoint(11);
    PreDebugController::setBreakPoint(16);
    PreDebugController::setBreakPoint(20);

    qDebug() << *(DebugController::step());
    qDebug() << DebugStore::asmCurLine;
    qDebug() << *(DebugController::step());
    qDebug() << DebugStore::asmCurLine;
    qDebug() << *(DebugController::step());
    qDebug() << DebugStore::asmCurLine;
    qDebug() << *(DebugController::step());
    qDebug() << DebugStore::asmCurLine;

    qDebug() << *(DebugController::run());
    qDebug() << *(DebugController::pause());
    qDebug() << DebugStore::asmCurLine;

}



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

    return app.exec();
}
