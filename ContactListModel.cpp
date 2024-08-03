#include "ContactListModel.h"

ContactListModel::ContactListModel(QAbstractListModel *parent)
    : QAbstractListModel(parent),
      _main_user(new ContactInfo(0, "Sley", 1234, true, "qrc:/QML/ClientApp/icons/name_icon.png", 0, this)),
      _active_chat(Q_NULLPTR),
      _contact_proxy_list(new ContactProxyList(this))
{
    _contacts.append(new ContactInfo(1, "Sley HORTES", 1111, true, "qrc:/QML/ClientApp/icons/name_icon.png", 0, this));
    _contacts.append(new ContactInfo(2, "Bruce Wayne", 2222, true, "qrc:/QML/ClientApp/icons/batman_icon1.png", 1, this));
    _contacts.append(new ContactInfo(3, "Tony Stark", 3333, false, "qrc:/QML/ClientApp/icons/ironman_icon.png", 1, this));
    _contacts.append(new ContactInfo(4, "Clark Kent", 4444, false, "qrc:/QML/ClientApp/icons/superman_icon.png", 1, this));
    _contacts.append(new ContactInfo(5, "Steve Rogers", 5555, true, "qrc:/QML/ClientApp/icons/captain_icon.png", 1, this));

    connect(this, &ContactListModel::send_message, this, &ContactListModel::on_send_message);

    _contact_proxy_list->setSourceModel(this);
}

const QList<ContactInfo *> &ContactListModel::contacts() const
{
    return _contacts;
}

void ContactListModel::set_contacts(const QList<ContactInfo *> &new_contacts)
{
    if (_contacts == new_contacts)
        return;

    _contacts = new_contacts;
    emit contacts_changed();
}

ContactInfo *ContactListModel::active_chat() const
{
    return _active_chat;
}

void ContactListModel::set_active_chat(ContactInfo *new_chat)
{
    if (_active_chat == new_chat)
        return;

    _active_chat = new_chat;
    emit active_chat_changed();
}

ContactInfo *ContactListModel::main_user() const
{
    return _main_user;
}

void ContactListModel::on_send_message(const QString &message)
{
    if (_active_chat == Q_NULLPTR)
        return;

    _active_chat->add_message(new MessageInfo(message, _active_chat->phone_number(), _active_chat));
}

int ContactListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return _contacts.count();
}

QVariant ContactListModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= _contacts.count())
        return QVariant();

    ContactInfo *contact_info = _contacts[index.row()];

    switch (ContactRoles(role))
    {
    case ConversationIDRole:
        return contact_info->conversation_ID();
    case NameRole:
        return contact_info->name();
    case PhoneNumberRole:
        return contact_info->phone_number();
    case StatusRole:
        return contact_info->status();
    case UnreadMessageRole:
        return contact_info->unread_message();
    case MessagesRole:
        return QVariant::fromValue(contact_info->messages());
    case ImageUrlRole:
        return contact_info->image_url();
    case ContactObjectRole:
        return QVariant::fromValue(contact_info);
    default:
        QVariant();
    }
}

QHash<int, QByteArray> ContactListModel::roleNames() const
{
    QHash<int, QByteArray> roles{};

    roles[ConversationIDRole] = "conversation_ID";
    roles[NameRole] = "name";
    roles[PhoneNumberRole] = "phone_number";
    roles[StatusRole] = "status";
    roles[UnreadMessageRole] = "unread_message";
    roles[MessagesRole] = "messages";
    roles[ImageUrlRole] = "image_url";
    roles[ContactObjectRole] = "contact_object";

    return roles;
}

bool ContactListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.row() < 0 || index.row() >= _contacts.count())
        return false;

    ContactInfo *contact_info = _contacts[index.row()];

    switch (ContactRoles(role))
    {
    case NameRole:
        contact_info->set_name(value.toString());
        break;
    case UnreadMessageRole:
        contact_info->set_unread_message(value.toInt());
        break;
    case StatusRole:
        contact_info->set_status(value.toBool());
        break;
    default:
        return false;
    }

    return true;
}

ContactProxyList *ContactListModel::contact_proxy_list() const
{
    return _contact_proxy_list;
}