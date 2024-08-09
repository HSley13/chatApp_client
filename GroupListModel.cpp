#include "GroupListModel.h"
#include "MediaController.h"
#include "GroupMessageInfo.h"

GroupListModel::GroupListModel(QAbstractListModel *parent)
    : QAbstractListModel(parent),
      _main_user(new ContactInfo(0, "Sley", 1234, true, "qrc:/QML/ClientApp/icons/name_icon.png", 0, this)),
      _active_group_chat(Q_NULLPTR),
      _group_proxy_list(new GroupProxyList(this)),
      _contact_list_model(new ContactListModel(this))
{
    GroupInfo *avengers = new GroupInfo(1111, "Avengers", {}, "qrc:/QML/ClientApp/icons/avengers_icon.png", 1, this);
    avengers->add_group_message(new GroupMessageInfo("Avengers Assemble", "", "", 3333, "Chris Evans", this));
    avengers->set_group_members(_contact_list_model->contacts());
    _groups.append(avengers);

    GroupInfo *deadpool_wolverine = new GroupInfo(2222, "DeadPool & Wolverine", {}, "https://lumiere-a.akamaihd.net/v1/images/deadpool_wolverine_mobile_640x480_ad8020fd.png", 1, this);
    deadpool_wolverine->add_group_message(new GroupMessageInfo("Let's get the People what They came for", "", "", 4444, "Ryan Reynolds", this));
    _groups.append(deadpool_wolverine);

    GroupInfo *justiceLeague = new GroupInfo(3333, "Justice League", {}, "qrc:/QML/ClientApp/icons/justice_league_icon.png", 1, this);
    justiceLeague->add_group_message(new GroupMessageInfo("Superman, tell me, do u bleed?", "", "", 5555, "Ben Affleck", this));
    _groups.append(justiceLeague);

    _group_proxy_list->setSourceModel(this);
}

ContactListModel *GroupListModel::contact_list_model() const
{
    return _contact_list_model;
}

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

ContactInfo *GroupListModel::main_user() const
{
    return _main_user;
}

void GroupListModel::group_message_sent(const QString &group_message)
{
    if (_active_group_chat == Q_NULLPTR)
        return;

    GroupMessageInfo *new_message = new GroupMessageInfo(group_message, "", "", _main_user->phone_number(), "", _active_group_chat);
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

    GroupMessageInfo *new_message = new GroupMessageInfo("", MediaController::_audio_path, "", _main_user->phone_number(), "", _active_group_chat);
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

    GroupMessageInfo *new_message = new GroupMessageInfo("", "", MediaController::_file_path, _main_user->phone_number(), "", _active_group_chat);
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
    case GroupMembersRole:
        group_info->set_group_members(value.value<QList<ContactInfo *>>());
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

void GroupListModel::add_group(const QString &group_name, const QStringList &members_list)
{
    beginInsertRows(QModelIndex(), _groups.count(), _groups.count());

    GroupInfo *new_group = new GroupInfo(9999, group_name, {}, "https://lumiere-a.akamaihd.net/v1/images/deadpool_wolverine_mobile_640x480_ad8020fd.png", 1, this);
    new_group->add_group_message(new GroupMessageInfo("New Group", "", "", 9999, "", this));
    _groups.append(new_group);

    endInsertRows();

    emit groups_changed();
}