
/**
 * @file DebugStore.h
 * @brief This file contains the declaration of the DebugStore class.
 * 
 * The DebugStore class is responsible for storing and managing debug information.
 * 
 */

#ifndef DEBUGSTORE_H
#define DEBUGSTORE_H

#include <memory>
#include "File/AsmFile.h"
#include "uart/comm.h"

/**
 * @brief The DebugStore class is responsible for storing and managing debug information.
 * 
 */
class DebugStore
{
public:
    /**
     * @brief Sets the current program counter (PC) for the assembly code.
     * 
     * @param asmPC The current program counter (PC) for the assembly code.
     * @return int Returns 0 if successful.
     */
    static int setPC_Asm(int asmPC);

    /**
     * @brief Sets the current program counter (PC) for the binary code.
     * 
     * @param PC The current program counter (PC) for the binary code.
     * @return int Returns 0 if successful.
     */
    static int setPC_Bin(int PC);

private:
    static int binCurLine; /**< The current line number for the binary code. */
    static int asmCurLine; /**< The current line number for the assembly code. */
    static std::shared_ptr<AsmFile> asmFilePtr; /**< A shared pointer to the AsmFile object. */
    friend class DebugController;
};

#endif // DEBUGSTORE_H


