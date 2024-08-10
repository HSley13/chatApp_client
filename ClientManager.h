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

    void mount_audio_IDBFS();
    void mount_file_IDBFS();
    static void IDBFS_save_audio(const QString &audio_name, const QByteArray &audio_data, const int &size);
    static void IDBFS_save_file(const QString &file_name, const QByteArray &file_data, const int &size);
    static QUrl get_audio_url(const QString &audio_name);
    static QUrl get_file_url(const QString &file_name);

    void get_user_time();
    void map_initialization();

    Q_INVOKABLE void send_sign_up(const int &phone_number, const QString &first_name, const QString &last_name, const QString &password, const QString &password_confirmation, const QString &secret_question, const QString &secret_answer);
    Q_INVOKABLE void send_login_request(const QString &phone_number, const QString &password);

public slots:
    void on_text_message_received(const QString &data);
    void on_disconnected();

signals:
    void notificationSignal(const QString &message);

private:
    QWebSocket *_socket;
    QString _time_zone;

    enum MessageType
    {
        SignUp = Qt::UserRole + 1,
        IsTyping,
        SetName,
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