#include "ChatListModel.h"

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
    case ContentRole:
        return message->contents();
    case TimeRole:
        return message->time();
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> ChatListModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[ConversationIDRole] = "conversation_ID";
    roles[PhoneNumberRole] = "phone_number";
    roles[ContentRole] = "contents";
    roles[TimeRole] = "time";

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

MessageInfo *ChatListModel::at(int index) const
{
    if (index < 0 || index >= _messages.count())
        return nullptr;

    return _messages.at(index);
}