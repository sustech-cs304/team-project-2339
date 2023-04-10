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
    int getNextBreakPointDiff(int curLine);
};

#endif // DEBUGFILE_H
