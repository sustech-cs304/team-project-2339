#include "TopVFileInputFactory.h"
#include "compile/compiler.h"

TopVFileInputFactory::TopVFileInputFactory() {

}

ModuleData TopVFileInputFactory::fileInput(FFile *file) {
    QFile* f = file->data;
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
    for (Token token: tokenList) {
        std::cout << "Token: " << token.toStdString() << std::endl;
    }
    return ModuleData();
}
