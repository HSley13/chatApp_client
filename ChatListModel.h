// #pragma once

// #include <QtQml>
// #include <QtQuick>
// #include <QAbstractListModel>
// #include <QTimer>

// #include "ChatInfo.h"
// class ChatListModel : public QAbstractListModel
// {
//     Q_OBJECT
//     QML_ELEMENT

//     // FIXME:
//     Q_PROPERTY(QHash<int, QString> friend_list READ friend_list WRITE set_friend_list NOTIFY friend_list_changed)

// public:
//     enum ChatRoles
//     {
//         ConversationIdRole = Qt::UserRole + 1,
//         NameRole,
//         PhoneNumberRole,
//         StatusRole,
//         ImageRole,
//         MessageCountRole,
//         LastMessageRole,
//         LastSeen,
//         MessageRole,
//         MessageListRole
//     };

//     ChatListModel(QObject *parent = nullptr);

//     int rowCount(const QModelIndex &parent = QModelIndex()) const override;
//     QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
//     QHash<int, QByteArray> roleNames() const override;

//     // FIXME:
//     bool is_searching() const;
//     void set_is_searching(bool new_is_searching);

//     void search_people(const int &phone_number);

//     const QHash<int, QString> &friend_list() const;
//     void set_friend_list(const QHash<int, QString> &friends);
//     void add_friend(const int &phone_number, const QString &name);

//     Q_INVOKABLE QStringList get_messages(const QString &index);
//     Q_INVOKABLE int get_index(const QString &conversation_ID) const;

//     Q_INVOKABLE void new_message_received(const QString &conversation_ID, const QString &time, const QString &text);
//     Q_INVOKABLE void new_audio_received(const QString &conversation_ID, const QString &time, bool is_audio, const QString &audio_source);
//     Q_INVOKABLE void new_file_received(const QString &conversation_ID, const QString &time, bool is_file, const QString &file_path);

// public slots:

// private:
//     QList<ChatInfo *> _conversations;
//     bool _is_searching;
//     QHash<int, QString> _friend_list{};

// signals:
//     void friend_list_changed();
//     void newTextReceived(const QString &conversation_ID, const QString &time, const QString &text);
//     void newAudioReceived(const QString &conversation_ID, const QString &time, bool is_audio, const QString &audio_source);
//     void newFileReceived(const QString &conversation_ID, const QString &time, bool is_file, const QString &file_path);
// };