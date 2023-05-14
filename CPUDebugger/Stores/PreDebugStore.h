#ifndef PREDEBUGSTORE_H
#define PREDEBUGSTORE_H
#include <memory>
#include <set>

#include "File/AsmFile.h"

class PreDebugStore
{
private:
    static std::shared_ptr<AsmFile> asmFile;
    static std::shared_ptr<QFile> file;
    static std::set<int> breakPoints;
    friend class PreDebugController;
};


#endif // PREDEBUGSTORE_H
