#include "FileStore.h"

FileStore::FileStore()
{

}

ModuleData *FileStore::getModuleData(QString key)
{
    return this->moduleMap.take(key);
}
