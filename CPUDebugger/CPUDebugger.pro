QT += quick
QT += serialport

TRANSLATIONS += \
    CPUDebugger_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

include(Debugger.pri)
include(gtest_dependency.pri)
include (uart.pri)

SOURCES += \
    PreDebugController_Test/compiler_test.cpp \
    main.cpp \
    test.cpp \
    tst_case1.cpp \
    PreDebugController_Test/upload_test.cpp


