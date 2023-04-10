#include <QtCore>
#include "Controllers/DebugController.h"
#include "File/DebugFile.h"

int main()
{
    QString s = *(DebugController::step(3));
    qDebug("%s", qPrintable(s));

    s = *(DebugController::run());
    qDebug("%s", qPrintable(s));

    struct PauseSignal signal = *(DebugController::pause());
    s = *(signal.stringPtr);
    qDebug("%s Current line is %d", qPrintable(s), signal.lineNum);


    DebugFile file;
    file.addBreakPoints(1);
    file.addBreakPoints(3);
    file.addBreakPoints(2);
    file.addBreakPoints(7);
    file.addBreakPoints(11);
    int next = file.getNextBreakPointDiff(8);
    qDebug("Next line is %d.", next);
}
