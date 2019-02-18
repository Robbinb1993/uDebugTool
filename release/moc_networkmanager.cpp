/****************************************************************************
** Meta object code from reading C++ file 'networkmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../networkmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'networkmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NetworkManager_t {
    QByteArrayData data[26];
    char stringdata0[389];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NetworkManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NetworkManager_t qt_meta_stringdata_NetworkManager = {
    {
QT_MOC_LITERAL(0, 0, 14), // "NetworkManager"
QT_MOC_LITERAL(1, 15, 13), // "inputsArrived"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 15), // "acOutputArrived"
QT_MOC_LITERAL(4, 46, 12), // "hintsArrived"
QT_MOC_LITERAL(5, 59, 17), // "hintOutputArrived"
QT_MOC_LITERAL(6, 77, 21), // "testcaseOutputArrived"
QT_MOC_LITERAL(7, 99, 13), // "acOutputError"
QT_MOC_LITERAL(8, 113, 13), // "probNameReady"
QT_MOC_LITERAL(9, 127, 8), // "probName"
QT_MOC_LITERAL(10, 136, 18), // "multiOutputProblem"
QT_MOC_LITERAL(11, 155, 23), // "problemDescriptionReady"
QT_MOC_LITERAL(12, 179, 3), // "url"
QT_MOC_LITERAL(13, 183, 11), // "getTestcase"
QT_MOC_LITERAL(14, 195, 17), // "getInputsFinished"
QT_MOC_LITERAL(15, 213, 20), // "QProcess::ExitStatus"
QT_MOC_LITERAL(16, 234, 19), // "getAcOutputFinished"
QT_MOC_LITERAL(17, 254, 19), // "getTestcaseFinished"
QT_MOC_LITERAL(18, 274, 16), // "getHintsFinished"
QT_MOC_LITERAL(19, 291, 15), // "getHintFinished"
QT_MOC_LITERAL(20, 307, 9), // "procError"
QT_MOC_LITERAL(21, 317, 22), // "QProcess::ProcessError"
QT_MOC_LITERAL(22, 340, 14), // "inputPostError"
QT_MOC_LITERAL(23, 355, 12), // "scrapingDone"
QT_MOC_LITERAL(24, 368, 14), // "QNetworkReply*"
QT_MOC_LITERAL(25, 383, 5) // "reply"

    },
    "NetworkManager\0inputsArrived\0\0"
    "acOutputArrived\0hintsArrived\0"
    "hintOutputArrived\0testcaseOutputArrived\0"
    "acOutputError\0probNameReady\0probName\0"
    "multiOutputProblem\0problemDescriptionReady\0"
    "url\0getTestcase\0getInputsFinished\0"
    "QProcess::ExitStatus\0getAcOutputFinished\0"
    "getTestcaseFinished\0getHintsFinished\0"
    "getHintFinished\0procError\0"
    "QProcess::ProcessError\0inputPostError\0"
    "scrapingDone\0QNetworkReply*\0reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NetworkManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  104,    2, 0x06 /* Public */,
       3,    1,  107,    2, 0x06 /* Public */,
       4,    1,  110,    2, 0x06 /* Public */,
       5,    1,  113,    2, 0x06 /* Public */,
       6,    1,  116,    2, 0x06 /* Public */,
       7,    0,  119,    2, 0x06 /* Public */,
       8,    1,  120,    2, 0x06 /* Public */,
      10,    0,  123,    2, 0x06 /* Public */,
      11,    1,  124,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    1,  127,    2, 0x08 /* Private */,
      14,    2,  130,    2, 0x08 /* Private */,
      16,    2,  135,    2, 0x08 /* Private */,
      17,    2,  140,    2, 0x08 /* Private */,
      18,    2,  145,    2, 0x08 /* Private */,
      19,    2,  150,    2, 0x08 /* Private */,
      20,    1,  155,    2, 0x08 /* Private */,
      22,    1,  158,    2, 0x08 /* Private */,
      23,    1,  161,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 15,    2,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 15,    2,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 15,    2,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 15,    2,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 15,    2,    2,
    QMetaType::Void, 0x80000000 | 21,    2,
    QMetaType::Void, 0x80000000 | 21,    2,
    QMetaType::Void, 0x80000000 | 24,   25,

       0        // eod
};

void NetworkManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NetworkManager *_t = static_cast<NetworkManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->inputsArrived((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 1: _t->acOutputArrived((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 2: _t->hintsArrived((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 3: _t->hintOutputArrived((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 4: _t->testcaseOutputArrived((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 5: _t->acOutputError(); break;
        case 6: _t->probNameReady((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->multiOutputProblem(); break;
        case 8: _t->problemDescriptionReady((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->getTestcase((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->getInputsFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 11: _t->getAcOutputFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 12: _t->getTestcaseFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 13: _t->getHintsFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 14: _t->getHintFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 15: _t->procError((*reinterpret_cast< QProcess::ProcessError(*)>(_a[1]))); break;
        case 16: _t->inputPostError((*reinterpret_cast< QProcess::ProcessError(*)>(_a[1]))); break;
        case 17: _t->scrapingDone((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (NetworkManager::*_t)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetworkManager::inputsArrived)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (NetworkManager::*_t)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetworkManager::acOutputArrived)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (NetworkManager::*_t)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetworkManager::hintsArrived)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (NetworkManager::*_t)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetworkManager::hintOutputArrived)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (NetworkManager::*_t)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetworkManager::testcaseOutputArrived)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (NetworkManager::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetworkManager::acOutputError)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (NetworkManager::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetworkManager::probNameReady)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (NetworkManager::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetworkManager::multiOutputProblem)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (NetworkManager::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetworkManager::problemDescriptionReady)) {
                *result = 8;
                return;
            }
        }
    }
}

const QMetaObject NetworkManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_NetworkManager.data,
      qt_meta_data_NetworkManager,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *NetworkManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NetworkManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NetworkManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int NetworkManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void NetworkManager::inputsArrived(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NetworkManager::acOutputArrived(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void NetworkManager::hintsArrived(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void NetworkManager::hintOutputArrived(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void NetworkManager::testcaseOutputArrived(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void NetworkManager::acOutputError()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void NetworkManager::probNameReady(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void NetworkManager::multiOutputProblem()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void NetworkManager::problemDescriptionReady(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
