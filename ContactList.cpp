#include "ContactList.h"

ContactList::ContactList(QObject *parent)
    : QObject(parent),
      _main_user(new ChatInfo(0, "Sley", 1234, "online", "qrc:/QML/ClientApp/icons/name_icon.png", "", "", this)),
      _open_chat_user(Q_NULLPTR)
{
    _contacts.append(new ChatInfo(1, "Sley HORTES", 1111, "Online", "qrc:/QML/ClientApp/icons/name_icon.png", "2", "Hello World", this));
    _contacts.append(new ChatInfo(2, "Bruce Wayne", 2222, "Online", "qrc:/QML/ClientApp/icons/batman_icon1.png", "1", "I have killed the Joker", this));
    _contacts.append(new ChatInfo(3, "Tony Stark", 3333, "Offline", "qrc:/QML/ClientApp/icons/ironman_icon.png", "6", "I survived the Snap in EndGame", this));
    _contacts.append(new ChatInfo(4, "Clark Kent", 4444, "Offline", "qrc:/QML/ClientApp/icons/superman_icon.png", "2", "I killed Doomsday", this));
    _contacts.append(new ChatInfo(5, "Steve Rogers", 5555, "Online", "qrc:/QML/ClientApp/icons/captain_icon.png", "3", "I had the dance with Peggy", this));

    connect(this, &ContactList::send_message, this, &ContactList::on_send_message);
}

const QList<ChatInfo *> &ContactList::contacts() const
{
    return _contacts;
}

void ContactList::set_contacts(const QList<ChatInfo *> &new_contacts)
{
    if (_contacts == new_contacts)
        return;

    _contacts = new_contacts;
    emit contacts_changed();
}

ChatInfo *ContactList::open_chat_user() const
{
    return _open_chat_user;
}

void ContactList::set_open_chat_user(ChatInfo *new_chat)
{
    if (_open_chat_user == new_chat)
        return;

    _open_chat_user = new_chat;
    emit open_chat_user_changed();
}

ChatInfo *ContactList::main_user() const
{
    return _main_user;
}

void ContactList::on_send_message(const QString &message)
{
    if (_open_chat_user == Q_NULLPTR)
        return;

    _open_chat_user->add_message(new MessageInfo(message, _open_chat_user->phone_number(), _open_chat_user));
}
