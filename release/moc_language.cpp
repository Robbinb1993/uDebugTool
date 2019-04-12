/****************************************************************************
** Meta object code from reading C++ file 'language.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../language.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'language.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Language_t {
    QByteArrayData data[8];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Language_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Language_t qt_meta_stringdata_Language = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Language"
QT_MOC_LITERAL(1, 9, 19), // "compileProcFinished"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 20), // "QProcess::ExitStatus"
QT_MOC_LITERAL(4, 51, 16), // "compileProcError"
QT_MOC_LITERAL(5, 68, 22), // "QProcess::ProcessError"
QT_MOC_LITERAL(6, 91, 19), // "executeProcFinished"
QT_MOC_LITERAL(7, 111, 16) // "executeProcError"

    },
    "Language\0compileProcFinished\0\0"
    "QProcess::ExitStatus\0compileProcError\0"
    "QProcess::ProcessError\0executeProcFinished\0"
    "executeProcError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Language[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x08 /* Private */,
       4,    1,   39,    2, 0x08 /* Private */,
       6,    2,   42,    2, 0x08 /* Private */,
       7,    1,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 3,    2,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 3,    2,    2,
    QMetaType::Void, 0x80000000 | 5,    2,

       0        // eod
};

void Language::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Language *_t = static_cast<Language *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->compileProcFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 1: _t->compileProcError((*reinterpret_cast< QProcess::ProcessError(*)>(_a[1]))); break;
        case 2: _t->executeProcFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 3: _t->executeProcError((*reinterpret_cast< QProcess::ProcessError(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Language::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Language.data,
      qt_meta_data_Language,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Language::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Language::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Language.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Language::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_LanguageCPP_t {
    QByteArrayData data[1];
    char stringdata0[12];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LanguageCPP_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LanguageCPP_t qt_meta_stringdata_LanguageCPP = {
    {
QT_MOC_LITERAL(0, 0, 11) // "LanguageCPP"

    },
    "LanguageCPP"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LanguageCPP[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void LanguageCPP::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject LanguageCPP::staticMetaObject = {
    { &Language::staticMetaObject, qt_meta_stringdata_LanguageCPP.data,
      qt_meta_data_LanguageCPP,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LanguageCPP::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LanguageCPP::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LanguageCPP.stringdata0))
        return static_cast<void*>(this);
    return Language::qt_metacast(_clname);
}

int LanguageCPP::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Language::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_LanguageC_t {
    QByteArrayData data[1];
    char stringdata0[10];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LanguageC_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LanguageC_t qt_meta_stringdata_LanguageC = {
    {
QT_MOC_LITERAL(0, 0, 9) // "LanguageC"

    },
    "LanguageC"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LanguageC[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void LanguageC::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject LanguageC::staticMetaObject = {
    { &Language::staticMetaObject, qt_meta_stringdata_LanguageC.data,
      qt_meta_data_LanguageC,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LanguageC::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LanguageC::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LanguageC.stringdata0))
        return static_cast<void*>(this);
    return Language::qt_metacast(_clname);
}

int LanguageC::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Language::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_LanguageCS_t {
    QByteArrayData data[1];
    char stringdata0[11];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LanguageCS_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LanguageCS_t qt_meta_stringdata_LanguageCS = {
    {
QT_MOC_LITERAL(0, 0, 10) // "LanguageCS"

    },
    "LanguageCS"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LanguageCS[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void LanguageCS::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject LanguageCS::staticMetaObject = {
    { &Language::staticMetaObject, qt_meta_stringdata_LanguageCS.data,
      qt_meta_data_LanguageCS,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LanguageCS::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LanguageCS::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LanguageCS.stringdata0))
        return static_cast<void*>(this);
    return Language::qt_metacast(_clname);
}

int LanguageCS::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Language::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_LanguageJava_t {
    QByteArrayData data[1];
    char stringdata0[13];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LanguageJava_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LanguageJava_t qt_meta_stringdata_LanguageJava = {
    {
QT_MOC_LITERAL(0, 0, 12) // "LanguageJava"

    },
    "LanguageJava"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LanguageJava[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void LanguageJava::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject LanguageJava::staticMetaObject = {
    { &Language::staticMetaObject, qt_meta_stringdata_LanguageJava.data,
      qt_meta_data_LanguageJava,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LanguageJava::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LanguageJava::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LanguageJava.stringdata0))
        return static_cast<void*>(this);
    return Language::qt_metacast(_clname);
}

int LanguageJava::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Language::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_LanguagePython_t {
    QByteArrayData data[1];
    char stringdata0[15];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LanguagePython_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LanguagePython_t qt_meta_stringdata_LanguagePython = {
    {
QT_MOC_LITERAL(0, 0, 14) // "LanguagePython"

    },
    "LanguagePython"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LanguagePython[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void LanguagePython::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject LanguagePython::staticMetaObject = {
    { &Language::staticMetaObject, qt_meta_stringdata_LanguagePython.data,
      qt_meta_data_LanguagePython,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LanguagePython::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LanguagePython::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LanguagePython.stringdata0))
        return static_cast<void*>(this);
    return Language::qt_metacast(_clname);
}

int LanguagePython::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Language::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
