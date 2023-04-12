#ifndef TOPVFILEINPUTFACTORY_H
#define TOPVFILEINPUTFACTORY_H
#include "FileInputFactory.h"
#include "QList"
class TopVFileInputFactory: public FileInputFactory {
public:
    TopVFileInputFactory();
    virtual ModuleData fileInput(FFile *file);
};

#endif // TOPVFILEINPUTFACTORY_H
