//
// Created by David Li on 4/12/23.
//

#ifndef COREGENERATOR_H
#define COREGENERATOR_H

#include <QFile>
#include <QDir>
#include <QDebug>
#include <QDirIterator>
#include <QCoreApplication>
#include <QRegularExpression>
#include <CPUSignal.h>

#define OPCODE_WIDTH 8

bool generateCore(QString topPath,
                  QString outputDirPath,
                  const QList<CPUSignal> &selectedSignals);

int setISAWidth(int ISAWidth);

#endif // COREGENERATOR_H
