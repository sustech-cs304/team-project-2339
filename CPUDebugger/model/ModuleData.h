#ifndef MODULEDATA_H
#define MODULEDATA_H
#include "QString"
#include <QList>
#include "Module.h"
class ModuleData {
public:

private:
    QString name;
    QList<Module> modules;
};

#endif // MODULEDATA_H
