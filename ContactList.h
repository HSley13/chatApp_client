#pragma once

#include <QtQuick>
#include "ChatInfo.h"
#include "ContactProxyList.h"
class ContactList : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(ChatInfo *open_chat_user READ open_chat_user WRITE set_open_chat_user NOTIFY open_chat_user_changed)
    Q_PROPERTY(ChatInfo *main_user READ main_user)
    Q_PROPERTY(ContactProxyList *contact_proxy_list READ contact_proxy_list)

public:
    enum ContactRoles
    {
        ConversationIDRole = Qt::UserRole + 1,
        PhoneNumberRole,
        NameRole,
        StatusRole,
        UnreadMessageRole,
        ImageUrlRole,
        MessagesRole,
        ChatObjectRole
    };

    ContactList(QAbstractListModel *parent = nullptr);

    const QList<ChatInfo *> &contacts() const;
    void set_contacts(const QList<ChatInfo *> &new_contacts);

    ChatInfo *open_chat_user() const;
    void set_open_chat_user(ChatInfo *new_chat);

    ChatInfo *main_user() const;
    ContactProxyList *contact_proxy_list() const;

    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QHash<int, QByteArray> roleNames() const override;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role) override;

private:
    QList<ChatInfo *> _contacts;
    ChatInfo *_open_chat_user{};
    ChatInfo *_main_user{};

    ContactProxyList *_contact_proxy_list{};

public slots:
    void on_send_message(const QString &message);

signals:
    void contacts_changed();
    void open_chat_user_changed();

    void send_message(const QString &message);
};
