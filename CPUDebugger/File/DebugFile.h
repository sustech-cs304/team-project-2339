#ifndef DEBUGFILE_H
#define DEBUGFILE_H

#include <vector>

class DebugFile
{
private:
    std::vector<int> breakPoints;
    
public:
    virtual void addBreakPoints() = 0;
    virtual std::vector<int>& getBreakPoints() = 0;
    virtual std::vector<int>& getNextBreakPoints() = 0;
};

#endif // DEBUGFILE_H
