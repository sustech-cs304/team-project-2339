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
    int getEquation(QList<Token> tokens);
    QString toPostfix(QString expr);
    double evaluatePostfix(QString expr);
    std::string infixToPostfix(std::string infixExpression);
private:
    int getPrecedence(char op);
    MAlex *alex;
};

#endif // COMPILER_H
