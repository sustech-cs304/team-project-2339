#ifndef COMPILER_H
#define COMPILER_H
#include <QtCore>
#include "MAlex.h"

class Compiler
{
public:
    Compiler();
//    void extracted(QList<QString> &lines, QList<Token> &tokenList);
    QList<Token> scan(QList<QString>);
    bool isMacro(int, QList<Token>);
private:
    MAlex *alex;
};

#endif // COMPILER_H
