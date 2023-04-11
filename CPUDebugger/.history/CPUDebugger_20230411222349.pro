QT += quick
QT += quickcontrols2

CONFIG += qmltypes
QML_IMPORT_NAME = MyObj
QML_IMPORT_MAJOR_VERSION = 1


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

<<<<<<< HEAD
include(Debugger.pri)
include(view.pri)
=======
INCLUDEPATH += \
    $$PWD/controller \
    $$PWD/view \
    $$PWD/uart \
    $$PWD/model


include($$PWD/controller/controller.pri)
include($$PWD/view/view.pri)
include($$PWD/uart/uart.pri)
include($$PWD/model/model.pri)
>>>>>>> read_dev
