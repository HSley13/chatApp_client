#include "ChatInfo.h"

ChatInfo::ChatInfo(const int &conversation_ID, const QString &name, const int &phone_number, const QString &status, const QString &image_url, const QString &message_count, const QString &last_message, QObject *parent)
    : QObject(parent),
      _conversation_ID(conversation_ID), _name(name),
      _phone_number(phone_number),
      _status(status),
      _image_url(image_url),
      _message_count(message_count),
      _last_message(last_message) {}

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

const QString &ChatInfo::status() const
{
    return _status;
}

void ChatInfo::set_status(const QString &new_status)
{
    if (!_status.compare(new_status))
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

const QString &ChatInfo::message_count() const
{
    return _message_count;
}

void ChatInfo::set_message_count(const QString &new_message_count)
{
    if (!_message_count.compare(new_message_count))
        return;

    _message_count = new_message_count;

    emit message_count_changed();
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

const QList<MessageInfo *> &ChatInfo::messages()
{
    return _messages;
}

void ChatInfo::set_messages(QList<MessageInfo *> new_message)
{
    if (_messages == new_message)
        return;

    _messages = new_message;

    emit messages_changed();
}

void ChatInfo::add_message(MessageInfo *message)
{
    _messages.append(message);

    emit messages_changed();
}