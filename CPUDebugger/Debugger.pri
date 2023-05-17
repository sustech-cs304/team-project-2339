SOURCES += \
        $$PWD/Stores/DebugStore.cpp \
        $$PWD/Stores/PreDebugStore.cpp \
        $$PWD/utils/utils.cpp \
        Controllers/DebugController.cpp \
        Controllers/PreDebugController.cpp \
        File/AsmFile.cpp
HEADERS += \
    Controllers/DebugController.h \
    Controllers/PreDebugController.h \
    File/AsmFile.h \
    Stores/DebugStore.h \
    Stores/PreDebugStore.h \
    utils/utils.h

DISTFILES += \
    $$PWD/CodeDetails.md \
