#ifndef TOPVFILEINPUTFACTORY_H
#define TOPVFILEINPUTFACTORY_H
#include "FileInputFactory.h"
class TopVFileInputFactory: public FileInputFactory {
public:
    virtual ModuleData fileInput(FFile file);
};

#endif // TOPVFILEINPUTFACTORY_H
