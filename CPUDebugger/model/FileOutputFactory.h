#ifndef FILEOUTPUTFACTORY_H
#define FILEOUTPUTFACTORY_H
#include "TopModule.h"

#include <QFile>
class FileOutputFactory {
public:
    virtual QFile exportUart(TopModule);
};

#endif // FILEOUTPUTFACTORY_H
