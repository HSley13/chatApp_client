#pragma once

#include <QtQuick>
#include "GroupChatListModel.h"

class GroupInfo : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(int group_ID READ group_ID WRITE set_group_ID NOTIFY group_ID_changed)
    Q_PROPERTY(QString group_name READ group_name WRITE set_group_name NOTIFY group_name_changed)
    Q_PROPERTY(QHash<int, QString> members_list READ members_list WRITE set_members_list NOTIFY members_list_changed)
    Q_PROPERTY(QString group_image_url READ group_image_url WRITE set_group_image_url NOTIFY group_image_url_changed)
    Q_PROPERTY(int group_unread_message READ group_unread_message WRITE set_group_unread_message NOTIFY group_unread_message_changed)

    Q_PROPERTY(GroupChatListModel *group_messages READ group_messages CONSTANT FINAL)

public:
    GroupInfo(QObject *parent = nullptr);
    GroupInfo(const int &group_ID, const QString &group_name, const QHash<int, QString> &members_list, const QString &group_image_url, const int &group_unread_message, QObject *parent = nullptr);

    const int &group_ID() const;
    void set_group_ID(const int &new_ID);

    const QString &group_name() const;
    void set_group_name(const QString &new_name);

    const QHash<int, QString> &members_list() const;
    void set_members_list(const QHash<int, QString> &new_members_list);

    // void add_group_members(const int &phone_number);

    const QString &group_image_url() const;
    void set_group_image_url(const QString &new_image_url);

    const int &group_unread_message() const;
    void set_group_unread_message(const int &new_unread_message);

    void add_group_message(GroupMessageInfo *group_message);
    GroupChatListModel *group_messages() const;

private:
    int _group_ID{0};
    QString _group_name{};
    QHash<int, QString> _members_list{};
    QString _group_image_url{};
    int _group_unread_message{};

    GroupChatListModel *_group_messages;

signals:
    void group_name_changed();
    void members_list_changed();
    void group_image_url_changed();
    void group_unread_message_changed();
    void group_ID_changed();

    void group_messages_changed();
};