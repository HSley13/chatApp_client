#include "ClientManager.h"

QHash<QString, ClientManager::MessageType> ClientManager::_map;
ClientManager *ClientManager::_instance{nullptr};
QWebSocket *ClientManager::_socket{nullptr};

ClientManager::ClientManager(QObject *parent)
    : QObject(parent)
{
    if (!_socket)
    {
        _socket = new QWebSocket(QString(), QWebSocketProtocol::VersionLatest, this);
        _socket->open(QUrl(QString("wss://chatapp.hslay13.online")));

        connect(_socket, &QWebSocket::disconnected, this, &ClientManager::on_disconnected);
        connect(_socket, &QWebSocket::textMessageReceived, this, &ClientManager::on_text_message_received);

        map_initialization();

        get_user_time();
    }
}

ClientManager *ClientManager::instance()
{
    if (!_instance)
        _instance = new ClientManager();

    return _instance;
}

void ClientManager::cleanup()
{
    delete _instance;
    _instance = nullptr;
}

void ClientManager::on_text_message_received(const QString &message)
{
    QJsonDocument json_doc = QJsonDocument::fromJson(message.toUtf8());
    if (json_doc.isNull())
    {
        qWarning() << "Invalid JSON document.";
        return;
    }

    QJsonObject json_object = json_doc.object();
    MessageType type = _map.value(json_object["type"].toString());

    switch (type)
    {
    case SignUp:
    {
        const QString &message = QString("%1: %2")
                                     .arg(json_object["status"].toString())
                                     .arg(json_object["message"].toString());

        _signup_message = message;
    }
    break;
    case LoginRequest:
    {
        const QString &message = QString("%1: %2")
                                     .arg(json_object["status"].toString())
                                     .arg(json_object["message"].toString());

        _login_message = message;

        emit load_my_info(json_object["my_info"].toObject());
        emit load_contacts(json_object["contacts"].toArray());
        emit load_groups(json_object["groups"].toArray());
    }
    break;
    case LookupFriend:
        emit load_contacts(json_object["json_array"].toArray());
        break;
    case AddedYou:
        emit load_contacts(json_object["json_array"].toArray());
        break;
    case ProfileImage:
        emit profile_image(json_object["image_url"].toString());
        break;
    case GroupProfileImage:
        emit group_profile_image(json_object["groupID"].toInt(), json_object["group_image_url"].toString());
        break;
    case ClientProfileImage:
        emit client_profile_image(json_object["phone_number"].toInt(), json_object["image_url"].toString());
        break;
    case Text:
        emit text_received(json_object["chatID"].toInt(), json_object["sender_ID"].toInt(), json_object["message"].toString(), json_object["time"].toString());
        break;
    case ClientConnected:
        emit client_connected(json_object["phone_number"].toInt());
        break;
    case ClientDisconnected:
        emit client_disconnected(json_object["phone_number"].toInt());
        break;
    case AddedToGroup:
        emit load_groups(json_object["groups"].toArray());
        break;
    case GroupText:
        emit group_text_received(json_object["groupID"].toInt(), json_object["sender_ID"].toInt(), json_object["sender_name"].toString(), json_object["message"].toString(), json_object["time"].toString());
        break;
    case File:
        emit file_received(json_object["chatID"].toInt(), json_object["sender_ID"].toInt(), json_object["file_url"].toString(), json_object["time"].toString());
        break;
    case GroupFile:
        emit group_file_received(json_object["groupID"].toInt(), json_object["sender_ID"].toInt(), json_object["sender_name"].toString(), json_object["file_url"].toString(), json_object["time"].toString());
        break;
    case IsTyping:
        emit is_typing_received(json_object["sender_ID"].toInt());
        break;
    case GroupIsTyping:
        emit group_is_typing_received(json_object["groupID"].toInt(), json_object["sender_ID"].toInt());
        break;
    case AudioMessage:
        break;
    case ClientNewName:
        break;
    case NewPasswordRequest:
        break;
    case UpdatePassword:
        break;
    case DeleteMessage:
        break;
    case DeleteGroupMessage:
        break;
    case GroupAudio:
        break;
    case NewGroupMember:
        break;
    case RemoveGroupMember:
        break;
    case DeleteAccount:
        break;
    case LastMessageRead:
        break;
    case GroupLastMessageRead:
        break;
    default:
        qWarning() << "Unknown message type: " << json_object["type"].toString();
        break;
    }
}

void ClientManager::on_disconnected()
{
    emit disconnected();
    qDebug() << "Disconnected Signal emitted";
}
/*-------------------------------------------------------------------- Functions --------------------------------------------------------------*/

void ClientManager::sign_up(const int &phone_number, const QString &first_name, const QString &last_name, const QString &password, const QString &password_confirmation, const QString &secret_question, const QString &secret_answer)
{
    QJsonObject json_object{
        {"type", "sign_up"},
        {"phone_number", phone_number},
        {"first_name", first_name},
        {"last_name", last_name},
        {"password", password},
        {"secret_question", secret_question},
        {"secret_answer", secret_answer}};

    _socket->sendTextMessage(QString::fromUtf8(QJsonDocument(json_object).toJson()));
}

void ClientManager::login_request(const int &phone_number, const QString &password)
{
    QJsonObject json_object{
        {"type", "login_request"},
        {"phone_number", phone_number},
        {"password", password},
        {"time_zone", _time_zone}};

    _socket->sendTextMessage(QString::fromUtf8(QJsonDocument(json_object).toJson()));
}

void ClientManager::lookup_friend(const int &phone_number)
{
    QJsonObject json_object{{"type", "lookup_friend"},
                            {"phone_number", phone_number}};

    _socket->sendTextMessage(QString::fromUtf8(QJsonDocument(json_object).toJson()));
}

void ClientManager::profile_image_deleted()
{
    QJsonObject json_object{{"type", "profile_image_deleted"}};

    _socket->sendTextMessage(QString::fromUtf8(QJsonDocument(json_object).toJson()));
}

void ClientManager::update_profile(const QString &file_name, const QByteArray &file_data)
{
    QString data = QString::fromUtf8(file_data.toBase64());

    QJsonObject json_object{{"type", "profile_image"},
                            {"file_name", file_name},
                            {"file_data", data}};

    _socket->sendTextMessage(QString::fromUtf8(QJsonDocument(json_object).toJson()));
}

void ClientManager::update_group_profile(const int &group_ID, const QString &file_name, const QByteArray &file_data)
{
    QString data = QString::fromUtf8(file_data.toBase64());

    QJsonObject json_object{{"type", "group_profile_image"},
                            {"groupID", group_ID},
                            {"file_name", file_name},
                            {"file_data", data}};

    _socket->sendTextMessage(QString::fromUtf8(QJsonDocument(json_object).toJson()));
}

void ClientManager::send_text(const int &receiver, const QString &message, const QString &time, const int &chat_ID)
{
    QJsonObject json_object{{"type", "text"},
                            {"receiver", receiver},
                            {"message", message},
                            {"time", time},
                            {"chatID", chat_ID}};

    _socket->sendTextMessage(QString::fromUtf8(QJsonDocument(json_object).toJson()));
}

void ClientManager::send_group_text(const int &groupID, QString sender_name, const QString &message, const QString &time)
{
    QJsonObject json_object{{"type", "group_text"},
                            {"groupID", groupID},
                            {"message", message},
                            {"sender_name", sender_name},
                            {"time", time}};

    _socket->sendTextMessage(QString::fromUtf8(QJsonDocument(json_object).toJson()));
}

void ClientManager::send_file(const int &chatID, const int &receiver, const QString &file_name, const QByteArray &file_data, const QString &time)
{
    QString data = QString::fromUtf8(file_data.toBase64());

    QJsonObject json_object{{"type", "file"},
                            {"chatID", chatID},
                            {"receiver", receiver},
                            {"file_name", file_name},
                            {"file_data", data},
                            {"time", time}};

    _socket->sendTextMessage(QString::fromUtf8(QJsonDocument(json_object).toJson()));
}

void ClientManager::send_group_file(const int &groupID, const QString &sender_name, const QString &file_name, const QByteArray &file_data, const QString &time)
{
    QString data = QString::fromUtf8(file_data.toBase64());

    QJsonObject json_object{{"type", "group_file"},
                            {"groupID", groupID},
                            {"sender_name", sender_name},
                            {"file_name", file_name},
                            {"file_data", data},
                            {"time", time}};

    _socket->sendTextMessage(QString::fromUtf8(QJsonDocument(json_object).toJson()));
}

void ClientManager::new_group(const QString &group_name, QJsonArray json_array)
{
    QJsonObject json_object{{"type", "new_group"},
                            {"group_name", group_name},
                            {"group_members", json_array}};

    _socket->sendTextMessage(QString::fromUtf8(QJsonDocument(json_object).toJson()));
}

void ClientManager::send_is_typing(const int &phone_number)
{
    QJsonObject json_object{{"type", "is_typing"},
                            {"receiver", phone_number}};

    _socket->sendTextMessage(QString::fromUtf8(QJsonDocument(json_object).toJson()));
}

void ClientManager::send_group_is_typing(const int &groupID)
{
    QJsonObject json_object{{"type", "group_is_typing"},
                            {"groupID", groupID}};

    _socket->sendTextMessage(QString::fromUtf8(QJsonDocument(json_object).toJson()));
}

void ClientManager::get_user_time()
{
#ifdef __EMSCRIPTEN__
    char *time_zone = (char *)EM_ASM_PTR({
        var tz = Intl.DateTimeFormat().resolvedOptions().timeZone;
        var lengthBytes = lengthBytesUTF8(tz) + 1;
        var stringOnWasmHeap = _malloc(lengthBytes);
        stringToUTF8(tz, stringOnWasmHeap, lengthBytes);
        return stringOnWasmHeap;
    });

    _time_zone = QString::fromUtf8(time_zone);
    free((void *)time_zone);
#else
    _time_zone = QTimeZone::systemTimeZone().id();
#endif
}

void ClientManager::map_initialization()
{
    _map["sign_up"] = SignUp;
    _map["login_request"] = LoginRequest;
    _map["lookup_friend"] = LookupFriend;
    _map["is_typing"] = IsTyping;
    _map["text"] = Text;
    _map["group_text"] = GroupText;
    _map["profile_image"] = ProfileImage;
    _map["group_profile_image"] = GroupProfileImage;
    _map["client_profile_image"] = ClientProfileImage;
    _map["client_disconnected"] = ClientDisconnected;
    _map["client_connected"] = ClientConnected;
    _map["added_you"] = AddedYou;
    _map["added_to_group"] = AddedToGroup;
    _map["file"] = File;
    _map["group_file"] = GroupFile;
    _map["group_is_typing"] = GroupIsTyping;
    _map["audio"] = AudioMessage;
    _map["client_new_name"] = ClientNewName;
    _map["new_password_request"] = NewPasswordRequest;
    _map["update_password"] = UpdatePassword;
    _map["delete_message"] = DeleteMessage;
    _map["delete_group_message"] = DeleteGroupMessage;
    _map["group_audio"] = GroupAudio;
    _map["new_group_member"] = NewGroupMember;
    _map["remove_group_member"] = RemoveGroupMember;
    _map["delete_account"] = DeleteAccount;
    _map["last_message_read"] = LastMessageRead;
    _map["group_last_message_read"] = GroupLastMessageRead;
    _map["invalid_type"] = InvalidType;
}