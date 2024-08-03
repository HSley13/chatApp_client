#include "GroupListModel.h"
#include "ContactListModel.h"

GroupListModel::GroupListModel(QAbstractListModel *parent)
    : QAbstractListModel(parent),
      _main_user(new ContactInfo(0, "Sley", 1234, true, "qrc:/QML/ClientApp/icons/name_icon.png", 0, this)),
      _active_group_chat(Q_NULLPTR),
      _group_proxy_list(new GroupProxyList(this))
{
    GroupInfo *avengers = new GroupInfo(1111, "Avengers", {}, "https://helios-i.mashable.com/imagery/articles/033kBmLCuB3k8dcc8kpMftI/hero-image.fill.size_1248x702.v1623370357.jpg", 1, this);
    avengers->add_group_message(new GroupMessageInfo("Avengers Assemble", 3333, "Chris Evans", this));
    _groups.append(avengers);

    GroupInfo *deadpool_wolverine = new GroupInfo(2222, "DeadPool & Wolverine", {}, "https://lumiere-a.akamaihd.net/v1/images/deadpool_wolverine_mobile_640x480_ad8020fd.png", 1, this);
    deadpool_wolverine->add_group_message(new GroupMessageInfo("Let's get the People what They came for", 4444, "Ryan Reynolds", this));
    _groups.append(deadpool_wolverine);

    GroupInfo *justiceLeague = new GroupInfo(3333, "Justice League", {}, "https://irs.www.warnerbros.com/keyart-jpeg/movies/media/browser/justice_league_whv_keyart.jpg", 1, this);
    justiceLeague->add_group_message(new GroupMessageInfo("Superman, tell me, do u bleed?", 5555, "Ben Affleck", this));
    _groups.append(justiceLeague);

    connect(this, &GroupListModel::group_send_message, this, &GroupListModel::on_group_send_message);

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

void GroupListModel::on_group_send_message(const QString &group_message)
{
    if (_active_group_chat == Q_NULLPTR)
        return;

    _active_group_chat->add_group_message(new GroupMessageInfo(group_message, _main_user->phone_number(), _main_user->name(), _active_group_chat));
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

    return roles;
}

GroupProxyList *GroupListModel::group_proxy_list() const
{
    return _group_proxy_list;
}