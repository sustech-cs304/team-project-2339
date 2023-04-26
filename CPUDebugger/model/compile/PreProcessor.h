
#ifndef PREPROCESSOR_H
#define PREPROCESSOR_H

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
    void process(QString path);
    void replace(QString path, QString dest, bool ignoreStatement);
    void filter(QList<Token>&, FilterType fType);
private:
    void replaceMarco(QList<Token>&);
    void filterIgnoreBeforeModule(QList<Token>&);
    void filterIgnoreStatement(QList<Token>&);
    void filterEquationCompution(QList<Token>&);
    QMap<QString, QString> *marcoMap;
    Compiler *c;
};

#endif // PREPROCESSOR_H
