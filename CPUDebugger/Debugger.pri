SOURCES += \
        $$PWD/Comm/comm.cpp \
        $$PWD/Comm/sender.cpp \
        Controllers/DebugController.cpp \
        Controllers/PreDebugController.cpp \
        File/AsmFile.cpp \
        File/CoeFile.cpp \
        File/DebugFile.cpp \
        Stores/DebugStore.cpp \
        Stores/PreDebugStore.cpp \
        uart/UartSimulator.cpp

HEADERS += \
    $$PWD/Comm/comm.h \
    $$PWD/Comm/sender.h \
    Controllers/DebugController.h \
    Controllers/PreDebugController.h \
    File/AsmFile.h \
    File/CoeFile.h \
    File/DebugFile.h \
    Stores/DebugStore.h \
    Stores/PreDebugStore.h \
    uart/UartSimulator.h \
    utils/utils.h
