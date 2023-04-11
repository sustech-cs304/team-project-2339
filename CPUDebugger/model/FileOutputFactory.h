#ifndef FILEOUTPUTFACTORY_H
#define FILEOUTPUTFACTORY_H
#include "ModuleData.h"

#include <QFile>
class FileOutputFactory {
public:
    virtual QFile exportUart(ModuleData);
};

#endif // FILEOUTPUTFACTORY_H
