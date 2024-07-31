#include "ContactList.h"
#include "ClientManager.h"

ContactList::ContactList(QAbstractListModel *parent)
    : QAbstractListModel(parent),
      _main_user(new ChatInfo(0, "Sley", 1234, true, "qrc:/QML/ClientApp/icons/name_icon.png", 0, this)),
      _open_chat_user(Q_NULLPTR),
      _contact_proxy_list(new ContactProxyList(this))
{
    _contacts.append(new ChatInfo(1, "Sley HORTES", 1111, true, "qrc:/QML/ClientApp/icons/name_icon.png", 2, this));
    _contacts.append(new ChatInfo(2, "Bruce Wayne", 2222, true, "qrc:/QML/ClientApp/icons/batman_icon1.png", 2, this));
    _contacts.append(new ChatInfo(3, "Tony Stark", 3333, false, "qrc:/QML/ClientApp/icons/ironman_icon.png", 1, this));
    _contacts.append(new ChatInfo(4, "Clark Kent", 4444, false, "qrc:/QML/ClientApp/icons/superman_icon.png", 3, this));
    _contacts.append(new ChatInfo(5, "Steve Rogers", 5555, true, "qrc:/QML/ClientApp/icons/captain_icon.png", 1, this));

    // "I have killed the Joker",
    //     "I survived the Snap in EndGame",
    //     "I killed Doomsday",
    //     "I had the dance with Peggy",

    connect(this, &ContactList::send_message, this, &ContactList::on_send_message);

    _contact_proxy_list->setSourceModel(this);
}

const QList<ChatInfo *> &ContactList::contacts() const
{
    return _contacts;
}

void ContactList::set_contacts(const QList<ChatInfo *> &new_contacts)
{
    if (_contacts == new_contacts)
        return;

    _contacts = new_contacts;
    emit contacts_changed();
}

ChatInfo *ContactList::open_chat_user() const
{
    return _open_chat_user;
}

void ContactList::set_open_chat_user(ChatInfo *new_chat)
{
    if (_open_chat_user == new_chat)
        return;

    _open_chat_user = new_chat;
    emit open_chat_user_changed();
}

ChatInfo *ContactList::main_user() const
{
    return _main_user;
}

void ContactList::on_send_message(const QString &message)
{
    if (_open_chat_user == Q_NULLPTR)
        return;

    _open_chat_user->add_message(new MessageInfo(message, _open_chat_user->phone_number(), _open_chat_user));
}

int ContactList::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return _contacts.count();
}

QVariant ContactList::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= _contacts.count())
        return QVariant();

    ChatInfo *chat_info = _contacts[index.row()];

    switch (ContactRoles(role))
    {
    case ConversationIDRole:
        return chat_info->conversation_ID();
    case NameRole:
        return chat_info->name();
    case PhoneNumberRole:
        return chat_info->phone_number();
    case StatusRole:
        return chat_info->status();
    case UnreadMessageRole:
        return chat_info->unread_message();
    case MessagesRole:
        return QVariant::fromValue(chat_info->messages());
    case ImageUrlRole:
        return chat_info->image_url();
    case ChatObjectRole:
        return QVariant::fromValue(chat_info);
    default:
        break;
    }

    return QVariant();
}

QHash<int, QByteArray> ContactList::roleNames() const
{
    QHash<int, QByteArray> roles{};

    roles[ConversationIDRole] = "conversation_ID";
    roles[NameRole] = "name";
    roles[PhoneNumberRole] = "phone_number";
    roles[StatusRole] = "status";
    roles[UnreadMessageRole] = "unread_message";
    roles[MessagesRole] = "messages";
    roles[ImageUrlRole] = "image_url";
    roles[ChatObjectRole] = "chat_object";

    return roles;
}

bool ContactList::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.row() < 0 || index.row() >= _contacts.count())
        return false;

    ChatInfo *chat_info = _contacts[index.row()];

    switch (ContactRoles(role))
    {
    case NameRole:
        chat_info->set_name(value.toString());
        break;
    case UnreadMessageRole:
        chat_info->set_unread_message(value.toInt());
        break;
    case StatusRole:
        chat_info->set_status(value.toBool());
        break;
    default:
        return false;
    }

    return true;
}

ContactProxyList *ContactList::contact_proxy_list() const
{
    return _contact_proxy_list;
}