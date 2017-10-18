/****************************************************************************
** Meta object code from reading C++ file 'dengluview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../dengluview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dengluview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_dengluview_t {
    QByteArrayData data[21];
    char stringdata0[332];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dengluview_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dengluview_t qt_meta_stringdata_dengluview = {
    {
QT_MOC_LITERAL(0, 0, 10), // "dengluview"
QT_MOC_LITERAL(1, 11, 11), // "CloseSignal"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 8), // "TimeStar"
QT_MOC_LITERAL(4, 33, 7), // "TimeEnd"
QT_MOC_LITERAL(5, 41, 16), // "closesendMessage"
QT_MOC_LITERAL(6, 58, 19), // "closereceiveMessage"
QT_MOC_LITERAL(7, 78, 15), // "closeNewConnect"
QT_MOC_LITERAL(8, 94, 28), // "receiveUserInformationSignal"
QT_MOC_LITERAL(9, 123, 20), // "sendStatisticsNumber"
QT_MOC_LITERAL(10, 144, 17), // "receiveNoteNumber"
QT_MOC_LITERAL(11, 162, 11), // "sendMessage"
QT_MOC_LITERAL(12, 174, 14), // "receiveMessage"
QT_MOC_LITERAL(13, 189, 10), // "newConnect"
QT_MOC_LITERAL(14, 200, 12), // "displayError"
QT_MOC_LITERAL(15, 213, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(16, 242, 14), // "sendAddSeccess"
QT_MOC_LITERAL(17, 257, 11), // "dealWithAdd"
QT_MOC_LITERAL(18, 269, 18), // "on_tianjia_clicked"
QT_MOC_LITERAL(19, 288, 21), // "on_touxiangbt_clicked"
QT_MOC_LITERAL(20, 310, 21) // "TurnIntoChatInterface"

    },
    "dengluview\0CloseSignal\0\0TimeStar\0"
    "TimeEnd\0closesendMessage\0closereceiveMessage\0"
    "closeNewConnect\0receiveUserInformationSignal\0"
    "sendStatisticsNumber\0receiveNoteNumber\0"
    "sendMessage\0receiveMessage\0newConnect\0"
    "displayError\0QAbstractSocket::SocketError\0"
    "sendAddSeccess\0dealWithAdd\0"
    "on_tianjia_clicked\0on_touxiangbt_clicked\0"
    "TurnIntoChatInterface"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dengluview[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,  105,    2, 0x08 /* Private */,
       4,    0,  106,    2, 0x08 /* Private */,
       5,    0,  107,    2, 0x08 /* Private */,
       6,    0,  108,    2, 0x08 /* Private */,
       7,    0,  109,    2, 0x08 /* Private */,
       8,    4,  110,    2, 0x08 /* Private */,
       9,    0,  119,    2, 0x08 /* Private */,
      10,    0,  120,    2, 0x08 /* Private */,
      11,    0,  121,    2, 0x08 /* Private */,
      12,    0,  122,    2, 0x08 /* Private */,
      13,    0,  123,    2, 0x08 /* Private */,
      14,    1,  124,    2, 0x08 /* Private */,
      16,    0,  127,    2, 0x08 /* Private */,
      17,    0,  128,    2, 0x08 /* Private */,
      18,    0,  129,    2, 0x08 /* Private */,
      19,    0,  130,    2, 0x08 /* Private */,
      20,    0,  131,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void dengluview::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        dengluview *_t = static_cast<dengluview *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CloseSignal(); break;
        case 1: _t->TimeStar(); break;
        case 2: _t->TimeEnd(); break;
        case 3: _t->closesendMessage(); break;
        case 4: _t->closereceiveMessage(); break;
        case 5: _t->closeNewConnect(); break;
        case 6: _t->receiveUserInformationSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 7: _t->sendStatisticsNumber(); break;
        case 8: _t->receiveNoteNumber(); break;
        case 9: _t->sendMessage(); break;
        case 10: _t->receiveMessage(); break;
        case 11: _t->newConnect(); break;
        case 12: _t->displayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 13: _t->sendAddSeccess(); break;
        case 14: _t->dealWithAdd(); break;
        case 15: _t->on_tianjia_clicked(); break;
        case 16: _t->on_touxiangbt_clicked(); break;
        case 17: _t->TurnIntoChatInterface(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 12:
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
            typedef void (dengluview::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&dengluview::CloseSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject dengluview::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_dengluview.data,
      qt_meta_data_dengluview,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *dengluview::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dengluview::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_dengluview.stringdata0))
        return static_cast<void*>(const_cast< dengluview*>(this));
    if (!strcmp(_clname, "Ui_dengluview"))
        return static_cast< Ui_dengluview*>(const_cast< dengluview*>(this));
    return QWidget::qt_metacast(_clname);
}

int dengluview::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void dengluview::CloseSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
