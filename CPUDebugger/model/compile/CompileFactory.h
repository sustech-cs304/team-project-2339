#ifndef COMPILEFACTORY_H
#define COMPILEFACTORY_H

#include "MAlex.h"
#include "FileStore.h"


class CompileFactory
{
public:
    CompileFactory(MAlex*);
    void addTopModule(QList<Token> &tokenList, qsizetype index);
    void addModule(QList<Token>& tokenList, qsizetype index);
    void addEquation(QList<Token>& tokenList, qsizetype index);
    void addSubModuleObject(QList<Token>& tokenList, qsizetype index);
private:
    MAlex *alex;
};

#endif // COMPILEFACTORY_H
