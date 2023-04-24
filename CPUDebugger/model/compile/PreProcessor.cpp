
#include "PreProcessor.h"

#include <FileUtil.h>
#include <iostream>

PreProcessor::PreProcessor()
{
    c = new Compiler();
    marcoMap = new QMap<QString, QString>();
}

void PreProcessor::process(QString path)
{
    QFile *f = FileUtil::importFile(path);
    QList<Token> tokens = c->scan(FileUtil::getTextStreams(f));
    QFile of("E:/d.v");
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

void PreProcessor::replace(QString path, QString dest)
{
    QFile *f = FileUtil::importFile(path);
    QList<Token> tokens = c->scan(FileUtil::getTextStreams(f));
    QStringList lines;
    QString ss;
    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i].s == '`') {
            if (c->isMacro(i, tokens)) {
                i += 3;
            } else {
                Token t = tokens[i+1];
                i += 1;
                ss.append(marcoMap->value(t.s)+' ');
            }
        } else {
            ss.append(tokens[i].s+' ');
        }
        if (tokens[i].s == ',' || tokens[i].s == ';') {
            lines.append(ss);
            ss.clear();
        }
    }
    lines.append(ss);
    FileUtil::exportFile(dest, lines);
    lines.clear();
    f->close();
    delete f;
}
