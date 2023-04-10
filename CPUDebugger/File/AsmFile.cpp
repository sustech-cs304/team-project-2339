#include "AsmFile.h"

AsmFile::AsmFile() : DebugFile::DebugFile()
{
    coeFile = nullptr;
    asmToCoeMap.clear();
}

void AsmFile::setCoeFile(std::shared_ptr<CoeFile> coeFile)
{
    this->coeFile = coeFile;
}
