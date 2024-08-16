#include "GroupListModel.h"
#include "MediaController.h"
#include "ContactListModel.h"
#include "GroupMessageInfo.h"

GroupInfo *GroupListModel::_active_group_chat{Q_NULLPTR};

GroupListModel::GroupListModel(QAbstractListModel *parent)
    : QAbstractListModel(parent),
      _group_proxy_list(new GroupProxyList(this))
{
    _group_proxy_list->setSourceModel(this);

    _client_manager = ClientManager::instance();

    connect(_client_manager, &ClientManager::load_groups, this, &GroupListModel::on_load_groups);
    connect(_client_manager, &ClientManager::group_text_received, this, &GroupListModel::on_group_text_received);
    connect(_client_manager, &ClientManager::group_profile_image, this, &GroupListModel::on_group_profile_image);
    connect(_client_manager, &ClientManager::group_file_received, this, &GroupListModel::on_group_file_received);
    connect(_client_manager, &ClientManager::group_is_typing_received, this, &GroupListModel::on_group_is_typing_received);
}

GroupListModel::~GroupListModel() { _groups.clear(); }

const QList<GroupInfo *> &GroupListModel::groups() const
{
    return _groups;
}

void GroupListModel::set_groups(const QList<GroupInfo *> &new_groups)
{
    if (_groups == new_groups)
        return;

    _groups = new_groups;

    emit groups_changed();
}

GroupInfo *GroupListModel::active_group_chat()
{
    return _active_group_chat;
}

void GroupListModel::set_active_group_chat(GroupInfo *new_group)
{
    if (_active_group_chat == new_group)
        return;

    _active_group_chat = new_group;

    emit active_group_chat_changed();
}

int GroupListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return _groups.count();
}

QVariant GroupListModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= _groups.count())
        return QVariant();

    GroupInfo *group_info = _groups[index.row()];

    switch (GroupRoles(role))
    {
    case GroupIDRole:
        return group_info->group_ID();
    case GroupAdminRole:
        return group_info->group_admin();
    case GroupNameRole:
        return group_info->group_name();
    case GroupIsTypingRole:
        return group_info->group_is_typing();
    case GroupMembersRole:
        return QVariant::fromValue(group_info->group_members());
    case GroupUnreadMessageRole:
        return group_info->group_unread_message();
    case GroupMessagesRole:
        return QVariant::fromValue(group_info->group_messages());
    case GroupImageUrlRole:
        return group_info->group_image_url();
    case GroupObjectRole:
        return QVariant::fromValue(group_info);
    case LastMessageTimeRole:
        return QVariant::fromValue(group_info->last_message_time());
    default:
        return QVariant();
    }
}

bool GroupListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.row() < 0 || index.row() >= _groups.count())
        return false;

    GroupInfo *group_info = _groups[index.row()];

    switch (GroupRoles(role))
    {
    case GroupNameRole:
        group_info->set_group_name(value.toString());
        break;
    case GroupAdminRole:
        group_info->set_group_admin(value.toInt());
        break;
    case GroupIsTypingRole:
        group_info->set_group_is_typing(value.toString());
        break;
    case GroupUnreadMessageRole:
        group_info->set_group_unread_message(value.toInt());
        break;
    case LastMessageTimeRole:
        group_info->set_last_message_time(value.value<QDateTime>());
        break;
    default:
        return false;
    }

    emit dataChanged(index, index, {role});
    return true;
}

QHash<int, QByteArray> GroupListModel::roleNames() const
{
    QHash<int, QByteArray> roles{};

    roles[GroupIDRole] = "group_ID";
    roles[GroupIsTypingRole] = "group_is_typing";
    roles[GroupAdminRole] = "group_admin";
    roles[GroupNameRole] = "group_name";
    roles[GroupMembersRole] = "group_members";
    roles[GroupUnreadMessageRole] = "group_unread_message";
    roles[GroupMessagesRole] = "group_messages";
    roles[GroupImageUrlRole] = "group_image_url";
    roles[GroupObjectRole] = "group_contact_object";
    roles[LastMessageTimeRole] = "last_message_time";

    return roles;
}

GroupProxyList *GroupListModel::group_proxy_list() const
{
    return _group_proxy_list;
}

void GroupListModel::add_group(const QString &group_name, const QList<ContactInfo *> members)
{
    QJsonArray json_array;
    for (ContactInfo *contact : members)
        json_array.append(contact->phone_number());

    json_array.append(ContactListModel::main_user()->phone_number());

    _client_manager->new_group(group_name, json_array);
}

void GroupListModel::on_load_groups(QJsonArray json_array)
{
    if (json_array.isEmpty())
        return;

    for (const QJsonValue &groups : json_array)
    {
        QJsonArray members_ID = groups["group_members"].toArray();
        QJsonArray messages = groups["group_messages"].toArray();

        QList<ContactInfo *> group_members;
        for (QJsonValue ID : members_ID)
        {
            if (ContactListModel::main_user()->phone_number() == ID.toInt())
                continue;

            for (ContactInfo *contact : *ContactListModel::_contacts_ptr)
            {
                if (contact->phone_number() == ID.toInt())
                {
                    group_members << contact;
                    break;
                }
            }
        }

        GroupInfo *group = new GroupInfo(groups["_id"].toInt(), groups["group_admin"].toInt(), groups["group_name"].toString(), group_members, groups["group_image_url"].toString(), groups["unread_messages"].toInt(), this);

        // FIXME: messageObj["timestamp"].toString()  --> add the real timestamp

        if (!messages.isEmpty())
        {
            for (const QJsonValue &message : messages)
                group->add_group_message(new GroupMessageInfo(message["message"].toString(), QString(), message["file_url"].toString(), message["sender_ID"].toInt(), message["sender_name"].toString(), message["time"].toString(), this));
        }

        beginInsertRows(QModelIndex(), _groups.count(), _groups.count());
        _groups.append(group);
        endInsertRows();

        group_members.clear();
    }

    emit groups_changed();
}

void GroupListModel::on_group_profile_image(const int &group_ID, const QString &group_image_url)
{
    if (!group_ID || group_image_url.isEmpty())
        return;

    for (size_t i{0}; i < _groups.size(); i++)
    {
        GroupInfo *group = _groups[i];
        if (group->group_ID() == group_ID)
        {
            group->set_group_image_url(group_image_url);

            QModelIndex index = createIndex(i, 0);
            emit dataChanged(index, index, {GroupImageUrlRole});

            return;
        }
    }
}

void GroupListModel::on_group_text_received(const int &groupID, const int &sender_ID, QString sender_name, const QString &message, const QString &time)
{
    for (GroupInfo *group : _groups)
    {
        if (group->group_ID() == groupID)
        {
            group->add_group_message(new GroupMessageInfo(message, QString(), QString(), sender_ID, sender_name, time, this));
            group->set_last_message_time(QDateTime::currentDateTime());
            QModelIndex top_left = index(0, 0);
            QModelIndex bottom_right = index(_groups.size() - 1, 0);
            emit dataChanged(top_left, bottom_right, {LastMessageTimeRole});

            return;
        }
    }
}

void GroupListModel::on_group_file_received(const int &groupID, const int &sender_ID, const QString &sender_name, const QString &file_url, const QString &time)
{
    for (GroupInfo *group : _groups)
    {
        if (group->group_ID() == groupID)
        {
            group->add_group_message(new GroupMessageInfo(QString(), QString(), file_url, sender_ID, sender_name, time, this));
            group->set_last_message_time(QDateTime::currentDateTime());
            QModelIndex top_left = index(0, 0);
            QModelIndex bottom_right = index(_groups.size() - 1, 0);
            emit dataChanged(top_left, bottom_right, {LastMessageTimeRole});

            return;
        }
    }
}

void GroupListModel::on_group_is_typing_received(const int &groupID, const int &sender_ID)
{
    if (!groupID || !sender_ID)
        return;

    for (size_t i{0}; i < _groups.size(); i++)
    {
        GroupInfo *group = _groups[i];
        if (group->group_ID() == groupID)
        {
            QString sender_name{QString::number(sender_ID)};

            for (ContactInfo *contact : *ContactListModel::_contacts_ptr)
            {
                if (contact->phone_number() == sender_ID)
                {
                    sender_name = contact->first_name();
                    break;
                }
            }

            group->set_group_is_typing(QString("%1 %2").arg(sender_name, "is typing..."));
            QModelIndex index = createIndex(i, 0);
            emit dataChanged(index, index, {GroupIsTypingRole});

            QTimer::singleShot(2000, this, [=]()
                               {    group->set_group_is_typing(QString());
                                    QModelIndex index = createIndex(i, 0);
                                    emit dataChanged(index, index, {GroupIsTypingRole}); });
            return;
        }
    }
}