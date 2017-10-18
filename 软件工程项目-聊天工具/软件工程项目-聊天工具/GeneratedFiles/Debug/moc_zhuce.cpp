/****************************************************************************
** Meta object code from reading C++ file 'zhuce.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../zhuce.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'zhuce.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_zhuce_t {
    QByteArrayData data[8];
    char stringdata0[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_zhuce_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_zhuce_t qt_meta_stringdata_zhuce = {
    {
QT_MOC_LITERAL(0, 0, 5), // "zhuce"
QT_MOC_LITERAL(1, 6, 11), // "sendMessage"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 14), // "receiveMessage"
QT_MOC_LITERAL(4, 34, 10), // "newConnect"
QT_MOC_LITERAL(5, 45, 12), // "displayError"
QT_MOC_LITERAL(6, 58, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(7, 87, 26) // "on_zhuce_quedingbt_clicked"

    },
    "zhuce\0sendMessage\0\0receiveMessage\0"
    "newConnect\0displayError\0"
    "QAbstractSocket::SocketError\0"
    "on_zhuce_quedingbt_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_zhuce[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    1,   42,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void,

       0        // eod
};

void zhuce::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        zhuce *_t = static_cast<zhuce *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendMessage(); break;
        case 1: _t->receiveMessage(); break;
        case 2: _t->newConnect(); break;
        case 3: _t->displayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 4: _t->on_zhuce_quedingbt_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

const QMetaObject zhuce::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_zhuce.data,
      qt_meta_data_zhuce,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *zhuce::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *zhuce::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_zhuce.stringdata0))
        return static_cast<void*>(const_cast< zhuce*>(this));
    if (!strcmp(_clname, "Ui_zhuce"))
        return static_cast< Ui_zhuce*>(const_cast< zhuce*>(this));
    return QWidget::qt_metacast(_clname);
}

int zhuce::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
