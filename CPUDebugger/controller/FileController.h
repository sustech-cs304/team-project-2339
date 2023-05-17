#ifndef FILECONTROLLER_H
#define FILECONTROLLER_H
#include "QFile"
#include <QDir>
#include <compile/PreProcessor.h>

#define TMP_PATH "/tmp"
#define PROJ_PATH qApp->applicationDirPath()+"/../.."
#define YOSYS_PATH "/yosys-win32-mxebin-0.7/yosys.exe"
#define GRAPHVIZ_PATH "/graphviz-2.38/release/bin/dot.exe"
class FileController {
public:
    FileController();
    ~FileController();
    void import(QString& absolutePath);
    QList<QString> getSignalList();
    void setSignal(QString signalName);
    void genGraph(QString path);
    void exportUart();
private:
    PreProcessor p;
    QString tmpPath;
};

#endif // FILECONTROLLER_H
