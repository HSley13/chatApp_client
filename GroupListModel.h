#pragma once

#include "GroupInfo.h"
#include "GroupProxyList.h"
#include "ClientManager.h"
class GroupListModel : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(GroupInfo *active_group_chat READ active_group_chat WRITE set_active_group_chat NOTIFY active_group_chat_changed)
    Q_PROPERTY(GroupProxyList *group_proxy_list READ group_proxy_list NOTIFY group_proxy_list_changed)

public:
    enum GroupRoles
    {
        GroupIDRole = Qt::UserRole + 1,
        GroupMembersRole,
        GroupNameRole,
        GroupUnreadMessageRole,
        GroupAdminRole,
        GroupImageUrlRole,
        GroupMessagesRole,
        GroupObjectRole,
        LastMessageTimeRole
    };

    GroupListModel(QAbstractListModel *parent = nullptr);
    ~GroupListModel();

    const QList<GroupInfo *> &groups() const;
    void set_groups(const QList<GroupInfo *> &new_groups);

    ContactInfo *main_user() const;
    GroupProxyList *group_proxy_list() const;

    static GroupInfo *active_group_chat();
    void set_active_group_chat(GroupInfo *new_group_chat);

    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QHash<int, QByteArray> roleNames() const override;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role) override;

    Q_INVOKABLE void group_message_sent(const QString &group_message);
    Q_INVOKABLE void add_group(const QString &group_name, const QList<ContactInfo *> members);
    Q_INVOKABLE void group_audio_sent();
    Q_INVOKABLE void group_file_sent();

private slots:
    void on_load_groups(QJsonArray json_array);
    void on_group_text_received(const int &groupID, const int &sender_ID, QString sender_name, const QString &message, const QString &time);
    void on_group_profile_image(const int &group_ID, const QString &group_image_url);

private:
    QList<GroupInfo *> _groups;
    static GroupInfo *_active_group_chat;

    GroupProxyList *_group_proxy_list{nullptr};
    ClientManager *_client_manager{nullptr};

signals:
    void groups_changed();
    void active_group_chat_changed();

    void group_proxy_list_changed();
    void main_user_changed();
};
