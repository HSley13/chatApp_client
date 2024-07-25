#pragma once

#include <QtQml>
#include <QtQuick>
#include <QAbstractListModel>

class ChatListModel : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT

public:
    enum ChatRoles
    {
        ConversationIdRole = Qt::UserRole + 1
    };

    ChatListModel(QObject *parent = nullptr);

    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    virtual QHash<int, QByteArray> roleNames() const override;

public slots:

private:
    QStringList _conversations;

signals:
};
