/****************************************************************************
** Meta object code from reading C++ file 'ClientManager.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/ClientManager.hpp"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ClientManager.hpp' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSClientManagerENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSClientManagerENDCLASS = QtMocHelpers::stringData(
    "ClientManager",
    "QML.Element",
    "auto",
    "load_contacts",
    "",
    "contacts",
    "load_groups",
    "json_array",
    "load_my_info",
    "my_info",
    "profile_image",
    "image_url",
    "group_profile_image",
    "group_ID",
    "text_received",
    "chatID",
    "sender_ID",
    "message",
    "time",
    "client_connected_disconnected",
    "phone_number",
    "true_or_false",
    "client_profile_image",
    "groupID",
    "group_name",
    "group_text_received",
    "sender_name",
    "file_received",
    "file_url",
    "group_file_received",
    "audio_received",
    "audio_url",
    "group_audio_received",
    "GroupID",
    "is_typing_received",
    "group_is_typing_received",
    "update_client_info",
    "first_name",
    "last_name",
    "disconnected",
    "question_answer",
    "secret_question",
    "secret_answer",
    "status_message",
    "pop_message_received",
    "remove_group_member_received",
    "group_members",
    "add_group_member_received",
    "new_group_members",
    "removed_from_group",
    "delete_message_received",
    "full_time",
    "delete_group_message_received",
    "socket_disconnected",
    "on_text_message_received",
    "data",
    "on_disconnected",
    "sign_up",
    "password",
    "password_confirmation",
    "login_request",
    "update_info",
    "update_password",
    "retrieve_question",
    "profile_image_deleted",
    "disconnect",
    "send_text",
    "receiver",
    "chat_ID",
    "send_group_text",
    "send_is_typing",
    "send_group_is_typing",
    "delete_message",
    "delete_account",
    "delete_group_message"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSClientManagerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       1,   14, // classinfo
      43,   16, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      27,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       3,    1,  274,    4, 0x06,    1 /* Public */,
       6,    1,  277,    4, 0x06,    3 /* Public */,
       8,    1,  280,    4, 0x06,    5 /* Public */,
      10,    1,  283,    4, 0x06,    7 /* Public */,
      12,    2,  286,    4, 0x06,    9 /* Public */,
      14,    4,  291,    4, 0x06,   12 /* Public */,
      19,    2,  300,    4, 0x06,   17 /* Public */,
      22,    2,  305,    4, 0x06,   20 /* Public */,
      13,    2,  310,    4, 0x06,   23 /* Public */,
      25,    5,  315,    4, 0x06,   26 /* Public */,
      27,    4,  326,    4, 0x06,   32 /* Public */,
      29,    5,  335,    4, 0x06,   37 /* Public */,
      30,    4,  346,    4, 0x06,   43 /* Public */,
      32,    5,  355,    4, 0x06,   48 /* Public */,
      34,    1,  366,    4, 0x06,   54 /* Public */,
      35,    2,  369,    4, 0x06,   56 /* Public */,
      36,    3,  374,    4, 0x06,   59 /* Public */,
      39,    0,  381,    4, 0x06,   63 /* Public */,
      40,    2,  382,    4, 0x06,   64 /* Public */,
      43,    2,  387,    4, 0x06,   67 /* Public */,
      44,    1,  392,    4, 0x06,   70 /* Public */,
      45,    2,  395,    4, 0x06,   72 /* Public */,
      47,    2,  400,    4, 0x06,   75 /* Public */,
      49,    1,  405,    4, 0x06,   78 /* Public */,
      50,    2,  408,    4, 0x06,   80 /* Public */,
      52,    2,  413,    4, 0x06,   83 /* Public */,
      53,    1,  418,    4, 0x06,   86 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      54,    1,  421,    4, 0x0a,   88 /* Public */,
      56,    0,  424,    4, 0x0a,   90 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      57,    7,  425,    4, 0x02,   91 /* Public */,
      60,    2,  440,    4, 0x02,   99 /* Public */,
      61,    3,  445,    4, 0x02,  102 /* Public */,
      62,    2,  452,    4, 0x02,  106 /* Public */,
      63,    1,  457,    4, 0x02,  109 /* Public */,
      64,    0,  460,    4, 0x02,  111 /* Public */,
      65,    0,  461,    4, 0x02,  112 /* Public */,
      66,    3,  462,    4, 0x02,  113 /* Public */,
      69,    3,  469,    4, 0x02,  117 /* Public */,
      70,    1,  476,    4, 0x02,  121 /* Public */,
      71,    2,  479,    4, 0x02,  123 /* Public */,
      72,    3,  484,    4, 0x02,  126 /* Public */,
      73,    0,  491,    4, 0x02,  130 /* Public */,
      74,    2,  492,    4, 0x02,  131 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QJsonArray,    5,
    QMetaType::Void, QMetaType::QJsonArray,    7,
    QMetaType::Void, QMetaType::QJsonObject,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   13,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString,   15,   16,   17,   18,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   20,   21,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   20,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   23,   24,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,   23,   16,   26,   17,   18,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString,   15,   16,   28,   18,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,   23,   16,   26,   28,   18,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString,   15,   16,   31,   18,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,   33,   16,   26,   31,   18,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   23,   26,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString,   20,   37,   38,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   41,   42,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   17,   21,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::Int, QMetaType::QJsonArray,   23,   46,
    QMetaType::Void, QMetaType::Int, QMetaType::QJsonArray,   23,   48,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   15,   51,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   23,   51,
    QMetaType::Void, QMetaType::Bool,   21,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   55,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   20,   37,   38,   58,   59,   41,   42,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   20,   58,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   37,   38,   58,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   20,   58,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Int,   67,   17,   68,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString,   23,   26,   17,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   23,   26,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString,   20,   68,   51,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   23,   51,

       0        // eod
};

Q_CONSTINIT const QMetaObject ClientManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSClientManagerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSClientManagerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // Q_OBJECT / Q_GADGET
        ClientManager,
        // method 'load_contacts'
        void,
        QJsonArray,
        // method 'load_groups'
        void,
        QJsonArray,
        // method 'load_my_info'
        void,
        QJsonObject,
        // method 'profile_image'
        void,
        const QString &,
        // method 'group_profile_image'
        void,
        const int &,
        const QString &,
        // method 'text_received'
        void,
        const int &,
        const int &,
        const QString &,
        const QString &,
        // method 'client_connected_disconnected'
        void,
        const int &,
        const bool &,
        // method 'client_profile_image'
        void,
        const int &,
        const QString &,
        // method 'group_ID'
        void,
        const int &,
        const QString &,
        // method 'group_text_received'
        void,
        const int &,
        const int &,
        QString,
        const QString &,
        const QString &,
        // method 'file_received'
        void,
        const int &,
        const int &,
        const QString &,
        const QString &,
        // method 'group_file_received'
        void,
        const int &,
        const int &,
        const QString &,
        const QString &,
        const QString &,
        // method 'audio_received'
        void,
        const int &,
        const int &,
        const QString &,
        const QString &,
        // method 'group_audio_received'
        void,
        const int &,
        const int &,
        const QString &,
        const QString &,
        const QString &,
        // method 'is_typing_received'
        void,
        const int &,
        // method 'group_is_typing_received'
        void,
        const int &,
        const QString &,
        // method 'update_client_info'
        void,
        const int &,
        const QString &,
        const QString &,
        // method 'disconnected'
        void,
        // method 'question_answer'
        void,
        const QString &,
        const QString &,
        // method 'status_message'
        void,
        const QString &,
        const bool &,
        // method 'pop_message_received'
        void,
        const QString &,
        // method 'remove_group_member_received'
        void,
        const int &,
        QJsonArray,
        // method 'add_group_member_received'
        void,
        const int &,
        const QJsonArray,
        // method 'removed_from_group'
        void,
        const int &,
        // method 'delete_message_received'
        void,
        const int &,
        const QString &,
        // method 'delete_group_message_received'
        void,
        const int &,
        const QString &,
        // method 'socket_disconnected'
        void,
        const bool &,
        // method 'on_text_message_received'
        void,
        const QString &,
        // method 'on_disconnected'
        void,
        // method 'sign_up'
        void,
        const int &,
        const QString &,
        const QString &,
        const QString &,
        const QString &,
        const QString &,
        const QString &,
        // method 'login_request'
        void,
        const int &,
        const QString &,
        // method 'update_info'
        void,
        const QString &,
        const QString &,
        const QString &,
        // method 'update_password'
        void,
        const int &,
        const QString &,
        // method 'retrieve_question'
        void,
        const int &,
        // method 'profile_image_deleted'
        void,
        // method 'disconnect'
        void,
        // method 'send_text'
        void,
        const int &,
        const QString &,
        const int &,
        // method 'send_group_text'
        void,
        const int &,
        QString,
        const QString &,
        // method 'send_is_typing'
        void,
        const int &,
        // method 'send_group_is_typing'
        void,
        const int &,
        const QString &,
        // method 'delete_message'
        void,
        const int &,
        const int &,
        const QString &,
        // method 'delete_account'
        void,
        // method 'delete_group_message'
        void,
        const int &,
        const QString &
    >,
    nullptr
} };

void ClientManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ClientManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->load_contacts((*reinterpret_cast< std::add_pointer_t<QJsonArray>>(_a[1]))); break;
        case 1: _t->load_groups((*reinterpret_cast< std::add_pointer_t<QJsonArray>>(_a[1]))); break;
        case 2: _t->load_my_info((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 3: _t->profile_image((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->group_profile_image((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 5: _t->text_received((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 6: _t->client_connected_disconnected((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 7: _t->client_profile_image((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 8: _t->group_ID((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 9: _t->group_text_received((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        case 10: _t->file_received((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 11: _t->group_file_received((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        case 12: _t->audio_received((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 13: _t->group_audio_received((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        case 14: _t->is_typing_received((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 15: _t->group_is_typing_received((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 16: _t->update_client_info((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 17: _t->disconnected(); break;
        case 18: _t->question_answer((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 19: _t->status_message((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 20: _t->pop_message_received((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 21: _t->remove_group_member_received((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QJsonArray>>(_a[2]))); break;
        case 22: _t->add_group_member_received((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QJsonArray>>(_a[2]))); break;
        case 23: _t->removed_from_group((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 24: _t->delete_message_received((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 25: _t->delete_group_message_received((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 26: _t->socket_disconnected((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 27: _t->on_text_message_received((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 28: _t->on_disconnected(); break;
        case 29: _t->sign_up((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[7]))); break;
        case 30: _t->login_request((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 31: _t->update_info((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 32: _t->update_password((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 33: _t->retrieve_question((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 34: _t->profile_image_deleted(); break;
        case 35: _t->disconnect(); break;
        case 36: _t->send_text((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 37: _t->send_group_text((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 38: _t->send_is_typing((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 39: _t->send_group_is_typing((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 40: _t->delete_message((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 41: _t->delete_account(); break;
        case 42: _t->delete_group_message((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ClientManager::*)(QJsonArray );
            if (_t _q_method = &ClientManager::load_contacts; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)(QJsonArray );
            if (_t _q_method = &ClientManager::load_groups; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)(QJsonObject );
            if (_t _q_method = &ClientManager::load_my_info; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)(const QString & );
            if (_t _q_method = &ClientManager::profile_image; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)(const int & , const QString & );
            if (_t _q_method = &ClientManager::group_profile_image; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)(const int & , const int & , const QString & , const QString & );
            if (_t _q_method = &ClientManager::text_received; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)(const int & , const bool & );
            if (_t _q_method = &ClientManager::client_connected_disconnected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)(const int & , const QString & );
            if (_t _q_method = &ClientManager::client_profile_image; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)(const int & , const QString & );
            if (_t _q_method = &ClientManager::group_ID; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)(const int & , const int & , QString , const QString & , const QString & );
            if (_t _q_method = &ClientManager::group_text_received; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)(const int & , const int & , const QString & , const QString & );
            if (_t _q_method = &ClientManager::file_received; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)(const int & , const int & , const QString & , const QString & , const QString & );
            if (_t _q_method = &ClientManager::group_file_received; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)(const int & , const int & , const QString & , const QString & );
            if (_t _q_method = &ClientManager::audio_received; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)(const int & , const int & , const QString & , const QString & , const QString & );
            if (_t _q_method = &ClientManager::group_audio_received; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)(const int & );
            if (_t _q_method = &ClientManager::is_typing_received; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)(const int & , const QString & );
            if (_t _q_method = &ClientManager::group_is_typing_received; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)(const int & , const QString & , const QString & );
            if (_t _q_method = &ClientManager::update_client_info; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)();
            if (_t _q_method = &ClientManager::disconnected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)(const QString & , const QString & );
            if (_t _q_method = &ClientManager::question_answer; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)(const QString & , const bool & );
            if (_t _q_method = &ClientManager::status_message; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)(const QString & );
            if (_t _q_method = &ClientManager::pop_message_received; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)(const int & , QJsonArray );
            if (_t _q_method = &ClientManager::remove_group_member_received; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)(const int & , const QJsonArray );
            if (_t _q_method = &ClientManager::add_group_member_received; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)(const int & );
            if (_t _q_method = &ClientManager::removed_from_group; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 23;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)(const int & , const QString & );
            if (_t _q_method = &ClientManager::delete_message_received; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 24;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)(const int & , const QString & );
            if (_t _q_method = &ClientManager::delete_group_message_received; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 25;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)(const bool & );
            if (_t _q_method = &ClientManager::socket_disconnected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 26;
                return;
            }
        }
    }
}

const QMetaObject *ClientManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClientManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSClientManagerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ClientManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 43)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 43;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 43)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 43;
    }
    return _id;
}

// SIGNAL 0
void ClientManager::load_contacts(QJsonArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ClientManager::load_groups(QJsonArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ClientManager::load_my_info(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ClientManager::profile_image(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ClientManager::group_profile_image(const int & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ClientManager::text_received(const int & _t1, const int & _t2, const QString & _t3, const QString & _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ClientManager::client_connected_disconnected(const int & _t1, const bool & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void ClientManager::client_profile_image(const int & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void ClientManager::group_ID(const int & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void ClientManager::group_text_received(const int & _t1, const int & _t2, QString _t3, const QString & _t4, const QString & _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void ClientManager::file_received(const int & _t1, const int & _t2, const QString & _t3, const QString & _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void ClientManager::group_file_received(const int & _t1, const int & _t2, const QString & _t3, const QString & _t4, const QString & _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void ClientManager::audio_received(const int & _t1, const int & _t2, const QString & _t3, const QString & _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void ClientManager::group_audio_received(const int & _t1, const int & _t2, const QString & _t3, const QString & _t4, const QString & _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void ClientManager::is_typing_received(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void ClientManager::group_is_typing_received(const int & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void ClientManager::update_client_info(const int & _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void ClientManager::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 17, nullptr);
}

// SIGNAL 18
void ClientManager::question_answer(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void ClientManager::status_message(const QString & _t1, const bool & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void ClientManager::pop_message_received(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void ClientManager::remove_group_member_received(const int & _t1, QJsonArray _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void ClientManager::add_group_member_received(const int & _t1, const QJsonArray _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void ClientManager::removed_from_group(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void ClientManager::delete_message_received(const int & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 24, _a);
}

// SIGNAL 25
void ClientManager::delete_group_message_received(const int & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 25, _a);
}

// SIGNAL 26
void ClientManager::socket_disconnected(const bool & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 26, _a);
}
QT_WARNING_POP
