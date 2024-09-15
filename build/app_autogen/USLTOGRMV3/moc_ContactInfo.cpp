/****************************************************************************
** Meta object code from reading C++ file 'ContactInfo.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/contacts/ContactInfo.hpp"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ContactInfo.hpp' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSContactInfoENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSContactInfoENDCLASS = QtMocHelpers::stringData(
    "ContactInfo",
    "QML.Element",
    "auto",
    "first_name_changed",
    "",
    "last_name_changed",
    "phone_number_changed",
    "status_changed",
    "image_url_changed",
    "unread_message_changed",
    "chat_ID_changed",
    "last_message_time_changed",
    "message_time_changed",
    "messages_changed",
    "is_typing_changed",
    "secret_question_changed",
    "secret_answer_changed",
    "popup_message_changed",
    "login_status_changed",
    "set_image_url",
    "new_image_url",
    "first_name",
    "chat_ID",
    "last_name",
    "phone_number",
    "status",
    "image_url",
    "unread_message",
    "is_typing",
    "message_time",
    "last_message_time",
    "secret_question",
    "secret_answer",
    "popup_message",
    "login_status",
    "messages",
    "ChatListModel*"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSContactInfoENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       1,   14, // classinfo
      16,   16, // methods
      15,  130, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      15,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,  112,    4, 0x06,   16 /* Public */,
       5,    0,  113,    4, 0x06,   17 /* Public */,
       6,    0,  114,    4, 0x06,   18 /* Public */,
       7,    0,  115,    4, 0x06,   19 /* Public */,
       8,    0,  116,    4, 0x06,   20 /* Public */,
       9,    0,  117,    4, 0x06,   21 /* Public */,
      10,    0,  118,    4, 0x06,   22 /* Public */,
      11,    0,  119,    4, 0x06,   23 /* Public */,
      12,    0,  120,    4, 0x06,   24 /* Public */,
      13,    0,  121,    4, 0x06,   25 /* Public */,
      14,    0,  122,    4, 0x06,   26 /* Public */,
      15,    0,  123,    4, 0x06,   27 /* Public */,
      16,    0,  124,    4, 0x06,   28 /* Public */,
      17,    0,  125,    4, 0x06,   29 /* Public */,
      18,    0,  126,    4, 0x06,   30 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      19,    1,  127,    4, 0x02,   31 /* Public */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,   20,

 // properties: name, type, flags
      21, QMetaType::QString, 0x00015003, uint(0), 0,
      22, QMetaType::Int, 0x00015003, uint(6), 0,
      23, QMetaType::QString, 0x00015003, uint(1), 0,
      24, QMetaType::Int, 0x00015003, uint(2), 0,
      25, QMetaType::Bool, 0x00015003, uint(3), 0,
      26, QMetaType::QString, 0x00015003, uint(4), 0,
      27, QMetaType::Int, 0x00015003, uint(5), 0,
      28, QMetaType::QString, 0x00015003, uint(10), 0,
      29, QMetaType::QString, 0x00015003, uint(8), 0,
      30, QMetaType::QString, 0x00015003, uint(7), 0,
      31, QMetaType::QString, 0x00015003, uint(11), 0,
      32, QMetaType::QString, 0x00015003, uint(12), 0,
      33, QMetaType::QString, 0x00015003, uint(13), 0,
      34, QMetaType::Bool, 0x00015003, uint(14), 0,
      35, 0x80000000 | 36, 0x00015009, uint(9), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject ContactInfo::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSContactInfoENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSContactInfoENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // property 'first_name'
        QString,
        // property 'chat_ID'
        int,
        // property 'last_name'
        QString,
        // property 'phone_number'
        int,
        // property 'status'
        bool,
        // property 'image_url'
        QString,
        // property 'unread_message'
        int,
        // property 'is_typing'
        QString,
        // property 'message_time'
        QString,
        // property 'last_message_time'
        QString,
        // property 'secret_question'
        QString,
        // property 'secret_answer'
        QString,
        // property 'popup_message'
        QString,
        // property 'login_status'
        bool,
        // property 'messages'
        ChatListModel*,
        // Q_OBJECT / Q_GADGET
        ContactInfo,
        // method 'first_name_changed'
        void,
        // method 'last_name_changed'
        void,
        // method 'phone_number_changed'
        void,
        // method 'status_changed'
        void,
        // method 'image_url_changed'
        void,
        // method 'unread_message_changed'
        void,
        // method 'chat_ID_changed'
        void,
        // method 'last_message_time_changed'
        void,
        // method 'message_time_changed'
        void,
        // method 'messages_changed'
        void,
        // method 'is_typing_changed'
        void,
        // method 'secret_question_changed'
        void,
        // method 'secret_answer_changed'
        void,
        // method 'popup_message_changed'
        void,
        // method 'login_status_changed'
        void,
        // method 'set_image_url'
        void,
        const QString &
    >,
    nullptr
} };

void ContactInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ContactInfo *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->first_name_changed(); break;
        case 1: _t->last_name_changed(); break;
        case 2: _t->phone_number_changed(); break;
        case 3: _t->status_changed(); break;
        case 4: _t->image_url_changed(); break;
        case 5: _t->unread_message_changed(); break;
        case 6: _t->chat_ID_changed(); break;
        case 7: _t->last_message_time_changed(); break;
        case 8: _t->message_time_changed(); break;
        case 9: _t->messages_changed(); break;
        case 10: _t->is_typing_changed(); break;
        case 11: _t->secret_question_changed(); break;
        case 12: _t->secret_answer_changed(); break;
        case 13: _t->popup_message_changed(); break;
        case 14: _t->login_status_changed(); break;
        case 15: _t->set_image_url((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ContactInfo::*)();
            if (_t _q_method = &ContactInfo::first_name_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ContactInfo::*)();
            if (_t _q_method = &ContactInfo::last_name_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ContactInfo::*)();
            if (_t _q_method = &ContactInfo::phone_number_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ContactInfo::*)();
            if (_t _q_method = &ContactInfo::status_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ContactInfo::*)();
            if (_t _q_method = &ContactInfo::image_url_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ContactInfo::*)();
            if (_t _q_method = &ContactInfo::unread_message_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ContactInfo::*)();
            if (_t _q_method = &ContactInfo::chat_ID_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (ContactInfo::*)();
            if (_t _q_method = &ContactInfo::last_message_time_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (ContactInfo::*)();
            if (_t _q_method = &ContactInfo::message_time_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (ContactInfo::*)();
            if (_t _q_method = &ContactInfo::messages_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (ContactInfo::*)();
            if (_t _q_method = &ContactInfo::is_typing_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (ContactInfo::*)();
            if (_t _q_method = &ContactInfo::secret_question_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (ContactInfo::*)();
            if (_t _q_method = &ContactInfo::secret_answer_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (ContactInfo::*)();
            if (_t _q_method = &ContactInfo::popup_message_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (ContactInfo::*)();
            if (_t _q_method = &ContactInfo::login_status_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 14;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 14:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ChatListModel* >(); break;
        }
    }  else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ContactInfo *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->first_name(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->chat_ID(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->last_name(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->phone_number(); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->status(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->image_url(); break;
        case 6: *reinterpret_cast< int*>(_v) = _t->unread_message(); break;
        case 7: *reinterpret_cast< QString*>(_v) = _t->is_typing(); break;
        case 8: *reinterpret_cast< QString*>(_v) = _t->message_time(); break;
        case 9: *reinterpret_cast< QString*>(_v) = _t->last_message_time(); break;
        case 10: *reinterpret_cast< QString*>(_v) = _t->secret_question(); break;
        case 11: *reinterpret_cast< QString*>(_v) = _t->secret_answer(); break;
        case 12: *reinterpret_cast< QString*>(_v) = _t->popup_message(); break;
        case 13: *reinterpret_cast< bool*>(_v) = _t->login_status(); break;
        case 14: *reinterpret_cast< ChatListModel**>(_v) = _t->messages(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<ContactInfo *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->set_first_name(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->set_chat_ID(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->set_last_name(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->set_phone_number(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->set_status(*reinterpret_cast< bool*>(_v)); break;
        case 5: _t->set_image_url(*reinterpret_cast< QString*>(_v)); break;
        case 6: _t->set_unread_message(*reinterpret_cast< int*>(_v)); break;
        case 7: _t->set_is_typing(*reinterpret_cast< QString*>(_v)); break;
        case 8: _t->set_message_time(*reinterpret_cast< QString*>(_v)); break;
        case 9: _t->set_last_message_time(*reinterpret_cast< QString*>(_v)); break;
        case 10: _t->set_secret_question(*reinterpret_cast< QString*>(_v)); break;
        case 11: _t->set_secret_answer(*reinterpret_cast< QString*>(_v)); break;
        case 12: _t->set_popup_message(*reinterpret_cast< QString*>(_v)); break;
        case 13: _t->set_login_status(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *ContactInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ContactInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSContactInfoENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ContactInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void ContactInfo::first_name_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ContactInfo::last_name_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ContactInfo::phone_number_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ContactInfo::status_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ContactInfo::image_url_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void ContactInfo::unread_message_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void ContactInfo::chat_ID_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void ContactInfo::last_message_time_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void ContactInfo::message_time_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void ContactInfo::messages_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void ContactInfo::is_typing_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void ContactInfo::secret_question_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void ContactInfo::secret_answer_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void ContactInfo::popup_message_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void ContactInfo::login_status_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}
QT_WARNING_POP
