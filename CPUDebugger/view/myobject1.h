#ifndef MYOBJECT1_H
#define MYOBJECT1_H

#include <QObject>
#include <QtQml>
#include <QtCore>
#include "Controllers/DebugController.h"
#include "Controllers/PreDebugController.h"
#include "controller/FileController.h"
#include <QFile>
#include <QTextStream>
#include <QVariantList>

class MyObject1 : public QObject
{
    Q_OBJECT

    QML_ELEMENT

public:
    explicit MyObject1(QObject *parent = nullptr);

    static MyObject1 * getInstance();
    int value() const;
    void setValue(int newValue);

    QString string() const;
    void setString(const QString &newString);

    Q_INVOKABLE void getAsmFile();

    Q_INVOKABLE void loadFile1();

    Q_INVOKABLE void makeBreakPoint();

    Q_INVOKABLE void makeList1();

    Q_INVOKABLE void removeMyList1(int index);

    Q_INVOKABLE void addMyList1();

    Q_INVOKABLE void makeList2();

    Q_INVOKABLE void removeMyList2(int index);

    Q_INVOKABLE void addMyList2(QString string);

    Q_INVOKABLE void makeList41();
    
    Q_INVOKABLE void sendResume();
    
    Q_INVOKABLE void sendPause();
    
    Q_INVOKABLE void sendStep();

    Q_INVOKABLE void detect();

    Q_INVOKABLE void confirm1();

    Q_INVOKABLE void loadSvgPath();

    Q_INVOKABLE void search();

    Q_INVOKABLE void searchCancel();

    int value1() const;
    void setValue1(int newValue1);

    QVariantList items1() const;
    void setItems1(const QVariantList &newItems1);

    QList<QString> getmyList1() const;
    void setmyList1(const QList<QString> &newmyList1);

    QList<QString> myList2() const;
    void setMyList2(const QList<QString> &newMyList2);

    QList<QString> myList41() const;
    void setMyList41(const QList<QString> &newMyList41);

    QString string1() const;
    void setString1(const QString &newString1);

    QString string21() const;
    void setString21(const QString &newString21);

    QString string22() const;
    void setString22(const QString &newString22);

private:
    int m_value;
    int m_value1;
    QString m_string;
    QString m_string1; //page1 folder address
    QString m_string21; //search context
    QString m_string22; //page2 image address

    std::shared_ptr<QFile> file1;
    FileController *fileContrl;
    QVariantList m_items1;
    QList<QString> m_myList1;
    QList<QString> m_myList2;
    QList<QString> m_myList41;
    


    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)

    Q_PROPERTY(QString string READ string WRITE setString NOTIFY stringChanged)

    Q_PROPERTY(int value1 READ value1 WRITE setValue1 NOTIFY value1Changed)

    Q_PROPERTY(QVariantList items1 READ items1 WRITE setItems1 NOTIFY items1Changed)

    Q_PROPERTY(QList<QString> myList1 READ getmyList1 WRITE setmyList1 NOTIFY myList1Changed)

    Q_PROPERTY(QList<QString> myList2 READ myList2 WRITE setMyList2 NOTIFY myList2Changed)

    Q_PROPERTY(QList<QString> myList41 READ myList41 WRITE setMyList41 NOTIFY myList41Changed)

    Q_PROPERTY(QString string1 READ string1 WRITE setString1 NOTIFY string1Changed)

    Q_PROPERTY(QString string21 READ string21 WRITE setString21 NOTIFY string21Changed)

    Q_PROPERTY(QString string22 READ string22 WRITE setString22 NOTIFY string22Changed)

signals:

    void valueChanged();
    void stringChanged();
    void value1Changed();
    void items1Changed();
    void myList1Changed();
    void myList2Changed();
    void myList41Changed();
    void string1Changed();
    void string21Changed();
    void string22Changed();
};


#endif // MYOBJECT1_H


