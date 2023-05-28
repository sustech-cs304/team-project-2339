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
#include <CPUDebugger/model/CPUSignal.h>

#define OPCODE_WIDTH 8

bool generateCore(QString topFilePath,
                  QString outputDirPath,
                  const QList<CPUSignal> &selectedSignals);

int setISAWidth(int ISAWidth);

#endif // COREGENERATOR_H
