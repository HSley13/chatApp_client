#pragma once

#include "ClientManager.hpp"
#include "ContactInfo.hpp"
#include "ContactProxyList.hpp"

class ContactListModel : public QAbstractListModel {
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(ContactInfo *active_chat READ active_chat WRITE set_active_chat NOTIFY active_chat_changed)
    Q_PROPERTY(ContactInfo *main_user READ main_user NOTIFY main_user_changed)
    Q_PROPERTY(ContactProxyList *contact_proxy_list_chat READ contact_proxy_list_chat NOTIFY contact_proxy_list_chat_changed)
    Q_PROPERTY(ContactProxyList *contact_proxy_list READ contact_proxy_list NOTIFY contact_proxy_list_changed)
    Q_PROPERTY(QList<ContactInfo *> contacts READ contacts NOTIFY contacts_changed)
    Q_PROPERTY(bool socket_disconnected READ socket_disconnected NOTIFY socket_disconnected_changed)

  public:
    ContactListModel(QAbstractListModel *parent = nullptr);
    ~ContactListModel();

    const QList<ContactInfo *> &contacts() const;

    static ContactInfo *active_chat();
    void set_active_chat(ContactInfo *new_chat);

    const QStringList &contacts_name() const;

    static ContactInfo *main_user();
    ContactProxyList *contact_proxy_list_chat() const;
    ContactProxyList *contact_proxy_list() const;

    const bool &socket_disconnected() const;
    void set_socket_disconnected(const bool &true_or_false);

    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QHash<int, QByteArray> roleNames() const override;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role) override;

    Q_INVOKABLE void lookup_friend(const int &phone_number);

    Q_INVOKABLE void update_unread_message(int chatID);

    std::shared_ptr<ClientManager> _client_manager{nullptr};

    static inline QList<ContactInfo *> *_contacts_ptr{nullptr};

    static inline ContactInfo *_main_user{nullptr};

  private slots:
    void on_load_contacts(QJsonArray json_array);
    void on_load_my_info(QJsonObject my_info);
    void on_text_received(const int &chatID, const int &sender_ID, const QString &message, const QString &time);

    void on_client_connected_disconnected(const int &phone_number, const bool &true_or_false);

    void on_client_profile_image(const int &phone_number, const QString &image_url);

    void on_file_received(const int &chatID, const int &sender_ID, const QString &file_url, const QString &time);
    void on_audio_received(const int &chatID, const int &sender_ID, const QString &audio_url, const QString &time);

    void on_is_typing_received(const int &phone_number);
    void on_update_client_info(const int &phone_number, const QString &first_name, const QString &last_name);

    void on_delete_message_received(const int &chatID, const QString &full_time);

  signals:
    void contacts_changed();
    void active_chat_changed();

    void contact_proxy_list_chat_changed();
    void contact_proxy_list_changed();
    void main_user_changed();

    void socket_disconnected_changed();

  public:
    enum ContactRoles {
        chat_IDRole = Qt::UserRole + 1,
        PhoneNumberRole,
        FirstNameRole,
        LastNameRole,
        StatusRole,
        UnreadMessageRole,
        ImageUrlRole,
        MessagesRole,
        ContactObjectRole,
        LastMessageTimeRole,
        IsTypingRole,
        SecretQuestionRole,
        secretAnswerRole,
        PopupMessageRole,
        LoginStatusRole,
        MessageTimeRole
    };

  private:
    static inline ContactInfo *_active_chat{nullptr};
    QList<ContactInfo *> _contacts;
    ContactProxyList *_contact_proxy_list_chat{nullptr};
    ContactProxyList *_contact_proxy_list{nullptr};

    bool _socket_disconnected{false};
};
