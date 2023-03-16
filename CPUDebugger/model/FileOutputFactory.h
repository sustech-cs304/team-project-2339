#ifndef FILEOUTPUTFACTORY_H
#define FILEOUTPUTFACTORY_H
#include "FFile.h"
#include "ModuleData.h"
class FileOutputFactory {
public:
    virtual FFile exportUart(ModuleData);
};

#endif // FILEOUTPUTFACTORY_H
