#ifndef PREDEBUGCONTROLLER_H
#define PREDEBUGCONTROLLER_H
#include <QtCore>
#include <memory>
#include <vector>

#include "Stores/PreDebugStore.h"

class PreDebugController
{
public:
    static std::shared_ptr<QFile> uploadFile(QString filePath);
    static void generateCoe(std::shared_ptr<QFile> file);
    static void setBreakPoint(int lineIdx);

};

#endif // PREDEBUGCONTROLLER_H
