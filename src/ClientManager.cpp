#include "ClientManager.hpp"

ClientManager::ClientManager(QObject *parent)
    : QObject(parent)
{
    if (!_socket)
    {
        _socket = new QWebSocket(QString(), QWebSocketProtocol::VersionLatest, this);
        _socket->open(QUrl(QString("wss://chatapp.hslay13.online")));

        connect(_socket, &QWebSocket::disconnected, this, &ClientManager::on_disconnected);
        connect(_socket, &QWebSocket::textMessageReceived, this, &ClientManager::on_text_message_received);
        connect(_socket, &QWebSocket::errorOccurred, this, [=, this]()
                { emit pop_message_received("Server not Connected"); });

        map_initialization();

        get_user_time();
    }
}

std::shared_ptr<ClientManager> ClientManager::instance()
{
    if (!_instance)
        _instance = std::make_shared<ClientManager>();

    return _instance;
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
        emit status_message(json_object["message"].toString(), json_object["status"].toBool());
        _socket->close();
        break;
    case LoginRequest:
        qDebug() << "Login Info Received";

        emit status_message(json_object["message"].toString(), json_object["status"].toBool());

        emit load_my_info(json_object["my_info"].toObject());
        emit load_contacts(json_object["contacts"].toArray());
        emit load_groups(json_object["groups"].toArray());
        break;
    case LookupFriend:
        emit load_contacts(json_object["json_array"].toArray());
        emit pop_message_received(json_object["message"].toString());
        break;
    case AddedYou:
        emit load_contacts(json_object["json_array"].toArray());
        emit pop_message_received(json_object["message"].toString());
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
        emit client_connected_disconnected(json_object["phone_number"].toInt(), true);
        break;
    case ClientDisconnected:
        emit client_connected_disconnected(json_object["phone_number"].toInt(), false);
        break;
    case AddedToGroup:
        emit load_groups(json_object["groups"].toArray());
        emit pop_message_received(json_object["message"].toString());
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
        emit group_is_typing_received(json_object["groupID"].toInt(), json_object["sender_name"].toString());
        break;
    case UpdateInfo:
        emit update_client_info(json_object["phone_number"].toInt(), json_object["first_name"].toString(), json_object["last_name"].toString());
        break;
    case QuestionAnswer:
        emit question_answer(json_object["secret_question"].toString(), json_object["secret_answer"].toString());
        break;
    case RemoveGroupMember:
        emit remove_group_member_received(json_object["groupID"].toInt(), json_object["group_members"].toArray());
        break;
    case AddGroupMember:
        emit add_group_member_received(json_object["groupID"].toInt(), json_object["group_members"].toArray());
        break;
    case RemovedFromGroup:
        emit removed_from_group(json_object["groupID"].toInt());
        break;
    case DeleteMessage:
        emit delete_message_received(json_object["chatID"].toInt(), json_object["full_time"].toString());
        break;
    case DeleteGroupMessage:
        emit delete_group_message_received(json_object["groupID"].toInt(), json_object["full_time"].toString());
        break;
    case Audio:
        emit audio_received(json_object["chatID"].toInt(), json_object["sender_ID"].toInt(), json_object["audio_url"].toString(), json_object["time"].toString());
        break;
    case GroupAudio:
        emit group_audio_received(json_object["groupID"].toInt(), json_object["sender_ID"].toInt(), json_object["sender_name"].toString(), json_object["audio_url"].toString(), json_object["time"].toString());
        break;
    default:
        qWarning() << "Unknown message type: " << json_object["type"].toString();
        break;
    }
}

void ClientManager::on_disconnected()
{
    emit disconnected();
    emit socket_disconnected(true);
    qDebug() << "Disconnected Signal emitted";
}

/*-------------------------------------------------------------------- Functions --------------------------------------------------------------*/

void ClientManager::sign_up(const int &phone_number, const QString &first_name, const QString &last_name, const QString &password, const QString &password_confirmation, const QString &secret_question, const QString &secret_answer)
{
    QJsonObject json_object{{"type", "sign_up"},
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
    QJsonObject json_object{{"type", "login_request"},
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

void ClientManager::update_info(const QString &first_name, const QString &last_name, const QString &password)
{
    QJsonObject json_object{{"type", "update_info"},
                            {"first_name", first_name},
                            {"last_name", last_name},
                            {"password", password}};

    _socket->sendTextMessage(QString::fromUtf8(QJsonDocument(json_object).toJson()));
}

void ClientManager::update_password(const int &phone_number, const QString &password)
{
    QJsonObject json_object{{"type", "update_password"},
                            {"phone_number", phone_number},
                            {"password", password}};

    _socket->sendTextMessage(QString::fromUtf8(QJsonDocument(json_object).toJson()));
}

void ClientManager::retrieve_question(const int &phone_number)
{
    QJsonObject json_object{{"type", "retrieve_question"},
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

void ClientManager::send_text(const int &receiver, const QString &message, const int &chat_ID)
{
    QJsonObject json_object{{"type", "text"},
                            {"receiver", receiver},
                            {"message", message},
                            {"time", QDateTime::currentDateTimeUtc().toString()},
                            {"chatID", chat_ID}};

    _socket->sendTextMessage(QString::fromUtf8(QJsonDocument(json_object).toJson()));
}

void ClientManager::send_group_text(const int &groupID, QString sender_name, const QString &message)
{
    QJsonObject json_object{{"type", "group_text"},
                            {"groupID", groupID},
                            {"message", message},
                            {"sender_name", sender_name},
                            {"time", QDateTime::currentDateTimeUtc().toString()}};

    _socket->sendTextMessage(QString::fromUtf8(QJsonDocument(json_object).toJson()));
}

void ClientManager::send_file(const int &chatID, const int &receiver, const QString &file_name, const QByteArray &file_data)
{
    QString data = QString::fromUtf8(file_data.toBase64());

    QJsonObject json_object{{"type", "file"},
                            {"chatID", chatID},
                            {"receiver", receiver},
                            {"file_name", file_name},
                            {"file_data", data},
                            {"time", QDateTime::currentDateTimeUtc().toString()}};

    _socket->sendTextMessage(QString::fromUtf8(QJsonDocument(json_object).toJson()));
}

void ClientManager::send_group_file(const int &groupID, const QString &sender_name, const QString &file_name, const QByteArray &file_data)
{
    QString data = QString::fromUtf8(file_data.toBase64());

    QJsonObject json_object{{"type", "group_file"},
                            {"groupID", groupID},
                            {"sender_name", sender_name},
                            {"file_name", file_name},
                            {"file_data", data},
                            {"time", QDateTime::currentDateTimeUtc().toString()}};

    _socket->sendTextMessage(QString::fromUtf8(QJsonDocument(json_object).toJson()));
}

void ClientManager::new_group(const QString &group_name, QJsonArray group_members)
{
    QJsonObject json_object{{"type", "new_group"},
                            {"group_name", group_name},
                            {"group_members", group_members}};

    _socket->sendTextMessage(QString::fromUtf8(QJsonDocument(json_object).toJson()));
}

void ClientManager::send_is_typing(const int &phone_number)
{
    QJsonObject json_object{{"type", "is_typing"},
                            {"receiver", phone_number}};

    _socket->sendTextMessage(QString::fromUtf8(QJsonDocument(json_object).toJson()));
}

void ClientManager::send_group_is_typing(const int &groupID, const QString &sender_name)
{
    QJsonObject json_object{{"type", "group_is_typing"},
                            {"groupID", groupID},
                            {"sender_name", sender_name}};

    _socket->sendTextMessage(QString::fromUtf8(QJsonDocument(json_object).toJson()));
}

void ClientManager::remove_group_member(const int &groupID, QJsonArray group_members)
{
    QJsonObject json_object{{"type", "remove_group_member"},
                            {"groupID", groupID},
                            {"group_members", group_members}};

    _socket->sendTextMessage(QString::fromUtf8(QJsonDocument(json_object).toJson()));
}

void ClientManager::add_group_member(const int &groupID, QJsonArray group_members)
{
    QJsonObject json_object{{"type", "add_group_member"},
                            {"groupID", groupID},
                            {"group_members", group_members}};

    _socket->sendTextMessage(QString::fromUtf8(QJsonDocument(json_object).toJson()));
}

void ClientManager::delete_message(const int &phone_number, const int &chat_ID, const QString &full_time)
{
    const QString &UTC_time = QDateTime::fromString(full_time, "yyyy-MM-dd HH:mm:ss")
                                  .toUTC()
                                  .toString();

    QJsonObject json_object{{"type", "delete_message"},
                            {"receiver", phone_number},
                            {"chatID", chat_ID},
                            {"full_time", UTC_time}};

    _socket->sendTextMessage(QString::fromUtf8(QJsonDocument(json_object).toJson()));
}

void ClientManager::delete_group_message(const int &groupID, const QString &full_time)
{
    const QString &UTC_time = QDateTime::fromString(full_time, "yyyy-MM-dd HH:mm:ss")
                                  .toUTC()
                                  .toString();

    QJsonObject json_object{{"type", "delete_group_message"},
                            {"groupID", groupID},
                            {"full_time", UTC_time}};

    _socket->sendTextMessage(QString::fromUtf8(QJsonDocument(json_object).toJson()));
}

void ClientManager::update_unread_message(const int &chatID)
{
    QJsonObject json_object{{"type", "update_unread_message"},
                            {"chatID", chatID}};

    _socket->sendTextMessage(QString::fromUtf8(QJsonDocument(json_object).toJson()));
}

void ClientManager::update_group_unread_message(const int &groupID)
{
    QJsonObject json_object{{"type", "update_group_unread_message"},
                            {"groupID", groupID}};

    _socket->sendTextMessage(QString::fromUtf8(QJsonDocument(json_object).toJson()));
}

void ClientManager::delete_account()
{
    QJsonObject json_object{{"type", "delete_account"}};

    _socket->sendTextMessage(QString::fromUtf8(QJsonDocument(json_object).toJson()));
}

void ClientManager::send_audio(const int &chatID, const int &receiver, const QString &audio_name, const QByteArray &audio_data)
{
    QString data = QString::fromUtf8(audio_data.toBase64());

    QJsonObject json_object{{"type", "audio"},
                            {"chatID", chatID},
                            {"receiver", receiver},
                            {"audio_name", audio_name},
                            {"audio_data", data},
                            {"time", QDateTime::currentDateTimeUtc().toString()}};

    _socket->sendTextMessage(QString::fromUtf8(QJsonDocument(json_object).toJson()));
}

void ClientManager::send_group_audio(const int &groupID, const QString &sender_name, const QString &audio_name, const QByteArray &audio_data)
{
    QString data = QString::fromUtf8(audio_data.toBase64());

    QJsonObject json_object{{"type", "group_audio"},
                            {"groupID", groupID},
                            {"sender_name", sender_name},
                            {"audio_name", audio_name},
                            {"audio_data", data},
                            {"time", QDateTime::currentDateTimeUtc().toString()}};

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
    _map["update_info"] = UpdateInfo;
    _map["question_answer"] = QuestionAnswer;
    _map["remove_group_member"] = RemoveGroupMember;
    _map["add_group_member"] = AddGroupMember;
    _map["removed_from_group"] = RemovedFromGroup;
    _map["delete_message"] = DeleteMessage;
    _map["delete_group_message"] = DeleteGroupMessage;
    _map["audio"] = Audio;
    _map["group_audio"] = GroupAudio;
}

QString ClientManager::UTC_to_timeZone(const QString &UTC_time)
{
    QDateTime UTC_dateTime = QDateTime::fromString(UTC_time);
    if (!UTC_dateTime.isValid())
    {
        qDebug() << "Invalid UTC time format:" << UTC_time;
        return QString();
    }

#ifdef __EMSCRIPTEN__
    QString utcDateString = UTC_dateTime.toUTC().toString(Qt::ISODate);

    const char *localTime = (char *)EM_ASM_PTR(
        {
            var date = new Date(UTF8ToString($0));

            var localDateStr = date.toLocaleString('en-GB', {
                                       year : 'numeric',
                                       month : '2-digit',
                                       day : '2-digit',
                                       hour : '2-digit',
                                       minute : '2-digit',
                                       second : '2-digit',
                                       hour12 : false
                                   })
                                   .replace(',', "");

            var ptr = stackAlloc(lengthBytesUTF8(localDateStr) + 1);
            stringToUTF8(localDateStr, ptr, lengthBytesUTF8(localDateStr) + 1);

            return ptr;
        },
        utcDateString.toStdString().c_str());

    return QString::fromUtf8(localTime);
#else
    QTimeZone targetTimeZone(_time_zone.toUtf8());
    if (!targetTimeZone.isValid())
    {
        qDebug() << "Invalid time zone ID:" << _time_zone;
        return QString();
    }

    QDateTime localDateTime = UTC_dateTime.toTimeZone(targetTimeZone);

    return localDateTime.toString("yyyy-MM-dd HH:mm:ss");
#endif
}
