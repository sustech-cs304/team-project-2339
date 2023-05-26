#ifndef WORKER1_H
#define WORKER1_H


#include <QThread>
#include <QDebug>
#include <QObject>
#include <QtQml>
#include <QtCore>
#include "Controllers/DebugController.h"
#include "Controllers/PreDebugController.h"
#include "controller/FileController.h"
#include "uart/comm.h"
#include <QFile>
#include <QTextStream>
#include <QVariantList>


//倒计时
class Worker1 : public QThread
{
    Q_OBJECT
    Q_PROPERTY(int data READ getData WRITE setData NOTIFY dataChanged )
public:
    explicit Worker1() = default;
    ~Worker1() = default;
    void run() {
        qDebug() << "Inside the worker thread!";
        qDebug() << "m_string1: " << m_string1;
        fileContrl->import(m_string1);

        m_myList1 = fileContrl->getStringSignals();
        qDebug() << m_myList1;

        fileContrl->genGraph();

        m_string2 = fileContrl->getSvgPath();
        qDebug() << "Get m_string: " << m_string2;
        setData(1);
        qDebug() <<"nnnn";
    }

    Q_INVOKABLE int getData() const { return data_; }

    // TODO: add signals for each type of received message by the worker thread?
    QString string() const;
    void setString(const QString &newString);

    QString string1() const;
    void setString1(const QString &newString1);

    QString string2() const;
    void setString2(const QString &newString2);

    QList<QString> myList1() const;
    void setMyList1(const QList<QString> &newMyList1);

signals:
    void dataChanged( const int data );

    void stringChanged();

    void string1Changed();

    void string2Changed();

    void myList1Changed();

public slots:
    void setData( const int data ) {
        if ( data != data_ ) {
            data_ = data;
            emit dataChanged( data_ );
        }
    }

private:
    int data_ = 0 ;
    QString m_string1;
    QString m_string2;

    QList<QString> m_myList1;
    FileController *fileContrl;

    Q_PROPERTY(QString string1 READ string1 WRITE setString1 NOTIFY string1Changed)
    Q_PROPERTY(QString string2 READ string2 WRITE setString2 NOTIFY string2Changed)
    Q_PROPERTY(QList<QString> myList1 READ myList1 WRITE setMyList1 NOTIFY myList1Changed)
};

inline QString Worker1::string1() const
{
    return m_string1;
}

inline void Worker1::setString1(const QString &newString1)
{
    if (m_string1 == newString1)
        return;
    m_string1 = newString1;
    emit string1Changed();
}

inline QString Worker1::string2() const
{
    return m_string2;
}

inline void Worker1::setString2(const QString &newString2)
{
    if (m_string2 == newString2)
        return;
    m_string2 = newString2;
    emit string2Changed();
}

inline QList<QString> Worker1::myList1() const
{
    return m_myList1;
}

inline void Worker1::setMyList1(const QList<QString> &newMyList1)
{
    if (m_myList1 == newMyList1)
        return;
    m_myList1 = newMyList1;
    emit myList1Changed();
}



#endif // WORKER1_H

