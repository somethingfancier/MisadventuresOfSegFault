/****************************************************************************
** Meta object code from reading C++ file 'boss.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MSFGame/boss.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'boss.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Boss_t {
    QByteArrayData data[6];
    char stringdata[52];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Boss_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Boss_t qt_meta_stringdata_Boss = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Boss"
QT_MOC_LITERAL(1, 5, 4), // "move"
QT_MOC_LITERAL(2, 10, 0), // ""
QT_MOC_LITERAL(3, 11, 15), // "bounceAnimation"
QT_MOC_LITERAL(4, 27, 14), // "deathAnimation"
QT_MOC_LITERAL(5, 42, 9) // "setAttack"

    },
    "Boss\0move\0\0bounceAnimation\0deathAnimation\0"
    "setAttack"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Boss[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    0,   35,    2, 0x0a /* Public */,
       4,    0,   36,    2, 0x0a /* Public */,
       5,    0,   37,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Boss::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Boss *_t = static_cast<Boss *>(_o);
        switch (_id) {
        case 0: _t->move(); break;
        case 1: _t->bounceAnimation(); break;
        case 2: _t->deathAnimation(); break;
        case 3: _t->setAttack(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Boss::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Boss.data,
      qt_meta_data_Boss,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Boss::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Boss::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Boss.stringdata))
        return static_cast<void*>(const_cast< Boss*>(this));
    if (!strcmp(_clname, "QGraphicsPixmapItem"))
        return static_cast< QGraphicsPixmapItem*>(const_cast< Boss*>(this));
    return QObject::qt_metacast(_clname);
}

int Boss::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
