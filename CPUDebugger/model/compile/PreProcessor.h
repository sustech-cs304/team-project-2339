
#ifndef PREPROCESSOR_H
#define PREPROCESSOR_H

#include "compile/CParser.h"
#include "compile/compiler.h"
#include <QString>
#define FilterType int
#define FILTER_IGNORE_BEFORE_MODULE 1
#define FILTER_IGNORE_STATEMENT 2
#define FILTER_EQUATION_COMPUTION 3

class PreProcessor
{
public:
    PreProcessor();
    ~PreProcessor()
    {
        delete marcoMap;
        delete c;
    }
    void clear();
    void process(QString path, std::optional<QString> dest);
    void replace(QString path, QString dest, bool ignoreStatement);
    void filter(QList<Token>&, FilterType fType);
    QMap<QString, QString>& getMarcoMap();
    QList<CPUSignal> genSignals(QString &path);
private:
    void replaceMarco(QList<Token>&);
    void filterIgnoreBeforeModule(QList<Token>&);
    void filterIgnoreStatement(QList<Token>&);
    void filterEquationCompution(QList<Token>&);
    QMap<QString, QString> *marcoMap;
    Compiler *c;
    CParser *parser;
};

#endif // PREPROCESSOR_H
