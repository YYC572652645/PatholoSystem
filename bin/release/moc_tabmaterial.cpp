/****************************************************************************
** Meta object code from reading C++ file 'tabmaterial.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../tabmaterial/tabmaterial.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tabmaterial.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TabMaterial_t {
    QByteArrayData data[13];
    char stringdata0[247];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TabMaterial_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TabMaterial_t qt_meta_stringdata_TabMaterial = {
    {
QT_MOC_LITERAL(0, 0, 11), // "TabMaterial"
QT_MOC_LITERAL(1, 12, 13), // "receiveSelect"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 13), // "receiveNumber"
QT_MOC_LITERAL(4, 41, 6), // "number"
QT_MOC_LITERAL(5, 48, 2), // "id"
QT_MOC_LITERAL(6, 51, 33), // "on_actionNormalMaterial_trigg..."
QT_MOC_LITERAL(7, 85, 28), // "on_actionAddBaoMai_triggered"
QT_MOC_LITERAL(8, 114, 29), // "on_actionPrintLabel_triggered"
QT_MOC_LITERAL(9, 144, 33), // "on_actionPrintMoreLabel_trigg..."
QT_MOC_LITERAL(10, 178, 34), // "on_actionAddBingLiNumber_trig..."
QT_MOC_LITERAL(11, 213, 27), // "on_treeWidget_doubleClicked"
QT_MOC_LITERAL(12, 241, 5) // "index"

    },
    "TabMaterial\0receiveSelect\0\0receiveNumber\0"
    "number\0id\0on_actionNormalMaterial_triggered\0"
    "on_actionAddBaoMai_triggered\0"
    "on_actionPrintLabel_triggered\0"
    "on_actionPrintMoreLabel_triggered\0"
    "on_actionAddBingLiNumber_triggered\0"
    "on_treeWidget_doubleClicked\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TabMaterial[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    2,   55,    2, 0x08 /* Private */,
       6,    0,   60,    2, 0x08 /* Private */,
       7,    0,   61,    2, 0x08 /* Private */,
       8,    0,   62,    2, 0x08 /* Private */,
       9,    0,   63,    2, 0x08 /* Private */,
      10,    0,   64,    2, 0x08 /* Private */,
      11,    1,   65,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   12,

       0        // eod
};

void TabMaterial::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TabMaterial *_t = static_cast<TabMaterial *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receiveSelect(); break;
        case 1: _t->receiveNumber((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->on_actionNormalMaterial_triggered(); break;
        case 3: _t->on_actionAddBaoMai_triggered(); break;
        case 4: _t->on_actionPrintLabel_triggered(); break;
        case 5: _t->on_actionPrintMoreLabel_triggered(); break;
        case 6: _t->on_actionAddBingLiNumber_triggered(); break;
        case 7: _t->on_treeWidget_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject TabMaterial::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TabMaterial.data,
      qt_meta_data_TabMaterial,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TabMaterial::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TabMaterial::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TabMaterial.stringdata0))
        return static_cast<void*>(const_cast< TabMaterial*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int TabMaterial::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
