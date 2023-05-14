#ifndef MODULEDATA_H
#define MODULEDATA_H
#include "QString"
#include <QList>
#include "Module.h"
class ModuleData {
public:
    void addModule(Module*);
    void removeModule(QString moduleName);
    void flagSignal(QString moduleName, QString signalName);
private:
    QString name;
    QList<Module> modules;
};

#endif // MODULEDATA_H
