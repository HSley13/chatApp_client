#include "ContactListModel.h"

ContactListModel::ContactListModel(QAbstractListModel *parent)
    : QAbstractListModel(parent),
      _main_user(new ContactInfo(0, "Sley", 1234, true, "https://lumiere-a.akamaihd.net/v1/images/deadpool_wolverine_mobile_640x480_ad8020fd.png", 0, this)),
      _active_chat(Q_NULLPTR),
      _contact_proxy_list(new ContactProxyList(this))
{
    ContactInfo *sleyHortes = new ContactInfo(1, "Sley HORTES", 1111, true, "qrc:/QML/ClientApp/icons/name_icon.png", 1, this);
    sleyHortes->add_message(new MessageInfo("", "/Users/test/Music/Music/Media.localized/Music/Unknown Artist/Unknown Album/06-4.mp3", "", 2222, this));
    sleyHortes->add_message(new MessageInfo("I created this app", "", "", 2222, this));
    sleyHortes->add_message(new MessageInfo("", "", "/Users/test/Downloads/Proof of Nationality_page-0001.jpg", 2222, this));
    _contacts.append(sleyHortes);

    ContactInfo *bruceWayne = new ContactInfo(2, "Bruce Wayne", 2222, true, "qrc:/QML/ClientApp/icons/batman_icon1.png", 1, this);
    bruceWayne->add_message(new MessageInfo("I killed the Joker", "/Users/test/Music/Music/Media.localized/Music/Unknown Artist/Unknown Album/06-4.mp3", "", 3333, this));
    _contacts.append(bruceWayne);

    ContactInfo *tonyStark = new ContactInfo(3, "Tony Stark", 3333, false, "qrc:/QML/ClientApp/icons/ironman_icon.png", 1, this);
    tonyStark->add_message(new MessageInfo("I survived the Snap in EndGame", "/Users/test/Music/Music/Media.localized/Music/Unknown Artist/Unknown Album/06-4.mp3", "", 4444, this));
    _contacts.append(tonyStark);

    ContactInfo *clarkKent = new ContactInfo(4, "Clark Kent", 4444, false, "qrc:/QML/ClientApp/icons/superman_icon.png", 1, this);
    clarkKent->add_message(new MessageInfo("I killed Doomsday", "/Users/test/Music/Music/Media.localized/Music/Unknown Artist/Unknown Album/06-4.mp3", "", 5555, this));
    _contacts.append(clarkKent);

    ContactInfo *steveRogers = new ContactInfo(5, "Steve Rogers", 5555, true, "qrc:/QML/ClientApp/icons/captain_icon.png", 1, this);
    steveRogers->add_message(new MessageInfo("I had the dance with Peggy", "/Users/test/Music/Music/Media.localized/Music/Unknown Artist/Unknown Album/06-4.mp3", "", 6666, this));
    _contacts.append(steveRogers);

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

    _active_chat->add_message(new MessageInfo(message, "/Users/test/Music/Music/Media.localized/Music/Unknown Artist/Unknown Album/06-4.mp3", "", _main_user->phone_number(), _active_chat));
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
    case conversation_IDRole:
        return contact_info->conversation_ID();
    case NameRole:
        return contact_info->name();
    case phone_numberRole:
        return contact_info->phone_number();
    case StatusRole:
        return contact_info->status();
    case unread_messageRole:
        return contact_info->unread_message();
    case MessagesRole:
        return QVariant::fromValue(contact_info->messages());
    case image_urlRole:
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

    roles[conversation_IDRole] = "conversation_ID";
    roles[NameRole] = "name";
    roles[phone_numberRole] = "phone_number";
    roles[StatusRole] = "status";
    roles[unread_messageRole] = "unread_message";
    roles[MessagesRole] = "messages";
    roles[image_urlRole] = "image_url";
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
    case unread_messageRole:
        contact_info->set_unread_message(value.toInt());
        break;
    case StatusRole:
        contact_info->set_Status(value.toBool());
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