#ifndef COEFILE_H
#define COEFILE_H
#include "AsmFile.h"
#include <memory>

class CoeFile : public DebugFile
{
public:
    std::shared_ptr<AsmFile> asmFile;
    QMap<int, std::shared_ptr<std::vector<int> > >  coeToAsmMap;

    CoeFile();
    void setAsmFile(std::shared_ptr<AsmFile> asmfile);
};

#endif // COEFILE_H
