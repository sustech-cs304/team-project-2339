#ifndef PREDEBUGSTORE_H
#define PREDEBUGSTORE_H
#include <memory>
#include <set>
#include <gtest/gtest.h>


#include "File/AsmFile.h"


class PreDebugStore
{
private:
    static std::shared_ptr<AsmFile> asmFile;
    static std::shared_ptr<QFile> file;
    static std::set<int> breakPoints;
    friend class PreDebugController;
    FRIEND_TEST(PreDebugControllerTest, SetBreakPoint_AddsBreakPoint);
    FRIEND_TEST(PreDebugControllerTest, Clear_ClearsFileAndAsmFile);
    FRIEND_TEST(PreDebugControllerTest, CompileAsm_WithUploadedFile_CompilesAsmAndSetsBreakPoints);
    FRIEND_TEST(PreDebugControllerTest, SetBreakPoint_WithExistingLineIndex_RemovesBreakPoint);
    FRIEND_TEST(PreDebugControllerTest, SetBreakPoint_WithNonExistingLineIndex_AddsBreakPoint);
    FRIEND_TEST(PreDebugControllerTest, GetAsm_ReturnsAsmFilePointer);
    FRIEND_TEST(PreDebugControllerTest, GetFile_ReturnsFilePointer);
};


#endif // PREDEBUGSTORE_H
