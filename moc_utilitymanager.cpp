/****************************************************************************
** Meta object code from reading C++ file 'utilitymanager.h'
**
** Created: Sun Apr 17 23:33:57 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "utilitymanager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'utilitymanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_UtilityManager[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      46,   15,   15,   15, 0x08,
      71,   15,   15,   15, 0x08,
     100,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_UtilityManager[] = {
    "UtilityManager\0\0on_troubleShootDisk_clicked()\0"
    "on_taskManager_clicked()\0"
    "on_checkSafeRemove_clicked()\0"
    "on_unmount_clicked()\0"
};

const QMetaObject UtilityManager::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_UtilityManager,
      qt_meta_data_UtilityManager, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &UtilityManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *UtilityManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *UtilityManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UtilityManager))
        return static_cast<void*>(const_cast< UtilityManager*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int UtilityManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_troubleShootDisk_clicked(); break;
        case 1: on_taskManager_clicked(); break;
        case 2: on_checkSafeRemove_clicked(); break;
        case 3: on_unmount_clicked(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
static const uint qt_meta_data_TaskManager[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TaskManager[] = {
    "TaskManager\0\0showTime()\0"
};

const QMetaObject TaskManager::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TaskManager,
      qt_meta_data_TaskManager, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TaskManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TaskManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TaskManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TaskManager))
        return static_cast<void*>(const_cast< TaskManager*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int TaskManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: showTime(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
static const uint qt_meta_data_safe_Remove[] = {

 // content:
       4,       // revision
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

static const char qt_meta_stringdata_safe_Remove[] = {
    "safe_Remove\0"
};

const QMetaObject safe_Remove::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_safe_Remove,
      qt_meta_data_safe_Remove, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &safe_Remove::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *safe_Remove::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *safe_Remove::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_safe_Remove))
        return static_cast<void*>(const_cast< safe_Remove*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int safe_Remove::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_UnmountDisk[] = {

 // content:
       4,       // revision
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

static const char qt_meta_stringdata_UnmountDisk[] = {
    "UnmountDisk\0"
};

const QMetaObject UnmountDisk::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_UnmountDisk,
      qt_meta_data_UnmountDisk, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &UnmountDisk::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *UnmountDisk::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *UnmountDisk::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UnmountDisk))
        return static_cast<void*>(const_cast< UnmountDisk*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int UnmountDisk::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
