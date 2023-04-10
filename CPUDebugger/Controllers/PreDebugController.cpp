#include "PreDebugController.h"
#include <stdexcept>

std::shared_ptr<QFile> PreDebugController::uploadFile(QString filePath)
{
    // 获取文件后缀
    QString suffix = QFileInfo(filePath).suffix();
    if (suffix == "asm")
    {
        PreDebugStore::setAsmFile(std::make_shared<AsmFile>());

        return std::make_shared<QFile>(filePath);
    }
    else if (suffix == "coe")
    {
        PreDebugStore::setCoeFile(std::make_shared<CoeFile>());
        return std::make_shared<QFile>(filePath);
    }
    else
    {
        throw std::invalid_argument("Select .asm or .coe file!");
    }

}
void PreDebugController::setBreakPoint(int lineIdx)
{
    PreDebugStore::getAsmFile()->addBreakPoints(lineIdx);
}
