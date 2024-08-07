#include "GroupInfo.h"

GroupInfo::GroupInfo(QObject *parent)
    : QObject(parent), _group_messages(new GroupChatListModel(this)) {}

GroupInfo::GroupInfo(const int &group_ID, const QString &group_name, const QHash<int, QString> &members_list, const QString &group_image_url, const int &group_unread_message, QObject *parent)
    : QObject(parent),
      _group_ID(group_ID),
      _group_name(group_name),
      _members_list(members_list),
      _group_image_url(group_image_url),
      _group_unread_message(group_unread_message),
      _group_messages(new GroupChatListModel(this)) {}

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

const QHash<int, QString> &GroupInfo::members_list() const
{
    return _members_list;
}

void GroupInfo::set_members_list(const QHash<int, QString> &new_members_list)
{
    if (_members_list == new_members_list)
        return;

    _members_list = new_members_list;

    emit members_list_changed();
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

GroupChatListModel *GroupInfo::group_messages() const
{
    return _group_messages;
}

void GroupInfo::add_group_message(GroupMessageInfo *message)
{
    _group_messages->append(message);

    emit group_messages_changed();
}
