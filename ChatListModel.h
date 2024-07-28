#pragma once

#include <QtQml>
#include <QtQuick>
#include <QAbstractListModel>

#include "ChatInfo.h"
class ChatListModel : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QHash<int, QString> friend_list READ friend_list WRITE set_friend_list NOTIFY friend_list_changed)

public:
    enum ChatRoles
    {
        ConversationIdRole = Qt::UserRole + 1,
        NameRole,
        PhoneNumberRole,
        StatusRole,
        ImageRole,
        MessageCountRole,
        LastMessageRole,
        LastSeen,
        MessageRole,
        MessageListRole
    };

    ChatListModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    bool is_searching() const;
    void set_is_searching(bool new_is_searching);

    void search_people(const int &phone_number);

    const QHash<int, QString> &friend_list() const;
    void set_friend_list(const QHash<int, QString> &friends);
    void add_friend(const int &phone_number, const QString &name);

    Q_INVOKABLE QStringList get_messages(const QString &index);
    Q_INVOKABLE int get_index(const QString &conversation_ID) const;

public slots:

private:
    QList<ChatInfo *> _conversations;
    bool _is_searching;
    QHash<int, QString> _friend_list{};

signals:
    void friend_list_changed();
};