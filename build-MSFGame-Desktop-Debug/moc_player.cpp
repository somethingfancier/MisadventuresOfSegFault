/****************************************************************************
** Meta object code from reading C++ file 'player.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MSFGame/player.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'player.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Player_t {
    QByteArrayData data[16];
    char stringdata[197];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Player_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Player_t qt_meta_stringdata_Player = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Player"
QT_MOC_LITERAL(1, 7, 10), // "timerHitUp"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 12), // "timerHitDown"
QT_MOC_LITERAL(4, 32, 12), // "timerHitLeft"
QT_MOC_LITERAL(5, 45, 13), // "timerHitRight"
QT_MOC_LITERAL(6, 59, 11), // "timerAnimUp"
QT_MOC_LITERAL(7, 71, 13), // "timerAnimDown"
QT_MOC_LITERAL(8, 85, 13), // "timerAnimLeft"
QT_MOC_LITERAL(9, 99, 14), // "timerAnimRight"
QT_MOC_LITERAL(10, 114, 12), // "timerSwordUp"
QT_MOC_LITERAL(11, 127, 14), // "timerSwordDown"
QT_MOC_LITERAL(12, 142, 14), // "timerSwordLeft"
QT_MOC_LITERAL(13, 157, 15), // "timerSwordRight"
QT_MOC_LITERAL(14, 173, 9), // "timerCool"
QT_MOC_LITERAL(15, 183, 13) // "updateDisplay"

    },
    "Player\0timerHitUp\0\0timerHitDown\0"
    "timerHitLeft\0timerHitRight\0timerAnimUp\0"
    "timerAnimDown\0timerAnimLeft\0timerAnimRight\0"
    "timerSwordUp\0timerSwordDown\0timerSwordLeft\0"
    "timerSwordRight\0timerCool\0updateDisplay"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Player[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    0,   91,    2, 0x08 /* Private */,
      10,    0,   92,    2, 0x08 /* Private */,
      11,    0,   93,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    0,   96,    2, 0x08 /* Private */,
      15,    0,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Player::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Player *_t = static_cast<Player *>(_o);
        switch (_id) {
        case 0: _t->timerHitUp(); break;
        case 1: _t->timerHitDown(); break;
        case 2: _t->timerHitLeft(); break;
        case 3: _t->timerHitRight(); break;
        case 4: _t->timerAnimUp(); break;
        case 5: _t->timerAnimDown(); break;
        case 6: _t->timerAnimLeft(); break;
        case 7: _t->timerAnimRight(); break;
        case 8: _t->timerSwordUp(); break;
        case 9: _t->timerSwordDown(); break;
        case 10: _t->timerSwordLeft(); break;
        case 11: _t->timerSwordRight(); break;
        case 12: _t->timerCool(); break;
        case 13: _t->updateDisplay(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Player::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Player.data,
      qt_meta_data_Player,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Player::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Player::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Player.stringdata))
        return static_cast<void*>(const_cast< Player*>(this));
    if (!strcmp(_clname, "QGraphicsPixmapItem"))
        return static_cast< QGraphicsPixmapItem*>(const_cast< Player*>(this));
    return QObject::qt_metacast(_clname);
}

int Player::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
