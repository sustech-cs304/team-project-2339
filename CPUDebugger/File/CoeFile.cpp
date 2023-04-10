#include "CoeFile.h"

CoeFile::CoeFile() : DebugFile::DebugFile()
{
    asmFile = nullptr;
    coeToAsmMap.clear();
}

void CoeFile::setAsmFile(std::shared_ptr<AsmFile> asmFile)
{
    this->asmFile = asmFile;
}
