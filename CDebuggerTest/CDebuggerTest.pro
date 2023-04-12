QT += testlib
QT += gui-private
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += \
    ../CPUDebugger/model

include(../CPUDebugger/model/model.pri)

SOURCES += \
    tst_model.cpp\

DISTFILES += \
    ../README.md \
    out.txt \
    top.v \
    top1.v
