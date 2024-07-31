#pragma once

#include <QtQuick>
#include "MessageInfo.h"
class ChatInfo : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(int conversation_ID READ conversation_ID WRITE set_conversation_ID NOTIFY conversation_ID_changed)
    Q_PROPERTY(QString name READ name WRITE set_name NOTIFY name_changed)
    Q_PROPERTY(int phone_number READ phone_number WRITE set_phone_number NOTIFY phone_number_changed)
    Q_PROPERTY(QString status READ status WRITE set_status NOTIFY status_changed)
    Q_PROPERTY(QString image_url READ image_url WRITE set_image_url NOTIFY image_url_changed)
    Q_PROPERTY(QString message_count READ message_count WRITE set_message_count NOTIFY message_count_changed)
    Q_PROPERTY(QString last_message READ last_message WRITE set_last_message NOTIFY last_message_changed)

    Q_PROPERTY(QList<MessageInfo *> messages READ messages WRITE set_messages NOTIFY messages_changed)

public:
    ChatInfo(const int &conversation_ID, const QString &name, const int &phone_number, const QString &status, const QString &image_url, const QString &message_count, const QString &last_message, QObject *parent = nullptr);

    const int &conversation_ID() const;
    void set_conversation_ID(const int &new_ID);

    const QString &name() const;
    void set_name(const QString &new_name);

    const int &phone_number() const;
    void set_phone_number(const int &new_phone_number);

    const QString &status() const;
    void set_status(const QString &new_status);

    const QString &image_url() const;
    void set_image_url(const QString &new_image_url);

    const QString &message_count() const;
    void set_message_count(const QString &new_message_count);

    const QString &last_message() const;
    void set_last_message(const QString &new_last_message);

    const QList<MessageInfo *> &messages();
    void set_messages(QList<MessageInfo *> new_messages);

    void add_message(MessageInfo *message);

private:
    int _conversation_ID{0};
    QString _name{};
    int _phone_number{0};
    QString _status{};
    QString _image_url{};
    QString _message_count{};
    QString _last_message{};

    QList<MessageInfo *> _messages;

signals:
    void name_changed();
    void phone_number_changed();
    void status_changed();
    void image_url_changed();
    void message_count_changed();
    void last_message_changed();
    void conversation_ID_changed();

    void messages_changed();
};