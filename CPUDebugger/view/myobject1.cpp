#include "myobject1.h"

MyObject1::MyObject1(QObject *parent)
    : QObject{parent}
{
    fileContrl = new FileController();
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
    m_myList41.clear();
    QString filePath = m_string.mid(8);
    qDebug()<<filePath;
    file1 = PreDebugController::uploadFile(filePath);
    if (file1->open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(file1.get());
            while (!in.atEnd())
            {
                QString line = in.readLine();
                m_myList41.append(line);
            }
        }
    qDebug()<<m_myList41;
    qDebug() << __FUNCTION__;
}

void MyObject1::loadFile1()
{
    if (file1->open(QIODevice::ReadOnly | QIODevice::Text)) {
        // 输出文件所有内容
        QTextStream in(file1.get());
        while (!in.atEnd())
        {
            QString line = in.readLine();
            m_items1.append(line);
            qDebug() << line;
        }
    }
}

void MyObject1::makeBreakPoint()
{

    PreDebugController::setBreakPoint(m_value);
    qDebug() << m_value;
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

QVariantList MyObject1::items1() const
{
    return m_items1;
}


void MyObject1::setItems1(const QVariantList &newItems1)
{
    if (m_items1 == newItems1)
        return;
    m_items1 = newItems1;
    emit items1Changed();
}

QList<QString> MyObject1::getmyList1() const
{
    return m_myList1;
}

void MyObject1::setmyList1(const QList<QString> &newmyList1)
{
    if (m_myList1 == newmyList1)
        return;
    m_myList1 = newmyList1;
    emit myList1Changed();
}

QList<QString> MyObject1::myList2() const
{
    return m_myList2;
}

void MyObject1::setMyList2(const QList<QString> &newMyList2)
{
    if (m_myList2 == newMyList2)
        return;
    m_myList2 = newMyList2;
    emit myList2Changed();
}

QList<QString> MyObject1::myList41() const
{
    return m_myList41;
}

void MyObject1::setMyList41(const QList<QString> &newMyList41)
{
    if (m_myList41 == newMyList41)
        return;
    m_myList41 = newMyList41;
    emit myList41Changed();
}

QString MyObject1::string1() const
{
    return m_string1;
}

void MyObject1::setString1(const QString &newString1)
{
    if (m_string1 == newString1)
        return;
    m_string1 = newString1;
    emit string1Changed();
}

QString MyObject1::string21() const
{
    return m_string21;
}

void MyObject1::setString21(const QString &newString21)
{
    if (m_string21 == newString21)
        return;
    m_string21 = newString21;
    emit string21Changed();
}

QString MyObject1::string22() const
{
    return m_string22;
}

void MyObject1::setString22(const QString &newString22)
{
    if (m_string22 == newString22)
        return;
    m_string22 = newString22;
    emit string22Changed();
}

void MyObject1::makeList1()
{
//    m_myList1=fileContrl->getSignalList();
//    qDebug()<<m_myList1;
}

void MyObject1::removeMyList1(int index)
{
    if (index >= 0 && index < m_myList1.count()) {
        m_myList1.removeAt(index);
        qDebug()<<m_myList1;
    }
}

void MyObject1::addMyList1()
{

}

void MyObject1::makeList2()
{
    m_myList2.clear();
    qDebug()<<m_myList2;
}

void MyObject1::removeMyList2(int index)
{
    if (index >= 0 && index < m_myList2.count()) {
        m_myList2.removeAt(index);
    }
}

void MyObject1::addMyList2(QString string)
{
    m_myList2.append(string);
    
}

void MyObject1::makeList41()
{


}

void MyObject1::sendResume(){
    DebugController::resume();
}

void MyObject1::sendPause(){
    DebugController::pause();
}

void MyObject1::sendStep(){
    DebugController::step();
}

void MyObject1::detect(){
    
}

/**
 * @brief MyObject1::confirm1
 */

void MyObject1::confirm1()
{
    qDebug() << "m_string: " << m_string1;
    fileContrl->import(m_string1);

    m_myList1 = fileContrl->getSignals();
    qDebug() << m_myList1;

    fileContrl->genGraph();

}

/**
 * @brief MyObject1::loadSvgPath
 * m_string="newSvgFilePath"
 * 测试的话直接点击page2的confirm，我在conclicked函数里面调用了
 */
void MyObject1::loadSvgPath(){
    m_string22 = fileContrl->getSvgPath();
    qDebug() << "Get m_string: " << m_string22;
}

