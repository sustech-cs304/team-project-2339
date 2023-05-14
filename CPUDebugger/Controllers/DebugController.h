#ifndef DEBUGCONTROLLER_H
#define DEBUGCONTROLLER_H

#include <QtCore>
#include <memory>

#include "File/AsmFile.h"
#include "Stores/DebugStore.h"
#include "uart/comm.h"

class DebugController
{
public:
    static int step();
    static int next();
    static int pause();
    static QByteArray getBin();
    friend class PreDebugController;



private:
    enum FileType
    {
        Asm,
        Bin
    };
    static void checkStore();
    static void initialize(std::shared_ptr<AsmFile> asmFilePtr);
    static void clear();

    inline static int extractPC(QByteArray& cpuResponse);

    inline static int setPC(FileType fileType, int PC);

};

#endif // DEBUGCONTROLLER_H
