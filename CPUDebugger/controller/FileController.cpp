#include "FileController.h"
#include "FileUtil.h"
#include <QDebug>
#include <QUrl>

FileController::FileController() {
    tmpPath = "";
}

FileController::~FileController()
{
}

void FileController::import(QString &absolutePath) {
    QString dirPath = FileUtil::convert(absolutePath);
    tmpPath = dirPath+TMP_PATH;
    QDir *dir = new QDir(tmpPath);
    if (!dir->exists()) {
        if (dir->mkpath(tmpPath))
            qDebug() << "Folder created successfully";
        else
            qDebug() << "Failed to create folder";
    }
    QStringList entries = FileUtil::getDirList(dirPath, "v", true);
    for (const QString &entryPath: entries) {
        qDebug() << "Process file: " << QFileInfo(entryPath).fileName();
        p.process(entryPath, std::nullopt);
    }
    for (const QString &entryPath: entries) {
        QFileInfo info(entryPath);
        qDebug() << "Replace file: " << info.fileName();
        if (!info.fileName().compare("top.v")) {
            p.replace(entryPath, tmpPath+"/"+info.fileName(), false);
            topPath = tmpPath+"/"+info.fileName();
        }
        else {
            p.replace(entryPath, tmpPath+"/"+info.fileName(), true);
        }
    }
}

QList<CPUSignal> FileController::getSignalList()
{
    return p.genSignals(topPath);
}

QList<QString> FileController::getSignals()
{
    QList<CPUSignal> signalList = p.genSignals(topPath);
    QList<QString> ss;
    for (CPUSignal sig: signalList) {
        ss.append(sig.toString());
    }
    return FileUtil::dupRemove(ss);
}

void FileController::genGraph(QString dirPath)
{

//    g.genSvg(PROJ_PATH+YOSYS_PATH, dirPath);
    g.genDot(PROJ_PATH+YOSYS_PATH, dirPath);
    g.genSvg(PROJ_PATH+GV_PATH, dirPath, "show.dot");
}

void FileController::genGraph()
{
    genGraph(tmpPath);
}

void FileController::exportUart() {

}
