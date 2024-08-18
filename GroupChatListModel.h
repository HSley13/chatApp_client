#pragma once

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
        SenderIDRole,
        TextRole,
        AudioSourceRole,
        FileSourceRole,
        TimeRole,
        SenderNameRole,
        FullTimeRole
    };

    GroupChatListModel(QObject *parent = nullptr);

    int count() const;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    void append(GroupMessageInfo *group_message);
    Q_INVOKABLE GroupMessageInfo *at(const int &index) const;
    void removeAt(const int &index);

signals:
    void count_changed();

private:
    QList<GroupMessageInfo *> _group_messages;
};
