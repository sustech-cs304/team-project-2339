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
