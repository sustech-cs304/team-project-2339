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

#define BYTE_LEN 8
#define WORD_LEN 32
#define ADDR_LEN 20
#define FUNC_LEN 6
#define REG_LEN 5
#define SHAMT_LEN 5
#define IMME_LEN 16
#define OFFS_LEN 26

class AsmFile {
public:
    explicit AsmFile(QFile &asmFile);

    explicit AsmFile();

    ~AsmFile();

    QString loadAsmFile(QFile &newAsmFile);

    QByteArray updateAsmFile(QString &asmString);

    QByteArray getBin();

    int getPC(int asmLine);

    int getAsmLine(int binLine);

private:
    QFile *asmFile{};

    unsigned int programCounter{};
    int          asmLine{};

    QMap<QString, int> labelMap;
    QByteArray         bin;

    QMap<int, unsigned int> asmToPCMap;
    QMap<unsigned int, int> PCToAsmMap;

    enum OpType {
        O_Type, R_Type, I_Type, J_Type, P_Type
    };

    void preprocess(QString &asmString);

    void parseAsm(QString asmString);

    static QByteArray asciiData(QString data, int *wordCnt);

    static bool isSingleLine(QStringList::const_iterator &wordIter);

    static bool isDoubleLine(QStringList::const_iterator &wordIter);

    static int getOpType(const QString &op);

    void binAppend(uint32_t word);

    static uint32_t zeroExtend(const QString &word, int length);

    static uint32_t signExtend(const QString &word, int length);

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
