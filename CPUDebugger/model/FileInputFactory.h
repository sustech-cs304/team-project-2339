#ifndef FILEINPUTFACTORY_H
#define FILEINPUTFACTORY_H
#include "TopModule.h"
#include "QTextStream"
#include <QFile>

class FileInputFactory {
public:
    virtual TopModule* fileInput(QFile *file)=0;
};

#endif // FILEINPUTFACTORY_H
