#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QLocale>
#include <QTranslator>
#include <iostream>
#include <QDebug>
#include "uart/UartSimulator.h"


int main()
{
    QString s = *(UartSimulator::step(3));
    qDebug("%s", qPrintable(s));

    s = *(UartSimulator::run());
    qDebug("%s", qPrintable(s));

    struct PauseSignal signal = *(UartSimulator::pause());
    s = *(signal.stringPtr);
    qDebug("%s Current line is %d", qPrintable(s), signal.lineNum);
}
