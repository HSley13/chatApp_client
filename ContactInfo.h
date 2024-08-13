#pragma once

#include "ChatListModel.h"

class ContactInfo : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(int conversation_ID READ conversation_ID WRITE set_conversation_ID NOTIFY conversation_ID_changed)
    Q_PROPERTY(QString name READ name WRITE set_name NOTIFY name_changed)
    Q_PROPERTY(int phone_number READ phone_number WRITE set_phone_number NOTIFY phone_number_changed)
    Q_PROPERTY(bool status READ status WRITE set_status NOTIFY status_changed)
    Q_PROPERTY(QString image_url READ image_url WRITE set_image_url NOTIFY image_url_changed)
    Q_PROPERTY(int unread_message READ unread_message WRITE set_unread_message NOTIFY unread_message_changed)

    Q_PROPERTY(ChatListModel *messages READ messages WRITE set_messages NOTIFY messages_changed)

public:
    ContactInfo(QObject *parent = nullptr);
    ContactInfo(const int &conversation_ID, const QString &name, const int &phone_number, const bool &status, const QString &image_url, const int &unread_message, QObject *parent = nullptr);

    const int &conversation_ID() const;
    void set_conversation_ID(const int &new_ID);

    const QString &name() const;
    void set_name(const QString &new_name);

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
    void set_messages(ChatListModel *messages);

    QDateTime last_message_time() const;
    void set_last_message_time(const QDateTime &time);

private:
    int _conversation_ID{0};
    QString _name{};
    int _phone_number{0};
    bool _status{false};
    QString _image_url{};
    int _unread_message{};

    ChatListModel *_messages;

    QDateTime _last_message_time = QDateTime::currentDateTime();

signals:
    void name_changed();
    void phone_number_changed();
    void status_changed();
    void image_url_changed();
    void unread_message_changed();
    void conversation_ID_changed();

    void messages_changed();
};