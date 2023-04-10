#ifndef COEFILE_H
#define COEFILE_H
#include "AsmFile.h"
#include <memory>

class CoeFile
{
public:
    std::shared_ptr<AsmFile> asmFile;
    std::shared_ptr< QMap< int, std::vector<int> > > coeToAsmMap;
};

#endif // COEFILE_H
