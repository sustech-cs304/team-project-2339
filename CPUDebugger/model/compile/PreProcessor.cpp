
#include "PreProcessor.h"

#include <FileUtil.h>
#include <iostream>

PreProcessor::PreProcessor()
{
    c = new Compiler();
    marcoMap = new QMap<QString, QString>();
}

void PreProcessor::process(QString path, QString dest)
{
    QFile *f = FileUtil::importFile(path);
    QList<Token> tokens = c->scan(FileUtil::getTextStreams(f));
    QFile of(dest);
    of.open(QIODevice::WriteOnly);
    QTextStream out(&of);
    for (Token token: tokens) {
        out << "Token: " << token.toStdString().c_str() << "\n";
    }
    for (int i = 0; i < tokens.size(); i++) {
        if (c->isMacro(i, tokens)) {
            marcoMap->insert(tokens[i+2].s, tokens[i+3].s);
        }
    }
    f->close();
    of.close();
    delete f;
}

void PreProcessor::replace(QString path, QString dest, bool ignoreStatement)
{
    QFile *f = FileUtil::importFile(path);
    QList<Token> tokens = c->scan(FileUtil::getTextStreams(f));
    filter(tokens, FILTER_IGNORE_BEFORE_MODULE);
    replaceMarco(tokens);
    if (ignoreStatement)
        filter(tokens, FILTER_IGNORE_STATEMENT);
    filter(tokens, FILTER_EQUATION_COMPUTION);
    FileUtil::exportFile(dest, tokens);
    f->close();
    delete f;
}

void PreProcessor::filter(QList<Token> &tokens, int fType)
{
    if (fType == FILTER_IGNORE_BEFORE_MODULE) {
        filterIgnoreBeforeModule(tokens);
    } else if (fType == FILTER_IGNORE_STATEMENT) {
        filterIgnoreStatement(tokens);
    } else if (fType == FILTER_EQUATION_COMPUTION) {
        filterEquationCompution(tokens);
    }
}

void PreProcessor::replaceMarco(QList<Token> &tokens)
{
    int p = 0;
    while (p < tokens.size()) {
        Token &t = tokens[p];
        if (t.s == '`') {
            if (c->isMacro(p, tokens)) {
                tokens.remove(p, 4);
            } else {
                tokens.remove(p);
                tokens.insert(p, Token(marcoMap->value(tokens.takeAt(p).s), CONS));
            }
        } else {
            p++;
        }
    }
}

void PreProcessor::filterIgnoreBeforeModule(QList<Token> &tokens)
{
    int p = 0;
    while (p < tokens.size()) {
        Token &t = tokens[p];
        if (t.s == "module") {
            break;
        }
        tokens.remove(p);
    }
}

void PreProcessor::filterIgnoreStatement(QList<Token> &tokens)
{
    int p = 0;
    bool isState = false;
    while (p <tokens.size()) {
        Token &t = tokens[p];
        if (t.s == "endmodule")
            isState = false;
        if (isState) {
            tokens.remove(p);
        } else {
            if (t.s == ';')
                isState = true;
            p++;
        }
    }
}

void PreProcessor::filterEquationCompution(QList<Token> &tokens)
{
    QList<Token> ts;
    int p = 0;
    bool transform = false;
    while (p < tokens.size()) {
        Token t = tokens[p];
        if (t.s == ']' || t.s == ':')
            transform = false;
        if (transform) {
            if (t.t == CONS || t.t == OPN || t.s == '(' || t.s == ')') {
                ts.append(t);
                tokens.remove(p);
            } else {
                qDebug() << "unexpected token " << t.s;
            }
        } else {
            if (ts.size() == 1) {
                tokens.insert(p, ts[0]);
                ts.clear();
            } else if (ts.size() > 1) {
                int res = c->getEquation(ts);
                tokens.insert(p, Token(QString::number(res), CONS));
                ts.clear();
            }
            p++;
        }
        if (t.s == '[' || t.s == ':')
            transform = true;
    }
}
