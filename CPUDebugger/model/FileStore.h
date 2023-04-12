#ifndef FILESTORE_H
#define FILESTORE_H
#include "ModuleData.h"
#include "QMap"
#include <QFile>
class FileStore {
private:
    static FileStore *fs;
public:
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
    FileStore();
    ~FileStore() {}
    FileStore(const FileStore&);
    FileStore& operator=(const FileStore&);
    QMap<QString, ModuleData*> moduleMap;
    QMap<QString, QFile*> fileMap;
};

#endif // FILESTORE_H
