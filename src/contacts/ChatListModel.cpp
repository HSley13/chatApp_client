#include "ChatListModel.hpp"

ChatListModel::ChatListModel(QObject *parent)
    : QAbstractListModel(parent) {}

int ChatListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return _messages.count();
}

QVariant ChatListModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= _messages.count())
        return QVariant();

    MessageInfo *message = _messages.at(index.row());

    switch (ChatRoles(role))
    {
    case PhoneNumberRole:
        return message->sender_ID();
    case TextRole:
        return message->text();
    case AudioSourceRole:
        return message->audio_source();
    case FileSourceRole:
        return message->file_source();
    case TimeRole:
        return message->time();
    case FullTimeRole:
        return message->full_time();
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> ChatListModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[ChatIDRole] = "chat_ID";
    roles[PhoneNumberRole] = "phone_number";
    roles[TextRole] = "text";
    roles[AudioSourceRole] = "audio_source";
    roles[FileSourceRole] = "file_source";
    roles[TimeRole] = "time";
    roles[FullTimeRole] = "full_time";

    return roles;
}

int ChatListModel::count() const
{
    return _messages.count();
}

void ChatListModel::append(MessageInfo *message)
{
    beginInsertRows(QModelIndex(), _messages.count(), _messages.count());
    _messages.append(message);
    endInsertRows();

    emit count_changed();
}

MessageInfo *ChatListModel::at(const int &index) const
{
    if (index < 0 || index >= _messages.count())
        return nullptr;

    return _messages.at(index);
}

void ChatListModel::removeAt(const int &index)
{
    if (index < 0 || index >= _messages.count())
        return;

    beginRemoveRows(QModelIndex(), index, index);
    _messages.removeAt(index);
    endRemoveRows();
}
