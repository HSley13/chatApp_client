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

    void get_user_time();
    void map_initialization();

    static void cleanup();

    Q_INVOKABLE void sign_up(const int &phone_number, const QString &first_name, const QString &last_name, const QString &password, const QString &password_confirmation, const QString &secret_question, const QString &secret_answer);
    Q_INVOKABLE void login_request(const int &phone_number, const QString &password);
    void lookup_friend(const int &phone_number);

    Q_INVOKABLE void profile_image_deleted();
    Q_INVOKABLE void disconnect() { _socket->close(); };

    void update_profile(const QString &file_name, const QByteArray &file_data);
    void send_text(const int &receiver, const QString &message, const QString &time, const int &chat_ID);
    void new_group(const QString &group_name, QJsonArray json_array);
    void send_group_text(const int &groupID, QString sender_name, const QString &message, const QString &time);

public slots:
    void on_text_message_received(const QString &data);
    void on_disconnected();

signals:
    void load_contacts(QJsonArray contacts);
    void load_groups(QJsonArray json_array);
    void load_my_info(QJsonObject my_info);

    void profile_image(const QString &image_url);
    void text_received(const int &chatID, const QString &message, const QString &time);

    void client_connected(const int &phone_number);
    void client_disconnected(const int &phone_number);

    void client_profile_image(const int &phone_number, const QString &image_url);

    void group_ID(const int &groupID, const QString &group_name);
    void group_text_received(const int &groupID, const int &sender_ID, QString sender_name, const QString &message, const QString &time);

    void disconnected();

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
        Text,
        GroupText,
        ProfileImage,
        ClientProfileImage,
        ClientDisconnected,
        ClientConnected,
        AddedYou,
        LookupFriend,
        AddedToGroup,
        FileMessage,
        IsTyping,
        SetName,
        AudioMessage,
        SaveData,
        ClientNewName,
        SaveMessage,
        LoginRequest,
        NewPasswordRequest,
        UpdatePassword,
        DeleteMessage,
        DeleteGroupMessage,
        GroupIsTyping,
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