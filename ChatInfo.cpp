#include "ChatInfo.h"

ChatInfo::ChatInfo(const int &conversation_ID, const QString &name, const int &phone_number, const bool &status, const QString &image_url, const int &unread_message, QObject *parent)
    : QObject(parent),
      _conversation_ID(conversation_ID), _name(name),
      _phone_number(phone_number),
      _status(status),
      _image_url(image_url),
      _messages(new ChatListModel(this)),
      _unread_message(unread_message) {}

const QString &ChatInfo::name() const
{
    return _name;
}

void ChatInfo::set_name(const QString &new_name)
{
    if (!_name.compare(new_name))
        return;

    _name = new_name;

    emit name_changed();
}

const int &ChatInfo::phone_number() const
{
    return _phone_number;
}

void ChatInfo::set_phone_number(const int &new_phone_number)
{
    if (_phone_number == new_phone_number)
        return;

    _phone_number = new_phone_number;

    emit phone_number_changed();
}

const bool &ChatInfo::status() const
{
    return _status;
}

void ChatInfo::set_status(const bool &new_status)
{
    if (_status == new_status)
        return;

    _status = new_status;

    emit status_changed();
}

const QString &ChatInfo::image_url() const
{
    return _image_url;
}

void ChatInfo::set_image_url(const QString &new_image_url)
{
    if (!_image_url.compare(new_image_url))
        return;

    _image_url = new_image_url;

    emit image_url_changed();
}

const int &ChatInfo::unread_message() const
{
    return _unread_message;
}

void ChatInfo::set_unread_message(const int &new_unread_message)
{
    if (_unread_message == new_unread_message)
        return;

    _unread_message = new_unread_message;

    emit unread_message_changed();
}

const QString &ChatInfo::last_message() const
{
    return _last_message;
}

void ChatInfo::set_last_message(const QString &new_last_message)
{
    if (_last_message == new_last_message)
        return;

    _last_message = new_last_message;

    emit last_message_changed();
}

const int &ChatInfo::conversation_ID() const
{
    return _conversation_ID;
}

void ChatInfo::set_conversation_ID(const int &new_ID)
{
    if (_conversation_ID == new_ID)
        return;

    _conversation_ID = new_ID;

    emit conversation_ID_changed();
}

ChatListModel *ChatInfo::messages() const
{
    return _messages;
}

void ChatInfo::add_message(MessageInfo *message)
{
    _messages->append(message);

    emit messages_changed();
}