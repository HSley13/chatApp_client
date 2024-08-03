#include "ContactInfo.h"

ContactInfo::ContactInfo(QObject *parent)
    : QObject(parent), _messages(new ChatListModel(this)) {}

ContactInfo::ContactInfo(const int &conversation_ID, const QString &name, const int &phone_number, const bool &status, const QString &image_url, const int &unread_message, QObject *parent)
    : QObject(parent),
      _conversation_ID(conversation_ID), _name(name),
      _phone_number(phone_number),
      _status(status),
      _image_url(image_url),
      _unread_message(unread_message),
      _messages(new ChatListModel(this)) {}

const QString &ContactInfo::name() const
{
    return _name;
}

void ContactInfo::set_name(const QString &new_name)
{
    if (!_name.compare(new_name))
        return;

    _name = new_name;

    emit name_changed();
}

const int &ContactInfo::phone_number() const
{
    return _phone_number;
}

void ContactInfo::set_phone_number(const int &new_phone_number)
{
    if (_phone_number == new_phone_number)
        return;

    _phone_number = new_phone_number;

    emit phone_number_changed();
}

const bool &ContactInfo::status() const
{
    return _status;
}

void ContactInfo::set_status(const bool &new_status)
{
    if (_status == new_status)
        return;

    _status = new_status;

    emit status_changed();
}

const QString &ContactInfo::image_url() const
{
    return _image_url;
}

void ContactInfo::set_image_url(const QString &new_image_url)
{
    if (!_image_url.compare(new_image_url))
        return;

    _image_url = new_image_url;

    emit image_url_changed();
}

const int &ContactInfo::unread_message() const
{
    return _unread_message;
}

void ContactInfo::set_unread_message(const int &new_unread_message)
{
    if (_unread_message == new_unread_message)
        return;

    _unread_message = new_unread_message;

    emit unread_message_changed();
}

const int &ContactInfo::conversation_ID() const
{
    return _conversation_ID;
}

void ContactInfo::set_conversation_ID(const int &new_ID)
{
    if (_conversation_ID == new_ID)
        return;

    _conversation_ID = new_ID;

    emit conversation_ID_changed();
}

ChatListModel *ContactInfo::messages() const
{
    return _messages;
}

void ContactInfo::add_message(MessageInfo *message)
{
    _messages->append(message);

    emit messages_changed();
}