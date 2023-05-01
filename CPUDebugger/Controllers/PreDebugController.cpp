#include "PreDebugController.h"
#include <stdexcept>

std::shared_ptr<QFile> PreDebugController::uploadFile(QString filePath)
{
    // 获取文件后缀
    QString suffix = QFileInfo(filePath).suffix();
    if (suffix == "asm")
    {
        PreDebugStore::setAsmFile(std::make_shared<AsmFile>());
        std::shared_ptr<QFile> filePtr = std::make_shared<QFile>(filePath);
        generateCoe(filePtr);
        return filePtr;
    }
    else
    {
        throw std::invalid_argument("Select .asm or .coe file!");
    }
}

//std::make_shared<QFile> PreDebugController::generateCoe()
void PreDebugController::generateCoe(std::shared_ptr<QFile> file)
{
}

void PreDebugController::setBreakPoint(int lineIdx)
{
}
