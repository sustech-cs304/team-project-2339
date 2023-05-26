
#ifndef GENERATOR_H
#define GENERATOR_H

#include <QString>

class Generator
{
public:
    Generator();
    void genDot(QString yosysPath, QString dirPath);
    void genSvg(QString yosysPath, QString dirPath);
    void genSvg(QString gvPath, QString dirPath, QString filename);
};

#endif // GENERATOR_H
