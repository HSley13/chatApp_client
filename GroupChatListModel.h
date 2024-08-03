#pragma once

#include <QtQuick>
#include <QTimer>
#include "GroupMessageInfo.h"

class GroupChatListModel : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(int count READ count NOTIFY count_changed FINAL)

public:
    enum GroupChatRoles
    {
        GroupIDRole = Qt::UserRole + 1,
        PhoneNumberRole,
        ContentRole,
        TimeRole,
        SenderNameRole
    };

    GroupChatListModel(QObject *parent = nullptr);

    int count() const;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    void append(GroupMessageInfo *group_message);
    Q_INVOKABLE GroupMessageInfo *at(const int &index) const;

signals:
    void count_changed();

private:
    QList<GroupMessageInfo *> _group_messages;
};