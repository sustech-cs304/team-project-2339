
#ifndef FILEUTIL_H
#define FILEUTIL_H

#include "compile/MAlex.h"
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
    static QFile* importFile(QString path, bool isUrl=false);
    static QStringList getDirList(QString dirPath, QString filter="v");
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

inline QFile *FileUtil::importFile(QString path, bool isUrl)
{
    if (isUrl) {
        QString absolutePath = path;
        QString cleanPath = QUrl(absolutePath).toLocalFile();
        return new QFile(cleanPath);
    } else
        return new QFile(path);
}

inline QStringList FileUtil::getDirList(QString dirPath, QString filter)
{
    QDir dirInfo(dirPath);
    QStringList result;
    QStringList entries = dirInfo.entryList();
    for (const QString &d: entries) {
        QFileInfo fInfo(dirPath+d);
        if (!fInfo.suffix().compare(filter))
            result.append(QDir::fromNativeSeparators(dirPath+'/'+d));
    }
    return result;
}

#endif // FILEUTIL_H
