#include "ContactListModel.h"

ContactListModel::ContactListModel(QAbstractListModel *parent)
    : QAbstractListModel(parent),
      _main_user(new ContactInfo(0, "Sley", 1234, true, "https://lumiere-a.akamaihd.net/v1/images/deadpool_wolverine_mobile_640x480_ad8020fd.png", 0, this)),
      _active_chat(Q_NULLPTR),
      _contact_proxy_list(new ContactProxyList(this)),
      _media_controller(new MediaController(this))
{
    ContactInfo *sleyHortes = new ContactInfo(1, "Sley HORTES", 1111, true, "qrc:/QML/ClientApp/icons/name_icon.png", 1, this);
    sleyHortes->add_message(new MessageInfo(QString(), "/Users/test/Music/Music/Media.localized/Music/Unknown Artist/Unknown Album/06-4.mp3", QString(), 2222, this));
    sleyHortes->add_message(new MessageInfo("I created this app", QString(), QString(), 2222, this));
    sleyHortes->add_message(new MessageInfo(QString(), QString(), "/Users/test/Downloads/Proof of Nationality_page-0001.jpg", 2222, this));
    _contacts.append(sleyHortes);

    ContactInfo *bruceWayne = new ContactInfo(2, "Bruce Wayne", 2222, true, "qrc:/QML/ClientApp/icons/batman_icon1.png", 1, this);
    bruceWayne->add_message(new MessageInfo("I killed the Joker", "/Users/test/Music/Music/Media.localized/Music/Unknown Artist/Unknown Album/06-4.mp3", QString(), 3333, this));
    _contacts.append(bruceWayne);

    ContactInfo *tonyStark = new ContactInfo(3, "Tony Stark", 3333, false, "qrc:/QML/ClientApp/icons/ironman_icon.png", 1, this);
    tonyStark->add_message(new MessageInfo("I survived the Snap in EndGame", "/Users/test/Music/Music/Media.localized/Music/Unknown Artist/Unknown Album/06-4.mp3", QString(), 4444, this));
    _contacts.append(tonyStark);

    ContactInfo *clarkKent = new ContactInfo(4, "Clark Kent", 4444, false, "qrc:/QML/ClientApp/icons/superman_icon.png", 1, this);
    clarkKent->add_message(new MessageInfo("I killed Doomsday", "/Users/test/Music/Music/Media.localized/Music/Unknown Artist/Unknown Album/06-4.mp3", QString(), 5555, this));
    _contacts.append(clarkKent);

    ContactInfo *steveRogers = new ContactInfo(5, "Steve Rogers", 5555, true, "qrc:/QML/ClientApp/icons/captain_icon.png", 1, this);
    steveRogers->add_message(new MessageInfo("I had the dance with Peggy", "/Users/test/Music/Music/Media.localized/Music/Unknown Artist/Unknown Album/06-4.mp3", QString(), 6666, this));
    _contacts.append(steveRogers);

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

void ContactListModel::message_sent(const QString &message)
{
    if (_active_chat == Q_NULLPTR)
        return;

    MessageInfo *new_message = new MessageInfo(message, QString(), QString(), _main_user->phone_number(), _active_chat);
    _active_chat->add_message(new_message);

    _active_chat->set_last_message_time(QDateTime::currentDateTime());
    QModelIndex top_left = index(0, 0);
    QModelIndex bottom_right = index(_contacts.size() - 1, 0);
    emit dataChanged(top_left, bottom_right, {LastMessageTimeRole});

    // _client_manager->send_text(_main_user->phone_number(), _active_chat->phone_number(), message, new_message->time());
}

void ContactListModel::audio_sent()
{
    if (_active_chat == Q_NULLPTR || _media_controller->_audio_path.isEmpty())
        return;

    MessageInfo *new_message = new MessageInfo(QString(), _media_controller->_audio_path, QString(), _main_user->phone_number(), _active_chat);
    _active_chat->add_message(new_message);

    _active_chat->set_last_message_time(QDateTime::currentDateTime());
    QModelIndex top_left = index(0, 0);
    QModelIndex bottom_right = index(_contacts.size() - 1, 0);
    emit dataChanged(top_left, bottom_right, {LastMessageTimeRole});

    // _client_manager->send_audio(_main_user->phone_number(), _active_chat->phone_number(), _media_controller->_audio_name, _media_controller->_audio_data, new_message->time());
    _media_controller->_audio_path = QString();
    _media_controller->_audio_name = QString();
    _media_controller->_audio_data = QByteArray();
}

void ContactListModel::file_sent()
{
    if (_active_chat == Q_NULLPTR || _media_controller->_file_path.isEmpty())
        return;

    MessageInfo *new_message = new MessageInfo(QString(), QString(), _media_controller->_file_path, _main_user->phone_number(), _active_chat);
    _active_chat->add_message(new_message);

    _active_chat->set_last_message_time(QDateTime::currentDateTime());
    QModelIndex top_left = index(0, 0);
    QModelIndex bottom_right = index(_contacts.size() - 1, 0);
    emit dataChanged(top_left, bottom_right, {LastMessageTimeRole});

    // _client_manager->send_file(_main_user->phone_number(), _active_chat->phone_number(), _media_controller->_file_name, _media_controller->_file_data, new_message->time());
    _media_controller->_file_path = QString();
    _media_controller->_file_name = QString();
    _media_controller->_file_data = QByteArray();
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
    case PhoneNumberRole:
        return contact_info->phone_number();
    case StatusRole:
        return contact_info->status();
    case UnreadMessageRole:
        return contact_info->unread_message();
    case ImageUrlRole:
        return contact_info->image_url();
    case MessagesRole:
        return QVariant::fromValue(contact_info->messages());
    case ContactObjectRole:
        return QVariant::fromValue(contact_info);
    case LastMessageTimeRole:
        return QVariant::fromValue(contact_info->last_message_time());
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> ContactListModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[conversation_IDRole] = "conversation_ID";
    roles[NameRole] = "name";
    roles[PhoneNumberRole] = "phone_number";
    roles[StatusRole] = "status";
    roles[UnreadMessageRole] = "unread_message";
    roles[ImageUrlRole] = "image_url";
    roles[MessagesRole] = "messages";
    roles[ContactObjectRole] = "contact_info";
    roles[LastMessageTimeRole] = "last_message_time";

    return roles;
}

bool ContactListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.row() < 0 || index.row() >= _contacts.count())
        return false;

    ContactInfo *contact_info = _contacts[index.row()];

    switch (ContactRoles(role))
    {
    case conversation_IDRole:
        contact_info->set_conversation_ID(value.toInt());
        break;
    case NameRole:
        contact_info->set_name(value.toString());
        break;
    case PhoneNumberRole:
        contact_info->set_phone_number(value.toLongLong());
        break;
    case StatusRole:
        contact_info->set_status(value.toBool());
        break;
    case UnreadMessageRole:
        contact_info->set_unread_message(value.toInt());
        break;
    case ImageUrlRole:
        contact_info->set_image_url(value.toString());
        break;
    // case MessagesRole:
    //     contact_info->set_messages(value.value<QList<MessageInfo *>>());
    //     break;
    // case ContactObjectRole:
    //     contact_info->set_contact_info(value.value<ContactInfo *>());
    // break;
    case LastMessageTimeRole:
        contact_info->set_last_message_time(value.value<QDateTime>());
        break;
    default:
        return false;
    }

    emit dataChanged(index, index, {role});
    return true;
}

ContactProxyList *ContactListModel::contact_proxy_list() const
{
    return _contact_proxy_list;
}