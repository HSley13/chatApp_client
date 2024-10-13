#pragma once

#include "ClientManager.hpp"
#include "GroupInfo.hpp"
#include "GroupProxyList.hpp"

class GroupListModel : public QAbstractListModel {
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(GroupInfo *active_group_chat READ active_group_chat WRITE set_active_group_chat NOTIFY active_group_chat_changed)
    Q_PROPERTY(GroupProxyList *group_proxy_list READ group_proxy_list NOTIFY group_proxy_list_changed)

  public:
    enum GroupRoles {
        GroupIDRole = Qt::UserRole + 1,
        GroupMembersRole,
        GroupNameRole,
        GroupUnreadMessageRole,
        GroupAdminRole,
        GroupImageUrlRole,
        GroupMessagesRole,
        GroupObjectRole,
        LastMessageTimeRole,
        GroupIsTypingRole,
        MessageTimeRole
    };

    GroupListModel(QAbstractListModel *parent = nullptr);
    ~GroupListModel();

    const QList<GroupInfo *> &groups() const;

    ContactInfo *main_user() const;
    GroupProxyList *group_proxy_list() const;

    static GroupInfo *active_group_chat();
    void set_active_group_chat(GroupInfo *new_group_chat);

    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QHash<int, QByteArray> roleNames() const override;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role) override;

    Q_INVOKABLE void add_group(const QString &group_name, const QList<ContactInfo *> members);
    Q_INVOKABLE void remove_group_member(const QList<ContactInfo *> members);
    Q_INVOKABLE void add_group_member(const int &phone_number, const QList<ContactInfo *> members);

    Q_INVOKABLE void update_group_unread_message(const int &groupID);

  private slots:
    void on_load_groups(QJsonArray json_array);
    void on_group_text_received(const int &groupID, const int &sender_ID, QString sender_name, const QString &message, const QString &time);
    void on_group_profile_image(const int &group_ID, const QString &group_image_url);
    void on_group_file_received(const int &groupID, const int &sender_ID, const QString &sender_name, const QString &file_url, const QString &time);
    void on_group_is_typing_received(const int &groupID, const QString &sender_name);
    void on_remove_group_member_received(const int &groupID, QJsonArray group_members);
    void on_add_group_member_received(const int &groupID, QJsonArray new_group_members);
    void on_removed_from_group(const int &groupID);
    void on_delete_group_message_received(const int &groupID, const QString &full_time);
    void on_group_audio_received(const int &groupID, const int &sender_ID, const QString &sender_name, const QString &audio_url, const QString &time);

  private:
    QList<GroupInfo *> _groups;
    static inline GroupInfo *_active_group_chat{nullptr};

    GroupProxyList *_group_proxy_list{nullptr};
    std::shared_ptr<ClientManager> _client_manager{nullptr};

  signals:
    void groups_changed();
    void active_group_chat_changed();

    void group_proxy_list_changed();
    void main_user_changed();
};
