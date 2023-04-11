#ifndef MYOBJECT1_H
#define MYOBJECT1_H

#include <QObject>
#include <QtQml>
#include <QtCore>
#include "Controllers/DebugController.h"
#include "Controllers/PreDebugController.h"
#include "File/DebugFile.h"
#include "File/AsmFile.h"
#include "File/CoeFile.h"
#include "Stores/PreDebugStore.h"
#include "Stores/DebugStore.h"

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

    Q_INVOKABLE void makeBreakPoint();

    Q_INVOKABLE void asmStep();

    Q_INVOKABLE void asmRun();

    Q_INVOKABLE void asmPause();

    int value1() const;
    void setValue1(int newValue1);

private:
    int m_value;
    int m_value1;
    QString m_string;
    std::shared_ptr<QFile> file1;
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)

    Q_PROPERTY(QString string READ string WRITE setString NOTIFY stringChanged)

    Q_PROPERTY(int value1 READ value1 WRITE setValue1 NOTIFY value1Changed)

signals:

    void valueChanged();
    void stringChanged();
    void value1Changed();
};

#endif // MYOBJECT1_H
