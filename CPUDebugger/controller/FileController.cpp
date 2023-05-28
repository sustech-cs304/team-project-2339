#include "FileController.h"
#include "FileUtil.h"
#include <QDebug>
#include <QUrl>

FileController::FileController() {
    tmpPath = "";
    tmpTopPath = "";
}

FileController::~FileController()
{
}

void FileController::import(QString &absolutePath) {
    QString dirPath = FileUtil::convert(absolutePath);
    tmpPath = QDir::tempPath()+TMP_PATH;
    QDir *dir = new QDir(tmpPath);
    delTempDir();
    if (!dir->exists()) {
        if (dir->mkpath(tmpPath))
            qDebug() << "Folder created successfully";
        else
            qDebug() << "Failed to create folder";
    }
    QStringList entries = FileUtil::getDirList(dirPath, "v", true);
    for (const QString &entryPath: entries) {
        QFileInfo info(entryPath);
        qDebug() << "Process file: " << info.fileName();
        if (!info.fileName().compare("top.v")) {
            oriTopPath = info.absoluteFilePath();
        }
        p.process(entryPath, std::nullopt);
    }
    for (const QString &entryPath: entries) {
        QFileInfo info(entryPath);
        qDebug() << "Replace file: " << info.fileName();
        if (!info.fileName().compare("top.v")) {
            p.replace(entryPath, tmpPath+"/"+info.fileName(), false);
            tmpTopPath = tmpPath+"/"+info.fileName();
        }
        else {
            p.replace(entryPath, tmpPath+"/"+info.fileName(), true);
        }
    }
    delete dir;
}

QList<CPUSignal> FileController::getSignalList()
{
    if (signalList.size() == 0) {
        signalList = p.genSignals(tmpTopPath);
    }
    return signalList;
}

QList<CPUSignal> FileController::getSignalList(QList<QString> &ss)
{
    if (signalList.size() == 0) {
        signalList = p.genSignals(tmpTopPath);
    }
    QList<CPUSignal> sigs;
    for (const QString &s: ss) {
        CPUSignal sig("NULL", -1, -1);
        if (searchSignal(s, sig))
            sigs.append(sig);
    }
    return sigs;
}

QList<QString> FileController::getStringSignals()
{
    if (signalList.size() == 0) {
        signalList = p.genSignals(tmpTopPath);
    }
    QList<QString> ss;
    for (CPUSignal sig: signalList) {
        ss.append(sig.toString());
    }
    return FileUtil::dupRemove(ss);
}

QString FileController::getSvgPath()
{
    QString s(tmpPath+"/show.svg");
    return QUrl::fromLocalFile(s).url();
}

void FileController::genGraph(QString dirPath)
{
    g.genDot(PROJ_PATH+YOSYS_PATH, dirPath);
    g.genSvg(PROJ_PATH+GV_PATH, dirPath, "show.dot");
}

void FileController::genGraph()
{
    genGraph(tmpPath);
}

void FileController::exportUart(QList<QString> signalList, QString outputUrl) {
    QList<CPUSignal> results;
    QString outputDir = FileUtil::convert(outputUrl);
    for (const QString& s: signalList) {
        CPUSignal sig("NULL", -1, -1);
        if (searchSignal(s, sig)) {
            qDebug() << sig.name;
            results.append(sig);
        }
    }
    generateCore(oriTopPath, outputUrl, results);
}

void FileController::delTempDir() {
    if (tmpPath == " ") {
        qDebug() << "You should import directory path first";
    } else {
        QDir *dir = new QDir(tmpPath);
        if (!dir->exists()) {
            qDebug() << "Temp directory does not exist";
        }
        dir->removeRecursively();
        delete dir;
    }
}

void FileController::filter(QList<QString> &ss, QString filter)
{
    QRegularExpression regExp("^"+filter);
    int count = 0;
    int match_count = 0;
    for (const QString& s: ss) {
        auto localMatch = regExp.match(s);
        if (localMatch.hasMatch()) {
            ss.swapItemsAt(count, match_count);
            match_count++;
        }
        count++;
    }
}

bool FileController::searchSignal(QString signalName, CPUSignal &cpusignal)
{
    for (const CPUSignal& sig: signalList) {
        if (sig.toString().compare(signalName) == 0) {
            cpusignal = sig;
            return true;
        }
    }
    return false;
}
