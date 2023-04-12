#ifndef FILEINPUTFACTORY_H
#define FILEINPUTFACTORY_H
#include "ModuleData.h"
#include "FFile.h"
#include "QTextStream"
class FileInputFactory {
public:
    virtual ModuleData fileInput(FFile *file)=0;
};

#endif // FILEINPUTFACTORY_H
