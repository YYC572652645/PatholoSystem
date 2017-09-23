/****************************************************************************
** Meta object code from reading C++ file 'typesetdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../tabsystemset/otherwidget/typesetdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'typesetdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TypeSetDialog_t {
    QByteArrayData data[5];
    char stringdata0[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TypeSetDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TypeSetDialog_t qt_meta_stringdata_TypeSetDialog = {
    {
QT_MOC_LITERAL(0, 0, 13), // "TypeSetDialog"
QT_MOC_LITERAL(1, 14, 10), // "sendString"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 23), // "on_pushButtonOk_clicked"
QT_MOC_LITERAL(4, 50, 27) // "on_pushButtonCancel_clicked"

    },
    "TypeSetDialog\0sendString\0\0"
    "on_pushButtonOk_clicked\0"
    "on_pushButtonCancel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TypeSetDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   34,    2, 0x06 /* Public */,
       1,    2,   41,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   46,    2, 0x08 /* Private */,
       4,    0,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TypeSetDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TypeSetDialog *_t = static_cast<TypeSetDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendString((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->sendString((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->on_pushButtonOk_clicked(); break;
        case 3: _t->on_pushButtonCancel_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TypeSetDialog::*_t)(QString , QString , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TypeSetDialog::sendString)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (TypeSetDialog::*_t)(QString , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TypeSetDialog::sendString)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject TypeSetDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_TypeSetDialog.data,
      qt_meta_data_TypeSetDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TypeSetDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TypeSetDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TypeSetDialog.stringdata0))
        return static_cast<void*>(const_cast< TypeSetDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int TypeSetDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void TypeSetDialog::sendString(QString _t1, QString _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TypeSetDialog::sendString(QString _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
