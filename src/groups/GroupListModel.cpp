#include "GroupListModel.hpp"
#include "ContactListModel.hpp"

GroupListModel::GroupListModel(QAbstractListModel *parent)
    : QAbstractListModel(parent),
      _group_proxy_list(new GroupProxyList(this)) {
    _group_proxy_list->setSourceModel(this);

    _client_manager = ClientManager::instance();

    connect(_client_manager.get(), &ClientManager::load_groups, this, &GroupListModel::on_load_groups);
    connect(_client_manager.get(), &ClientManager::group_text_received, this, &GroupListModel::on_group_text_received);
    connect(_client_manager.get(), &ClientManager::group_profile_image, this, &GroupListModel::on_group_profile_image);
    connect(_client_manager.get(), &ClientManager::group_file_received, this, &GroupListModel::on_group_file_received);
    connect(_client_manager.get(), &ClientManager::group_is_typing_received, this, &GroupListModel::on_group_is_typing_received);
    connect(_client_manager.get(), &ClientManager::remove_group_member_received, this, &GroupListModel::on_remove_group_member_received);
    connect(_client_manager.get(), &ClientManager::add_group_member_received, this, &GroupListModel::on_add_group_member_received);
    connect(_client_manager.get(), &ClientManager::removed_from_group, this, &GroupListModel::on_removed_from_group);
    connect(_client_manager.get(), &ClientManager::delete_group_message_received, this, &GroupListModel::on_delete_group_message_received);
    connect(_client_manager.get(), &ClientManager::group_audio_received, this, &GroupListModel::on_group_audio_received);
}

GroupListModel::~GroupListModel() { _groups.clear(); }

const QList<GroupInfo *> &GroupListModel::groups() const {
    return _groups;
}

GroupInfo *GroupListModel::active_group_chat() {
    return _active_group_chat;
}

void GroupListModel::set_active_group_chat(GroupInfo *new_group) {
    if (_active_group_chat == new_group)
        return;

    _active_group_chat = new_group;

    emit active_group_chat_changed();
}

int GroupListModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);

    return _groups.count();
}

QVariant GroupListModel::data(const QModelIndex &index, int role) const {
    if (index.row() < 0 || index.row() >= _groups.count())
        return QVariant();

    GroupInfo *group_info = _groups[index.row()];

    switch (GroupRoles(role)) {
    case GroupIDRole:
        return group_info->group_ID();
    case GroupAdminRole:
        return group_info->group_admin();
    case GroupNameRole:
        return group_info->group_name();
    case GroupIsTypingRole:
        return group_info->group_is_typing();
    case GroupUnreadMessageRole:
        return group_info->group_unread_message();
    case GroupImageUrlRole:
        return group_info->group_image_url();
    case MessageTimeRole:
        return group_info->message_time();
    case LastMessageTimeRole:
        return group_info->last_message_time();
    case GroupMessagesRole:
        return QVariant::fromValue(group_info->group_messages());
    case GroupObjectRole:
        return QVariant::fromValue(group_info);
    case GroupMembersRole:
        return QVariant::fromValue(group_info->group_members());
    default:
        return QVariant();
    }
}

bool GroupListModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (index.row() < 0 || index.row() >= _groups.count())
        return false;

    GroupInfo *group_info = _groups[index.row()];

    switch (GroupRoles(role)) {
    case GroupNameRole:
        group_info->set_group_name(value.toString());
        break;
    case GroupAdminRole:
        group_info->set_group_admin(value.toInt());
        break;
    case GroupIsTypingRole:
        group_info->set_group_is_typing(value.toString());
        break;
    case GroupUnreadMessageRole:
        group_info->set_group_unread_message(value.toInt());
        break;
    case MessageTimeRole:
        group_info->set_message_time(value.toString());
        break;
    case LastMessageTimeRole:
        group_info->set_last_message_time(value.toString());
        break;
    default:
        return false;
    }

    emit dataChanged(index, index, {role});

    return true;
}

QHash<int, QByteArray> GroupListModel::roleNames() const {
    QHash<int, QByteArray> roles{};

    roles[GroupIDRole] = "group_ID";
    roles[GroupIsTypingRole] = "group_is_typing";
    roles[GroupAdminRole] = "group_admin";
    roles[GroupNameRole] = "group_name";
    roles[GroupMembersRole] = "group_members";
    roles[GroupUnreadMessageRole] = "group_unread_message";
    roles[GroupMessagesRole] = "group_messages";
    roles[GroupImageUrlRole] = "group_image_url";
    roles[GroupObjectRole] = "group_contact_object";
    roles[LastMessageTimeRole] = "last_message_time";
    roles[MessageTimeRole] = "message_time";

    return roles;
}

GroupProxyList *GroupListModel::group_proxy_list() const {
    return _group_proxy_list;
}

void GroupListModel::add_group(const QString &group_name, const QList<ContactInfo *> members) {
    if (group_name.isEmpty() || members.isEmpty())
        return;

    QJsonArray json_array;
    for (ContactInfo *contact : members)
        json_array.append(contact->phone_number());

    json_array.append(ContactListModel::main_user()->phone_number());

    _client_manager->new_group(group_name, json_array);
}

void GroupListModel::remove_group_member(const QList<ContactInfo *> members) {
    if (members.isEmpty())
        return;

    QJsonArray json_array;
    for (ContactInfo *contact : members)
        json_array.append(contact->phone_number());

    _client_manager->remove_group_member(_active_group_chat->group_ID(), json_array);
}

void GroupListModel::add_group_member(const int &phone_number, const QList<ContactInfo *> members) {
    if (!phone_number && members.isEmpty())
        return;

    QJsonArray json_array;
    for (ContactInfo *contact : members)
        json_array.append(contact->phone_number());

    if (phone_number)
        json_array.append(phone_number);

    _client_manager->add_group_member(_active_group_chat->group_ID(), json_array);
}

void GroupListModel::on_load_groups(QJsonArray json_array) {
    if (json_array.isEmpty())
        return;

    for (const QJsonValue &groups : json_array) {
        QJsonArray members_ID = groups["group_members"].toArray();
        QJsonArray messages = groups["group_messages"].toArray();

        QList<ContactInfo *> group_members;
        for (const QJsonValue &ID : members_ID) {
            if (ContactListModel::main_user()->phone_number() == ID.toInt())
                continue;

            for (ContactInfo *contact : *ContactListModel::_contacts_ptr) {
                if (contact->phone_number() == ID.toInt()) {
                    group_members << contact;
                    break;
                }
            }
        }

        GroupInfo *group = new GroupInfo(groups["_id"].toInt(), groups["group_admin"].toInt(), groups["group_name"].toString(), group_members, groups["group_image_url"].toString(), groups["group_unread_messages"].toInt(), this);

        if (!messages.isEmpty()) {
            for (const QJsonValue &message : messages) {
                group->add_group_message(new GroupMessageInfo(message["message"].toString(), message["audio_url"].toString(), message["file_url"].toString(), message["sender_ID"].toInt(), message["sender_name"].toString(), _client_manager->UTC_to_timeZone(message["time"].toString()), this));
                group->set_message_time(_client_manager->UTC_to_timeZone(message["time"].toString()).split(" ").last());
                group->set_last_message_time(_client_manager->UTC_to_timeZone(message["time"].toString()));
            }
        }

        beginInsertRows(QModelIndex(), _groups.count(), _groups.count());
        _groups.append(group);
        endInsertRows();

        group_members.clear();
    }

    emit groups_changed();
}

void GroupListModel::on_group_profile_image(const int &group_ID, const QString &group_image_url) {
    if (!group_ID || group_image_url.isEmpty())
        return;

    for (GroupInfo *group : _groups) {
        if (group->group_ID() == group_ID) {
            group->set_group_image_url(group_image_url);

            QModelIndex index = createIndex(_groups.indexOf(group), 0);
            emit dataChanged(index, index, {GroupImageUrlRole});

            return;
        }
    }
}

void GroupListModel::on_group_text_received(const int &groupID, const int &sender_ID, QString sender_name, const QString &message, const QString &time) {
    if (!groupID)
        return;

    for (GroupInfo *group : _groups) {
        if (group->group_ID() == groupID) {
            group->add_group_message(new GroupMessageInfo(message, QString(), QString(), sender_ID, sender_name, _client_manager->UTC_to_timeZone(time), this));
            group->set_message_time(_client_manager->UTC_to_timeZone(time).split(" ").last());
            group->set_last_message_time(_client_manager->UTC_to_timeZone(time));

            if (!_active_group_chat || (_active_group_chat && _active_group_chat->group_ID() != groupID))
                group->set_group_unread_message(group->group_unread_message() + 1);
            else {
                group->set_group_unread_message(0);
                _client_manager->update_group_unread_message(groupID);
            }

            QModelIndex index = createIndex(_groups.indexOf(group), 0);
            emit dataChanged(index, index, {MessageTimeRole});
            emit dataChanged(index, index, {LastMessageTimeRole});
            emit dataChanged(index, index, {GroupUnreadMessageRole});
        }
    }
}

void GroupListModel::on_group_file_received(const int &groupID, const int &sender_ID, const QString &sender_name, const QString &audio_url, const QString &time) {
    if (!groupID || audio_url.isEmpty())
        return;

    for (GroupInfo *group : _groups) {
        if (group->group_ID() == groupID) {
            group->add_group_message(new GroupMessageInfo(QString(), QString(), audio_url, sender_ID, sender_name, _client_manager->UTC_to_timeZone(time), this));
            group->set_message_time(_client_manager->UTC_to_timeZone(time).split(" ").last());
            group->set_last_message_time(_client_manager->UTC_to_timeZone(time));

            if (!_active_group_chat || (_active_group_chat && _active_group_chat->group_ID() != groupID))
                group->set_group_unread_message(group->group_unread_message() + 1);
            else {
                group->set_group_unread_message(0);
                _client_manager->update_group_unread_message(groupID);
            }

            QModelIndex index = createIndex(_groups.indexOf(group), 0);
            emit dataChanged(index, index, {MessageTimeRole});
            emit dataChanged(index, index, {LastMessageTimeRole});
            emit dataChanged(index, index, {GroupUnreadMessageRole});
        }
    }
}

void GroupListModel::on_group_is_typing_received(const int &groupID, const QString &sender_name) {
    if (!groupID || sender_name.isEmpty())
        return;

    for (GroupInfo *group : _groups) {
        if (group->group_ID() == groupID) {
            group->set_group_is_typing(QString("%1 %2").arg(sender_name, "is typing..."));
            QModelIndex index = createIndex(_groups.indexOf(group), 0);
            emit dataChanged(index, index, {GroupIsTypingRole});

            QTimer::singleShot(2000, this, [=, this]() {    group->set_group_is_typing(QString());
                                    QModelIndex index = createIndex(_groups.indexOf(group), 0);
                                    emit dataChanged(index, index, {GroupIsTypingRole}); });
            return;
        }
    }
}

void GroupListModel::on_remove_group_member_received(const int &groupID, QJsonArray group_members) {
    if (!groupID || group_members.isEmpty())
        return;

    QSet<int> members_to_remove;
    for (const QJsonValue &value : group_members) {
        if (value.isDouble())
            members_to_remove.insert(static_cast<int>(value.toDouble()));
    }

    for (GroupInfo *group : _groups) {
        if (group->group_ID() == groupID) {
            for (size_t i{0}; i < group->group_members().size();) {
                ContactInfo *contact = group->group_members().at(i);
                if (members_to_remove.contains(contact->phone_number()))
                    group->group_members().removeAt(i);
                else
                    i++;
            }

            emit group->group_members_changed();
            QModelIndex topLeft = createIndex(0, 0);
            QModelIndex bottomRight = createIndex(group->group_members().size() - 1, 0);
            emit dataChanged(topLeft, bottomRight, {GroupMembersRole});

            return;
        }
    }
}

void GroupListModel::on_add_group_member_received(const int &groupID, QJsonArray new_group_members) {
    if (!groupID || new_group_members.isEmpty())
        return;

    for (GroupInfo *group : _groups) {
        if (group->group_ID() == groupID) {
            for (const QJsonValue &ID : new_group_members) {
                for (ContactInfo *contact : *ContactListModel::_contacts_ptr) {
                    if (contact->phone_number() == ID.toInt()) {
                        group->add_group_members(contact);
                        break;
                    }
                }
            }

            emit group->group_members_changed();
            QModelIndex topLeft = createIndex(0, 0);
            QModelIndex bottomRight = createIndex(group->group_members().size() - 1, 0);
            emit dataChanged(topLeft, bottomRight, {GroupMembersRole});

            return;
        }
    }
}

void GroupListModel::on_removed_from_group(const int &groupID) {
    if (!groupID)
        return;

    for (GroupInfo *group : _groups) {
        if (group->group_ID() == groupID) {
            int index = _groups.indexOf(group);
            beginRemoveRows(QModelIndex(), index, index);
            _groups.removeAt(index);
            endRemoveRows();

            emit groups_changed();

            return;
        }
    }
}

void GroupListModel::on_delete_group_message_received(const int &groupID, const QString &full_time) {
    if (!groupID)
        return;

    for (GroupInfo *group : _groups) {
        if (group->group_ID() == groupID) {
            for (size_t i{0}; i < group->group_messages()->count(); i++) {
                GroupMessageInfo *message = group->group_messages()->at(i);
                if (!message->full_time().compare(_client_manager->UTC_to_timeZone(full_time))) {
                    delete message;
                    group->group_messages()->removeAt(i);

                    if (i == group->group_messages()->count()) {
                        group->set_message_time(group->group_messages()->at(i - 1)->time());
                        group->set_last_message_time(group->group_messages()->at(i - 1)->full_time());

                        QModelIndex index = createIndex(i - 1, 0);
                        emit dataChanged(index, index, {MessageTimeRole});
                        emit dataChanged(index, index, {LastMessageTimeRole});
                    }

                    return;
                }
            }
        }
    }
}

void GroupListModel::on_group_audio_received(const int &groupID, const int &sender_ID, const QString &sender_name, const QString &audio_url, const QString &time) {
    if (!groupID || audio_url.isEmpty())
        return;

    for (GroupInfo *group : _groups) {
        if (group->group_ID() == groupID) {
            group->add_group_message(new GroupMessageInfo(QString(), audio_url, QString(), sender_ID, sender_name, _client_manager->UTC_to_timeZone(time), this));
            group->set_message_time(_client_manager->UTC_to_timeZone(time).split(" ").last());
            group->set_last_message_time(_client_manager->UTC_to_timeZone(time));

            if (!_active_group_chat || (_active_group_chat && _active_group_chat->group_ID() != groupID))
                group->set_group_unread_message(group->group_unread_message() + 1);
            else {
                group->set_group_unread_message(0);
                _client_manager->update_group_unread_message(groupID);
            }

            QModelIndex index = createIndex(_groups.indexOf(group), 0);
            emit dataChanged(index, index, {MessageTimeRole});
            emit dataChanged(index, index, {LastMessageTimeRole});
            emit dataChanged(index, index, {GroupUnreadMessageRole});
        }
    }
}

void GroupListModel::update_group_unread_message(const int &groupID) {
    _client_manager->update_group_unread_message(groupID);

    for (GroupInfo *group : _groups) {
        if (group->group_ID() == groupID) {
            group->set_group_unread_message(0);

            QModelIndex index = createIndex(_groups.indexOf(group), 0);
            emit dataChanged(index, index, {GroupUnreadMessageRole});

            return;
        }
    }
}
