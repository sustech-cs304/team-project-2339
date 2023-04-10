#ifndef PREDEBUGCONTROLLER_H
#define PREDEBUGCONTROLLER_H
#include <QtCore>
#include <memory>

#include "Stores/PreDebugStore.h"

class PreDebugController
{
public:
    static std::shared_ptr<QFile> uploadFile(QString filePath);
    static void setBreakPoint(int lineIdx);
};

#endif // PREDEBUGCONTROLLER_H
