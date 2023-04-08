#ifndef ASMFILE_H
#define ASMFILE_H
#include <vector>
#include <memory>
#include <QMap>
#include "CoeFile.h"

class AsmFile
{
public:
    std::shared_ptr<CoeFile> coeFile;
    std::shared_ptr< QMap< int, std::vector<int> > > asmToCoeMap;
    AsmFile();
};

#endif // ASMFILE_H
