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
        p.process(entryPath, std::nullopt);
    }
    for (const QString &entryPath: entries) {
        QFileInfo info(entryPath);
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

void FileController::genGraph(QString path)
{
    QProcess process;
    QString yosysPath = PROJ_PATH+YOSYS_PATH;
    process.setProgram(yosysPath);
    QStringList arguments;
    QStringList entries = FileUtil::getDirList(path, "v", true);
    QString f;
    for (QString &s: entries) {
        f.append(s+" ");
    }
    arguments << "-p" << QString("read_verilog %1").arg(f) << "-p" << QString(path+"/show");
    process.setArguments(arguments);
    process.start();
    process.waitForFinished();
    QString output = process.readAllStandardOutput();
    QString error = process.readAllStandardError();
    qDebug() << output;
    qDebug() << error;

    QString graphvizPath = PROJ_PATH+GRAPHVIZ_PATH;

}

void FileController::exportUart() {

}
