#pragma once

#include "MessageInfo.h"

class ChatListModel : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(int count READ count NOTIFY count_changed FINAL)

public:
    enum ChatRoles
    {
        ChatIDRole = Qt::UserRole + 1,
        TextRole,
        AudioSourceRole,
        FileSourceRole,
        PhoneNumberRole,
        ContentRole,
        TimeRole,
    };

    ChatListModel(QObject *parent = nullptr);

    int count() const;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    void append(MessageInfo *message);
    Q_INVOKABLE MessageInfo *at(const int &index) const;

signals:
    void count_changed();

private:
    QList<MessageInfo *> _messages;
};
