#pragma once

#include "ChatListModel.h"
class ContactInfo : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QString first_name READ first_name WRITE set_first_name NOTIFY first_name_changed)
    Q_PROPERTY(int chat_ID READ chat_ID WRITE set_chat_ID NOTIFY chat_ID_changed)
    Q_PROPERTY(QString last_name READ last_name WRITE set_last_name NOTIFY last_name_changed)
    Q_PROPERTY(int phone_number READ phone_number WRITE set_phone_number NOTIFY phone_number_changed)
    Q_PROPERTY(bool status READ status WRITE set_status NOTIFY status_changed)
    Q_PROPERTY(QString image_url READ image_url WRITE set_image_url NOTIFY image_url_changed)
    Q_PROPERTY(int unread_message READ unread_message WRITE set_unread_message NOTIFY unread_message_changed)
    Q_PROPERTY(QString is_typing READ is_typing WRITE set_is_typing NOTIFY is_typing_changed)

    Q_PROPERTY(QString secret_question READ secret_question WRITE set_secret_question NOTIFY secret_question_changed)
    Q_PROPERTY(QString secret_answer READ secret_answer WRITE set_secret_answer NOTIFY secret_answer_changed)

    Q_PROPERTY(QString popup_message READ popup_message WRITE set_popup_message NOTIFY popup_message_changed)
    Q_PROPERTY(bool login_status READ login_status WRITE set_login_status NOTIFY login_status_changed)

    Q_PROPERTY(ChatListModel *messages READ messages NOTIFY messages_changed)

public:
    ContactInfo(QObject *parent = nullptr);
    ContactInfo(const int &chat_ID, const QString &first_name, const QString &last_name, const int &phone_number, const bool &status, const QString &image_url, const int &unread_message, QObject *parent = nullptr);

    const QString &popup_message() const;
    void set_popup_message(const QString &message);

    const bool &login_status() const;
    void set_login_status(const bool &status);

    const QString &secret_question() const;
    void set_secret_question(const QString &status);

    const QString &secret_answer() const;
    void set_secret_answer(const QString &answer);

    const int &chat_ID() const;
    void set_chat_ID(const int &new_ID);

    const QString &first_name() const;
    void set_first_name(const QString &new_first_name);

    const QString &is_typing() const;
    void set_is_typing(const QString &new_is_typing);

    const QString &last_name() const;
    void set_last_name(const QString &new_first_name);

    const int &phone_number() const;
    void set_phone_number(const int &new_phone_number);

    const bool &status() const;
    void set_status(const bool &new_status);

    const QString &image_url() const;
    Q_INVOKABLE void set_image_url(const QString &new_image_url);

    const int &unread_message() const;
    void set_unread_message(const int &new_unread_message);

    void add_message(MessageInfo *message);
    ChatListModel *messages() const;

    QDateTime last_message_time() const;
    void set_last_message_time(const QDateTime &time);

private:
    int _chat_ID{0};
    QString _first_name{};
    QString _last_name{};
    int _phone_number{0};
    bool _status{false};
    QString _image_url{};
    int _unread_message{};
    QString _is_typing{};
    QString _popup_message{};
    bool _login_status{false};

    QString _secret_question{};
    QString _secret_answer{};

    ChatListModel *_messages;

    QDateTime _last_message_time = QDateTime::currentDateTime();

signals:
    void first_name_changed();
    void last_name_changed();
    void phone_number_changed();
    void status_changed();
    void image_url_changed();
    void unread_message_changed();
    void chat_ID_changed();

    void messages_changed();

    void is_typing_changed();
    void secret_question_changed();
    void secret_answer_changed();

    void popup_message_changed();
    void login_status_changed();
};