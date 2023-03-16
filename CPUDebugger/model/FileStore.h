#ifndef FILESTORE_H
#define FILESTORE_H
#include "ModuleData.h"
#include "QMap"
#include "FFile.h"
class FileStore {
public:
    static FileStore *fileStore;
    FileStore() {}
    ~FileStore() {}
    FileStore instance();
    void setSignal(QString key, QString moduleName, QString signalName, SignalState state);
    void setFile(QString key, FFile file);
    void setModuleData(ModuleData*);
    void deleteModuleData();
private:
    QMap<QString, ModuleData> moduleMap;
    QMap<QString, FFile> fileMap;

};
#endif // FILESTORE_H
