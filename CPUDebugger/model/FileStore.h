#ifndef FILESTORE_H
#define FILESTORE_H

#include "ModuleData.h"
#include <QFile>
#include "QMap"

class FileStore {
private:
    static FileStore *fs;
public:
    static FileStore *fileStore;

    FileStore instance();

    void setSignal(QString key, QString moduleName, QString signalName, SType state);

    void setFile(QString key, QFile file);

    void setModuleData(ModuleData *);

    static FileStore* getInstance() {
        if (fs == nullptr)
            fs = new FileStore();
        return fs;
    }
    void setFile(QString key, QFile* value);
    void setModuleData(QString key, ModuleData* value);
    ModuleData* getModuleData(QString);
    void deleteModuleData();

private:
    QMap<QString, ModuleData> moduleMap;
    QMap<QString, FFile *>    fileMap;
    FileStore();
    ~FileStore() {}
    FileStore(const FileStore&);
    FileStore& operator=(const FileStore&);
    QMap<QString, ModuleData*> moduleMap;
    QMap<QString, QFile*> fileMap;
};

#endif // FILESTORE_H
