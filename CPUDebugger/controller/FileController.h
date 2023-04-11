#ifndef FILECONTROLLER_H
#define FILECONTROLLER_H
#include "FileInputFactory.h"
#include "FileOutputFactory.h"
#include <TopVFileInputFactory.h>
#include "QFile"
class FileController {
public:
    FileController();
    void import(QFile file);
    QList<MySignal> getSignalList();
    void setSignal(QString signalName);
    void exportUart();
private:
    FileInputFactory *inputFac;
    FileOutputFactory *outputFac;
};

#endif // FILECONTROLLER_H
