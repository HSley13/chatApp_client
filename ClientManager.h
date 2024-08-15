#pragma once

#include <QtQuick>
#include <QTimeZone>
#include <QWebSocket>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QDebug>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif
class ClientManager : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QString signup_message READ signup_message NOTIFY signup_message_changed)
    Q_PROPERTY(QString login_message READ login_message NOTIFY login_message_changed)

public:
    ClientManager(QObject *parent = nullptr);
    ClientManager(const ClientManager &) = delete;
    ClientManager &operator=(const ClientManager &) = delete;

    void mount_audio_IDBFS();
    void mount_file_IDBFS();
    void IDBFS_save_audio(const QString &audio_name, const QByteArray &audio_data, const int &size);
    void IDBFS_save_file(const QString &file_name, const QByteArray &file_data, const int &size);
    Q_INVOKABLE QUrl get_audio_url(const QString &audio_name);
    QUrl get_file_url(const QString &file_name);

    const QString &signup_message() const;
    const QString &login_message() const;

    void get_user_time();
    void map_initialization();

    static void cleanup();

    Q_INVOKABLE void sign_up(const int &phone_number, const QString &first_name, const QString &last_name, const QString &password, const QString &password_confirmation, const QString &secret_question, const QString &secret_answer);
    Q_INVOKABLE void login_request(const int &phone_number, const QString &password);
    Q_INVOKABLE void lookup_friend(const int &phone_number);

    void update_profile(const QString &file_name, const QByteArray &file_data);
    void send_text(const int &receiver, const QString &message, const QString &time, const int &chat_ID);

public slots:
    void on_text_message_received(const QString &data);
    void on_disconnected();

signals:
    void load_contacts(QJsonArray contacts);
    void load_groups(QJsonArray json_array);
    void load_my_info(QJsonObject my_info);

    void signup_message_changed();
    void login_message_changed();

    void profile_image(const QString &image_url);
    void text_received(const int &chatID, const QString &message, const QString &time);

    void client_connected(const int &phone_number);
    void client_disconnected(const int &phone_number);

    void client_profile_image(const int &phone_number, const QString &image_url);

public:
    static ClientManager *instance();

private:
    static QWebSocket *_socket;
    QString _time_zone;
    static ClientManager *_instance;

    QString _signup_message{};
    QString _login_message{};

    enum MessageType
    {
        SignUp = Qt::UserRole + 1,
        IsTyping,
        SetName,
        ProfileImage,
        ClientProfileImage,
        FileMessage,
        AudioMessage,
        SaveData,
        ClientNewName,
        ClientDisconnected,
        ClientConnected,
        AddedYou,
        LookupFriend,
        CreateConversation,
        SaveMessage,
        TextMessage,
        LoginRequest,
        NewPasswordRequest,
        UpdatePassword,
        DeleteMessage,
        DeleteGroupMessage,
        NewGroup,
        AddedToGroup,
        GroupIsTyping,
        GroupText,
        GroupFile,
        GroupAudio,
        NewGroupMember,
        RemoveGroupMember,
        RequestData,
        DeleteAccount,
        LastMessageRead,
        GroupLastMessageRead,
        InvalidType
    };
    static QHash<QString, MessageType> _map;
};