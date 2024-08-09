#pragma once

#include "GroupChatListModel.h"
#include "ContactInfo.h"
#include <QList>
class GroupInfo : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(int group_ID READ group_ID WRITE set_group_ID NOTIFY group_ID_changed)
    Q_PROPERTY(QString group_name READ group_name WRITE set_group_name NOTIFY group_name_changed)
    Q_PROPERTY(QString group_image_url READ group_image_url WRITE set_group_image_url NOTIFY group_image_url_changed)
    Q_PROPERTY(int group_unread_message READ group_unread_message WRITE set_group_unread_message NOTIFY group_unread_message_changed)

    Q_PROPERTY(QList<ContactInfo *> group_members READ group_members WRITE set_group_members NOTIFY group_members_changed)
    Q_PROPERTY(GroupChatListModel *group_messages READ group_messages WRITE set_group_messages NOTIFY group_messages_changed)

public:
    GroupInfo(QObject *parent = nullptr);
    GroupInfo(const int &group_ID, const QString &group_name, const QList<ContactInfo *> &group_members, const QString &group_image_url, const int &group_unread_message, QObject *parent = nullptr);

    const int &group_ID() const;
    void set_group_ID(const int &new_ID);

    const QString &group_name() const;
    void set_group_name(const QString &new_name);

    const QList<ContactInfo *> &group_members() const;
    void set_group_members(const QList<ContactInfo *> &group_members);

    void add_group_members(ContactInfo *new_member);

    const QString &group_image_url() const;
    void set_group_image_url(const QString &new_image_url);

    const int &group_unread_message() const;
    void set_group_unread_message(const int &new_unread_message);

    void add_group_message(GroupMessageInfo *group_message);
    GroupChatListModel *group_messages() const;
    void set_group_messages(GroupChatListModel *group_messages);

    QDateTime last_message_time() const;
    void set_last_message_time(const QDateTime &time);

private:
    int _group_ID{0};
    QString _group_name{};
    QList<ContactInfo *> _group_members;
    QString _group_image_url{};
    int _group_unread_message{};

    GroupChatListModel *_group_messages;

    QDateTime _last_message_time = QDateTime::currentDateTime();

signals:
    void group_name_changed();
    void group_members_changed();
    void group_image_url_changed();
    void group_unread_message_changed();
    void group_ID_changed();

    void group_messages_changed();
};