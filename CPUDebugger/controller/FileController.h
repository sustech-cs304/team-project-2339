#ifndef FILECONTROLLER_H
#define FILECONTROLLER_H
#include "FileInputFactory.h"
#include "FileOutputFactory.h"
#include "QFile"
class FileController {
public:
    void import(QFile file);
    void exportUart();
private:
    FileInputFactory *inputFac;
    FileOutputFactory *outputFac;
};

#endif // FILECONTROLLER_H
