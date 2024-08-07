#include "GroupListModel.h"
#include "MediaController.h"
#include "GroupMessageInfo.h"

GroupListModel::GroupListModel(QAbstractListModel *parent)
    : QAbstractListModel(parent),
      _main_user(new ContactInfo(0, "Sley", 1234, true, "qrc:/QML/ClientApp/icons/name_icon.png", 0, this)),
      _active_group_chat(Q_NULLPTR),
      _group_proxy_list(new GroupProxyList(this))
{
    GroupInfo *avengers = new GroupInfo(1111, "Avengers", {}, "qrc:/QML/ClientApp/icons/avengers_icon.png", 1, this);
    avengers->add_group_message(new GroupMessageInfo("Avengers Assemble", "", "", 3333, "Chris Evans", this));
    _groups.append(avengers);

    GroupInfo *deadpool_wolverine = new GroupInfo(2222, "DeadPool & Wolverine", {}, "https://lumiere-a.akamaihd.net/v1/images/deadpool_wolverine_mobile_640x480_ad8020fd.png", 1, this);
    deadpool_wolverine->add_group_message(new GroupMessageInfo("Let's get the People what They came for", "", "", 4444, "Ryan Reynolds", this));
    _groups.append(deadpool_wolverine);

    GroupInfo *justiceLeague = new GroupInfo(3333, "Justice League", {}, "qrc:/QML/ClientApp/icons/justice_league_icon.png", 1, this);
    justiceLeague->add_group_message(new GroupMessageInfo("Superman, tell me, do u bleed?", "", "", 5555, "Ben Affleck", this));
    _groups.append(justiceLeague);

    _group_proxy_list->setSourceModel(this);
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

    _active_group_chat->add_group_message(new GroupMessageInfo(group_message, "", "", _main_user->phone_number(), "", _active_group_chat));
}

void GroupListModel::group_audio_sent()
{
    if (_active_group_chat == Q_NULLPTR || MediaController::_audio_path.isEmpty())
        return;

    _active_group_chat->add_group_message(new GroupMessageInfo("", MediaController::_audio_path, "", _main_user->phone_number(), "", _active_group_chat));
    MediaController::_audio_path = QString();
}

void GroupListModel::group_file_sent()
{
    if (_active_group_chat == Q_NULLPTR || MediaController::_file_path.isEmpty())
        return;

    _active_group_chat->add_group_message(new GroupMessageInfo("", "", MediaController::_file_path, _main_user->phone_number(), "", _active_group_chat));
    MediaController::_file_path = QString();
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
    case MemberListRole:
        return QVariant::fromValue(group_info->members_list());
    case GroupUnreadMessageRole:
        return group_info->group_unread_message();
    case GroupMessagesRole:
        return QVariant::fromValue(group_info->group_messages());
    case GroupImageUrlRole:
        return group_info->group_image_url();
    case GroupObjectRole:
        return QVariant::fromValue(group_info);
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
    default:
        return false;
    }

    return true;
}

QHash<int, QByteArray> GroupListModel::roleNames() const
{
    QHash<int, QByteArray> roles{};

    roles[GroupIDRole] = "Group_ID";
    roles[GroupNameRole] = "group_name";
    roles[MemberListRole] = "members_list";
    roles[GroupUnreadMessageRole] = "group_unread_message";
    roles[GroupMessagesRole] = "group_messages";
    roles[GroupImageUrlRole] = "group_image_url";
    roles[GroupObjectRole] = "group_contact_object";

    // emit dataChanged(index, index, {role});
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
