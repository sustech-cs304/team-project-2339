#include "DebugFile.h"

DebugFile::DebugFile()
{
    breakPoints.clear();
}

void DebugFile::addBreakPoints(int lineIdx)
{
    breakPoints.push_back(lineIdx);

}
std::vector<int>& DebugFile::getBreakPoints()
{
    return breakPoints;
}
std::vector<int>& DebugFile::getNextBreakPoints()
{

}
