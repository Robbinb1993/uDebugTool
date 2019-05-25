/****************************************************************************
** Meta object code from reading C++ file 'sourcecode.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../sourcecode.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sourcecode.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SourceCode_t {
    QByteArrayData data[15];
    char stringdata0[186];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SourceCode_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SourceCode_t qt_meta_stringdata_SourceCode = {
    {
QT_MOC_LITERAL(0, 0, 10), // "SourceCode"
QT_MOC_LITERAL(1, 11, 13), // "outputArrived"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 6), // "output"
QT_MOC_LITERAL(4, 33, 4), // "time"
QT_MOC_LITERAL(5, 38, 19), // "loaderOutputArrived"
QT_MOC_LITERAL(6, 58, 3), // "ret"
QT_MOC_LITERAL(7, 62, 5), // "error"
QT_MOC_LITERAL(8, 68, 15), // "executionFailed"
QT_MOC_LITERAL(9, 84, 7), // "crashed"
QT_MOC_LITERAL(10, 92, 19), // "executeProcFinished"
QT_MOC_LITERAL(11, 112, 20), // "QProcess::ExitStatus"
QT_MOC_LITERAL(12, 133, 16), // "executeProcError"
QT_MOC_LITERAL(13, 150, 22), // "QProcess::ProcessError"
QT_MOC_LITERAL(14, 173, 12) // "procTimedOut"

    },
    "SourceCode\0outputArrived\0\0output\0time\0"
    "loaderOutputArrived\0ret\0error\0"
    "executionFailed\0crashed\0executeProcFinished\0"
    "QProcess::ExitStatus\0executeProcError\0"
    "QProcess::ProcessError\0procTimedOut"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SourceCode[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,
       5,    3,   49,    2, 0x06 /* Public */,
       8,    2,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    2,   61,    2, 0x08 /* Private */,
      12,    1,   66,    2, 0x08 /* Private */,
      14,    0,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray, QMetaType::LongLong,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QByteArray, QMetaType::QByteArray,    6,    7,    3,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Bool,    7,    9,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 11,    2,    2,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void,

       0        // eod
};

void SourceCode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SourceCode *_t = static_cast<SourceCode *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->outputArrived((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< const qint64(*)>(_a[2]))); break;
        case 1: _t->loaderOutputArrived((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2])),(*reinterpret_cast< const QByteArray(*)>(_a[3]))); break;
        case 2: _t->executionFailed((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->executeProcFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 4: _t->executeProcError((*reinterpret_cast< QProcess::ProcessError(*)>(_a[1]))); break;
        case 5: _t->procTimedOut(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (SourceCode::*_t)(const QByteArray & , const qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SourceCode::outputArrived)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SourceCode::*_t)(int , const QByteArray & , const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SourceCode::loaderOutputArrived)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (SourceCode::*_t)(const QByteArray & , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SourceCode::executionFailed)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject SourceCode::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SourceCode.data,
      qt_meta_data_SourceCode,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SourceCode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SourceCode::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SourceCode.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SourceCode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void SourceCode::outputArrived(const QByteArray & _t1, const qint64 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SourceCode::loaderOutputArrived(int _t1, const QByteArray & _t2, const QByteArray & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SourceCode::executionFailed(const QByteArray & _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
struct qt_meta_stringdata_CompiledSourceCode_t {
    QByteArrayData data[4];
    char stringdata0[61];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CompiledSourceCode_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CompiledSourceCode_t qt_meta_stringdata_CompiledSourceCode = {
    {
QT_MOC_LITERAL(0, 0, 18), // "CompiledSourceCode"
QT_MOC_LITERAL(1, 19, 19), // "compileProcFinished"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 20) // "QProcess::ExitStatus"

    },
    "CompiledSourceCode\0compileProcFinished\0"
    "\0QProcess::ExitStatus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CompiledSourceCode[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 3,    2,    2,

       0        // eod
};

void CompiledSourceCode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CompiledSourceCode *_t = static_cast<CompiledSourceCode *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->compileProcFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject CompiledSourceCode::staticMetaObject = {
    { &SourceCode::staticMetaObject, qt_meta_stringdata_CompiledSourceCode.data,
      qt_meta_data_CompiledSourceCode,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CompiledSourceCode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CompiledSourceCode::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CompiledSourceCode.stringdata0))
        return static_cast<void*>(this);
    return SourceCode::qt_metacast(_clname);
}

int CompiledSourceCode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SourceCode::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_InterpretedSourceCode_t {
    QByteArrayData data[1];
    char stringdata0[22];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_InterpretedSourceCode_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_InterpretedSourceCode_t qt_meta_stringdata_InterpretedSourceCode = {
    {
QT_MOC_LITERAL(0, 0, 21) // "InterpretedSourceCode"

    },
    "InterpretedSourceCode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InterpretedSourceCode[] = {

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

void InterpretedSourceCode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject InterpretedSourceCode::staticMetaObject = {
    { &SourceCode::staticMetaObject, qt_meta_stringdata_InterpretedSourceCode.data,
      qt_meta_data_InterpretedSourceCode,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *InterpretedSourceCode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InterpretedSourceCode::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_InterpretedSourceCode.stringdata0))
        return static_cast<void*>(this);
    return SourceCode::qt_metacast(_clname);
}

int InterpretedSourceCode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SourceCode::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_SourceCodeCType_t {
    QByteArrayData data[1];
    char stringdata0[16];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SourceCodeCType_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SourceCodeCType_t qt_meta_stringdata_SourceCodeCType = {
    {
QT_MOC_LITERAL(0, 0, 15) // "SourceCodeCType"

    },
    "SourceCodeCType"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SourceCodeCType[] = {

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

void SourceCodeCType::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject SourceCodeCType::staticMetaObject = {
    { &CompiledSourceCode::staticMetaObject, qt_meta_stringdata_SourceCodeCType.data,
      qt_meta_data_SourceCodeCType,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SourceCodeCType::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SourceCodeCType::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SourceCodeCType.stringdata0))
        return static_cast<void*>(this);
    return CompiledSourceCode::qt_metacast(_clname);
}

int SourceCodeCType::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CompiledSourceCode::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_SourceCodeJava_t {
    QByteArrayData data[6];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SourceCodeJava_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SourceCodeJava_t qt_meta_stringdata_SourceCodeJava = {
    {
QT_MOC_LITERAL(0, 0, 14), // "SourceCodeJava"
QT_MOC_LITERAL(1, 15, 19), // "javaParsingFinished"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 20), // "QProcess::ExitStatus"
QT_MOC_LITERAL(4, 57, 16), // "javaParsingError"
QT_MOC_LITERAL(5, 74, 22) // "QProcess::ProcessError"

    },
    "SourceCodeJava\0javaParsingFinished\0\0"
    "QProcess::ExitStatus\0javaParsingError\0"
    "QProcess::ProcessError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SourceCodeJava[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x08 /* Private */,
       4,    1,   29,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 3,    2,    2,
    QMetaType::Void, 0x80000000 | 5,    2,

       0        // eod
};

void SourceCodeJava::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SourceCodeJava *_t = static_cast<SourceCodeJava *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->javaParsingFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 1: _t->javaParsingError((*reinterpret_cast< QProcess::ProcessError(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject SourceCodeJava::staticMetaObject = {
    { &CompiledSourceCode::staticMetaObject, qt_meta_stringdata_SourceCodeJava.data,
      qt_meta_data_SourceCodeJava,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SourceCodeJava::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SourceCodeJava::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SourceCodeJava.stringdata0))
        return static_cast<void*>(this);
    return CompiledSourceCode::qt_metacast(_clname);
}

int SourceCodeJava::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CompiledSourceCode::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
struct qt_meta_stringdata_SourceCodePython_t {
    QByteArrayData data[1];
    char stringdata0[17];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SourceCodePython_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SourceCodePython_t qt_meta_stringdata_SourceCodePython = {
    {
QT_MOC_LITERAL(0, 0, 16) // "SourceCodePython"

    },
    "SourceCodePython"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SourceCodePython[] = {

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

void SourceCodePython::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject SourceCodePython::staticMetaObject = {
    { &InterpretedSourceCode::staticMetaObject, qt_meta_stringdata_SourceCodePython.data,
      qt_meta_data_SourceCodePython,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SourceCodePython::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SourceCodePython::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SourceCodePython.stringdata0))
        return static_cast<void*>(this);
    return InterpretedSourceCode::qt_metacast(_clname);
}

int SourceCodePython::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = InterpretedSourceCode::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
