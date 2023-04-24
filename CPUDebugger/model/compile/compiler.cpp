#include "compiler.h"

Compiler::Compiler()
{
    alex = new MAlex();
}

QList<Token> Compiler::scan(QList<QString> lines)
{
    alex->tokenList.clear();
    for (QString line: lines) {
        alex->read_line(line);
    }
    return alex->tokenList;
}

bool Compiler::isMacro(int index, QList<Token> tokens)
{
    if (index+3 >= tokens.size())
        return false;
    if (tokens[index].s == '`' && tokens[index].t == RANGE &&
        tokens[index+1].s.toLower() == "define" &&
        tokens[index+2].t == ID &&
        tokens[index+3].t == CONS) {
        return true;
    }
    return false;
}
