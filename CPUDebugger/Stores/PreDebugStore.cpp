#include "Stores/PreDebugStore.h"

std::shared_ptr<AsmFile> PreDebugStore::asmFile = nullptr;
std::shared_ptr<QFile> PreDebugStore::file = nullptr;
std::set<int> PreDebugStore::breakPoints = {};
