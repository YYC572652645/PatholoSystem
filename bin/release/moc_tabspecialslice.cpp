/****************************************************************************
** Meta object code from reading C++ file 'tabspecialslice.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../tabspecialslice/tabspecialslice.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tabspecialslice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TabSpeciaSlice_t {
    QByteArrayData data[13];
    char stringdata0[280];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TabSpeciaSlice_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TabSpeciaSlice_t qt_meta_stringdata_TabSpeciaSlice = {
    {
QT_MOC_LITERAL(0, 0, 14), // "TabSpeciaSlice"
QT_MOC_LITERAL(1, 15, 13), // "receiveSelect"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 11), // "updateMovie"
QT_MOC_LITERAL(4, 42, 27), // "on_actionNewSlice_triggered"
QT_MOC_LITERAL(5, 70, 26), // "on_actionNewMore_triggered"
QT_MOC_LITERAL(6, 97, 29), // "on_actionPrintLabel_triggered"
QT_MOC_LITERAL(7, 127, 29), // "on_actionDeleteInfo_triggered"
QT_MOC_LITERAL(8, 157, 32), // "on_actionPrintTemplate_triggered"
QT_MOC_LITERAL(9, 190, 28), // "on_pushButtonRefresh_clicked"
QT_MOC_LITERAL(10, 219, 28), // "on_tableWidget_doubleClicked"
QT_MOC_LITERAL(11, 248, 5), // "index"
QT_MOC_LITERAL(12, 254, 25) // "on_pushButtonFind_clicked"

    },
    "TabSpeciaSlice\0receiveSelect\0\0updateMovie\0"
    "on_actionNewSlice_triggered\0"
    "on_actionNewMore_triggered\0"
    "on_actionPrintLabel_triggered\0"
    "on_actionDeleteInfo_triggered\0"
    "on_actionPrintTemplate_triggered\0"
    "on_pushButtonRefresh_clicked\0"
    "on_tableWidget_doubleClicked\0index\0"
    "on_pushButtonFind_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TabSpeciaSlice[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    1,   72,    2, 0x08 /* Private */,
      12,    0,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   11,
    QMetaType::Void,

       0        // eod
};

void TabSpeciaSlice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TabSpeciaSlice *_t = static_cast<TabSpeciaSlice *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receiveSelect(); break;
        case 1: _t->updateMovie(); break;
        case 2: _t->on_actionNewSlice_triggered(); break;
        case 3: _t->on_actionNewMore_triggered(); break;
        case 4: _t->on_actionPrintLabel_triggered(); break;
        case 5: _t->on_actionDeleteInfo_triggered(); break;
        case 6: _t->on_actionPrintTemplate_triggered(); break;
        case 7: _t->on_pushButtonRefresh_clicked(); break;
        case 8: _t->on_tableWidget_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 9: _t->on_pushButtonFind_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject TabSpeciaSlice::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TabSpeciaSlice.data,
      qt_meta_data_TabSpeciaSlice,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TabSpeciaSlice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TabSpeciaSlice::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TabSpeciaSlice.stringdata0))
        return static_cast<void*>(const_cast< TabSpeciaSlice*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int TabSpeciaSlice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
