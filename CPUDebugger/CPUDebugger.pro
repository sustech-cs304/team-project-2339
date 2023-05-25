QT += quick
QT += quickcontrols2
QT += gui-private
QT += serialport

CONFIG += qmltypes
QML_IMPORT_NAME = MyObj
QML_IMPORT_MAJOR_VERSION = 1
QMAKE_CXXFLAGS += -std=c++17

TRANSLATIONS += \
        CPUDebugger_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

include(gtest_dependency.pri)
include($$PWD/uart.pri)
include($$PWD/parse-verilog/parse-verilog.pri)
include($$PWD/controller/controller.pri)
include($$PWD/view/view.pri)
include($$PWD/model/model.pri)
include($$PWD/Debugger.pri)

SOURCES += \
    main.cpp \

INCLUDEPATH += \
    $$PWD/controller \
    $$PWD/view \
    $$PWD/model \
    $$PWD/parse-verilog

DISTFILES += \
    $$PWD/CodeDetails.md \
    CPUDebugger.pdocconf



