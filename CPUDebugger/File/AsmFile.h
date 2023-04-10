#ifndef ASMFILE_H
#define ASMFILE_H
#include <vector>
#include <memory>
#include <QMap>

class CoeFile;
class AsmFile
{
public:
    std::shared_ptr<CoeFile> coeFile;
    std::shared_ptr< QMap< int, std::vector<int> > > asmToCoeMap;
};

#endif // ASMFILE_H
