#include "PreDebugController.h"
#include <stdexcept>

std::shared_ptr<QFile> PreDebugController::uploadFile(QString filePath)
{
    std::shared_ptr<QFile> file_ptr = std::make_shared<QFile>(filePath);
    if (file_ptr == nullptr)
    {
        throw std::invalid_argument("wrong file path");
    }

    // 获取文件后缀
    QString suffix = QFileInfo(filePath).suffix();
    // 检查文件后缀
    if (suffix == "asm")
    {
        std::shared_ptr<QFile> filePtr = std::make_shared<QFile>(filePath);
        PreDebugStore::file = filePtr;
        return filePtr;
    }
    else
    {
        throw std::invalid_argument("Select .asm file!");
    }
}

void PreDebugController::clear()
{
    PreDebugStore::file = nullptr;
    PreDebugStore::asmFile = nullptr;
}

int PreDebugController::compileAsm()
{
    std::shared_ptr<QFile> filePtr = PreDebugStore::file;
    if (filePtr == nullptr)
        throw std::invalid_argument("Select .asm file first!");
    std::shared_ptr<AsmFile> asmFilePtr = std::make_shared<AsmFile>(*filePtr);
    PreDebugStore::asmFile = asmFilePtr;
//    asmFilePtr->setBreakPoints(PreDebugStore::breakPoints);
    DebugController::initialize(asmFilePtr);
    return 0;
}

void PreDebugController::setBreakPoint(int lineIdx)
{
    std::set<int>::iterator iter = PreDebugStore::breakPoints.find(lineIdx);
    if (iter != PreDebugStore::breakPoints.end())
    {
        PreDebugStore::breakPoints.erase(iter);
    }
    else
    {
        PreDebugStore::breakPoints.insert(lineIdx);
    }
}

std::shared_ptr<AsmFile> PreDebugController::getAsm()
{
    return PreDebugStore::asmFile;
}

std::shared_ptr<QFile> PreDebugController::getFile()
{
    return PreDebugStore::file;
}
