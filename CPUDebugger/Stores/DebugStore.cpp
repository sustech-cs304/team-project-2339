#include "Stores/DebugStore.h"

int DebugStore::binCurLine = 0;
int DebugStore::asmCurLine = 0;
std::shared_ptr<AsmFile> DebugStore::asmFilePtr = nullptr;


int DebugStore::setPC_Asm(int asmPC)
{
    DebugStore::asmCurLine = asmPC;
    int binPC = asmFilePtr->getPC(asmPC);
    DebugStore::binCurLine = binPC;
    return 0;
}

int DebugStore::setPC_Bin(int PC)
{
    DebugStore::binCurLine = PC;
    int asmPC = asmFilePtr->getAsmLine(PC);
    DebugStore::asmCurLine = asmPC;
    return 0;
}
