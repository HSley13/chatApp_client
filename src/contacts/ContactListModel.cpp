#include "ContactListModel.hpp"

ContactInfo *ContactListModel::_main_user{nullptr};
ContactInfo *ContactListModel::_active_chat{Q_NULLPTR};
QList<ContactInfo *> *ContactListModel::_contacts_ptr{nullptr};

ContactListModel::ContactListModel(QAbstractListModel *parent)
    : QAbstractListModel(parent),
      _contact_proxy_list_chat(new ContactProxyList(this)),
      _contact_proxy_list(new ContactProxyList(this))
{
    _main_user = new ContactInfo(0, QString(), QString(), 0, true, QString(), 0, this);

    _client_manager = ClientManager::instance();

    connect(_client_manager.get(), &ClientManager::load_contacts, this, &ContactListModel::on_load_contacts);
    connect(_client_manager.get(), &ClientManager::load_my_info, this, &ContactListModel::on_load_my_info);

    connect(_client_manager.get(), &ClientManager::text_received, this, &ContactListModel::on_text_received);

    connect(_client_manager.get(), &ClientManager::profile_image, this, [=](const QString &image_url)
            { _main_user->set_image_url(image_url); });
    connect(_client_manager.get(), &ClientManager::client_profile_image, this, &ContactListModel::on_client_profile_image);

    connect(_client_manager.get(), &ClientManager::client_connected, this, &ContactListModel::on_client_connected);
    connect(_client_manager.get(), &ClientManager::client_disconnected, this, &ContactListModel::on_client_disconnected);

    connect(_client_manager.get(), &ClientManager::file_received, this, &ContactListModel::on_file_received);
    connect(_client_manager.get(), &ClientManager::is_typing_received, this, &ContactListModel::on_is_typing_received);

    connect(_client_manager.get(), &ClientManager::update_client_info, this, &ContactListModel::on_update_client_info);

    connect(_client_manager.get(), &ClientManager::question_answer, this, &ContactListModel::on_question_answer);
    connect(_client_manager.get(), &ClientManager::status_message, this, &ContactListModel::on_status_message);
    connect(_client_manager.get(), &ClientManager::message_received, this, &ContactListModel::on_message_received);

    connect(_client_manager.get(), &ClientManager::delete_message_received, this, &ContactListModel::on_delete_message_received);

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

ContactInfo *ContactListModel::active_chat()
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
    case SecretQuestionRole:
        return contact_info->secret_question();
    case secretAnswerRole:
        return contact_info->secret_answer();
    case PhoneNumberRole:
        return contact_info->phone_number();
    case StatusRole:
        return contact_info->status();
    case IsTypingRole:
        return contact_info->is_typing();
    case UnreadMessageRole:
        return contact_info->unread_message();
    case ImageUrlRole:
        return contact_info->image_url();
    case PopupMessageRole:
        return contact_info->popup_message();
    case LoginStatusRole:
        return contact_info->login_status();
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
    roles[SecretQuestionRole] = "secret_question";
    roles[secretAnswerRole] = "secret_answer";
    roles[FirstNameRole] = "first_name";
    roles[LastNameRole] = "last_name";
    roles[PhoneNumberRole] = "phone_number";
    roles[PopupMessageRole] = "popup_message";
    roles[LoginStatusRole] = "login_status";
    roles[IsTypingRole] = "is_typing";
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
    case SecretQuestionRole:
        contact_info->set_secret_question(value.toString());
        break;
    case PopupMessageRole:
        contact_info->set_popup_message(value.toString());
    case LoginStatusRole:
        contact_info->set_login_status(value.toBool());
        break;
    case secretAnswerRole:
        contact_info->set_secret_answer(value.toString());
        break;
    case PhoneNumberRole:
        contact_info->set_phone_number(value.toLongLong());
        break;
    case StatusRole:
        contact_info->set_status(value.toBool());
        break;
    case IsTypingRole:
        contact_info->set_is_typing(value.toString());
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

void ContactListModel::on_load_contacts(QJsonArray json_array)
{
    if (json_array.isEmpty())
        return;

    for (const QJsonValue &obj : json_array)
    {
        QJsonObject contact_info = obj["contactInfo"].toObject();
        QJsonArray chat_messages = obj["chatMessages"].toArray();

        ContactInfo *contact = new ContactInfo(obj["chatID"].toInt(), contact_info["first_name"].toString(), contact_info["last_name"].toString(), contact_info["_id"].toInt(), contact_info["status"].toBool(), contact_info["image_url"].toString(), obj["unread_messages"].toInt(), this);

        for (const QJsonValue &message : chat_messages)
            contact->add_message(new MessageInfo(message["message"].toString(), QString(), message["file_url"].toString(), message["sender"].toInt(), _client_manager->UTC_to_timeZone(message["time"].toString()), this));

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

            return;
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

            return;
        }
    }
}

void ContactListModel::lookup_friend(const int &phone_number)
{
    if (!phone_number)
        return;

    if (phone_number == _main_user->phone_number())
    {
        _main_user->set_popup_message("Can't add Yourself as a Friend");

        return;
    }

    for (const ContactInfo *contact : _contacts)
    {
        if (contact->phone_number() == phone_number)
        {
            _main_user->set_popup_message("Phone Number already in Your Contact");

            return;
        }
    }

    _client_manager->lookup_friend(phone_number);
}

void ContactListModel::on_text_received(const int &chatID, const int &sender_ID, const QString &message, const QString &time)
{
    if (!chatID || !sender_ID || message.isEmpty())
        return;

    for (size_t i{0}; i < _contacts.size(); i++)
    {
        ContactInfo *contact = _contacts[i];
        if (contact->chat_ID() == chatID)
        {
            contact->add_message(new MessageInfo(message, QString(), QString(), sender_ID, _client_manager->UTC_to_timeZone(time), this));
            contact->set_last_message_time(QDateTime::currentDateTime());

            if (!_active_chat || (_active_chat && _active_chat->chat_ID() != chatID))
                contact->set_unread_message(contact->unread_message() + 1);
            else
            {
                contact->set_unread_message(0);
                _client_manager->update_unread_message(chatID);
            }

            QModelIndex index = createIndex(i, 0);
            emit dataChanged(index, index, {LastMessageTimeRole});
            emit dataChanged(index, index, {UnreadMessageRole});

            return;
        }
    }
}

void ContactListModel::on_file_received(const int &chatID, const int &sender_ID, const QString &file_url, const QString &time)
{
    if (!chatID || !sender_ID || file_url.isEmpty())
        return;

    for (ContactInfo *contact : _contacts)
    {
        if (contact->chat_ID() == chatID)
        {
            contact->add_message(new MessageInfo(QString(), QString(), file_url, sender_ID, _client_manager->UTC_to_timeZone(time), this));
            contact->set_last_message_time(QDateTime::currentDateTime());

            if (!_active_chat || (_active_chat && _active_chat->chat_ID() != chatID))
                contact->set_unread_message(contact->unread_message() + 1);
            else
            {
                contact->set_unread_message(0);
                _client_manager->update_unread_message(chatID);
            }

            QModelIndex index = createIndex(_contacts.indexOf(contact), 0);
            emit dataChanged(index, index, {LastMessageTimeRole});
            emit dataChanged(index, index, {UnreadMessageRole});

            return;
        }
    }
}

void ContactListModel::on_is_typing_received(const int &phone_number)
{
    if (!phone_number)
        return;

    for (ContactInfo *contact : _contacts)
    {
        if (contact->phone_number() == phone_number)
        {
            contact->set_is_typing("is typing...");

            QModelIndex index = createIndex(_contacts.indexOf(contact), 0);
            emit dataChanged(index, index, {IsTypingRole});

            QTimer::singleShot(2000, this, [=, this]()
                               {    contact->set_is_typing(QString());
                                    QModelIndex index = createIndex(_contacts.indexOf(contact), 0);
                                    emit dataChanged(index, index, {IsTypingRole}); });

            return;
        }
    }
}

void ContactListModel::on_update_client_info(const int &phone_number, const QString &first_name, const QString &last_name)
{
    if (!phone_number || first_name.isEmpty() || last_name.isEmpty())
        return;

    for (ContactInfo *contact : _contacts)
    {
        if (contact->phone_number() == phone_number)
        {
            contact->set_first_name(first_name);
            contact->set_last_name(last_name);

            QModelIndex index = createIndex(_contacts.indexOf(contact), 0);
            emit dataChanged(index, index, {FirstNameRole});
            emit dataChanged(index, index, {LastNameRole});

            return;
        }
    }
}

void ContactListModel::on_question_answer(const QString &secret_question, const QString &secret_answer)
{
    _main_user->set_secret_question(QString("%1 ????").arg(secret_question));
    _main_user->set_secret_answer(secret_answer);
}

void ContactListModel::on_status_message(const QString &message, const bool &true_or_false)
{
    if (message.isEmpty())
        return;

    _main_user->set_login_status(true_or_false);
    _main_user->set_popup_message(message);
}

void ContactListModel::on_message_received(const QString &message)
{
    if (message.isEmpty())
        return;

    _main_user->set_popup_message(message);
}

void ContactListModel::on_delete_message_received(const int &chatID, const QString &full_time)
{
    if (!chatID)
        return;

    for (ContactInfo *contact : _contacts)
    {
        if (contact->chat_ID() == chatID)
        {
            for (size_t i{0}; i < contact->messages()->count(); i++)
            {
                MessageInfo *message = contact->messages()->at(i);
                if (!message->full_time().compare(_client_manager->UTC_to_timeZone(full_time)))
                {
                    delete message;
                    contact->messages()->removeAt(i);

                FIXME:
                    // if (i == contact->messages()->count())
                    // {
                    // emit group_changed cause the list view for the last message read should be updated
                    //     MessageInfo *last_message = contact->messages()->last();
                    //     contact->set_last_message_time();
                    // }

                    return;
                }
            }
        }
    }
}

void ContactListModel::update_unread_message(int chatID)
{
    _client_manager->update_unread_message(chatID);

    for (ContactInfo *contact : _contacts)
    {
        if (contact->chat_ID() == chatID)
        {
            contact->set_unread_message(0);
            QModelIndex index = createIndex(_contacts.indexOf(contact), 0);
            emit dataChanged(index, index, {UnreadMessageRole});

            return;
        }
    }
}