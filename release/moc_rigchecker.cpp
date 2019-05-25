/****************************************************************************
** Meta object code from reading C++ file 'rigchecker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../rigchecker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rigchecker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RIGChecker_t {
    QByteArrayData data[16];
    char stringdata0[215];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RIGChecker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RIGChecker_t qt_meta_stringdata_RIGChecker = {
    {
QT_MOC_LITERAL(0, 0, 10), // "RIGChecker"
QT_MOC_LITERAL(1, 11, 8), // "RIGCrash"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 9), // "sendInput"
QT_MOC_LITERAL(4, 31, 2), // "in"
QT_MOC_LITERAL(5, 34, 13), // "RIGCheckStart"
QT_MOC_LITERAL(6, 48, 12), // "terminateRIG"
QT_MOC_LITERAL(7, 61, 18), // "on_loadRIG_clicked"
QT_MOC_LITERAL(8, 80, 33), // "on_iterationsLine_editingFini..."
QT_MOC_LITERAL(9, 114, 6), // "setRIG"
QT_MOC_LITERAL(10, 121, 16), // "on_check_clicked"
QT_MOC_LITERAL(11, 138, 23), // "executionFailedReceived"
QT_MOC_LITERAL(12, 162, 7), // "crashed"
QT_MOC_LITERAL(13, 170, 17), // "RIGOutputReceived"
QT_MOC_LITERAL(14, 188, 6), // "output"
QT_MOC_LITERAL(15, 195, 19) // "loaderErrorReceived"

    },
    "RIGChecker\0RIGCrash\0\0sendInput\0in\0"
    "RIGCheckStart\0terminateRIG\0"
    "on_loadRIG_clicked\0on_iterationsLine_editingFinished\0"
    "setRIG\0on_check_clicked\0executionFailedReceived\0"
    "crashed\0RIGOutputReceived\0output\0"
    "loaderErrorReceived"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RIGChecker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    1,   70,    2, 0x06 /* Public */,
       5,    0,   73,    2, 0x06 /* Public */,
       6,    0,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   75,    2, 0x08 /* Private */,
       8,    0,   76,    2, 0x08 /* Private */,
       9,    0,   77,    2, 0x08 /* Private */,
      10,    0,   78,    2, 0x08 /* Private */,
      11,    2,   79,    2, 0x08 /* Private */,
      13,    2,   84,    2, 0x08 /* Private */,
      15,    0,   89,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    4,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Bool,    2,   12,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::LongLong,   14,    2,
    QMetaType::Void,

       0        // eod
};

void RIGChecker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RIGChecker *_t = static_cast<RIGChecker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->RIGCrash(); break;
        case 1: _t->sendInput((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 2: _t->RIGCheckStart(); break;
        case 3: _t->terminateRIG(); break;
        case 4: _t->on_loadRIG_clicked(); break;
        case 5: _t->on_iterationsLine_editingFinished(); break;
        case 6: _t->setRIG(); break;
        case 7: _t->on_check_clicked(); break;
        case 8: _t->executionFailedReceived((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 9: _t->RIGOutputReceived((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< const qint64(*)>(_a[2]))); break;
        case 10: _t->loaderErrorReceived(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (RIGChecker::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RIGChecker::RIGCrash)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (RIGChecker::*_t)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RIGChecker::sendInput)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (RIGChecker::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RIGChecker::RIGCheckStart)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (RIGChecker::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RIGChecker::terminateRIG)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject RIGChecker::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_RIGChecker.data,
      qt_meta_data_RIGChecker,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RIGChecker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RIGChecker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RIGChecker.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int RIGChecker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void RIGChecker::RIGCrash()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void RIGChecker::sendInput(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RIGChecker::RIGCheckStart()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void RIGChecker::terminateRIG()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
