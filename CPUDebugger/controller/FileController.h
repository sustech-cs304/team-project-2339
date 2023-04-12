#ifndef FILECONTROLLER_H
#define FILECONTROLLER_H
#include "FileInputFactory.h"
#include "FileOutputFactory.h"
#include <TopVFileInputFactory.h>
#include "QFile"
#include "QtGui/private/qzipreader_p.h"
#include <QDir>

#define TMP_PATH "tmp/"
class FileController {
public:
    FileController();
    ~FileController();
    void import(QString& absolutePath);
    QList<CPUSignal> getSignalList();
    void setSignal(QString signalName);
    void exportUart();
private:
    FileInputFactory *inputFac;
    FileOutputFactory *outputFac;
};

#endif // FILECONTROLLER_H
