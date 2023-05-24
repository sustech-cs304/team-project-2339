#ifndef FILECONTROLLER_H
#define FILECONTROLLER_H
#include "Generator.h"
#include "QFile"
#include <QDir>
#include <compile/PreProcessor.h>
#include <uart/CoreGenerator.h>

#define TMP_PATH "/tmp"
#define PROJ_PATH QDir::currentPath()+"/.."
#define YOSYS_PATH "/yosys-win32-mxebin-0.7/yosys.exe"
#define GV_PATH "/graphviz-2.38/release/bin/dot.exe"

class FileController {
public:
    FileController();
    ~FileController();
    void import(QString& absolutePath);
    QList<CPUSignal> getSignalList();
    QList<QString> getSignals();
    QString getSvgPath();
    void genGraph(QString path);
    void genGraph();
    void exportUart(QList<QString> signalList, QString outputUrl);
    void delTempDir();
private:
    bool searchSignal(QString signalName, CPUSignal&cpusignal);
    PreProcessor p;
    Generator g;
    QString tmpPath;
    QString tmpTopPath;
    QString oriTopPath;
    QList<CPUSignal> signalList;
};

#endif // FILECONTROLLER_H
