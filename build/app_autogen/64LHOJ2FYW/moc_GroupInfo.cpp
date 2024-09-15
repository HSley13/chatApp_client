/****************************************************************************
** Meta object code from reading C++ file 'GroupInfo.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/groups/GroupInfo.hpp"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GroupInfo.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSGroupInfoENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSGroupInfoENDCLASS = QtMocHelpers::stringData(
    "GroupInfo",
    "QML.Element",
    "auto",
    "group_name_changed",
    "",
    "group_members_changed",
    "group_image_url_changed",
    "group_unread_message_changed",
    "group_ID_changed",
    "group_admin_changed",
    "last_message_time_changed",
    "message_time_changed",
    "group_messages_changed",
    "group_is_typing_changed",
    "group_ID",
    "group_name",
    "group_admin",
    "group_image_url",
    "group_unread_message",
    "group_is_typing",
    "message_time",
    "last_message_time",
    "group_members",
    "QList<ContactInfo*>",
    "group_messages",
    "GroupChatListModel*"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSGroupInfoENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       1,   14, // classinfo
      10,   16, // methods
      10,   86, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   76,    4, 0x06,   11 /* Public */,
       5,    0,   77,    4, 0x06,   12 /* Public */,
       6,    0,   78,    4, 0x06,   13 /* Public */,
       7,    0,   79,    4, 0x06,   14 /* Public */,
       8,    0,   80,    4, 0x06,   15 /* Public */,
       9,    0,   81,    4, 0x06,   16 /* Public */,
      10,    0,   82,    4, 0x06,   17 /* Public */,
      11,    0,   83,    4, 0x06,   18 /* Public */,
      12,    0,   84,    4, 0x06,   19 /* Public */,
      13,    0,   85,    4, 0x06,   20 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      14, QMetaType::Int, 0x00015003, uint(4), 0,
      15, QMetaType::QString, 0x00015003, uint(0), 0,
      16, QMetaType::Int, 0x00015003, uint(5), 0,
      17, QMetaType::QString, 0x00015003, uint(2), 0,
      18, QMetaType::Int, 0x00015003, uint(3), 0,
      19, QMetaType::QString, 0x00015003, uint(9), 0,
      20, QMetaType::QString, 0x00015003, uint(7), 0,
      21, QMetaType::QString, 0x00015003, uint(6), 0,
      22, 0x80000000 | 23, 0x00015009, uint(1), 0,
      24, 0x80000000 | 25, 0x00015009, uint(8), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject GroupInfo::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSGroupInfoENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSGroupInfoENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // property 'group_ID'
        int,
        // property 'group_name'
        QString,
        // property 'group_admin'
        int,
        // property 'group_image_url'
        QString,
        // property 'group_unread_message'
        int,
        // property 'group_is_typing'
        QString,
        // property 'message_time'
        QString,
        // property 'last_message_time'
        QString,
        // property 'group_members'
        QList<ContactInfo*>,
        // property 'group_messages'
        GroupChatListModel*,
        // Q_OBJECT / Q_GADGET
        GroupInfo,
        // method 'group_name_changed'
        void,
        // method 'group_members_changed'
        void,
        // method 'group_image_url_changed'
        void,
        // method 'group_unread_message_changed'
        void,
        // method 'group_ID_changed'
        void,
        // method 'group_admin_changed'
        void,
        // method 'last_message_time_changed'
        void,
        // method 'message_time_changed'
        void,
        // method 'group_messages_changed'
        void,
        // method 'group_is_typing_changed'
        void
    >,
    nullptr
} };

void GroupInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GroupInfo *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->group_name_changed(); break;
        case 1: _t->group_members_changed(); break;
        case 2: _t->group_image_url_changed(); break;
        case 3: _t->group_unread_message_changed(); break;
        case 4: _t->group_ID_changed(); break;
        case 5: _t->group_admin_changed(); break;
        case 6: _t->last_message_time_changed(); break;
        case 7: _t->message_time_changed(); break;
        case 8: _t->group_messages_changed(); break;
        case 9: _t->group_is_typing_changed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GroupInfo::*)();
            if (_t _q_method = &GroupInfo::group_name_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GroupInfo::*)();
            if (_t _q_method = &GroupInfo::group_members_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GroupInfo::*)();
            if (_t _q_method = &GroupInfo::group_image_url_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (GroupInfo::*)();
            if (_t _q_method = &GroupInfo::group_unread_message_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (GroupInfo::*)();
            if (_t _q_method = &GroupInfo::group_ID_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (GroupInfo::*)();
            if (_t _q_method = &GroupInfo::group_admin_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (GroupInfo::*)();
            if (_t _q_method = &GroupInfo::last_message_time_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (GroupInfo::*)();
            if (_t _q_method = &GroupInfo::message_time_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (GroupInfo::*)();
            if (_t _q_method = &GroupInfo::group_messages_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (GroupInfo::*)();
            if (_t _q_method = &GroupInfo::group_is_typing_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GroupChatListModel* >(); break;
        case 8:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<ContactInfo*> >(); break;
        }
    }  else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<GroupInfo *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->group_ID(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->group_name(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->group_admin(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->group_image_url(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->group_unread_message(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->group_is_typing(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->message_time(); break;
        case 7: *reinterpret_cast< QString*>(_v) = _t->last_message_time(); break;
        case 8: *reinterpret_cast< QList<ContactInfo*>*>(_v) = _t->group_members(); break;
        case 9: *reinterpret_cast< GroupChatListModel**>(_v) = _t->group_messages(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<GroupInfo *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->set_group_ID(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->set_group_name(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->set_group_admin(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->set_group_image_url(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->set_group_unread_message(*reinterpret_cast< int*>(_v)); break;
        case 5: _t->set_group_is_typing(*reinterpret_cast< QString*>(_v)); break;
        case 6: _t->set_message_time(*reinterpret_cast< QString*>(_v)); break;
        case 7: _t->set_last_message_time(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *GroupInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GroupInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSGroupInfoENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int GroupInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void GroupInfo::group_name_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GroupInfo::group_members_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void GroupInfo::group_image_url_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void GroupInfo::group_unread_message_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void GroupInfo::group_ID_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void GroupInfo::group_admin_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void GroupInfo::last_message_time_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void GroupInfo::message_time_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void GroupInfo::group_messages_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void GroupInfo::group_is_typing_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
QT_WARNING_POP
