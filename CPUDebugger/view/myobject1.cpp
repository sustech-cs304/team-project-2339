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
    QString filePath = m_string41.mid(8);
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
    file1->close();
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

QString MyObject1::string31() const
{
    return m_string31;
}

void MyObject1::setString31(const QString &newString31)
{
    if (m_string31 == newString31)
        return;
    m_string31 = newString31;
    emit string31Changed();
}

QString MyObject1::string32() const
{
    return m_string32;
}

void MyObject1::setString32(const QString &newString32)
{
    if (m_string32 == newString32)
        return;
    m_string32 = newString32;
    emit string32Changed();
}

QString MyObject1::string41() const
{
    return m_string41;
}

void MyObject1::setString41(const QString &newString41)
{
    if (m_string41 == newString41)
        return;
    m_string41 = newString41;
    emit string41Changed();
}

QList<QString> MyObject1::myList42() const
{
    return m_myList42;
}

void MyObject1::setMyList42(const QList<QString> &newMyList42)
{
    if (m_myList42 == newMyList42)
        return;
    m_myList42 = newMyList42;
    emit myList42Changed();
}

bool MyObject1::getDetectResult() const
{
    return detectResult;
}

void MyObject1::setDetectResult(bool newDetectResult)
{
    if (detectResult == newDetectResult)
        return;
    detectResult = newDetectResult;
    emit detectResultChanged();
}

bool MyObject1::getResult41() const
{
    return result41;
}

void MyObject1::setResult41(bool newResult41)
{
    if (result41 == newResult41)
        return;
    result41 = newResult41;
    emit result41Changed();
}

bool MyObject1::getResult42() const
{
    return result42;
}

void MyObject1::setResult42(bool newResult42)
{
    if (result42 == newResult42)
        return;
    result42 = newResult42;
    emit result42Changed();
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

QString MyObject1::string42() const
{
    return m_string42;
}

void MyObject1::setString42(const QString &newString42)
{
    if (m_string42 == newString42)
        return;
    m_string42 = newString42;
    emit string42Changed();
}

int MyObject1::value42() const
{
    return m_value42;
}

void MyObject1::setValue42(int newValue42)
{
    if (m_value42 == newValue42)
        return;
    m_value42 = newValue42;
    emit value42Changed();
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

extern QList<CPUSignal> mysignals;

void MyObject1::sendResume(){
    std::optional<QByteArray> cpuResponse = DebugController::resume();
    if (cpuResponse == nullptr)
        return;
    int binPC = (static_cast<unsigned int>(cpuResponse->at(0)) & 0xFF)
             + ((static_cast<unsigned int>(cpuResponse->at(1)) & 0xFF) << 8)
            + ((static_cast<unsigned int>(cpuResponse->at(2)) & 0xFF) << 16)
            + ((static_cast<unsigned int>(cpuResponse->at(3)) & 0xFF) << 24);
    int lineNum = PreDebugStore::asmFile->getAsmLine(binPC);

    m_myList42.clear();
    int start_idx = 3;
    for (int i = 0 ; i < mysignals.length() ; i ++){
        QString hexString;
        for (int j = start_idx + mysignals.at(i).width; j > start_idx; j--) {
            hexString += QString("%1").arg(static_cast<quint8>(cpuResponse->at(j)), 2, 16, QChar('0'));
        }
        m_myList42.append(hexString);
        start_idx += mysignals.at(i).width;
    }
    m_value1=lineNum;
}

void MyObject1::sendPause(){
    DebugController::pause();
}

void MyObject1::sendBreakPoint()
{
    std::optional<QByteArray> cpuResponse = DebugController::sendPrograme();
    if(cpuResponse == nullptr){
        result42=false;
    }else {
        result42=true;
    }
    int binPC = (static_cast<unsigned int>(cpuResponse->at(0)) & 0xFF)
             + ((static_cast<unsigned int>(cpuResponse->at(1)) & 0xFF) << 8)
            + ((static_cast<unsigned int>(cpuResponse->at(2)) & 0xFF) << 16)
            + ((static_cast<unsigned int>(cpuResponse->at(3)) & 0xFF) << 24);
    int lineNum = PreDebugStore::asmFile->getAsmLine(binPC);
    m_value1=lineNum;
}

void MyObject1::sendStep(){
    std::optional<QByteArray> cpuResponse = DebugController::step();
    if (cpuResponse == nullptr)
        return;
    int binPC = (static_cast<unsigned int>(cpuResponse->at(0)) & 0xFF)
             + ((static_cast<unsigned int>(cpuResponse->at(1)) & 0xFF) << 8)
            + ((static_cast<unsigned int>(cpuResponse->at(2)) & 0xFF) << 16)
            + ((static_cast<unsigned int>(cpuResponse->at(3)) & 0xFF) << 24);
    int lineNum = PreDebugStore::asmFile->getAsmLine(binPC);

    m_myList42.clear();
    int start_idx = 3;
    for (int i = 0 ; i < mysignals.length() ; i ++){
        QString hexString;
        for (int j = start_idx + mysignals.at(i).width; j > start_idx; j--) {
            hexString += QString("%1").arg(static_cast<quint8>(cpuResponse->at(j)), 2, 16, QChar('0'));
        }
        m_myList42.append(hexString);
        start_idx += mysignals.at(i).width;
    }
    m_value1=lineNum;
}

void MyObject1::detect(){
    detectResult=DebugController::detect();
}

void MyObject1::exportTo()
{
    QString filePath = m_string31.mid(8);
    qDebug() << "Signal list: " << m_myList2;
    fileContrl->exportUart(m_myList2, filePath);
}

void MyObject1::complete()
{

}

/**
 * @brief MyObject1::confirm1
 */

void MyObject1::confirm1()
{
    qDebug() << "m_string: " << m_string1;
    fileContrl->import(m_string1);
    
    m_myList1 = fileContrl->getStringSignals();
    qDebug() << m_myList1;

    fileContrl->genGraph();

}

void MyObject1::confirm2()
{
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

void MyObject1::search()
{
    fileContrl->filter(m_myList1, m_string21);
    fileContrl->filter(m_myList2, m_string21);
    qDebug()<<m_myList1;
}

void MyObject1::searchCancel()
{

}

void MyObject1::closeWindow()
{

}

void MyObject1::changeAsmFile()
{
    m_myList41.replace(m_value42, m_string42);
}


