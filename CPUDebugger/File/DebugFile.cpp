#include "DebugFile.h"

#include <algorithm>

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

int DebugFile::getNextBreakPointDiff(int curLine)
{
    std::sort(breakPoints.begin(), breakPoints.end());
    for (int pointLineIdx : breakPoints)
    {
        if (pointLineIdx > curLine) return pointLineIdx - curLine;
    }
}
