#include "Stores/DebugStore.h"

int DebugStore::binCurLine = 0;
int DebugStore::asmCurLine = 0;
std::shared_ptr<AsmFile> DebugStore::asmFilePtr = nullptr;
