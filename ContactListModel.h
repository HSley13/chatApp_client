#pragma once

#include "ContactInfo.h"
#include "ContactProxyList.h"
#include "MediaController.h"
class ContactListModel : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(ContactInfo *active_chat READ active_chat WRITE set_active_chat NOTIFY active_chat_changed)
    Q_PROPERTY(ContactInfo *main_user READ main_user NOTIFY main_user_changed)
    Q_PROPERTY(ContactProxyList *contact_proxy_list_chat READ contact_proxy_list_chat NOTIFY contact_proxy_list_chat_changed)
    Q_PROPERTY(ContactProxyList *contact_proxy_list READ contact_proxy_list NOTIFY contact_proxy_list_changed)
    Q_PROPERTY(QList<ContactInfo *> contacts READ contacts WRITE set_contacts NOTIFY contacts_changed)

public:
    ContactListModel(QAbstractListModel *parent = nullptr);
    ~ContactListModel();

    const QList<ContactInfo *> &contacts() const;
    void set_contacts(const QList<ContactInfo *> &new_contacts);

    ContactInfo *active_chat() const;
    void set_active_chat(ContactInfo *new_chat);

    const QStringList &contacts_name() const;

    static ContactInfo *main_user();
    ContactProxyList *contact_proxy_list_chat() const;
    ContactProxyList *contact_proxy_list() const;

    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QHash<int, QByteArray> roleNames() const override;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role) override;

    Q_INVOKABLE void message_sent(const QString &message);
    Q_INVOKABLE void audio_sent();
    Q_INVOKABLE void file_sent();

    ClientManager *_client_manager{nullptr};

    static QList<ContactInfo *> *_contacts_ptr;

private slots:
    void on_load_contacts(QJsonArray json_array);

signals:
    void contacts_changed();
    void active_chat_changed();

    void contact_proxy_list_chat_changed();
    void contact_proxy_list_changed();
    void main_user_changed();

public:
    enum ContactRoles
    {
        chat_IDRole = Qt::UserRole + 1,
        PhoneNumberRole,
        NameRole,
        StatusRole,
        UnreadMessageRole,
        ImageUrlRole,
        MessagesRole,
        ContactObjectRole,
        LastMessageTimeRole
    };

private:
    ContactInfo *_active_chat{nullptr};
    QList<ContactInfo *> _contacts;
    static ContactInfo *_main_user;
    ContactProxyList *_contact_proxy_list_chat{nullptr};
    ContactProxyList *_contact_proxy_list{nullptr};
    MediaController *_media_controller{nullptr};
};
