#include "GroupListModel.h"
#include "MediaController.h"
#include "GroupMessageInfo.h"

GroupListModel::GroupListModel(QAbstractListModel *parent)
    : QAbstractListModel(parent),
      _active_group_chat(Q_NULLPTR),
      _group_proxy_list(new GroupProxyList(this))
{
    GroupInfo *avengers = new GroupInfo(1111, "Avengers", *ContactListModel::_contacts_ptr, "qrc:/QML/ClientApp/icons/avengers_icon.png", 1, this);
    avengers->add_group_message(new GroupMessageInfo("Avengers Assemble", QString(), QString(), 3333, "Chris Evans", QTime::currentTime().toString("HH:mm"), this));
    _groups.append(avengers);

    GroupInfo *deadpool_wolverine = new GroupInfo(2222, "DeadPool & Wolverine", {}, "https://lumiere-a.akamaihd.net/v1/images/deadpool_wolverine_mobile_640x480_ad8020fd.png", 1, this);
    deadpool_wolverine->add_group_message(new GroupMessageInfo("Let's get the People what They came for", QString(), QString(), 4444, "Ryan Reynolds", QTime::currentTime().toString("HH:mm"), this));
    _groups.append(deadpool_wolverine);

    GroupInfo *justiceLeague = new GroupInfo(3333, "Justice League", {}, "qrc:/QML/ClientApp/icons/justice_league_icon.png", 1, this);
    justiceLeague->add_group_message(new GroupMessageInfo("Superman, tell me, do u bleed?", QString(), QString(), 5555, "Ben Affleck", QTime::currentTime().toString("HH:mm"), this));
    _groups.append(justiceLeague);

    _group_proxy_list->setSourceModel(this);

    _client_manager = ClientManager::instance();
    connect(_client_manager, &ClientManager::load_groups, this, &GroupListModel::on_load_groups);
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

GroupInfo *GroupListModel::active_group_chat() const
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

void GroupListModel::group_message_sent(const QString &group_message)
{
    if (_active_group_chat == Q_NULLPTR)
        return;

    GroupMessageInfo *new_message = new GroupMessageInfo(group_message, QString(), QString(), ContactListModel::main_user()->phone_number(), QString(), QTime::currentTime().toString("HH:mm"), _active_group_chat);
    _active_group_chat->add_group_message(new_message);

    _active_group_chat->set_last_message_time(QDateTime::currentDateTime());
    QModelIndex top_left = index(0, 0);
    QModelIndex bottom_right = index(_groups.size() - 1, 0);
    emit dataChanged(top_left, bottom_right, {LastMessageTimeRole});
}

void GroupListModel::group_audio_sent()
{
    if (_active_group_chat == Q_NULLPTR || MediaController::_audio_path.isEmpty())
        return;

    GroupMessageInfo *new_message = new GroupMessageInfo(QString(), MediaController::_audio_path, QString(), ContactListModel::main_user()->phone_number(), QString(), QTime::currentTime().toString("HH:mm"), _active_group_chat);
    _active_group_chat->add_group_message(new_message);
    MediaController::_audio_path = QString();

    _active_group_chat->set_last_message_time(QDateTime::currentDateTime());
    QModelIndex top_left = index(0, 0);
    QModelIndex bottom_right = index(_groups.size() - 1, 0);
    emit dataChanged(top_left, bottom_right, {LastMessageTimeRole});
}

void GroupListModel::group_file_sent()
{
    if (_active_group_chat == Q_NULLPTR || MediaController::_file_path.isEmpty())
        return;

    GroupMessageInfo *new_message = new GroupMessageInfo(QString(), QString(), MediaController::_file_path, ContactListModel::main_user()->phone_number(), QString(), QTime::currentTime().toString("HH:mm"), _active_group_chat);
    _active_group_chat->add_group_message(new_message);
    MediaController::_file_path = QString();

    _active_group_chat->set_last_message_time(QDateTime::currentDateTime());
    QModelIndex top_left = index(0, 0);
    QModelIndex bottom_right = index(_groups.size() - 1, 0);
    emit dataChanged(top_left, bottom_right, {LastMessageTimeRole});
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
    case GroupNameRole:
        return group_info->group_name();
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

    roles[GroupIDRole] = "Group_ID";
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
    beginInsertRows(QModelIndex(), _groups.count(), _groups.count());

    GroupInfo *new_group = new GroupInfo(9999, group_name, members, "https://lumiere-a.akamaihd.net/v1/images/deadpool_wolverine_mobile_640x480_ad8020fd.png", 1, this);
    new_group->add_group_message(new GroupMessageInfo("New Group", QString(), QString(), 9999, QString(), QTime::currentTime().toString("HH:mm"), this));
    _groups.append(new_group);

    endInsertRows();

    emit groups_changed();
}

void GroupListModel::on_load_groups(QJsonArray json_array)
{
    if (json_array.isEmpty())
    {
        qDebug() << "JsonArray is empty, on_load_groups";
        return;
    }

    for (const QJsonValue &groups : json_array)
    {
        QJsonArray members_ID = groups["membersID"].toArray();
        QJsonArray messages = groups["messages"].toArray();

        QList<ContactInfo *> group_members;

        for (QJsonValue ID : members_ID)
        {
            bool found = false;

            for (ContactInfo *contact : *ContactListModel::_contacts_ptr)
            {
                if (ContactListModel::main_user()->phone_number() == ID.toInt())
                    break;

                if (contact->phone_number() == ID.toInt())
                {
                    group_members << contact;
                    break;
                }
            }
        }

        GroupInfo *group = new GroupInfo(groups["_id"].toInt(), groups["groupName"].toString(), group_members, groups["imageUrl"].toString(), 1, this);

        // FIXME: messageObj["timestamp"].toString()  --> add the real timestamp
        for (const QJsonValue &message : messages)
            group->add_group_message(new GroupMessageInfo(message["message"].toString(), QString(), QString(), message["sender"].toInt(), message["sender"].toString(), QTime::currentTime().toString("HH:mm"), this));

        beginInsertRows(QModelIndex(), _groups.count(), _groups.count());
        _groups.append(group);
        endInsertRows();

        group_members.clear();
    }

    emit groups_changed();
}