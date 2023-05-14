#include "FileStore.h"

FileStore::FileStore()
{

}

TopModule *FileStore::getModuleData(QString key)
{
    return this->moduleMap.take(key);
}
