#include <QtCore>
#include "Controllers/DebugController.h"
#include "Controllers/PreDebugController.h"
#include "File/DebugFile.h"
#include "File/AsmFile.h"
#include "File/CoeFile.h"
#include "Stores/PreDebugStore.h"

int test()
{
    QString s = *(DebugController::step(3));
    qDebug("%s", qPrintable(s));

    s = *(DebugController::run());
    qDebug("%s", qPrintable(s));

    struct PauseSignal signal = *(DebugController::pause());
    s = *(signal.stringPtr);
    qDebug("%s Current line is %d", qPrintable(s), signal.lineIdx);


    AsmFile asmFile;
    asmFile.addBreakPoints(1);
    asmFile.addBreakPoints(3);
    asmFile.addBreakPoints(2);
    asmFile.addBreakPoints(7);
    asmFile.addBreakPoints(11);
    int next = asmFile.getNextBreakPointDiff(8);
    qDebug("Next line is %d.", next);

    CoeFile coeFile;
    coeFile.setAsmFile(std::make_shared<AsmFile>(asmFile));
    next = coeFile.asmFile->getNextBreakPointDiff(2);
    qDebug("Next line is %d.", next);

    asmFile.setCoeFile(std::make_shared<CoeFile>(coeFile));
    next = asmFile.coeFile->asmFile->getNextBreakPointDiff(3);
    qDebug("Next line is %d.", next);

    std::shared_ptr<AsmFile> asmfile_ptr = std::make_shared<AsmFile>(asmFile);
    std::shared_ptr<CoeFile> coefile_ptr = std::make_shared<CoeFile>(coeFile);

    PreDebugStore::setAsmFile(asmfile_ptr);
    PreDebugStore::setCoeFile(coefile_ptr);

    next = PreDebugStore::getAsmFile()->getNextBreakPointDiff(8);
    qDebug("Next line is %d.", next);

    QString filePath = "/Users/zitong/Downloads/test.asm";
    std::shared_ptr<QFile> file = PreDebugController::uploadFile(filePath);
    // 打开文件
    if (file->open(QIODevice::ReadOnly | QIODevice::Text)) {
        // 读取第一行
        QString firstLine = file->readLine();
        qDebug() << firstLine;
}
}
