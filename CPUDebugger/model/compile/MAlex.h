#ifndef MALEX_H
#define MALEX_H

#include "compile/global_compile.h"
#include <QString>
#include <QStringList>
class Token {
public:
    Code c;
    QString s;
    Type t;
    Token(QString s, Type t) {
        this->s = s;
        this->t = t;
    }
    std::string toStdString() {
        std::string p;
        switch (t) {
        case RANGE:
            p = "RANGE";
            break;
        case OPN:
            p = "OPN";
            break;
        case KEY:
            p = "KEY";
            break;
        case ID:
            p = "ID";
            break;
        case CONS:
            p = "CONS";
            break;
        }

        return "<" + s.toStdString() + ", " + p + ">";
    }
};

class MAlex
{
public:
    QStringList range;
    QStringList opn;
    QStringList key;
    QList<Token> tokenList;
    MAlex();
    void read_line(Line);
    int next_c(QChar);
    bool is_range(QChar);
    bool is_operator(QChar);
    bool is_alpha(QChar);
    bool is_number(QChar);
    bool is_number(QString);
    bool is_key(QString);
private:
    Line pre_check(Line);
};

#endif // MALEX_H
