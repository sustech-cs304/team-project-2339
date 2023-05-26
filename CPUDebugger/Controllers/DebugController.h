#ifndef DEBUGCONTROLLER_H
#define DEBUGCONTROLLER_H

#include <QtCore>
#include <memory>

#include "File/AsmFile.h"
#include "Stores/DebugStore.h"
#include "uart/comm.h"
#include "Controllers/PreDebugController.h"
#include "Stores/PreDebugStore.h"
#include "model/CPUSignal.h"

class DebugController
{
public:
    static std::optional<QByteArray> resume();
    static std::optional<QByteArray> step();
    static int pause();
    static int detect();
    static QByteArray getBin();
    static std::optional<QByteArray> sendPrograme();
    static void setSignals(QList<CPUSignal>* sharedSignals);
    static int compileAsm();
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
    static QList<CPUSignal>* mysignals;
};

#endif // DEBUGCONTROLLER_H
