#ifndef PREDEBUGSTORE_H
#define PREDEBUGSTORE_H
#include <memory>

#include "File/AsmFile.h"
#include "File/CoeFile.h"

class PreDebugStore
{
private:
    static std::shared_ptr<AsmFile> asmFile;
    static std::shared_ptr<CoeFile> coeFile;

public:
    static std::shared_ptr<AsmFile> getAsmFile() {
        return asmFile;
    }
    static void setAsmFile(std::shared_ptr<AsmFile> file) {
        asmFile = file;
    }

    static std::shared_ptr<CoeFile> getCoeFile() {
        return coeFile;
    }
    static void setCoeFile(std::shared_ptr<CoeFile> file) {
        coeFile = file;
    }
};

#endif // PREDEBUGSTORE_H
