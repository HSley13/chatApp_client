#include "ChatListModel.h"

ChatListModel::ChatListModel(QObject *parent)
    : QAbstractListModel(parent) {}

int ChatListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return _conversations.count();
}

QVariant ChatListModel::data(const QModelIndex &index, int role) const
{
    // FIXME: To Implement

    return QVariant();
}

QHash<int, QByteArray> ChatListModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    // FIXME: To Implement

    return roles;
}