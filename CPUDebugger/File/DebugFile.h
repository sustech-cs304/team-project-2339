#ifndef DEBUGFILE_H
#define DEBUGFILE_H

#include <vector>

class DebugFile
{
private:
    std::vector<int> breakPoints;
    
public:
    void addBreakPoints();
    std::vector<int> getBreakPoints();
    std::vector<int> getNextBreakPoints();
};

#endif // DEBUGFILE_H
