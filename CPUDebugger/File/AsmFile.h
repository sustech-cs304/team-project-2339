#ifndef ASMFILE_H
#define ASMFILE_H
#include <vector>
#include <memory>
#include <QMap>
#include "DebugFile.h"

class CoeFile;
class AsmFile : public DebugFile
{
public:
    std::shared_ptr<CoeFile> coeFile;
    QMap<int, std::shared_ptr<std::vector<int> > >  asmToCoeMap;

    AsmFile();
    void setCoeFile(std::shared_ptr<CoeFile> coeFile);
};

#endif // ASMFILE_H
