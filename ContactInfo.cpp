#include "ContactInfo.h"

ContactInfo::ContactInfo(QObject *parent)
    : QObject(parent), _messages(new ChatListModel(this)) {}

ContactInfo::ContactInfo(const int &chat_ID, const QString &first_name, const QString &last_name, const int &phone_number, const bool &status, const QString &image_url, const int &unread_message, QObject *parent)
    : QObject(parent),
      _chat_ID(chat_ID),
      _first_name(first_name),
      _last_name(last_name),
      _phone_number(phone_number),
      _status(status),
      _image_url(image_url),
      _unread_message(unread_message),
      _messages(new ChatListModel(this)) {}

const QString &ContactInfo::first_name() const
{
    return _first_name;
}

const QString &ContactInfo::last_name() const
{
    return _last_name;
}

void ContactInfo::set_first_name(const QString &new_first_name)
{
    if (!_first_name.compare(new_first_name))
        return;

    _first_name = new_first_name;

    emit first_name_changed();
}

void ContactInfo::set_last_name(const QString &new_last_name)
{
    if (!_last_name.compare(new_last_name))
        return;

    _last_name = new_last_name;

    emit last_name_changed();
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

const int &ContactInfo::chat_ID() const
{
    return _chat_ID;
}

void ContactInfo::set_chat_ID(const int &new_ID)
{
    if (_chat_ID == new_ID)
        return;

    _chat_ID = new_ID;

    emit chat_ID_changed();
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

QDateTime ContactInfo::last_message_time() const
{
    return _last_message_time;
}

void ContactInfo::set_last_message_time(const QDateTime &time)
{
    if (_last_message_time != time)
        _last_message_time = time;
}