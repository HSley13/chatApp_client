/****************************************************************************
** Meta object code from reading C++ file 'GroupListModel.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/groups/GroupListModel.hpp"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GroupListModel.hpp' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSGroupListModelENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSGroupListModelENDCLASS = QtMocHelpers::stringData(
    "GroupListModel",
    "QML.Element",
    "auto",
    "groups_changed",
    "",
    "active_group_chat_changed",
    "group_proxy_list_changed",
    "main_user_changed",
    "on_load_groups",
    "json_array",
    "on_group_text_received",
    "groupID",
    "sender_ID",
    "sender_name",
    "message",
    "time",
    "on_group_profile_image",
    "group_ID",
    "group_image_url",
    "on_group_file_received",
    "file_url",
    "on_group_is_typing_received",
    "on_remove_group_member_received",
    "group_members",
    "on_add_group_member_received",
    "new_group_members",
    "on_removed_from_group",
    "on_delete_group_message_received",
    "full_time",
    "on_group_audio_received",
    "audio_url",
    "add_group",
    "group_name",
    "QList<ContactInfo*>",
    "members",
    "remove_group_member",
    "add_group_member",
    "phone_number",
    "update_group_unread_message",
    "active_group_chat",
    "GroupInfo*",
    "group_proxy_list",
    "GroupProxyList*"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSGroupListModelENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       1,   14, // classinfo
      18,   16, // methods
       2,  208, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,  124,    4, 0x06,    3 /* Public */,
       5,    0,  125,    4, 0x06,    4 /* Public */,
       6,    0,  126,    4, 0x06,    5 /* Public */,
       7,    0,  127,    4, 0x06,    6 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    1,  128,    4, 0x08,    7 /* Private */,
      10,    5,  131,    4, 0x08,    9 /* Private */,
      16,    2,  142,    4, 0x08,   15 /* Private */,
      19,    5,  147,    4, 0x08,   18 /* Private */,
      21,    2,  158,    4, 0x08,   24 /* Private */,
      22,    2,  163,    4, 0x08,   27 /* Private */,
      24,    2,  168,    4, 0x08,   30 /* Private */,
      26,    1,  173,    4, 0x08,   33 /* Private */,
      27,    2,  176,    4, 0x08,   35 /* Private */,
      29,    5,  181,    4, 0x08,   38 /* Private */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      31,    2,  192,    4, 0x02,   44 /* Public */,
      35,    1,  197,    4, 0x02,   47 /* Public */,
      36,    2,  200,    4, 0x02,   49 /* Public */,
      38,    1,  205,    4, 0x02,   52 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QJsonArray,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,   11,   12,   13,   14,   15,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   17,   18,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,   11,   12,   13,   20,   15,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   11,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::QJsonArray,   11,   23,
    QMetaType::Void, QMetaType::Int, QMetaType::QJsonArray,   11,   25,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   11,   28,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,   11,   12,   13,   30,   15,

 // methods: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 33,   32,   34,
    QMetaType::Void, 0x80000000 | 33,   34,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 33,   37,   34,
    QMetaType::Void, QMetaType::Int,   11,

 // properties: name, type, flags
      39, 0x80000000 | 40, 0x0001500b, uint(1), 0,
      41, 0x80000000 | 42, 0x00015009, uint(2), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject GroupListModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_CLASSGroupListModelENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSGroupListModelENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // property 'active_group_chat'
        GroupInfo*,
        // property 'group_proxy_list'
        GroupProxyList*,
        // Q_OBJECT / Q_GADGET
        GroupListModel,
        // method 'groups_changed'
        void,
        // method 'active_group_chat_changed'
        void,
        // method 'group_proxy_list_changed'
        void,
        // method 'main_user_changed'
        void,
        // method 'on_load_groups'
        void,
        QJsonArray,
        // method 'on_group_text_received'
        void,
        const int &,
        const int &,
        QString,
        const QString &,
        const QString &,
        // method 'on_group_profile_image'
        void,
        const int &,
        const QString &,
        // method 'on_group_file_received'
        void,
        const int &,
        const int &,
        const QString &,
        const QString &,
        const QString &,
        // method 'on_group_is_typing_received'
        void,
        const int &,
        const QString &,
        // method 'on_remove_group_member_received'
        void,
        const int &,
        QJsonArray,
        // method 'on_add_group_member_received'
        void,
        const int &,
        QJsonArray,
        // method 'on_removed_from_group'
        void,
        const int &,
        // method 'on_delete_group_message_received'
        void,
        const int &,
        const QString &,
        // method 'on_group_audio_received'
        void,
        const int &,
        const int &,
        const QString &,
        const QString &,
        const QString &,
        // method 'add_group'
        void,
        const QString &,
        const QList<ContactInfo*>,
        // method 'remove_group_member'
        void,
        const QList<ContactInfo*>,
        // method 'add_group_member'
        void,
        const int &,
        const QList<ContactInfo*>,
        // method 'update_group_unread_message'
        void,
        const int &
    >,
    nullptr
} };

void GroupListModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GroupListModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->groups_changed(); break;
        case 1: _t->active_group_chat_changed(); break;
        case 2: _t->group_proxy_list_changed(); break;
        case 3: _t->main_user_changed(); break;
        case 4: _t->on_load_groups((*reinterpret_cast< std::add_pointer_t<QJsonArray>>(_a[1]))); break;
        case 5: _t->on_group_text_received((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        case 6: _t->on_group_profile_image((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 7: _t->on_group_file_received((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        case 8: _t->on_group_is_typing_received((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 9: _t->on_remove_group_member_received((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QJsonArray>>(_a[2]))); break;
        case 10: _t->on_add_group_member_received((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QJsonArray>>(_a[2]))); break;
        case 11: _t->on_removed_from_group((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->on_delete_group_message_received((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 13: _t->on_group_audio_received((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        case 14: _t->add_group((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<ContactInfo*>>>(_a[2]))); break;
        case 15: _t->remove_group_member((*reinterpret_cast< std::add_pointer_t<QList<ContactInfo*>>>(_a[1]))); break;
        case 16: _t->add_group_member((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<ContactInfo*>>>(_a[2]))); break;
        case 17: _t->update_group_unread_message((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<ContactInfo*> >(); break;
            }
            break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<ContactInfo*> >(); break;
            }
            break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<ContactInfo*> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GroupListModel::*)();
            if (_t _q_method = &GroupListModel::groups_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GroupListModel::*)();
            if (_t _q_method = &GroupListModel::active_group_chat_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GroupListModel::*)();
            if (_t _q_method = &GroupListModel::group_proxy_list_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (GroupListModel::*)();
            if (_t _q_method = &GroupListModel::main_user_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GroupInfo* >(); break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GroupProxyList* >(); break;
        }
    }  else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<GroupListModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< GroupInfo**>(_v) = _t->active_group_chat(); break;
        case 1: *reinterpret_cast< GroupProxyList**>(_v) = _t->group_proxy_list(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<GroupListModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->set_active_group_chat(*reinterpret_cast< GroupInfo**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *GroupListModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GroupListModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSGroupListModelENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int GroupListModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
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
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void GroupListModel::groups_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GroupListModel::active_group_chat_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void GroupListModel::group_proxy_list_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void GroupListModel::main_user_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
