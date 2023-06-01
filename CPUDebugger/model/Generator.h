
#ifndef GENERATOR_H
#define GENERATOR_H

#include <QString>

/**
 * @brief The Generator class
 * The class deals with the generation of dot file and svg file.
 */
class Generator
{
public:
    Generator();
    /**
     * @brief genDot
     * Generate file with dot format based on yosys.
     * @param yosysPath
     * The path of yosys
     * @param dirPath
     * The generating path of directory
     */
    void genDot(QString yosysPath, QString dirPath);
    /**
     * @brief genSvg (deprecated)
     * Generate file with svg format based on yosys.
     * The function can not work well because the yosys has no
     * idea to generate svg file directory
     * @param yosysPath
     * @param dirPath
     */
    void genSvg(QString yosysPath, QString dirPath);
    /**
     * @brief genSvg
     * Generate file with svg format based on Graphviz.
     * @param gvPath
     * The path of graphviz
     * @param dirPath
     * The generating path of directory
     * @param filename
     * The name of file generated
     */
    void genSvg(QString gvPath, QString dirPath, QString filename);
};

#endif // GENERATOR_H
