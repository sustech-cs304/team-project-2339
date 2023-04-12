#ifndef FFILE_H
#define FFILE_H
#include "QFile"
#include <iostream>
class FFile {
public:
    QFile *data;
    virtual void Show()=0;
};

#endif // FFILE_H
