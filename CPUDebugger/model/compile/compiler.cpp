#include "compiler.h"

Compiler::Compiler()
{
    alex = new MAlex();
}

QList<Token> Compiler::scan(QList<QString> lines)
{
    for (QString line: lines) {
        alex->read_line(line);
    }
    return alex->tokenList;
}
