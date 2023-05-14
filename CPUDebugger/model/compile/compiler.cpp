#include "compiler.h"

#include <stack>

Compiler::Compiler()
{
    alex = new MAlex();
}

QList<Token> Compiler::scan(QList<QString> lines)
{
    alex->clear();
    for (QString line: lines) {
        alex->read_line(line);
    }
    return alex->tokenList;
}

bool Compiler::isMacro(int index, QList<Token> tokens)
{
    if (index+3 >= tokens.size())
        return false;
    if (tokens[index].s == '`' && tokens[index].t == RANGE &&
        tokens[index+1].s.toLower() == "define" &&
        tokens[index+2].t == ID &&
        tokens[index+3].t == CONS) {
        return true;
    }
    return false;
}

int Compiler::getEquation(QList<Token> tokens)
{
    QString expr;
    for (int i = 0; i < tokens.size(); i++) {
        expr.append(tokens[i].s);
        if (i != tokens.size()-1)
            expr.append(' ');
    }
    std::string s = infixToPostfix(expr.toStdString());
    return (int) evaluatePostfix(QString::fromStdString(s));
}

// 定义一个函数，参数为中缀表达式字符串，返回值为后缀表达式字符串
std::string Compiler::infixToPostfix(std::string infixExpression) {
    std::string postfixExpression = ""; // 初始化后缀表达式字符串为空
    std::stack<char> operatorStack; // 定义一个栈用于存储运算符

    // 遍历中缀表达式字符串中的每个字符
    for (char& c : infixExpression) {
        if (c == ' ') {
            postfixExpression += ' ';
            continue; // 如果是空格则跳过
        } else if (isdigit(c)) {
            postfixExpression += c; // 如果是数字则直接加入后缀表达式字符串
        } else if (c == '(') {
            operatorStack.push(c); // 如果是左括号则入栈
        } else if (c == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfixExpression += operatorStack.top(); // 如果是右括号则将栈中的运算符弹出并加入后缀表达式字符串，直到遇到左括号
                operatorStack.pop();
            }
            operatorStack.pop(); // 弹出左括号
        } else {
            while (!operatorStack.empty() && operatorStack.top() != '(' && getPrecedence(c) <= getPrecedence(operatorStack.top())) {
                postfixExpression += operatorStack.top(); // 如果是运算符则将栈中优先级高于等于它的运算符弹出并加入后缀表达式字符串
                operatorStack.pop();
            }
            operatorStack.push(c); // 将该运算符入栈
        }
    }

    while (!operatorStack.empty()) {
        postfixExpression += ' ';
        postfixExpression += operatorStack.top(); // 将栈中剩余的运算符弹出并加入后缀表达式字符串
        operatorStack.pop();
    }

    return postfixExpression;
}

// 定义一个函数，参数为运算符，返回值为该运算符的优先级
int Compiler::getPrecedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else {
        return 0;
    }
}


QString Compiler::toPostfix(QString expr) {
    QStack<QString> stack;
    QStringList tokens = expr.split(" ");
    QString result;

    foreach (QString token, tokens) {
        if (token == "+" || token == "-") {
            while (!stack.isEmpty() && (stack.top() == "*" || stack.top() == "/")) {
                result += stack.pop() + " ";
            }
            stack.push(token);
        } else if (token == "*" || token == "/") {
            stack.push(token);
        } else if (token == "(") {
            stack.push(token);
        } else if (token == ")") {
            while (!stack.isEmpty() && stack.top() != "(") {
                result += stack.pop() + " ";
            }
            stack.pop();
        } else {
            result += token + " ";
        }
    }

    while (!stack.isEmpty()) {
        result += stack.pop() + " ";
    }

    return result.trimmed();
}

double Compiler::evaluatePostfix(QString expr) {
    QStack<double> stack;
    QStringList tokens = expr.split(" ");

    foreach (QString token, tokens) {
        if (token == " " || token == "")
            continue;
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            double b = stack.pop();
            double a = stack.pop();
            if (token == "+") stack.push(a + b);
            else if (token == "-") stack.push(a - b);
            else if (token == "*") stack.push(a * b);
            else if (token == "/") stack.push(a / b);
        } else {
            double num = token.toDouble();
            stack.push(num);
        }
    }

    return stack.pop();
}
