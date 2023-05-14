QT += quick
QT += quickcontrols2
QT += gui-private
QT += serialport

CONFIG += qmltypes
QML_IMPORT_NAME = MyObj
QML_IMPORT_MAJOR_VERSION = 1

SOURCES += \
        main.cpp \


resources.files = main.qml
resources.prefix = /$${TARGET}
RESOURCES += resources

#LEXSOURCES = verilog_lexer.l

#YACCSOURCES = verilog_parser.yy

#QMAKE_EXT_LEX = flex
#QMAKE_EXT_YACC = bison

TRANSLATIONS += \
        CPUDebugger_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += \
    $$PWD/controller \
    $$PWD/view \
    $$PWD/uart \
    $$PWD/model \
    $$PWD/parse-verilog


include($$PWD/controller/controller.pri)
include($$PWD/view/view.pri)
include($$PWD/uart/uart.pri)
include($$PWD/model/model.pri)
include($$PWD/Debugger.pri)
include($$PWD/parse-verilog/parse-verilog.pri)

DISTFILES += \
    parse-verilog/verilog_lexer.l \
    parse-verilog/verilog_parser.yy
