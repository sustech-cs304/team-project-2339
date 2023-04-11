#ifndef MYOBJECT1_H
#define MYOBJECT1_H

#include <QObject>
#include <QtQml>

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

private:
    int m_value;
    QString m_string;
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)

    Q_PROPERTY(QString string READ string WRITE setString NOTIFY stringChanged)

signals:

    void valueChanged();
    void stringChanged();
};

#endif // MYOBJECT1_H
