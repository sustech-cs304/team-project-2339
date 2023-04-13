/****************************************************************************
** Generated QML type registration code
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/qqmlmoduleregistration.h>

#include <myobject1.h>

#if !defined(QT_STATIC)
#define Q_QMLTYPE_EXPORT Q_DECL_EXPORT
#else
#define Q_QMLTYPE_EXPORT
#endif

Q_QMLTYPE_EXPORT void qml_register_types_MyObj()
{
    qmlRegisterTypesAndRevisions<MyObject1>("MyObj", 1);
    qmlRegisterModule("MyObj", 1, 0);
}

static const QQmlModuleRegistration registration("MyObj", qml_register_types_MyObj);
