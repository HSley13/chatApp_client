#pragma once

#include <QtQuick>
#include "ContactInfo.h"
#include "ContactProxyList.h"

class ContactListModel : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(ContactInfo *active_chat READ active_chat WRITE set_active_chat NOTIFY active_chat_changed)
    Q_PROPERTY(ContactInfo *main_user READ main_user)
    Q_PROPERTY(ContactProxyList *contact_proxy_list READ contact_proxy_list)
    Q_PROPERTY(QStringList contacts_name READ contacts_name);

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
        ContactObjectRole
    };

    ContactListModel(QAbstractListModel *parent = nullptr);

    const QList<ContactInfo *> &contacts() const;
    void set_contacts(const QList<ContactInfo *> &new_contacts);

    ContactInfo *active_chat() const;
    void set_active_chat(ContactInfo *new_chat);

    const QStringList &contacts_name() const;

    ContactInfo *main_user() const;
    ContactProxyList *contact_proxy_list() const;

    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QHash<int, QByteArray> roleNames() const override;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role) override;

private:
    QList<ContactInfo *> _contacts;
    ContactInfo *_active_chat{};
    ContactInfo *_main_user{};

    QStringList _contacts_name{};

    ContactProxyList *_contact_proxy_list{};

public slots:
    void on_send_message(const QString &message);

signals:
    void contacts_changed();
    void active_chat_changed();

    void send_message(const QString &message);
};
