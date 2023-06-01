#ifndef COMPILER_H
#define COMPILER_H
#include <QtCore>
#include "MAlex.h"

/**
 * @brief The Compiler class
 * The class deals with the pre-process of one file.
 */
class Compiler
{
public:
    Compiler();
    /**
     * @brief scan
     * Scan the string list from file and generate the token list of file.
     * The token list is based on lexical analysis.
     * @return
     * The token list
     */
    QList<Token> scan(QList<QString>&);
    /**
     * @brief isMacro
     * Judge indexed element in token list whether is a macro.
     * @return
     *
     * @example
     * @c `define INSTURCTION 30 @c is a macro
     */
    bool isMacro(int, QList<Token> &);
    /**
     * @brief getEquation
     * Get the result with token list. The token list should be
     * an equation format.
     * @param tokens
     * The equation token list.
     * @return
     * @example
     * The token list is like @c 3 - 2 + 5 * 2 @c. The result should be
     * 11
     */
    int getEquation(QList<Token>& tokens);
    double evaluatePostfix(QString expr);
    std::string infixToPostfix(std::string infixExpression);
private:
    int getPrecedence(char op);
    MAlex *alex;
};

#endif // COMPILER_H
