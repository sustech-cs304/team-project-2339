QT += testlib
QT += gui-private
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += \
    ../CPUDebugger/model \
    ../CPUDebugger/controller \
    ../CPUDebugger/parse-verilog

include(../CPUDebugger/model/model.pri)
include(../CPUDebugger/controller/controller.pri)

SOURCES += \
    ../CPUDebugger/parse-verilog/lex.yy.cc \
    ../CPUDebugger/parse-verilog/verilog_parser.tab.cc \
    tst_model.cpp\

DISTFILES += \
    ../README.md \
    out.txt \
    top.v \
    top1.v

HEADERS += \
    ../CPUDebugger/parse-verilog/FlexLexer.h \
    ../CPUDebugger/parse-verilog/location.hh \
    ../CPUDebugger/parse-verilog/position.hh \
    ../CPUDebugger/parse-verilog/stack.hh \
    ../CPUDebugger/parse-verilog/verilog_data.hpp \
    ../CPUDebugger/parse-verilog/verilog_driver.hpp \
    ../CPUDebugger/parse-verilog/verilog_parser.tab.hh \
    ../CPUDebugger/parse-verilog/verilog_scanner.hpp
