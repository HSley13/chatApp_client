#include "GroupChatListModel.h"

GroupChatListModel::GroupChatListModel(QObject *parent)
    : QAbstractListModel(parent) {}

int GroupChatListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return _group_messages.count();
}

QVariant GroupChatListModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= _group_messages.count())
        return QVariant();

    GroupMessageInfo *group_message = _group_messages.at(index.row());

    switch (GroupChatRoles(role))
    {
    case SenderIDRole:
        return group_message->sender_ID();
    case TextRole:
        return group_message->text();
    case AudioSourceRole:
        return group_message->audio_source();
    case FileSourceRole:
        return group_message->file_source();
    case TimeRole:
        return group_message->time();
    case SenderNameRole:
        return group_message->sender_name();
    case FullTimeRole:
        return group_message->full_time();
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> GroupChatListModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[GroupIDRole] = "group_ID";
    roles[SenderIDRole] = "sender_ID";
    roles[TextRole] = "text";
    roles[AudioSourceRole] = "audio_source";
    roles[FileSourceRole] = "file_source";
    roles[TimeRole] = "time";
    roles[SenderNameRole] = "sender_name";
    roles[FullTimeRole] = "full_time";

    return roles;
}

int GroupChatListModel::count() const
{
    return _group_messages.count();
}

void GroupChatListModel::append(GroupMessageInfo *group_message)
{
    beginInsertRows(QModelIndex(), _group_messages.count(), _group_messages.count());
    _group_messages.append(group_message);
    endInsertRows();

    emit count_changed();
}

GroupMessageInfo *GroupChatListModel::at(const int &index) const
{
    if (index < 0 || index >= _group_messages.count())
        return nullptr;

    return _group_messages.at(index);
}

void GroupChatListModel::removeAt(const int &index)
{
    if (index < 0 || index >= _group_messages.count())
        return;

    beginRemoveRows(QModelIndex(), index, index);
    _group_messages.removeAt(index);
    endRemoveRows();
}
