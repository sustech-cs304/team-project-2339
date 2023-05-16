#ifndef FILESTORE_H
#define FILESTORE_H

#include "TopModule.h"
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

    void setModuleData(TopModule *);

    static FileStore* getInstance() {
        if (fs == nullptr)
            fs = new FileStore();
        return fs;
    }
    void setFile(QString key, QFile* value);
    void setModuleData(QString key, TopModule* value);
    TopModule* getModuleData(QString);
    void deleteModuleData();

private:
    FileStore();
    ~FileStore() {}
    FileStore(const FileStore&);
    FileStore& operator=(const FileStore&);
    QMap<QString, TopModule*> moduleMap;
    QMap<QString, QFile*> fileMap;
};

#endif // FILESTORE_H
