#include "FileController.h"

#include <QDebug>
#include <QUrl>

FileController::FileController() {
    inputFac = new TopVFileInputFactory();
}

FileController::~FileController()
{
}

void FileController::import(QString &absolutePath) {
    QString cleanPath = QUrl(absolutePath).toLocalFile();
//    QZipReader r(cleanPath);
    QFileInfo *fileInfo = new QFileInfo(cleanPath);
    QString tmpPath = fileInfo->path()+TMP_PATH;
    QDir *dirInfo = new QDir(tmpPath);
//    r.extractAll(tmpPath);
    QStringList dirList = dirInfo->entryList(QDir::Dirs);
    for (const QString &d: dirList) {
        QFile f(tmpPath+d);
        QFileInfo fInfo(tmpPath+d);
        if (!fInfo.suffix().compare(".v")) {
            inputFac->fileInput(&f);
        }
    }
    dirInfo->removeRecursively();
}

QList<QString> FileController::getSignalList()
{
    QList<QString> sigList;
    sigList.append("instruction_mem_instruction");
    return sigList;
}

void FileController::exportUart() {

}
