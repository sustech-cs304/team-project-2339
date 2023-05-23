
QT += quickcontrols2
QT += serialport

QML_IMPORT_NAME = MyObj
QML_IMPORT_MAJOR_VERSION = 1

QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_LFLAGS += --coverage -g -O0

CONFIG += console c++17
CONFIG -= app_bundle
CONFIG += thread

SOURCES += \
        main.cpp \
        tst_importfile.cpp \
        tst_uart.cpp

INCLUDEPATH += \
    ../CPUDebugger/model \
    ../CPUDebugger/controller \
    ../CPUDebugger/parse-verilog \
    ../CPUDebugger/view \
    ../CPUDebugger \

LIBS += -lgcov


include(../CPUDebugger/model/model.pri)
include(../CPUDebugger/controller/controller.pri)
include(../CPUDebugger/parse-verilog/parse-verilog.pri)
include(../CPUDebugger/view/view.pri)
include(../CPUDebugger/Debugger.pri)
include(../CPUDebugger/uart.pri)
include(gtest_dependency.pri)
