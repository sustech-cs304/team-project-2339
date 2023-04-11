#include "myobject1.h"

MyObject1::MyObject1(QObject *parent)
    : QObject{parent}
{

}

MyObject1 *MyObject1::getInstance()
{
    static MyObject1 * obj = new MyObject1;
    return obj;
}

int MyObject1::value() const
{

    return m_value;
}

void MyObject1::setValue(int newValue)
{
    if (m_value == newValue)
        return;
    m_value = newValue;
    emit valueChanged();
}

QString MyObject1::string() const
{
    return m_string;
}

void MyObject1::setString(const QString &newString)
{
    if (m_string == newString)
        return;
    m_string = newString;
    emit stringChanged();
}

void MyObject1::getAsmFile()
{
    QString filePath = m_string.mid(7);
    qDebug()<<filePath;
    file1 = PreDebugController::uploadFile(filePath);
    qDebug() << __FUNCTION__;
}

void MyObject1::makeBreakPoint()
{

    PreDebugController::setBreakPoint(m_value);
    qDebug() << m_value;
}

void MyObject1::asmStep()
{
    qDebug() << *(DebugController::step());
    m_value1=DebugStore::asmCurLine;
    qDebug() << m_value1;
}

void MyObject1::asmRun()
{
    DebugController::run();
}

void MyObject1::asmPause()
{
    DebugController::pause();
}

int MyObject1::value1() const
{
    return m_value1;
}

void MyObject1::setValue1(int newValue1)
{
    if (m_value1 == newValue1)
        return;
    m_value1 = newValue1;
    emit value1Changed();
}
