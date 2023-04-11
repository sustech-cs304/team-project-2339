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
    PreDebugStore::setCoeFile(std::make_shared<CoeFile>());

    // 获取文件的行数
    QTextStream in(file.get());
    int lineCount = 0;
    if (file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(file.get());
        while (!in.atEnd())
        {
            QString line = in.readLine();
//            qDebug() << line;
            lineCount ++;
        }
    }
    file->close();

    qDebug() << "Have" << lineCount << "lines";


    for (int cnt = 0; cnt < lineCount; cnt++)
    {
        PreDebugStore::getAsmFile()->asmToCoeMap.insert(cnt, std::make_shared<std::vector<int> >(std::initializer_list<int>{cnt}));
        PreDebugStore::getCoeFile()->coeToAsmMap.insert(cnt, cnt);
    }

}

void PreDebugController::setBreakPoint(int lineIdx)
{
    PreDebugStore::getAsmFile()->addBreakPoints(lineIdx);
    std::vector<int> breakPoints = PreDebugStore::getAsmFile()->getBreakPoints();
    for (int i = 0; i < breakPoints.size(); i++) {
        std::shared_ptr<std::vector<int> > coeBreakPointsPtr = PreDebugStore::getAsmFile()->asmToCoeMap[breakPoints[i]];

//        if (coeBreakPointsPtr == nullptr) qDebug() << "empty";
//        else qDebug() << "not empty";

        std::vector<int> coeBreakPoints = *(coeBreakPointsPtr);
        for (int i = 0; i < coeBreakPoints.size(); i++)
        {
            PreDebugStore::getCoeFile()->addBreakPoints(coeBreakPoints[i]);
        }
    }
}
