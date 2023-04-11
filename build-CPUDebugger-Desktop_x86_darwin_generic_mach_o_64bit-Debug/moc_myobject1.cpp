/****************************************************************************
** Meta object code from reading C++ file 'myobject1.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../CPUDebugger/myobject1.h"
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myobject1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_MyObject1_t {
    uint offsetsAndSizes[30];
    char stringdata0[10];
    char stringdata1[12];
    char stringdata2[5];
    char stringdata3[13];
    char stringdata4[1];
    char stringdata5[14];
    char stringdata6[14];
    char stringdata7[11];
    char stringdata8[15];
    char stringdata9[8];
    char stringdata10[7];
    char stringdata11[9];
    char stringdata12[6];
    char stringdata13[7];
    char stringdata14[7];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MyObject1_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MyObject1_t qt_meta_stringdata_MyObject1 = {
    {
        QT_MOC_LITERAL(0, 9),  // "MyObject1"
        QT_MOC_LITERAL(10, 11),  // "QML.Element"
        QT_MOC_LITERAL(22, 4),  // "auto"
        QT_MOC_LITERAL(27, 12),  // "valueChanged"
        QT_MOC_LITERAL(40, 0),  // ""
        QT_MOC_LITERAL(41, 13),  // "stringChanged"
        QT_MOC_LITERAL(55, 13),  // "value1Changed"
        QT_MOC_LITERAL(69, 10),  // "getAsmFile"
        QT_MOC_LITERAL(80, 14),  // "makeBreakPoint"
        QT_MOC_LITERAL(95, 7),  // "asmStep"
        QT_MOC_LITERAL(103, 6),  // "asmRun"
        QT_MOC_LITERAL(110, 8),  // "asmPause"
        QT_MOC_LITERAL(119, 5),  // "value"
        QT_MOC_LITERAL(125, 6),  // "string"
        QT_MOC_LITERAL(132, 6)   // "value1"
    },
    "MyObject1",
    "QML.Element",
    "auto",
    "valueChanged",
    "",
    "stringChanged",
    "value1Changed",
    "getAsmFile",
    "makeBreakPoint",
    "asmStep",
    "asmRun",
    "asmPause",
    "value",
    "string",
    "value1"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MyObject1[] = {

 // content:
      10,       // revision
       0,       // classname
       1,   14, // classinfo
       8,   16, // methods
       3,   72, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   64,    4, 0x06,    4 /* Public */,
       5,    0,   65,    4, 0x06,    5 /* Public */,
       6,    0,   66,    4, 0x06,    6 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   67,    4, 0x02,    7 /* Public */,
       8,    0,   68,    4, 0x02,    8 /* Public */,
       9,    0,   69,    4, 0x02,    9 /* Public */,
      10,    0,   70,    4, 0x02,   10 /* Public */,
      11,    0,   71,    4, 0x02,   11 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      12, QMetaType::Int, 0x00015103, uint(0), 0,
      13, QMetaType::QString, 0x00015103, uint(1), 0,
      14, QMetaType::Int, 0x00015103, uint(2), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject MyObject1::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_MyObject1.offsetsAndSizes,
    qt_meta_data_MyObject1,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // property 'value'
        int,
        // property 'string'
        QString,
        // property 'value1'
        int,
        // Q_OBJECT / Q_GADGET
        MyObject1,
        // method 'valueChanged'
        void,
        // method 'stringChanged'
        void,
        // method 'value1Changed'
        void,
        // method 'getAsmFile'
        void,
        // method 'makeBreakPoint'
        void,
        // method 'asmStep'
        void,
        // method 'asmRun'
        void,
        // method 'asmPause'
        void
    >,
    nullptr
} };

void MyObject1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyObject1 *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->valueChanged(); break;
        case 1: _t->stringChanged(); break;
        case 2: _t->value1Changed(); break;
        case 3: _t->getAsmFile(); break;
        case 4: _t->makeBreakPoint(); break;
        case 5: _t->asmStep(); break;
        case 6: _t->asmRun(); break;
        case 7: _t->asmPause(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyObject1::*)();
            if (_t _q_method = &MyObject1::valueChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MyObject1::*)();
            if (_t _q_method = &MyObject1::stringChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MyObject1::*)();
            if (_t _q_method = &MyObject1::value1Changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<MyObject1 *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->value(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->string(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->value1(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<MyObject1 *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setValue(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setString(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setValue1(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
    (void)_a;
}

const QMetaObject *MyObject1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyObject1::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyObject1.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MyObject1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void MyObject1::valueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MyObject1::stringChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MyObject1::value1Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
