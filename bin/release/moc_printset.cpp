/****************************************************************************
** Meta object code from reading C++ file 'printset.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../tabsystemset/otherwidget/printset.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'printset.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PrintSet_t {
    QByteArrayData data[12];
    char stringdata0[189];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PrintSet_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PrintSet_t qt_meta_stringdata_PrintSet = {
    {
QT_MOC_LITERAL(0, 0, 8), // "PrintSet"
QT_MOC_LITERAL(1, 9, 11), // "receiveData"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 16), // "typeAbbreviation"
QT_MOC_LITERAL(4, 39, 8), // "typeName"
QT_MOC_LITERAL(5, 48, 4), // "type"
QT_MOC_LITERAL(6, 53, 24), // "on_pushButtonNew_clicked"
QT_MOC_LITERAL(7, 78, 27), // "on_pushButtonDelete_clicked"
QT_MOC_LITERAL(8, 106, 27), // "on_pushButtonUpdate_clicked"
QT_MOC_LITERAL(9, 134, 25), // "on_pushButtonExit_clicked"
QT_MOC_LITERAL(10, 160, 22), // "on_tableWidget_clicked"
QT_MOC_LITERAL(11, 183, 5) // "index"

    },
    "PrintSet\0receiveData\0\0typeAbbreviation\0"
    "typeName\0type\0on_pushButtonNew_clicked\0"
    "on_pushButtonDelete_clicked\0"
    "on_pushButtonUpdate_clicked\0"
    "on_pushButtonExit_clicked\0"
    "on_tableWidget_clicked\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PrintSet[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   44,    2, 0x08 /* Private */,
       6,    0,   51,    2, 0x08 /* Private */,
       7,    0,   52,    2, 0x08 /* Private */,
       8,    0,   53,    2, 0x08 /* Private */,
       9,    0,   54,    2, 0x08 /* Private */,
      10,    1,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    3,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   11,

       0        // eod
};

void PrintSet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PrintSet *_t = static_cast<PrintSet *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receiveData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->on_pushButtonNew_clicked(); break;
        case 2: _t->on_pushButtonDelete_clicked(); break;
        case 3: _t->on_pushButtonUpdate_clicked(); break;
        case 4: _t->on_pushButtonExit_clicked(); break;
        case 5: _t->on_tableWidget_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject PrintSet::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PrintSet.data,
      qt_meta_data_PrintSet,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PrintSet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PrintSet::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PrintSet.stringdata0))
        return static_cast<void*>(const_cast< PrintSet*>(this));
    return QWidget::qt_metacast(_clname);
}

int PrintSet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
