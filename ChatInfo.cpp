#include "ChatInfo.h"

ChatInfo::ChatInfo(QObject *parent)
    : QObject(parent) {}

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

const QString &ChatInfo::image() const
{
    return _image;
}

void ChatInfo::set_image(const QString &new_image)
{
    if (!_image.compare(new_image))
        return;

    _image = new_image;

    emit image_changed();
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

const QString &ChatInfo::message() const
{
    return _message;
}

void ChatInfo::set_message(const QString &new_message)
{
    if (!_message.compare(new_message))
        return;

    _message = new_message;

    emit message_changed();
}