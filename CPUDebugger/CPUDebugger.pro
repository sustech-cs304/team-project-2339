QT += quick

SOURCES += \
        Controllers/DebugController.cpp \
        Controllers/PreDebugController.cpp \
        File/AsmFile.cpp \
        File/CoeFile.cpp \
        File/DebugFile.cpp \
        main.cpp \
        uart/UartSimulator.cpp

TRANSLATIONS += \
    CPUDebugger_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Controllers/DebugController.h \
    Controllers/PreDebugController.h \
    File/AsmFile.h \
    File/CoeFile.h \
    File/DebugFile.h \
    uart/UartSimulator.h
