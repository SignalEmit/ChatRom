/****************************************************************************
** Meta object code from reading C++ file 'xiugaixingxi.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../xiugaixingxi.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'xiugaixingxi.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_xiugaixingxi_t {
    QByteArrayData data[14];
    char stringdata0[191];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_xiugaixingxi_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_xiugaixingxi_t qt_meta_stringdata_xiugaixingxi = {
    {
QT_MOC_LITERAL(0, 0, 12), // "xiugaixingxi"
QT_MOC_LITERAL(1, 13, 17), // "xiugaixinxixinhao"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 3), // "Sex"
QT_MOC_LITERAL(4, 36, 8), // "NickName"
QT_MOC_LITERAL(5, 45, 21), // "PersonalizedSignature"
QT_MOC_LITERAL(6, 67, 15), // "Display_picture"
QT_MOC_LITERAL(7, 83, 12), // "displayError"
QT_MOC_LITERAL(8, 96, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(9, 125, 11), // "sendMessage"
QT_MOC_LITERAL(10, 137, 18), // "on_queding_clicked"
QT_MOC_LITERAL(11, 156, 14), // "Xiugai_Display"
QT_MOC_LITERAL(12, 171, 7), // "qingchu"
QT_MOC_LITERAL(13, 179, 11) // "radioChange"

    },
    "xiugaixingxi\0xiugaixinxixinhao\0\0Sex\0"
    "NickName\0PersonalizedSignature\0"
    "Display_picture\0displayError\0"
    "QAbstractSocket::SocketError\0sendMessage\0"
    "on_queding_clicked\0Xiugai_Display\0"
    "qingchu\0radioChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_xiugaixingxi[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   58,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,
      10,    0,   62,    2, 0x08 /* Private */,
      11,    0,   63,    2, 0x08 /* Private */,
      12,    0,   64,    2, 0x08 /* Private */,
      13,    0,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void xiugaixingxi::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        xiugaixingxi *_t = static_cast<xiugaixingxi *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->xiugaixinxixinhao((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 1: _t->displayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 2: _t->sendMessage(); break;
        case 3: _t->on_queding_clicked(); break;
        case 4: _t->Xiugai_Display(); break;
        case 5: _t->qingchu(); break;
        case 6: _t->radioChange(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (xiugaixingxi::*_t)(QString , QString , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&xiugaixingxi::xiugaixinxixinhao)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject xiugaixingxi::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_xiugaixingxi.data,
      qt_meta_data_xiugaixingxi,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *xiugaixingxi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *xiugaixingxi::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_xiugaixingxi.stringdata0))
        return static_cast<void*>(const_cast< xiugaixingxi*>(this));
    if (!strcmp(_clname, "Ui_xiugaixingxi"))
        return static_cast< Ui_xiugaixingxi*>(const_cast< xiugaixingxi*>(this));
    return QWidget::qt_metacast(_clname);
}

int xiugaixingxi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void xiugaixingxi::xiugaixinxixinhao(QString _t1, QString _t2, QString _t3, QString _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
