#include "MAlex.h"

void init(std::pair<qsizetype, qsizetype> p, QStringList &ss) {
    int l, r;
    l = p.first;
    r = p.first + p.second;
    for (int i = l; i < r; i++) {
        ss.append(global_data[i].split(" ")[1]);
    }
}

MAlex::MAlex()
{
    init(global_type[RANGE], this->range);
    init(global_type[OPN], this->opn);
    init(global_type[KEY], this->key);
}

void MAlex::read_line(Line line)
{
    line = pre_check(line);
    QString s;

    for (QChar c: qAsConst(line)) {
        if (is_alpha(c) || is_number(c) || c == '_') {
            s.append(c);
            continue;
        } else {
            if (!s.isEmpty()) {
                if (is_key(s))
                    this->tokenList.append(Token(s, KEY));
                else if (is_alpha(s[0]) || s[0] == '_')
                    this->tokenList.append(Token(s, ID));
                else if (is_number(s)) {
                    this->tokenList.append(Token(s, CONS));
                } else {
                    throw QException();
                }
                s.clear();
            }
        }
        if (is_range(c)) {
            this->tokenList.append(Token(c, RANGE));
            continue;
        }
        if (is_operator(c)) {
            this->tokenList.append(Token(c, OPN));
            continue;
        }
    }
}

bool MAlex::is_range(QChar c)
{
    return this->range.contains(c);
}

bool MAlex::is_operator(QChar c)
{
    return this->opn.contains(c);
}

bool MAlex::is_alpha(QChar c)
{
    return c.isLetter();
}

bool MAlex::is_number(QChar c)
{
    return c.isNumber();
}

bool MAlex::is_number(QString s)
{
    for (QChar c: s) {
        if (!is_number(c))
            return false;
    }
    return true;
}

bool MAlex::is_key(QString s)
{
    return this->key.contains(s);
}

Line MAlex::pre_check(Line line)
{
    QChar las = ' ';
    Line new_line;
    for (QChar c: line) {
        if (c == las && las == ' ')
            continue;
        if (c == las && las == '/') {
            new_line.remove(new_line.size()-1, 1);
            break;
        }
        new_line.append(c);
        las = c;
    }
    return new_line;
}

