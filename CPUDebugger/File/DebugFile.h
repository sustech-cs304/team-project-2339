#ifndef DEBUGFILE_H
#define DEBUGFILE_H

#include <vector>

class DebugFile
{
private:
    std::vector<int> breakPoints;
    
public:
    DebugFile();
    void addBreakPoints(int lineIdx);
    std::vector<int>& getBreakPoints();
    std::vector<int>& getNextBreakPoints();
};

#endif // DEBUGFILE_H
