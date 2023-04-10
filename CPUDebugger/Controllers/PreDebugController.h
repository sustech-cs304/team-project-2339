#ifndef PREDEBUGCONTROLLER_H
#define PREDEBUGCONTROLLER_H
#include <QFile>

class PreDebugController
{

public:
    static QFile uploadFile();
    static int setBreakPoint();
};

#endif // PREDEBUGCONTROLLER_H
