/****************************************************************************
** Meta object code from reading C++ file 'ContactListModel.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/contacts/ContactListModel.hpp"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ContactListModel.hpp' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSContactListModelENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSContactListModelENDCLASS = QtMocHelpers::stringData(
    "ContactListModel",
    "QML.Element",
    "auto",
    "contacts_changed",
    "",
    "active_chat_changed",
    "contact_proxy_list_chat_changed",
    "contact_proxy_list_changed",
    "main_user_changed",
    "socket_disconnected_changed",
    "on_load_contacts",
    "json_array",
    "on_load_my_info",
    "my_info",
    "on_text_received",
    "chatID",
    "sender_ID",
    "message",
    "time",
    "on_client_connected_disconnected",
    "phone_number",
    "true_or_false",
    "on_client_profile_image",
    "image_url",
    "on_file_received",
    "file_url",
    "on_audio_received",
    "audio_url",
    "on_is_typing_received",
    "on_update_client_info",
    "first_name",
    "last_name",
    "on_delete_message_received",
    "full_time",
    "lookup_friend",
    "update_unread_message",
    "active_chat",
    "ContactInfo*",
    "main_user",
    "contact_proxy_list_chat",
    "ContactProxyList*",
    "contact_proxy_list",
    "contacts",
    "QList<ContactInfo*>",
    "socket_disconnected"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSContactListModelENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       1,   14, // classinfo
      18,   16, // methods
       6,  194, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,  124,    4, 0x06,    7 /* Public */,
       5,    0,  125,    4, 0x06,    8 /* Public */,
       6,    0,  126,    4, 0x06,    9 /* Public */,
       7,    0,  127,    4, 0x06,   10 /* Public */,
       8,    0,  128,    4, 0x06,   11 /* Public */,
       9,    0,  129,    4, 0x06,   12 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    1,  130,    4, 0x08,   13 /* Private */,
      12,    1,  133,    4, 0x08,   15 /* Private */,
      14,    4,  136,    4, 0x08,   17 /* Private */,
      19,    2,  145,    4, 0x08,   22 /* Private */,
      22,    2,  150,    4, 0x08,   25 /* Private */,
      24,    4,  155,    4, 0x08,   28 /* Private */,
      26,    4,  164,    4, 0x08,   33 /* Private */,
      28,    1,  173,    4, 0x08,   38 /* Private */,
      29,    3,  176,    4, 0x08,   40 /* Private */,
      32,    2,  183,    4, 0x08,   44 /* Private */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      34,    1,  188,    4, 0x02,   47 /* Public */,
      35,    1,  191,    4, 0x02,   49 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QJsonArray,   11,
    QMetaType::Void, QMetaType::QJsonObject,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString,   15,   16,   17,   18,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   20,   21,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   20,   23,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString,   15,   16,   25,   18,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString,   15,   16,   27,   18,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString,   20,   30,   31,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   15,   33,

 // methods: parameters
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int,   15,

 // properties: name, type, flags
      36, 0x80000000 | 37, 0x0001500b, uint(1), 0,
      38, 0x80000000 | 37, 0x00015009, uint(4), 0,
      39, 0x80000000 | 40, 0x00015009, uint(2), 0,
      41, 0x80000000 | 40, 0x00015009, uint(3), 0,
      42, 0x80000000 | 43, 0x00015009, uint(0), 0,
      44, QMetaType::Bool, 0x00015001, uint(5), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject ContactListModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_CLASSContactListModelENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSContactListModelENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // property 'active_chat'
        ContactInfo*,
        // property 'main_user'
        ContactInfo*,
        // property 'contact_proxy_list_chat'
        ContactProxyList*,
        // property 'contact_proxy_list'
        ContactProxyList*,
        // property 'contacts'
        QList<ContactInfo*>,
        // property 'socket_disconnected'
        bool,
        // Q_OBJECT / Q_GADGET
        ContactListModel,
        // method 'contacts_changed'
        void,
        // method 'active_chat_changed'
        void,
        // method 'contact_proxy_list_chat_changed'
        void,
        // method 'contact_proxy_list_changed'
        void,
        // method 'main_user_changed'
        void,
        // method 'socket_disconnected_changed'
        void,
        // method 'on_load_contacts'
        void,
        QJsonArray,
        // method 'on_load_my_info'
        void,
        QJsonObject,
        // method 'on_text_received'
        void,
        const int &,
        const int &,
        const QString &,
        const QString &,
        // method 'on_client_connected_disconnected'
        void,
        const int &,
        const bool &,
        // method 'on_client_profile_image'
        void,
        const int &,
        const QString &,
        // method 'on_file_received'
        void,
        const int &,
        const int &,
        const QString &,
        const QString &,
        // method 'on_audio_received'
        void,
        const int &,
        const int &,
        const QString &,
        const QString &,
        // method 'on_is_typing_received'
        void,
        const int &,
        // method 'on_update_client_info'
        void,
        const int &,
        const QString &,
        const QString &,
        // method 'on_delete_message_received'
        void,
        const int &,
        const QString &,
        // method 'lookup_friend'
        void,
        const int &,
        // method 'update_unread_message'
        void,
        int
    >,
    nullptr
} };

void ContactListModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ContactListModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->contacts_changed(); break;
        case 1: _t->active_chat_changed(); break;
        case 2: _t->contact_proxy_list_chat_changed(); break;
        case 3: _t->contact_proxy_list_changed(); break;
        case 4: _t->main_user_changed(); break;
        case 5: _t->socket_disconnected_changed(); break;
        case 6: _t->on_load_contacts((*reinterpret_cast< std::add_pointer_t<QJsonArray>>(_a[1]))); break;
        case 7: _t->on_load_my_info((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 8: _t->on_text_received((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 9: _t->on_client_connected_disconnected((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 10: _t->on_client_profile_image((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 11: _t->on_file_received((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 12: _t->on_audio_received((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 13: _t->on_is_typing_received((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->on_update_client_info((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 15: _t->on_delete_message_received((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 16: _t->lookup_friend((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 17: _t->update_unread_message((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ContactListModel::*)();
            if (_t _q_method = &ContactListModel::contacts_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ContactListModel::*)();
            if (_t _q_method = &ContactListModel::active_chat_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ContactListModel::*)();
            if (_t _q_method = &ContactListModel::contact_proxy_list_chat_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ContactListModel::*)();
            if (_t _q_method = &ContactListModel::contact_proxy_list_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ContactListModel::*)();
            if (_t _q_method = &ContactListModel::main_user_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ContactListModel::*)();
            if (_t _q_method = &ContactListModel::socket_disconnected_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ContactInfo* >(); break;
        case 3:
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ContactProxyList* >(); break;
        case 4:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<ContactInfo*> >(); break;
        }
    }  else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ContactListModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< ContactInfo**>(_v) = _t->active_chat(); break;
        case 1: *reinterpret_cast< ContactInfo**>(_v) = _t->main_user(); break;
        case 2: *reinterpret_cast< ContactProxyList**>(_v) = _t->contact_proxy_list_chat(); break;
        case 3: *reinterpret_cast< ContactProxyList**>(_v) = _t->contact_proxy_list(); break;
        case 4: *reinterpret_cast< QList<ContactInfo*>*>(_v) = _t->contacts(); break;
        case 5: *reinterpret_cast< bool*>(_v) = _t->socket_disconnected(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<ContactListModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->set_active_chat(*reinterpret_cast< ContactInfo**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *ContactListModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ContactListModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSContactListModelENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int ContactListModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 18;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ContactListModel::contacts_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ContactListModel::active_chat_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ContactListModel::contact_proxy_list_chat_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ContactListModel::contact_proxy_list_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ContactListModel::main_user_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void ContactListModel::socket_disconnected_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
