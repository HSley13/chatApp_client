#include "ClientManager.h"

QHash<QString, ClientManager::MessageType> ClientManager::_map;
ClientManager *ClientManager::_instance = nullptr;
QWebSocket *ClientManager::_socket = nullptr;

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

        mount_audio_IDBFS();
        mount_file_IDBFS();
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
        emit signup_message_changed();
    }
    break;
    case LoginRequest:
    {
        const QString &message = QString("%1: %2")
                                     .arg(json_object["status"].toString())
                                     .arg(json_object["message"].toString());

        _login_message = message;
        emit login_message_changed();

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
    case ClientProfileImage:
        emit client_profile_image(json_object["phone_number"].toInt(), json_object["image_url"].toString());
        break;
    case TextMessage:
        emit text_received(json_object["chatID"].toInt(), json_object["message"].toString(), json_object["time"].toString());
        break;
    case ClientDisconnected:
        emit client_connected(json_object["phone_number"].toInt());
        break;
    case ClientConnected:
        emit client_disconnected(json_object["phone_number"].toInt());
        break;
    case AudioMessage:
        break;
    case IsTyping:
        break;
    case SetName:
        break;
    case FileMessage:
        break;
    case SaveData:
        break;
    case ClientNewName:
        break;
    case CreateConversation:
        break;
    case SaveMessage:
        break;
    case NewPasswordRequest:
        break;
    case UpdatePassword:
        break;
    case DeleteMessage:
        break;
    case DeleteGroupMessage:
        break;
    case NewGroup:
        break;
    case AddedToGroup:
        break;
    case GroupIsTyping:
        break;
    case GroupText:
        break;
    case GroupFile:
        break;
    case GroupAudio:
        break;
    case NewGroupMember:
        break;
    case RemoveGroupMember:
        break;
    case RequestData:
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

void ClientManager::update_profile(const QString &file_name, const QByteArray &file_data)
{
    QString data = QString::fromUtf8(file_data.toBase64());

    QJsonObject json_object{{"type", "profile_image"},
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

const QString &ClientManager::signup_message() const
{
    return _signup_message;
}

const QString &ClientManager::login_message() const
{
    return _login_message;
}

void ClientManager::mount_audio_IDBFS()
{
#ifdef __EMSCRIPTEN__
    EM_ASM({
        FS.mkdir('/audio');
        FS.mount(IDBFS, {}, '/audio');
        FS.syncfs(true);
    });
#endif
}

void ClientManager::mount_file_IDBFS()
{
#ifdef __EMSCRIPTEN__
    EM_ASM({
        FS.mkdir('/file');
        FS.mount(IDBFS, {}, '/file');
        FS.syncfs(true);
    });
#endif
}

void ClientManager::IDBFS_save_audio(const QString &audio_name, const QByteArray &audio_data, const int &size)
{
#ifdef __EMSCRIPTEN__
    std::string audio_path = "/audio/" + audio_name.toStdString();

    FILE *file = fopen(audio_path.c_str(), "wb");
    if (file)
    {
        fwrite(audio_data, 1, size, file);
        fclose(file);
    }

    EM_ASM({ FS.syncfs(); });
#endif
}

void ClientManager::IDBFS_save_file(const QString &file_name, const QByteArray &file_data, const int &size)
{
#ifdef __EMSCRIPTEN__
    std::string file_path = "/file/" + file_name.toStdString();

    FILE *file = fopen(file_path.c_str(), "wb");
    if (file)
    {
        fwrite(file_data, 1, size, file);
        fclose(file);
    }

    EM_ASM({ FS.syncfs(); });
#endif
}

QUrl ClientManager::get_audio_url(const QString &audio_name)
{
#ifdef __EMSCRIPTEN__
    const QString full_audio_path = "/audio/" + audio_name;

    qDebug() << "ClientManager --> get_audio_url() --> audio full_path: " << full_audio_path;

    char *url = (char *)EM_ASM_PTR(
        {
            var audio_path = UTF8ToString($0);
            try
            {
                var audio_data = FS.readFile(audio_path);

                if (!audio_data)
                    throw 'Audio data not found';

                var blob = new Blob([audio_data],
                                    { type: 'audio/*' });
                var url = URL.createObjectURL(blob);

                var url_length = lengthBytesUTF8(url) + 1;
                var stringOnWasmHeap = _malloc(url_length);

                stringToUTF8(url, stringOnWasmHeap, url_length);

                return stringOnWasmHeap;
            }
            catch (e)
            {
                console.error('Error creating Audio URL:', e);
                return 0;
            }
        },
        full_audio_path.toUtf8().constData());

    if (!url)
    {

        return QUrl();
    }

    QString qUrl = QString::fromUtf8(url);
    free(url);

    return QUrl(qUrl);
#else
    return QUrl();
#endif
}

QUrl ClientManager::get_file_url(const QString &file_name)
{
#ifdef __EMSCRIPTEN__
    const QString full_file_path = "/file/" + file_name;

    char *url = (char *)EM_ASM_PTR(
        {
            var file_path = UTF8ToString($0);
            try
            {
                var file_data = FS.readFile(file_path);

                if (!file_data)
                    return null;

                var mime_type = 'application/octet-stream';
                var extension = file_path.split('.').pop().toLowerCase();

                switch (extension)
                {
                case 'pdf':
                    mime_type = 'application/pdf';
                    break;
                case 'jpg':
                case 'jpeg':
                case 'png':
                case 'webp':
                case 'gif':
                case 'bmp':
                case 'svg':
                    mime_type = 'image/*';
                    break;
                case 'txt':
                    mime_type = 'text/plain';
                    break;
                case 'html':
                case 'htm':
                    mime_type = 'text/html';
                    break;
                case 'css':
                    mime_type = 'text/css';
                    break;
                case 'js':
                    mime_type = 'application/javascript';
                    break;
                case 'json':
                    mime_type = 'application/json';
                    break;
                case 'xml':
                    mime_type = 'application/xml';
                    break;
                case 'csv':
                    mime_type = 'text/csv';
                    break;
                case 'doc':
                    mime_type = 'application/msword';
                    break;
                case 'docx':
                    mime_type = 'application/vnd.openxmlformats-officedocument.wordprocessingml.document';
                    break;
                case 'xls':
                    mime_type = 'application/vnd.ms-excel';
                    break;
                case 'xlsx':
                    mime_type = 'application/vnd.openxmlformats-officedocument.spreadsheetml.sheet';
                    break;
                case 'ppt':
                    mime_type = 'application/vnd.ms-powerpoint';
                    break;
                case 'pptx':
                    mime_type = 'application/vnd.openxmlformats-officedocument.presentationml.presentation';
                    break;
                case 'mp4':
                    mime_type = 'video/mp4';
                    break;
                case 'avi':
                    mime_type = 'video/x-msvideo';
                    break;
                case 'mov':
                    mime_type = 'video/quicktime';
                    break;
                case 'zip':
                    mime_type = 'application/zip';
                    break;
                case 'rar':
                    mime_type = 'application/vnd.rar';
                    break;
                case 'tar':
                    mime_type = 'application/x-tar';
                    break;
                case '7z':
                    mime_type = 'application/x-7z-compressed';
                    break;
                case 'epub':
                    mime_type = 'application/epub+zip';
                    break;
                case 'mobi':
                    mime_type = 'application/x-mobipocket-ebook';
                    break;
                case 'azw':
                    mime_type = 'application/vnd.amazon.ebook';
                    break;
                case 'webm':
                    mime_type = 'video/webm';
                    break;
                case 'mkv':
                    mime_type = 'video/x-matroska';
                    break;
                case 'rtf':
                    mime_type = 'application/rtf';
                    break;
                case 'psd':
                    mime_type = 'image/vnd.adobe.photoshop';
                    break;
                case 'ai':
                case 'eps':
                case 'ps':
                    mime_type = 'application/postscript';
                    break;
                case 'tex':
                    mime_type = 'application/x-tex';
                    break;
                case 'latex':
                    mime_type = 'application/x-latex';
                    break;
                case 'md':
                    mime_type = 'text/markdown';
                    break;
                case 'log':
                    mime_type = 'text/plain';
                    break;
                case 'c':
                case 'cpp':
                case 'h':
                case 'hpp':
                    mime_type = 'text/x-c';
                    break;
                case 'py':
                    mime_type = 'text/x-python';
                    break;
                case 'java':
                    mime_type = 'text/x-java-source';
                    break;
                case 'sh':
                    mime_type = 'application/x-sh';
                    break;
                case 'bat':
                    mime_type = 'application/x-msdos-program';
                    break;
                case 'exe':
                    mime_type = 'application/x-msdownload';
                    break;
                default:
                    console.warn("Unknown file extension:", extension);
                    break;
                }

                var blob = new Blob([file_data],
                                    { type: mime_type });
                var url = URL.createObjectURL(blob);

                var url_length = lengthBytesUTF8(url) + 1;
                var stringOnWasmHeap = _malloc(url_length);

                stringToUTF8(url, stringOnWasmHeap, url_length);

                return stringOnWasmHeap;
            }
            catch (e)
            {
                console.error('Error creating File URL:', e);
                return 0;
            }
        },
        full_file_path.toUtf8().constData());

    if (!url)
    {

        return QUrl();
    }

    QString qUrl = QString::fromUtf8(url);
    free(url);

    return QUrl(qUrl);
#else
    return QUrl();
#endif
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
    _map["text"] = TextMessage;
    _map["profile_image"] = ProfileImage;
    _map["client_profile_image"] = ClientProfileImage;
    _map["client_disconnected"] = ClientDisconnected;
    _map["client_connected"] = ClientConnected;
    _map["set_name"] = SetName;
    _map["file"] = FileMessage;
    _map["audio"] = AudioMessage;
    _map["save_data"] = SaveData;
    _map["client_new_name"] = ClientNewName;
    _map["added_you"] = AddedYou;
    _map["create_conversation"] = CreateConversation;
    _map["save_message"] = SaveMessage;
    _map["new_password_request"] = NewPasswordRequest;
    _map["update_password"] = UpdatePassword;
    _map["delete_message"] = DeleteMessage;
    _map["delete_group_message"] = DeleteGroupMessage;
    _map["new_group"] = NewGroup;
    _map["added_to_group"] = AddedToGroup;
    _map["group_is_typing"] = GroupIsTyping;
    _map["group_text"] = GroupText;
    _map["group_file"] = GroupFile;
    _map["group_audio"] = GroupAudio;
    _map["new_group_member"] = NewGroupMember;
    _map["remove_group_member"] = RemoveGroupMember;
    _map["request_data"] = RequestData;
    _map["delete_account"] = DeleteAccount;
    _map["last_message_read"] = LastMessageRead;
    _map["group_last_message_read"] = GroupLastMessageRead;
    _map["invalid_type"] = InvalidType;
}