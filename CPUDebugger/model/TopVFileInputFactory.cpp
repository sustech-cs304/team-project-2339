#include "TopVFileInputFactory.h"
#include "compile/compiler.h"
#include <iostream>

TopVFileInputFactory::TopVFileInputFactory() {

}

ModuleData* TopVFileInputFactory::fileInput(QFile *file) {
    QFile* f = file;
    std::cout << f->fileName().toStdString() << std::endl;
    f->open(QIODevice::ReadOnly);
    QTextStream in(f);
    QList<QString> lines;

    QString line;
    while (in.readLineInto(&line)) {
        lines.append(line);
//        std::cout << line.toStdString() << std::endl;
    }
    Compiler compiler;
    QList<Token> tokenList = compiler.scan(lines);
    QFile *of = new QFile("CDebuggerTest/out.txt");
    of->open(QIODevice::WriteOnly);
    QTextStream out(of);
    for (Token token: tokenList) {
        out << "Token: " << token.toStdString().c_str() << "\n";
    }
    return ModuleData();
}
