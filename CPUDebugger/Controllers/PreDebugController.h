#ifndef PREDEBUGCONTROLLER_H
#define PREDEBUGCONTROLLER_H

#include <QtCore>
#include <memory>
#include <set>

#include "Stores/PreDebugStore.h"
#include "Controllers/DebugController.h"


class PreDebugController
{
public:
    static std::shared_ptr<QFile> uploadFile(QString filePath);

    static void setBreakPoint(int lineIdx);
    static std::shared_ptr<AsmFile> getAsm();
    static std::shared_ptr<QFile> getFile();
    static void clear();




private:
    static void asmToBin(std::shared_ptr<QFile> file);
};
#endif // PREDEBUGCONTROLLER_H
