#include "ContactListModel.h"

ContactInfo *ContactListModel::_main_user;

QList<ContactInfo *> *ContactListModel::_contacts_ptr;

ContactListModel::ContactListModel(QAbstractListModel *parent)
    : QAbstractListModel(parent),
      _active_chat(Q_NULLPTR),
      _contact_proxy_list_chat(new ContactProxyList(this)),
      _contact_proxy_list(new ContactProxyList(this)),
      _media_controller(new MediaController(this))
{
    _main_user = new ContactInfo(0, QString(), QString(), 0, true, QString(), 0, this);

    _client_manager = ClientManager::instance();

    connect(_client_manager, &ClientManager::load_contacts, this, &ContactListModel::on_load_contacts);
    connect(_client_manager, &ClientManager::load_my_info, this, &ContactListModel::on_load_my_info);

    connect(_client_manager, &ClientManager::text_received, this, &ContactListModel::on_text_received);

    connect(_client_manager, &ClientManager::profile_image, this, [=](const QString &image_url)
            { _main_user->set_image_url(image_url); });
    connect(_client_manager, &ClientManager::client_profile_image, this, &ContactListModel::on_client_profile_image);

    connect(_client_manager, &ClientManager::client_connected, this, &ContactListModel::on_client_connected);
    connect(_client_manager, &ClientManager::client_disconnected, this, &ContactListModel::on_client_disconnected);

    _contact_proxy_list_chat->setSourceModel(this);
    _contact_proxy_list_chat->set_custom_sort_role(ContactListModel::ContactRoles::LastMessageTimeRole);

    _contact_proxy_list->setSourceModel(this);

    _contacts_ptr = &_contacts;
}

ContactListModel::~ContactListModel() { _contacts.clear(); }

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

ContactInfo *ContactListModel::main_user()
{
    return _main_user;
}

void ContactListModel::message_sent(const QString &message)
{
    if (_active_chat == Q_NULLPTR)
        return;

    MessageInfo *new_message = new MessageInfo(message, QString(), QString(), _main_user->phone_number(), QTime::currentTime().toString("HH:mm"), _active_chat);
    _active_chat->add_message(new_message);

    _active_chat->set_last_message_time(QDateTime::currentDateTime());
    QModelIndex top_left = index(0, 0);
    QModelIndex bottom_right = index(_contacts.size() - 1, 0);
    emit dataChanged(top_left, bottom_right, {LastMessageTimeRole});

    _client_manager->send_text(_active_chat->phone_number(), message, new_message->time(), _active_chat->chat_ID());
}

void ContactListModel::audio_sent()
{
    if (_active_chat == Q_NULLPTR || _media_controller->_audio_path.isEmpty())
        return;

    MessageInfo *new_message = new MessageInfo(QString(), _media_controller->_audio_path, QString(), _main_user->phone_number(), QTime::currentTime().toString("HH:mm"), _active_chat);
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

    MessageInfo *new_message = new MessageInfo(QString(), QString(), _media_controller->_file_path, _main_user->phone_number(), QTime::currentTime().toString("HH:mm"), _active_chat);
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
    case chat_IDRole:
        return contact_info->chat_ID();
    case FirstNameRole:
        return contact_info->first_name();
    case LastNameRole:
        return contact_info->last_name();
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

    roles[chat_IDRole] = "chat_ID";
    roles[FirstNameRole] = "first_name";
    roles[LastNameRole] = "last_name";
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
    case chat_IDRole:
        contact_info->set_chat_ID(value.toInt());
        break;
    case FirstNameRole:
        contact_info->set_first_name(value.toString());
        break;
    case LastNameRole:
        contact_info->set_last_name(value.toString());
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
    case LastMessageTimeRole:
        contact_info->set_last_message_time(value.value<QDateTime>());
        break;
    default:
        return false;
    }

    emit dataChanged(index, index, {role});
    return true;
}

ContactProxyList *ContactListModel::contact_proxy_list_chat() const
{
    return _contact_proxy_list_chat;
}

ContactProxyList *ContactListModel::contact_proxy_list() const
{
    return _contact_proxy_list;
}

void ContactListModel::on_load_my_info(QJsonObject my_info)
{
    if (my_info.isEmpty())
        return;

    _main_user->set_first_name(my_info["first_name"].toString());
    _main_user->set_last_name(my_info["last_name"].toString());
    _main_user->set_phone_number(my_info["_id"].toInt());
    _main_user->set_image_url(my_info["image_url"].toString());
}

void ContactListModel::on_text_received(const int &chatID, const QString &message, const QString &time)
{
    for (ContactInfo *contact : _contacts)
    {
        if (contact->chat_ID() == chatID)
            contact->add_message(new MessageInfo(message, QString(), QString(), contact->phone_number(), time, this));

        return;
    }
}

void ContactListModel::on_load_contacts(QJsonArray json_array)
{
    if (json_array.isEmpty())
        return;

    for (const QJsonValue &obj : json_array)
    {
        QJsonObject contact_info = obj["contactInfo"].toObject();
        QJsonArray chat_messages = obj["chatMessages"].toArray();

        ContactInfo *contact = new ContactInfo(obj["chatID"].toInt(), contact_info["first_name"].toString(), contact_info["last_name"].toString(), contact_info["_id"].toInt(), contact_info["status"].toBool(), contact_info["image_url"].toString(), 1, this);

        // FIXME: messageObj["timestamp"].toString()  --> add the real timestamp
        for (const QJsonValue &message : chat_messages)
            contact->add_message(new MessageInfo(message["message"].toString(), QString(), QString(), message["sender"].toInt(), QTime::currentTime().toString("HH:mm"), this));

        beginInsertRows(QModelIndex(), _contacts.count(), _contacts.count());
        _contacts.append(contact);
        endInsertRows();
    }

    emit contacts_changed();
}

void ContactListModel::on_client_profile_image(const int &phone_number, const QString &image_url)
{
    if (!phone_number || image_url.isEmpty())
        return;

    for (size_t i{0}; i < _contacts.size(); i++)
    {
        ContactInfo *contact = _contacts[i];
        if (contact->phone_number() == phone_number)
        {
            contact->set_image_url(image_url);

            QModelIndex index = createIndex(i, 0);
            emit dataChanged(index, index, {ImageUrlRole});

            return;
        }
    }
}

void ContactListModel::on_client_connected(const int &phone_number)
{
    if (!phone_number)
        return;

    for (size_t i{0}; i < _contacts.size(); i++)
    {
        ContactInfo *contact = _contacts[i];
        if (contact->phone_number() == phone_number)
        {
            contact->set_status(true);

            QModelIndex index = createIndex(i, 0);
            emit dataChanged(index, index, {StatusRole});

            break;
        }
    }
}

void ContactListModel::on_client_disconnected(const int &phone_number)
{
    if (!phone_number)
        return;

    for (size_t i{0}; i < _contacts.size(); i++)
    {
        ContactInfo *contact = _contacts[i];
        if (contact->phone_number() == phone_number)
        {
            contact->set_status(false);

            QModelIndex index = createIndex(i, 0);
            emit dataChanged(index, index, {StatusRole});

            break;
        }
    }
}

void ContactListModel::lookup_friend(const int &phone_number)
{
    for (const ContactInfo *contact : _contacts)
    {
        if (contact->phone_number() == phone_number)
            return;
    }

    _client_manager->lookup_friend(phone_number);

    // FIXME: send pop up notification
}
