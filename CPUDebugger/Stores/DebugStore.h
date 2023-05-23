#ifndef DEBUGSTORE_H
#define DEBUGSTORE_H

#include <memory>
#include "File/AsmFile.h"
#include "uart/comm.h"

class DebugStore
{
private:
    static int binCurLine;
    static int asmCurLine;
    static std::shared_ptr<AsmFile> asmFilePtr;
    friend class DebugController;
};


#endif // DEBUGSTORE_H
