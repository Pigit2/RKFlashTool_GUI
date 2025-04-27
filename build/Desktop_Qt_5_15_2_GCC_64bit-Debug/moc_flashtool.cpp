/****************************************************************************
** Meta object code from reading C++ file 'flashtool.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../flashtool.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'flashtool.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FlashTool_t {
    QByteArrayData data[21];
    char stringdata0[210];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FlashTool_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FlashTool_t qt_meta_stringdata_FlashTool = {
    {
QT_MOC_LITERAL(0, 0, 9), // "FlashTool"
QT_MOC_LITERAL(1, 10, 9), // "updateLog"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 7), // "message"
QT_MOC_LITERAL(4, 29, 9), // "addDevice"
QT_MOC_LITERAL(5, 39, 6), // "device"
QT_MOC_LITERAL(6, 46, 11), // "showWarning"
QT_MOC_LITERAL(7, 58, 5), // "title"
QT_MOC_LITERAL(8, 64, 20), // "flashProgressChanged"
QT_MOC_LITERAL(9, 85, 8), // "progress"
QT_MOC_LITERAL(10, 94, 11), // "flashStatus"
QT_MOC_LITERAL(11, 106, 11), // "FlashStatus"
QT_MOC_LITERAL(12, 118, 6), // "status"
QT_MOC_LITERAL(13, 125, 13), // "detectDevices"
QT_MOC_LITERAL(14, 139, 14), // "rebootToLoader"
QT_MOC_LITERAL(15, 154, 13), // "flashFirmware"
QT_MOC_LITERAL(16, 168, 12), // "firmwarePath"
QT_MOC_LITERAL(17, 181, 4), // "Idle"
QT_MOC_LITERAL(18, 186, 8), // "Flashing"
QT_MOC_LITERAL(19, 195, 7), // "Success"
QT_MOC_LITERAL(20, 203, 6) // "Failed"

    },
    "FlashTool\0updateLog\0\0message\0addDevice\0"
    "device\0showWarning\0title\0flashProgressChanged\0"
    "progress\0flashStatus\0FlashStatus\0"
    "status\0detectDevices\0rebootToLoader\0"
    "flashFirmware\0firmwarePath\0Idle\0"
    "Flashing\0Success\0Failed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FlashTool[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       1,   76, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       6,    2,   60,    2, 0x06 /* Public */,
       8,    1,   65,    2, 0x06 /* Public */,
      10,    1,   68,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
      13,    0,   71,    2, 0x02 /* Public */,
      14,    0,   72,    2, 0x02 /* Public */,
      15,    1,   73,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    7,    3,
    QMetaType::Void, QMetaType::Float,    9,
    QMetaType::Void, 0x80000000 | 11,   12,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   16,

 // enums: name, alias, flags, count, data
      11,   11, 0x0,    4,   81,

 // enum data: key, value
      17, uint(FlashTool::Idle),
      18, uint(FlashTool::Flashing),
      19, uint(FlashTool::Success),
      20, uint(FlashTool::Failed),

       0        // eod
};

void FlashTool::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FlashTool *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateLog((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->addDevice((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->showWarning((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: _t->flashProgressChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 4: _t->flashStatus((*reinterpret_cast< FlashStatus(*)>(_a[1]))); break;
        case 5: _t->detectDevices(); break;
        case 6: _t->rebootToLoader(); break;
        case 7: _t->flashFirmware((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FlashTool::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FlashTool::updateLog)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FlashTool::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FlashTool::addDevice)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FlashTool::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FlashTool::showWarning)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FlashTool::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FlashTool::flashProgressChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (FlashTool::*)(FlashStatus );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FlashTool::flashStatus)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FlashTool::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_FlashTool.data,
    qt_meta_data_FlashTool,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FlashTool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FlashTool::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FlashTool.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FlashTool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void FlashTool::updateLog(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FlashTool::addDevice(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FlashTool::showWarning(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FlashTool::flashProgressChanged(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void FlashTool::flashStatus(FlashStatus _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
