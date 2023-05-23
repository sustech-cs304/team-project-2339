QT += quick testlib
QT += quickcontrols2
QT += gui-private
QT += serialport

QML_IMPORT_NAME = MyObj
QML_IMPORT_MAJOR_VERSION = 1

TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG += thread
CONFIG += qt
CONFIG += qmltypes

SOURCES += \
        main.cpp \
        tst_importfile.cpp \
        tst_render.cpp \
        tst_uart.cpp \
        PreDebugController_Test/compiler_test.cpp \
        PreDebugController_Test/generalTest.cpp \
        PreDebugController_Test/upload_test.cpp \

INCLUDEPATH += \
    ../CPUDebugger/model \
    ../CPUDebugger/controller \
    ../CPUDebugger/parse-verilog \
    ../CPUDebugger/view \
    ../CPUDebugger

DISTFILES += \
    $$PWD/PreDebugController_Test/test_conf.ini

include(gtest_dependency.pri)
include(../CPUDebugger/model/model.pri)
include(../CPUDebugger/controller/controller.pri)
include(../CPUDebugger/parse-verilog/parse-verilog.pri)
include(../CPUDebugger/view/view.pri)
include(../CPUDebugger/Debugger.pri)
include(../CPUDebugger/uart.pri)
