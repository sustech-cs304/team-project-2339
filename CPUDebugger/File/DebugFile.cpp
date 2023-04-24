#include "DebugFile.h"

#include <algorithm>

DebugFile::DebugFile()
{
    breakPoints.clear();
}

void DebugFile::addBreakPoints(int lineIdx)
{
//    auto iter = std::find(breakPoints.begin(), breakPoints.end(), lineIdx);

//    if (iter != breakPoints.end()) {

//        auto new_end = std::remove(breakPoints.begin(), breakPoints.end(), lineIdx);
//        breakPoints.erase(new_end, breakPoints.end());

//    } else {
//        breakPoints.push_back(lineIdx);
//    }
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
