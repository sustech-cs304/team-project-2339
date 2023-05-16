#ifndef TOPVFILEINPUTFACTORY_H
#define TOPVFILEINPUTFACTORY_H
#include "FileInputFactory.h"
#include "QList"

#include <compile/PreProcessor.h>
class TopVFileInputFactory: public FileInputFactory {
public:
    TopVFileInputFactory();
    virtual TopModule* fileInput(QFile *file);
private:
    PreProcessor *prePro;
};

#endif // TOPVFILEINPUTFACTORY_H
