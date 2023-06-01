
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
    /**
     * @brief getTextStreams (deprecated)
     * Get the string list for one file.
     * @param the pointer of QFile
     * @return
     */
    static QStringList getTextStreams(QFile *f);
    /**
     * @brief exportFile
     * Export file to the path with @c ss @c
     * @param path
     * @param ss
     */
    static void exportFile(QString path, QString ss);
    /**
     * @brief exportFile
     * Export file to the path with string list.
     * @param path
     * @param lines
     */
    static void exportFile(QString path, QStringList lines);
    /**
     * @brief exportFile
     * Export file to the path with tokens.
     * @param path
     * @param tokens
     */
    static void exportFile(QString path, QList<Token> tokens);
    /**
     * @brief exportFile
     * Export file with filename in directory with path with string list.
     * @param dirPath
     * The path of directory
     * @param filename
     * The name of file
     * @param lines
     */
    static void exportFile(QString dirPath, QString filename, QStringList lines);
    /**
     * @brief execute
     * Execute the file with ".exe" in Windows.
     * @param binPath
     * The path of executing file.
     * @param workDir
     * The working directory when you execute the file.
     * @param arguments
     * The argumnets you import
     * @return
     */
    static QString execute(QString binPath, QString workDir, QStringList &arguments);
    /**
     * @brief importFile
     * Import one file with path. The path should be url when @c isUrl=true @c
     * @param path
     * @param isUrl
     * The path is url or not.
     * @return
     */
    static QFile* importFile(QString path, bool isUrl=false);
    /**
     * @brief convert
     * Convert the url to file path
     * @param url
     * @return
     */
    static QString convert(QString url);
    /**
     * @brief dupRemove
     * Remove all the duplicated element in string list.
     * @param ss
     * @return
     */
    static QList<QString> dupRemove(QList<QString> ss);
    /**
     * @brief getDirList
     * Get all the files in the directory with filter.
     * @param dirPath
     * The path of directory.
     * @param filter
     * Search the file with @c filter @c suffix.
     * @param recursively
     * If it is true, it will search the directory recursively.
     * @return
     */
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
