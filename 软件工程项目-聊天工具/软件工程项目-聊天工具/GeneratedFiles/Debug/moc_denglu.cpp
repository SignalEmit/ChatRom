/****************************************************************************
** Meta object code from reading C++ file 'denglu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../denglu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'denglu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_denglu_t {
    QByteArrayData data[10];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_denglu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_denglu_t qt_meta_stringdata_denglu = {
    {
QT_MOC_LITERAL(0, 0, 6), // "denglu"
QT_MOC_LITERAL(1, 7, 9), // "showzhuce"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 14), // "showwangjimima"
QT_MOC_LITERAL(4, 33, 11), // "sendMessage"
QT_MOC_LITERAL(5, 45, 14), // "receiveMessage"
QT_MOC_LITERAL(6, 60, 10), // "newConnect"
QT_MOC_LITERAL(7, 71, 12), // "displayError"
QT_MOC_LITERAL(8, 84, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(9, 113, 19) // "on_denglubt_clicked"

    },
    "denglu\0showzhuce\0\0showwangjimima\0"
    "sendMessage\0receiveMessage\0newConnect\0"
    "displayError\0QAbstractSocket::SocketError\0"
    "on_denglubt_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_denglu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    1,   54,    2, 0x08 /* Private */,
       9,    0,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void,

       0        // eod
};

void denglu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        denglu *_t = static_cast<denglu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showzhuce(); break;
        case 1: _t->showwangjimima(); break;
        case 2: _t->sendMessage(); break;
        case 3: _t->receiveMessage(); break;
        case 4: _t->newConnect(); break;
        case 5: _t->displayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 6: _t->on_denglubt_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

const QMetaObject denglu::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_denglu.data,
      qt_meta_data_denglu,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *denglu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *denglu::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_denglu.stringdata0))
        return static_cast<void*>(const_cast< denglu*>(this));
    if (!strcmp(_clname, "Ui_dengluClass"))
        return static_cast< Ui_dengluClass*>(const_cast< denglu*>(this));
    return QWidget::qt_metacast(_clname);
}

int denglu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
