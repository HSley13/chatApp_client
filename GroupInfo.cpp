#include "GroupInfo.h"

GroupInfo::GroupInfo(QObject *parent)
    : QObject(parent), _group_messages(new GroupChatListModel(this)) {}

GroupInfo::GroupInfo(const int &group_ID, const int &group_admin, const QString &group_name, const QList<ContactInfo *> &group_members, const QString &group_image_url, const int &group_unread_message, QObject *parent)
    : QObject(parent),
      _group_ID(group_ID),
      _group_admin(group_admin),
      _group_name(group_name),
      _group_members(group_members),
      _group_image_url(group_image_url),
      _group_unread_message(group_unread_message),
      _group_messages(new GroupChatListModel(this)) {}

GroupInfo::~GroupInfo() { _group_members.clear(); }

const QString &GroupInfo::group_name() const
{
    return _group_name;
}

void GroupInfo::set_group_name(const QString &new_group_name)
{
    if (!_group_name.compare(new_group_name))
        return;

    _group_name = new_group_name;

    emit group_name_changed();
}

const QList<ContactInfo *> &GroupInfo::group_members() const
{
    return _group_members;
}

void GroupInfo::add_group_members(ContactInfo *new_member)
{
    if (_group_members.contains(new_member))
        return;

    _group_members.append(new_member);

    emit group_members_changed();
}

const QString &GroupInfo::group_image_url() const
{
    return _group_image_url;
}

void GroupInfo::set_group_image_url(const QString &group_new_image_url)
{
    if (!_group_image_url.compare(group_new_image_url))
        return;

    _group_image_url = group_new_image_url;

    emit group_image_url_changed();
}

const int &GroupInfo::group_unread_message() const
{
    return _group_unread_message;
}

void GroupInfo::set_group_unread_message(const int &group_new_unread_message)
{
    if (_group_unread_message == group_new_unread_message)
        return;

    _group_unread_message = group_new_unread_message;

    emit group_unread_message_changed();
}

const int &GroupInfo::group_ID() const
{
    return _group_ID;
}

void GroupInfo::set_group_ID(const int &new_ID)
{
    if (_group_ID == new_ID)
        return;

    _group_ID = new_ID;

    emit group_ID_changed();
}

const int &GroupInfo::group_admin() const
{
    return _group_admin;
}

void GroupInfo::set_group_admin(const int &new_admin)
{
    if (_group_admin == new_admin)
        return;

    _group_admin = new_admin;

    emit group_admin_changed();
}

GroupChatListModel *GroupInfo::group_messages() const
{
    return _group_messages;
}

void GroupInfo::add_group_message(GroupMessageInfo *message)
{
    _group_messages->append(message);

    emit group_messages_changed();
}

QDateTime GroupInfo::last_message_time() const
{
    return _last_message_time;
}

void GroupInfo::set_last_message_time(const QDateTime &time)
{
    if (_last_message_time != time)
        _last_message_time = time;
}

const QString &GroupInfo::group_is_typing() const
{
    return _group_is_typing;
}

void GroupInfo::set_group_is_typing(const QString &new_group_is_typing)
{
    _group_is_typing = new_group_is_typing;

    emit group_is_typing_changed();
}
