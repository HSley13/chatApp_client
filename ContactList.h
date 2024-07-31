#pragma once

#include <QtQuick>
#include "ChatInfo.h"

class ContactList : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QList<ChatInfo *> contacts READ contacts WRITE set_contacts NOTIFY contacts_changed)
    Q_PROPERTY(ChatInfo *open_chat_user READ open_chat_user WRITE set_open_chat_user NOTIFY open_chat_user_changed)
    Q_PROPERTY(ChatInfo *main_user READ main_user)

public:
    ContactList(QObject *parent = nullptr);

    const QList<ChatInfo *> &contacts() const;
    void set_contacts(const QList<ChatInfo *> &new_contacts);

    ChatInfo *open_chat_user() const;
    void set_open_chat_user(ChatInfo *new_chat);

    ChatInfo *main_user() const;

private:
    QList<ChatInfo *> _contacts;
    ChatInfo *_open_chat_user{};
    ChatInfo *_main_user{};

public slots:
    void on_send_message(const QString &message);

signals:
    void contacts_changed();
    void open_chat_user_changed();

    void send_message(const QString &message);
};
