#include <QDebug>
#include "Controllers/DebugController.h"

int main()
{
    QString s = *(DebugController::step(3));
    qDebug("%s", qPrintable(s));

    s = *(DebugController::run());
    qDebug("%s", qPrintable(s));

    struct PauseSignal signal = *(DebugController::pause());
    s = *(signal.stringPtr);
    qDebug("%s Current line is %d", qPrintable(s), signal.lineNum);

}
