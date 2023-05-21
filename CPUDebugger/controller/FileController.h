#ifndef FILECONTROLLER_H
#define FILECONTROLLER_H
#include "Generator.h"
#include "QFile"
#include <QDir>
#include <compile/PreProcessor.h>

#define TMP_PATH "/tmp"
#define PROJ_PATH qApp->applicationDirPath()+"/../.."
#define YOSYS_PATH "/yosys-win32-mxebin-0.7/yosys.exe"
#define GV_PATH "/graphviz-2.38/release/bin/dot.exe"

class FileController {
public:
    FileController();
    ~FileController();
    void import(QString& absolutePath);
    QList<CPUSignal> getSignalList();
    QList<QString> getSignals();
    void setSignal(QString signalName);
    void genGraph(QString path);
    void genGraph();
    void exportUart();
private:
    PreProcessor p;
    Generator g;
    QString tmpPath;
    QString topPath;
};

#endif // FILECONTROLLER_H
