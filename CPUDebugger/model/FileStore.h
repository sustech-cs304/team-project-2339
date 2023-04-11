#ifndef FILESTORE_H
#define FILESTORE_H
#include "ModuleData.h"
#include "QMap"
#include <QFile>
class FileStore {
public:
    FileStore();
    ~FileStore() {}
    static FileStore *instance() {
        if (fileStore != nullptr)
            fileStore = new FileStore();
        return fileStore;
    }
    void setFile(QString key, QFile* value);
    void setModuleData(QString key, ModuleData* value);
    ModuleData* getModuleData(QString);
    void deleteModuleData();
private:
    static FileStore *fileStore;
    QMap<QString, ModuleData*> moduleMap;
    QMap<QString, QFile*> fileMap;
};
#endif // FILESTORE_H
