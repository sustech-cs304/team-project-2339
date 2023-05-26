#ifndef MYOBJECT1_H
#define MYOBJECT1_H

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

    Q_INVOKABLE void loadFile1();

    Q_INVOKABLE void makeBreakPoint();

    Q_INVOKABLE void makeList1();

    Q_INVOKABLE void removeMyList1(int index);

    Q_INVOKABLE void addMyList1();

    Q_INVOKABLE void makeList2();

    Q_INVOKABLE void removeMyList2(int index);

    Q_INVOKABLE void addMyList2(QString string);

    Q_INVOKABLE void makeList41();
    
    Q_INVOKABLE void sendResume(); //page4 resume

    Q_INVOKABLE void sendStep(); //page4 step
    
    Q_INVOKABLE void sendPause(); //page4 pause

    Q_INVOKABLE void sendBreakPoint(); //page4 break point

    Q_INVOKABLE void getAsmFile(); //page4 get asm file

    Q_INVOKABLE void changeAsmFile();

    Q_INVOKABLE void exportTo(); //page3 export to button

    Q_INVOKABLE void complete(); //page3 complete button

    Q_INVOKABLE void detect();  //page3 detect button

    Q_INVOKABLE void confirm1();

    Q_INVOKABLE void confirm2();

    Q_INVOKABLE void loadSvgPath();

    Q_INVOKABLE void search();

    Q_INVOKABLE void searchCancel();

    Q_INVOKABLE void closeWindow();

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

    QString string31() const;
    void setString31(const QString &newString31);

    QString string32() const;
    void setString32(const QString &newString32);

    QString string41() const;
    void setString41(const QString &newString41);

    QList<QString> myList42() const;
    void setMyList42(const QList<QString> &newMyList42);

    bool getDetectResult() const;
    void setDetectResult(bool newDetectResult);

    bool getResult41() const;
    void setResult41(bool newResult41);

    bool getResult42() const;
    void setResult42(bool newResult42);

    QString string1() const;
    void setString1(const QString &newString1);

    QString string21() const;
    void setString21(const QString &newString21);

    QString string22() const;
    void setString22(const QString &newString22);

    QString string42() const;
    void setString42(const QString &newString42);

    int value42() const;
    void setValue42(int newValue42);

private:
    int m_value;
    int m_value1;
    QString m_string;

    QString m_string31; //page3 folder address
    QString m_string32; //page3 detect result
    QString m_string41; //page4 asm file address
    QString m_string42; //page4 change asm file
    int m_value42;

    bool detectResult;
    bool result41; //page4 get asm file
    bool result42; //send breaking point

    QString m_string1; //page1 folder address
    QString m_string21; //search context
    QString m_string22; //page2 image address

    std::shared_ptr<QFile> file1;
    FileController *fileContrl;
    QVariantList m_items1;
    QList<QString> m_myList1;
    QList<QString> m_myList2;
    QList<QString> m_myList41;
    QList<QString> m_myList42; //page4 signal result list
    


    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)

    Q_PROPERTY(QString string READ string WRITE setString NOTIFY stringChanged)

    Q_PROPERTY(int value1 READ value1 WRITE setValue1 NOTIFY value1Changed)

    Q_PROPERTY(QVariantList items1 READ items1 WRITE setItems1 NOTIFY items1Changed)

    Q_PROPERTY(QList<QString> myList1 READ getmyList1 WRITE setmyList1 NOTIFY myList1Changed)

    Q_PROPERTY(QList<QString> myList2 READ myList2 WRITE setMyList2 NOTIFY myList2Changed)

    Q_PROPERTY(QList<QString> myList41 READ myList41 WRITE setMyList41 NOTIFY myList41Changed)

    Q_PROPERTY(QString string31 READ string31 WRITE setString31 NOTIFY string31Changed)

    Q_PROPERTY(QString string32 READ string32 WRITE setString32 NOTIFY string32Changed)

    Q_PROPERTY(QString string41 READ string41 WRITE setString41 NOTIFY string41Changed)

    Q_PROPERTY(QList<QString> myList42 READ myList42 WRITE setMyList42 NOTIFY myList42Changed)

    Q_PROPERTY(bool detectResult READ getDetectResult WRITE setDetectResult NOTIFY detectResultChanged)

    Q_PROPERTY(bool result41 READ getResult41 WRITE setResult41 NOTIFY result41Changed)

    Q_PROPERTY(bool result42 READ getResult42 WRITE setResult42 NOTIFY result42Changed)

    Q_PROPERTY(QString string1 READ string1 WRITE setString1 NOTIFY string1Changed)

    Q_PROPERTY(QString string21 READ string21 WRITE setString21 NOTIFY string21Changed)

    Q_PROPERTY(QString string22 READ string22 WRITE setString22 NOTIFY string22Changed)

    Q_PROPERTY(QString string42 READ string42 WRITE setString42 NOTIFY string42Changed)

    Q_PROPERTY(int value42 READ value42 WRITE setValue42 NOTIFY value42Changed)

signals:

    void valueChanged();
    void stringChanged();
    void value1Changed();
    void items1Changed();
    void myList1Changed();
    void myList2Changed();
    void myList41Changed();
    void string31Changed();
    void string32Changed();
    void string41Changed();
    void myList42Changed();
    void detectResultChanged();
    void result41Changed();
    void result42Changed();
    void string1Changed();
    void string21Changed();
    void string22Changed();
    void string42Changed();
    void value42Changed();
};


#endif // MYOBJECT1_H


