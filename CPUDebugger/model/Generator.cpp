
#include "Generator.h"
#include "FileController.h"
#include "FileUtil.h"
Generator::Generator()
{

}

void Generator::genDot(QString yosysPath, QString dirPath)
{
    QStringList arguments;
    QStringList entries = FileUtil::getDirList(dirPath, "v", true);
    QString f;
    for (QString &s: entries) {
        f.append(s+" ");
    }
    arguments << "-p" << QString("read_verilog %1").arg(f) << "-p" << QString("show");
    qDebug() << FileUtil::execute(yosysPath, dirPath, arguments);
}

void Generator::genSvg(QString gvPath, QString dirPath, QString filename)
{
    QStringList arguments;
    arguments << "-Tsvg" << filename << "-o" << "show.svg";
    qDebug() << FileUtil::execute(gvPath, dirPath, arguments);
}
