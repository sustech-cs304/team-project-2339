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
    /**
     * @brief import
     * Import directory from absolutePath. It analyzes the info
     * of files with suffix "v". The temporary directory will be
     * created in the tmp path of OS.
     * @param absolutePath
     * The absolutePath of one directory
     */
    void import(QString& absolutePath);
    /**
     * @brief getSignalList
     * Get the list of signals with @c CPUSignal for top module file. You
     * should execute this function before you use @c import.
     * @return
     * A list with @c CPUSignal.
     */
    QList<CPUSignal> getSignalList();
    /**
     * @brief getSignalList
     * Get the list of signals with @c CPUSignal for top module file filtered by @c ss @c. You
     * should execute this function before you use @c import.
     * @param ss
     * @return
     * A list with @c CPUSignal .
     */
    QList<CPUSignal> getSignalList(QList<QString> &ss);
    /**
     * @brief getStringSignals
     * Get the list of signals with @c QString for top module file. You
     * should execute this function before you use @c import .
     * @return
     * A list with @c QString @c
     */
    QList<QString> getStringSignals();
    /**
     * @brief getSvgPath
     * Get the path of graph file with svg format. You should execute this function
     * before you use @c import .
     * @return
     * The path of svg file.
     */
    QString getSvgPath();
    /**
     * @brief genGraph
     * Generate graph with svg format under the path.
     * @param path
     *
     * @warning
     * You should check out all the @c *.v  in the path.
     */
    void genGraph(QString path);
    /**
     * @brief genGraph
     * Generate graph with svg format under the tmporary directory
     * You should execute this function before you use @c import
     */
    void genGraph();
    /**
     * @brief exportUart
     * Export the debug unit into the file with outputUrl. The debug
     * unit is based on signalList.
     * @param signalList
     * @param outputUrl
     */
    void exportUart(QList<QString> signalList, QString outputUrl);
    /**
     * @brief delTempDir
     * Delete the temporary directory created before
     */
    void delTempDir();
    /**
     * @brief filter
     * Sort the string list with the rule of @c filter .
     * The string will rank in the front if the its prefix matches
     * the @c filter
     * @param ss
     * The string list to be sorted.
     * @param filter
     * The run to sort the list.
     */
    void filter(QList<QString> &ss, QString filter);
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
