#ifndef ASMFILE_H
#define ASMFILE_H

#include "DebugFile.h"
#include <vector>
#include <memory>
#include <QMap>
#include <QFile>
#include <QRegularExpression>

#define DATA_MEM_SIZE 0x3FFF
#define TEXT_MEM_SIZE 0x3FFF

class AsmFile {
public:
    explicit AsmFile(QFile &asmFile);

    ~AsmFile();

    QString loadAsmFile(QFile &asmFile);

    QString updateAsmFile(QString &asmString);

    QByteArray getBin();

    int getBinAddress(int asmLine);

private:
    QFile &asmFile;

    unsigned int       programCounter{};
    QMap<QString, int> labelMap;
    QByteArray         bin;
    QString            hexString;

    QMap<int, int> asmToBinMap;
    QList<int>     breakpoints;

    enum OpType {
        O_Type, R_Type, I_Type, J_Type, P_Type
    };

    QByteArray preprocess(QString &asmString);

    void parseAsm(QString &asmString);

    static QByteArray asciiData(QString data, int *wordCnt);

    static bool isSingleLine(QStringList::const_iterator &wordIter);

    static bool isDoubleLine(QStringList::const_iterator &wordIter);

    static int getOpType(const QString &op);

    void binAppend(int word);

    static int zeroExtend(const QString &word);

    static int signExtend(const QString &word, int length);

    void O_TypeProcess(QStringList::const_iterator &wordIter);

    void R_TypeProcess(QStringList::const_iterator &wordIter);

    void I_TypeProcess(QStringList::const_iterator &wordIter);

    void J_TypeProcess(QStringList::const_iterator &wordIter);

    void P_TypeProcess(QStringList::const_iterator &wordIter);

    void pseudoCompare(QStringList::const_iterator &instruction);

    static int getRegCode(const QString &r);

//    static QString zeroExtent(QString string, int length);
};

#endif // ASMFILE_H
