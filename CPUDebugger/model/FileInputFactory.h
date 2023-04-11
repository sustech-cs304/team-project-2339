#ifndef FILEINPUTFACTORY_H
#define FILEINPUTFACTORY_H
#include "ModuleData.h"
#include "QTextStream"
#include <QFile>

class FileInputFactory {
public:
    virtual ModuleData fileInput(QFile *file)=0;
};

#endif // FILEINPUTFACTORY_H
