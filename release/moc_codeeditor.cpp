/****************************************************************************
** Meta object code from reading C++ file 'codeeditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../codeeditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'codeeditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CodeEditor_t {
    QByteArrayData data[18];
    char stringdata0[269];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CodeEditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CodeEditor_t qt_meta_stringdata_CodeEditor = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CodeEditor"
QT_MOC_LITERAL(1, 11, 11), // "outputReady"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 6), // "output"
QT_MOC_LITERAL(4, 31, 4), // "time"
QT_MOC_LITERAL(5, 36, 15), // "executionFailed"
QT_MOC_LITERAL(6, 52, 7), // "crashed"
QT_MOC_LITERAL(7, 60, 18), // "loaderErrorArrived"
QT_MOC_LITERAL(8, 79, 23), // "on_loaderButton_clicked"
QT_MOC_LITERAL(9, 103, 27), // "on_submitCodeButton_clicked"
QT_MOC_LITERAL(10, 131, 37), // "on_languageSelect_currentInde..."
QT_MOC_LITERAL(11, 169, 4), // "arg1"
QT_MOC_LITERAL(12, 174, 27), // "on_flagLine_editingFinished"
QT_MOC_LITERAL(13, 202, 20), // "loaderOutputReceived"
QT_MOC_LITERAL(14, 223, 3), // "ret"
QT_MOC_LITERAL(15, 227, 5), // "error"
QT_MOC_LITERAL(16, 233, 14), // "outputReceived"
QT_MOC_LITERAL(17, 248, 20) // "executionFailArrived"

    },
    "CodeEditor\0outputReady\0\0output\0time\0"
    "executionFailed\0crashed\0loaderErrorArrived\0"
    "on_loaderButton_clicked\0"
    "on_submitCodeButton_clicked\0"
    "on_languageSelect_currentIndexChanged\0"
    "arg1\0on_flagLine_editingFinished\0"
    "loaderOutputReceived\0ret\0error\0"
    "outputReceived\0executionFailArrived"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CodeEditor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x06 /* Public */,
       5,    1,   69,    2, 0x06 /* Public */,
       7,    0,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   73,    2, 0x08 /* Private */,
       9,    0,   74,    2, 0x08 /* Private */,
      10,    1,   75,    2, 0x08 /* Private */,
      12,    0,   78,    2, 0x08 /* Private */,
      13,    3,   79,    2, 0x08 /* Private */,
      16,    2,   86,    2, 0x08 /* Private */,
      17,    1,   91,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QByteArray, QMetaType::QByteArray,   14,   15,    3,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Bool,    6,

       0        // eod
};

void CodeEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CodeEditor *_t = static_cast<CodeEditor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->outputReady((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 1: _t->executionFailed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->loaderErrorArrived(); break;
        case 3: _t->on_loaderButton_clicked(); break;
        case 4: _t->on_submitCodeButton_clicked(); break;
        case 5: _t->on_languageSelect_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_flagLine_editingFinished(); break;
        case 7: _t->loaderOutputReceived((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2])),(*reinterpret_cast< const QByteArray(*)>(_a[3]))); break;
        case 8: _t->outputReceived((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 9: _t->executionFailArrived((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (CodeEditor::*_t)(const QByteArray & , const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CodeEditor::outputReady)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CodeEditor::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CodeEditor::executionFailed)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CodeEditor::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CodeEditor::loaderErrorArrived)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject CodeEditor::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CodeEditor.data,
      qt_meta_data_CodeEditor,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CodeEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CodeEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CodeEditor.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int CodeEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void CodeEditor::outputReady(const QByteArray & _t1, const int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CodeEditor::executionFailed(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CodeEditor::loaderErrorArrived()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
