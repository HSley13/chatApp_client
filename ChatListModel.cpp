#include "ChatListModel.h"

ChatListModel::ChatListModel(QObject *parent)
    : QAbstractListModel(parent), _is_searching(false)
{
    ChatInfo *chatInfo1 = new ChatInfo(this);

    chatInfo1->set_conversation_ID("12345");
    chatInfo1->set_phone_number(1111);
    chatInfo1->set_name("Sley");
    chatInfo1->set_status("qrc:/QML_modules/ClientApp/icons/online_icon.png");
    chatInfo1->set_image("qrc:/QML_modules/ClientApp/icons/name_icon.png");
    chatInfo1->set_last_message("Hello World");
    chatInfo1->set_message_count("1");
    chatInfo1->set_message("Hello How are u doing?");
    chatInfo1->set_message_list(QStringList({"Hello How are u doing?", "How's everything?"}));

    ChatInfo *chatInfo2 = new ChatInfo(this);
    chatInfo2->set_conversation_ID("12346");
    chatInfo2->set_phone_number(2222);
    chatInfo2->set_name("Naruto");
    chatInfo2->set_status("qrc:/QML_modules/ClientApp/icons/offline_icon.png");
    chatInfo2->set_image("qrc:/QML_modules/ClientApp/icons/name_icon.png");
    chatInfo2->set_last_message("Hello Sasuke");
    chatInfo2->set_message_count("2");
    chatInfo2->set_message_list(QStringList("Yow Broh Naruto"));

    // FIXME: To Implement
    // chatInfo->set_last_seen("Now");
    _conversations << chatInfo1;
    _conversations << chatInfo2;
}

int ChatListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return _conversations.count();
}

QVariant ChatListModel::data(const QModelIndex &index, int role) const
{
    if (index.isValid() && index.row() >= 0 && index.row() < _conversations.size())
    {
        ChatInfo *chatInfo = _conversations.at(index.row());

        switch (ChatRoles(role))
        {
        case ConversationIdRole:
            return chatInfo->conversation_ID();
        case NameRole:
            return chatInfo->name();
        case PhoneNumberRole:
            return chatInfo->phone_number();
        case StatusRole:
            return chatInfo->status();
        case ImageRole:
            return chatInfo->image();
        case MessageCountRole:
            return chatInfo->message_count();
        case LastMessageRole:
            return chatInfo->last_message();
        case LastSeen:
            return "Now";
        case MessageRole:
            return chatInfo->message();
        case MessageListRole:
            return chatInfo->message_list();
        default:
            return QVariant();
        }
    }

    return QVariant();
}

QHash<int, QByteArray> ChatListModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[ConversationIdRole] = "conversation_ID";
    roles[NameRole] = "name";
    roles[PhoneNumberRole] = "phone_number";
    roles[StatusRole] = "status";
    roles[ImageRole] = "image";
    roles[MessageCountRole] = "message_count";
    roles[LastMessageRole] = "last_message";
    roles[MessageRole] = "message";
    roles[MessageListRole] = "Message_list";

    return roles;
}

bool ChatListModel::is_searching() const
{
    return _is_searching;
}

void ChatListModel::set_is_searching(bool new_is_searching)
{
    _is_searching = new_is_searching;
}

void ChatListModel::search_people(const int &phone_number)
{
    // FIXME: To Implement
}

const QHash<int, QString> &ChatListModel::friend_list() const
{
    return _friend_list;
}

void ChatListModel::set_friend_list(const QHash<int, QString> &friends)
{
    if (_friend_list == friends)
        return;

    _friend_list = friends;

    emit friend_list_changed();
}

void ChatListModel::add_friend(const int &phone_number, const QString &name)
{
    if (_friend_list.contains(phone_number))
        return;

    _friend_list.insert(phone_number, name);

    emit friend_list_changed();
}

QStringList ChatListModel::get_messages(const QString &id)
{
    QStringList messages;
    for (const ChatInfo *chat : _conversations)
    {
        if (chat->conversation_ID() == id)
        {
            messages = chat->message_list();
            return messages;
        }
    }
    return messages;
}

int ChatListModel::get_index(const QString &conversation_ID) const
{
    for (int i = 0; i < _conversations.size(); i++)
    {
        if (_conversations.at(i)->conversation_ID() == conversation_ID)
            return i;
    }

    return -1;
}