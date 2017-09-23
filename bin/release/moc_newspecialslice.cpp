/****************************************************************************
** Meta object code from reading C++ file 'newspecialslice.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../tabspecialslice/newspecialslice.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newspecialslice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NewSpecialSlice_t {
    QByteArrayData data[5];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NewSpecialSlice_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NewSpecialSlice_t qt_meta_stringdata_NewSpecialSlice = {
    {
QT_MOC_LITERAL(0, 0, 15), // "NewSpecialSlice"
QT_MOC_LITERAL(1, 16, 10), // "sendSelect"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 23), // "on_pushButtonOk_clicked"
QT_MOC_LITERAL(4, 52, 27) // "on_pushButtonCancel_clicked"

    },
    "NewSpecialSlice\0sendSelect\0\0"
    "on_pushButtonOk_clicked\0"
    "on_pushButtonCancel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NewSpecialSlice[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   30,    2, 0x08 /* Private */,
       4,    0,   31,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NewSpecialSlice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NewSpecialSlice *_t = static_cast<NewSpecialSlice *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendSelect(); break;
        case 1: _t->on_pushButtonOk_clicked(); break;
        case 2: _t->on_pushButtonCancel_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NewSpecialSlice::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NewSpecialSlice::sendSelect)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject NewSpecialSlice::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_NewSpecialSlice.data,
      qt_meta_data_NewSpecialSlice,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NewSpecialSlice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NewSpecialSlice::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NewSpecialSlice.stringdata0))
        return static_cast<void*>(const_cast< NewSpecialSlice*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int NewSpecialSlice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void NewSpecialSlice::sendSelect()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
