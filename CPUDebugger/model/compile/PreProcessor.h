
#ifndef PREPROCESSOR_H
#define PREPROCESSOR_H

#include "compile/compiler.h"
#include <QString>





class PreProcessor
{
public:
    PreProcessor();
    void process(QString path);
    void replace(QString path, QString dest);
private:
    QMap<QString, QString> *marcoMap;
    Compiler *c;
};

#endif // PREPROCESSOR_H
