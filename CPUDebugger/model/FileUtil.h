
#ifndef FILEUTIL_H
#define FILEUTIL_H

#include "compile/MAlex.h"
#include "qforeach.h"
#include "qurl.h"
#include <QDebug>
#include <QDir>
#include <QFile>


class FileUtil
{
public:
    static QStringList getTextStreams(QFile *f);
    static void exportFile(QString path, QString ss);
    static void exportFile(QString path, QStringList lines);
    static void exportFile(QString path, QList<Token> tokens);
    static void exportFile(QString dirPath, QString filename, QStringList lines);
    static QString execute(QString binPath, QString workDir, QStringList &arguments);
    static QFile* importFile(QString path, bool isUrl=false);
    static QString convert(QString url);
    static QList<QString> dupRemove(QList<QString> ss);
    static QStringList getDirList(QString dirPath, QString filter="v", bool recursively=false);
private:
    static int findFile(const QString &filePath, QString &filter, QStringList &result, bool recursively);
};

inline QStringList FileUtil::getTextStreams(QFile *f)
{
    f->open(QIODevice::ReadOnly);
    QStringList lines;
    QString line;
    QTextStream in(f);
    while (in.readLineInto(&line)) {
        lines.append(line);
    }
    return lines;
}

inline void FileUtil::exportFile(QString path, QString ss)
{
    QFile f(path);
    f.open(QIODevice::WriteOnly);
    QTextStream out(&f);
    out << ss << '\n';
    f.close();
}

inline void FileUtil::exportFile(QString path, QStringList lines)
{
    QFile f(path);
    f.open(QIODevice::WriteOnly);
    QTextStream out(&f);
    for (const QString &line: lines) {
        out << line << '\n';
        out.flush();
    }
    f.close();
}

inline void FileUtil::exportFile(QString path, QList<Token> tokens)
{
    QStringList lines;
    QString s;
    for (Token &t: tokens) {
        s.append(t.s+' ');
        if (t.s == ';' || t.s == ',') {
            lines.append(s);
            s.clear();
        }
    }
    if (!s.isEmpty()) {
        lines.append(s);
    }
    exportFile(path, lines);
}

inline void FileUtil::exportFile(QString dirPath, QString filename, QStringList lines)
{
    exportFile(dirPath+filename, lines);
}

inline QString FileUtil::execute(QString binPath, QString workDir, QStringList &arguments)
{
    QProcess process;
    process.setProgram(binPath);
    process.setWorkingDirectory(workDir);
    process.setArguments(arguments);
    process.start();
    process.waitForFinished();
//    QString output = process.readAllStandardOutput();
    QString error = process.readAllStandardError();
    return "Error message: " + error;
}

inline QFile *FileUtil::importFile(QString path, bool isUrl)
{
    if (isUrl) {
        return new QFile(convert(path));
    } else
        return new QFile(path);
}

inline QString FileUtil::convert(QString url)
{
    return QUrl(url).toLocalFile();
}

inline QList<QString> FileUtil::dupRemove(QList<QString> ss)
{
    QSet<QString> uniqueSet;
    foreach (QString s, ss) {
        uniqueSet.insert(s);
    }

    return QList<QString>(uniqueSet.begin(), uniqueSet.end());
}

inline QStringList FileUtil::getDirList(QString dirPath, QString filter, bool recursively)
{
    QDir dir(dirPath);
    QStringList result;
    findFile(dirPath, filter, result, recursively);
    return result;
}

inline int FileUtil::findFile(const QString &filePath, QString &filter, QStringList &result, bool recursively)
{
    QDir dir(filePath);
    if (!dir.exists()) {
        return -1;
    }

    dir.setFilter(QDir::Dirs|QDir::Files|QDir::NoDotAndDotDot);
    dir.setSorting(QDir::DirsFirst);
    QFileInfoList infos = dir.entryInfoList();
    for (const QFileInfo &info: infos) {
        if (info.isDir() && recursively) {
            findFile(info.filePath(), filter, result, recursively);
        } else {
            if (info.fileName().endsWith(filter)) {
                result.append(QDir::fromNativeSeparators(filePath+'/'+info.fileName()));
            }
        }
    }
    return 0;
}

#endif // FILEUTIL_H
