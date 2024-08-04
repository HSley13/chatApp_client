#include "ClientManager.h"

QWebSocket *ClientManager::_socket = nullptr;
ChatProtocol *ClientManager::_protocol = nullptr;

QString ClientManager::_my_ID;
QString ClientManager::_my_name;
QString ClientManager::_file_name;
QString ClientManager::_time_zone;

ClientManager::ClientManager(QObject *parent)
    : QObject(parent)
{
    if (!_socket && !_protocol)
    {
        _socket = new QWebSocket(QString(), QWebSocketProtocol::VersionLatest, this);
        QUrl url = QUrl(QString("wss://chatapp.hslay13.online"));

        connect(_socket, &QWebSocket::disconnected, this, &ClientManager::on_disconnected);
        connect(_socket, &QWebSocket::binaryMessageReceived, this, &ClientManager::on_binary_message_received);
        connect(_socket, &QWebSocket::errorOccurred, this, [this, &url]()
                {
                    if (_socket->state() == QAbstractSocket::UnconnectedState)
                        QTimer::singleShot(3000, this, [this, &url]() { _socket->open(url); }); });

        _socket->open(url);

        _protocol = new ChatProtocol(this);

        get_user_time();

        mount_audio_IDBFS();
        mount_file_IDBFS();
    }
}

/*-------------------------------------------------------------------- Slots --------------------------------------------------------------*/

void ClientManager::on_binary_message_received(const QByteArray &message)
{
    _protocol->load_data(message);

    switch (_protocol->type())
    {
    case ChatProtocol::text:
        emit text_message_received(_protocol->sender(), _protocol->message(), _protocol->time());

        break;

    case ChatProtocol::is_typing:
        emit is_typing_received(_protocol->sender());

        break;

    case ChatProtocol::client_new_name:
        emit client_name_changed(_protocol->old_name(), _protocol->client_name());

        break;

    case ChatProtocol::client_disconnected:
        emit client_disconnected(_protocol->client_name());

        break;

    case ChatProtocol::client_connected:
        emit client_connected(_protocol->client_name());

        break;

    case ChatProtocol::added_you:
        emit client_added_you(_protocol->conversation_ID(), _protocol->client_name(), _protocol->clients_ID());

        break;

    case ChatProtocol::lookup_friend:
        emit lookup_friend_result(_protocol->conversation_ID(), _protocol->client_name(), _protocol->true_or_false());

        break;

    case ChatProtocol::audio:
        save_audio(_protocol->audio_sender(), _protocol->audio_name(), _protocol->audio_data(), _protocol->time());

        break;

    case ChatProtocol::login_request:
    {
        _my_name = _protocol->my_name();

        emit login_request(_protocol->hashed_password(), _protocol->true_or_false(), _protocol->friend_list(), _protocol->online_friends(), _protocol->messages(), _protocol->group_list(), _protocol->group_messages(), _protocol->groups_members());
    }

    break;

    case ChatProtocol::new_password_request:
        emit new_password_requested(_protocol->secret_question(), _protocol->secret_answer());

        break;

    case ChatProtocol::file:
        save_file(_protocol->file_sender(), _protocol->file_name(), _protocol->file_data(), _protocol->time());

        break;

    case ChatProtocol::delete_message:
        delete_message(_protocol->sender(), _protocol->time());

        break;

    case ChatProtocol::new_group:
        emit new_group_ID(_protocol->group_ID());

        break;

    case ChatProtocol::added_to_group:
        emit added_to_group(_protocol->group_ID(), _protocol->adm(), _protocol->group_members(), _protocol->group_name());

        break;

    case ChatProtocol::group_is_typing:
        emit group_is_typing_received(_protocol->group_ID(), _protocol->group_name(), _protocol->group_sender());

        break;

    case ChatProtocol::group_text:
        emit group_text_received(_protocol->group_ID(), _protocol->group_name(), _protocol->group_sender(), _protocol->group_message(), _protocol->group_time());

        break;

    case ChatProtocol::group_audio:
        save_group_audio(_protocol->group_ID(), _protocol->group_name(), _protocol->group_sender(), _protocol->group_audio_name(), _protocol->group_audio_data(), _protocol->group_time());

        break;

    case ChatProtocol::group_file:
        save_group_file(_protocol->group_ID(), _protocol->group_name(), _protocol->group_sender(), _protocol->group_file_name(), _protocol->group_file_data(), _protocol->group_time());

        break;

    case ChatProtocol::remove_group_member:
        removed_from_group(_protocol->group_ID(), _protocol->group_name(), _protocol->adm(), _protocol->clients_ID());

        break;

    case ChatProtocol::request_data:
        (!_protocol->data_type().compare("file")) ? IDBFS_save_file(_file_name, _protocol->file_data(), _protocol->file_data().size()) : IDBFS_save_audio(_file_name, _protocol->file_data(), _protocol->file_data().size());

        break;

    default:
        break;
    }
}

void ClientManager::on_disconnected()
{
    emit socket_disconnected();
}

void ClientManager::disconnect_from_host()
{
    _socket->close();
}
/*-------------------------------------------------------------------- Functions --------------------------------------------------------------*/

void ClientManager::send_text(const QString &sender, const QString &receiver, const QString &text, const QString &time)
{
    _socket->sendBinaryMessage(_protocol->set_text_message(sender, receiver, text, time));
}

void ClientManager::send_name(const QString &name)
{
    _my_name = name;

    _socket->sendBinaryMessage(_protocol->set_name_message(_my_ID, name));
}

void ClientManager::send_is_typing(const QString &sender, const QString &receiver)
{
    _socket->sendBinaryMessage(_protocol->set_is_typing_message(sender, receiver));
}

void ClientManager::save_file(const QString &sender, const QString &file_name, const QByteArray &file_data, const QString &time)
{
    const QString &IDBFS_file_name = QString("%1_%2").arg(time, file_name);

#ifdef __EMSCRIPTEN__
    IDBFS_save_file(IDBFS_file_name, file_data, static_cast<int>(file_data.size()));
    emit file_received(sender, IDBFS_file_name, time.split(" ").last());
#else
    QDir dir(QCoreApplication::applicationDirPath());

    if (!sender.isEmpty() && !sender.isNull())
    {
        const QString &dir_path = dir.filePath(sender);
        if (!dir.exists(dir_path))
            dir.mkpath(dir_path);
    }

    const QString &path = QString("%1/%2").arg(dir.canonicalPath(), IDBFS_file_name);

    QFile file(path);
    if (file.open(QIODevice::WriteOnly))
    {
        file.write(file_data);
        file.close();
    }

    emit file_received(sender, path, time.split(" ").last());
#endif
}

void ClientManager::send_save_data(const int &conversation_ID, const QString &sender, const QString &receiver, const QString &data_name, const QByteArray &data_data, const QString &type, const QString &time)
{
    _socket->sendBinaryMessage(_protocol->set_save_data_message(conversation_ID, sender, receiver, data_name, data_data, type, time));
}

void ClientManager::save_audio(const QString &sender, const QString &audio_name, const QByteArray &audio_data, const QString &time)
{
    const QString &IDBFS_audio_name = QString("%1_%2").arg(time, audio_name);

#ifdef __EMSCRIPTEN__
    IDBFS_save_audio(IDBFS_audio_name, audio_data, static_cast<int>(audio_data.size()));
    emit audio_received(sender, IDBFS_audio_name, time.split(" ").last());
#else
    QDir dir(QCoreApplication::applicationDirPath());

    if (!sender.isEmpty() && !sender.isNull())
    {
        const QString &dir_path = dir.filePath(sender);
        if (!dir.exists(dir_path))
            dir.mkpath(dir_path);
    }

    const QString &path = QString("%1/%2").arg(dir.canonicalPath(), IDBFS_audio_name);

    QFile audio(path);
    if (audio.open(QIODevice::WriteOnly))
    {
        audio.write(audio_data);
        audio.close();
    }

    emit audio_received(sender, path, time.split(" ").last());
#endif
}

void ClientManager::save_group_file(const int &group_ID, const QString &group_name, const QString &sender, const QString &file_name, const QByteArray &file_data, const QString &time)
{
    const QString &IDBFS_file_name = QString("%1_%2").arg(time, file_name);

#ifdef __EMSCRIPTEN__
    IDBFS_save_file(IDBFS_file_name, file_data, static_cast<int>(file_data.size()));
    emit group_file_received(group_ID, group_name, sender, IDBFS_file_name, time.split(" ").last());
#else
    QDir dir(QCoreApplication::applicationDirPath());

    if (!group_name.isEmpty() && !group_name.isNull())
    {
        const QString &dir_path = dir.filePath(group_name);
        if (!dir.exists(dir_path))
            dir.mkpath(dir_path);
    }

    const QString &path = QString("%1/%2").arg(dir.canonicalPath(), IDBFS_file_name);

    QFile file(path);
    if (file.open(QIODevice::WriteOnly))
    {
        file.write(file_data);
        file.close();
    }

    emit group_file_received(group_ID, group_name, sender, path, time.split(" ").last());
#endif
}

void ClientManager::save_group_audio(const int &group_ID, const QString &group_name, const QString &sender, const QString &audio_name, const QByteArray &audio_data, const QString &time)
{
    const QString &IDBFS_audio_name = QString("%1_%2").arg(time, audio_name);

#ifdef __EMSCRIPTEN__
    IDBFS_save_audio(IDBFS_audio_name, audio_data, static_cast<int>(audio_data.size()));
    emit group_audio_received(group_ID, group_name, sender, IDBFS_audio_name, time.split(" ").last());
#else
    QDir dir(QCoreApplication::applicationDirPath());

    if (!group_name.isEmpty() && !group_name.isNull())
    {
        const QString &dir_path = dir.filePath(group_name);
        if (!dir.exists(dir_path))
            dir.mkpath(dir_path);
    }

    const QString &path = QString("%1/%2").arg(dir.canonicalPath(), IDBFS_audio_name);

    QFile audio(path);
    if (audio.open(QIODevice::WriteOnly))
    {
        audio.write(audio_data);
        audio.close();
    }

    emit group_audio_received(group_ID, group_name, sender, path, time.split(" ").last());
#endif
}

void ClientManager::send_audio(const QString &sender, const QString &receiver, const QString &audio_name, const QByteArray &audio_data, const QString &time)
{
    _socket->sendBinaryMessage(_protocol->set_audio_message(sender, receiver, audio_name, audio_data, time));
}

void ClientManager::send_lookup_friend(const QString &ID)
{
    if (my_ID().compare(ID))
        _socket->sendBinaryMessage(_protocol->set_lookup_friend_message(ID));
}

void ClientManager::send_create_conversation(const int &conversation_ID, const QString &participant1, const int &participant1_ID, const QString &participant2, const int &participant2_ID)
{
    _socket->sendBinaryMessage(_protocol->set_create_conversation_message(conversation_ID, participant1, participant1_ID, participant2, participant2_ID));
}

void ClientManager::send_save_conversation(const int &conversation_ID, const QString &sender, const QString &receiver, const QString &content, const QString &time)
{
    _socket->sendBinaryMessage(_protocol->set_save_message_message(conversation_ID, sender, receiver, content, time));
}

void ClientManager::send_sign_up(const QString &phone_number, const QString &first_name, const QString &last_name, const QString &password, const QString &secret_question, const QString &secret_answer)
{
    _my_ID = phone_number;

    _socket->sendBinaryMessage(_protocol->set_sign_up_message(phone_number, first_name, last_name, password, secret_question, secret_answer));
}

void ClientManager::send_login_request(const QString &phone_number, const QString &password, const QString &time_zone)
{
    _my_ID = phone_number;

    _socket->sendBinaryMessage(_protocol->set_login_request_message(phone_number, password, time_zone));
}

void ClientManager::send_new_password_request(const QString &phone_number)
{
    _my_ID = phone_number;

    _socket->sendBinaryMessage(_protocol->set_new_password_request_message(phone_number));
}

void ClientManager::send_update_password_message(const QString &new_password)
{
    _socket->sendBinaryMessage(_protocol->set_update_password_message(_my_ID, new_password));
}

void ClientManager::send_file(const QString &sender, const QString &receiver, const QString &file_name, const QByteArray &file_data, const QString &time)
{
    _socket->sendBinaryMessage(_protocol->set_file_message(sender, receiver, file_name, file_data, time));
}

void ClientManager::send_delete_message(const int &conversation_ID, const QString &sender, const QString &receiver, const QString &time)
{
    _socket->sendBinaryMessage(_protocol->set_delete_message(conversation_ID, sender, receiver, time));
}

void ClientManager::send_delete_group_message(const int &group_ID, const QString &group_name, const QString &time)
{
    _socket->sendBinaryMessage(_protocol->set_delete_group_message(group_ID, group_name, time));
}

void ClientManager::send_create_new_group(const QString &adm, const QStringList &members, const QString &group_name)
{
    _socket->sendBinaryMessage(_protocol->set_new_group_message(adm, members, group_name));
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

QUrl ClientManager::get_audio_url(const QString &audio_name, const int &conversation_ID, const QString &type, const QString &UTC_time)
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
        _file_name = audio_name;

        _socket->sendBinaryMessage(_protocol->set_request_data_message(conversation_ID, UTC_time, type));

        return QUrl();
    }

    QString qUrl = QString::fromUtf8(url);
    free(url);

    return QUrl(qUrl);
#else
    return QUrl();
#endif
}

QUrl ClientManager::get_file_url(const QString &file_name, const int &conversation_ID, const QString &type, const QString &UTC_time)
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
        _file_name = file_name;

        _socket->sendBinaryMessage(_protocol->set_request_data_message(conversation_ID, UTC_time, type));

        return QUrl();
    }

    QString qUrl = QString::fromUtf8(url);
    free(url);

    return QUrl(qUrl);
#else
    return QUrl();
#endif
}

void ClientManager::delete_audio_IDBFS(const QString &audio_name)
{
#ifdef __EMSCRIPTEN__
    std::string audio_path = "/audio/" + audio_name.toStdString();

    EM_ASM(
        {
            var audioPath = UTF8ToString($0);
            var audioStatus = FS.analyzePath(audioPath);
            if (audioStatus.exists)
                FS.unlink(audioPath);

            FS.syncfs(false);
        },
        audio_path.c_str());
#endif
}

void ClientManager::delete_file_IDBFS(const QString &file_name)
{
#ifdef __EMSCRIPTEN__
    std::string file_path = "/file/" + file_name.toStdString();

    EM_ASM(
        {
            var filePath = UTF8ToString($0);
            var fileStatus = FS.analyzePath(filePath);
            if (fileStatus.exists)
                FS.unlink(filePath);

            FS.syncfs(false);
        },
        file_path.c_str());
#endif
}

void ClientManager::get_user_time() const
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

const QString &ClientManager::my_ID() const
{
    return _my_ID;
}

const QString &ClientManager::my_name() const
{
    return _my_name;
}

const QString &ClientManager::time_zone() const
{
    return _time_zone;
}

void ClientManager::send_group_is_typing(const int &group_ID, const QString &group_name, const QString &sender)
{
    _socket->sendBinaryMessage(_protocol->set_group_is_typing(group_ID, group_name, sender));
}

void ClientManager::send_group_text(const int &group_ID, const QString &group_name, const QString &sender, const QString &message, const QString &time)
{
    _socket->sendBinaryMessage(_protocol->set_group_text_message(group_ID, group_name, sender, message, time));
}

void ClientManager::send_group_file(const int &group_ID, const QString &group_name, const QString &sender, const QString &file_name, const QByteArray &file_data, const QString &time)
{
    _socket->sendBinaryMessage(_protocol->set_group_file_message(group_ID, group_name, sender, file_name, file_data, time));
}

void ClientManager::send_group_audio(const int &group_ID, const QString &group_name, const QString &sender, const QString &audio_name, const QByteArray &audio_data, const QString &time)
{
    _socket->sendBinaryMessage(_protocol->set_group_audio_message(group_ID, group_name, sender, audio_name, audio_data, time));
}

void ClientManager::send_new_group_member_message(const int &group_ID, const QString &group_name, const QString &adm, const QString &group_member)
{
    _socket->sendBinaryMessage(_protocol->set_new_group_member_message(group_ID, group_name, adm, group_member));
}

void ClientManager::send_remove_group_member_message(const int &group_ID, const QString &group_name, const QString &adm, const QString &group_member)
{
    _socket->sendBinaryMessage(_protocol->set_remove_group_member_message(group_ID, group_name, adm, group_member));
}

void ClientManager::send_delete_account_message(const QString &phone_number)
{
    _socket->sendBinaryMessage(_protocol->set_delete_account_message(phone_number));
}

void ClientManager::send_last_message_read(const int &conversation_ID, const QString &client_ID, const QString &time)
{
    _socket->sendBinaryMessage(_protocol->set_last_message_read(conversation_ID, client_ID, time));
}

void ClientManager::send_group_last_message_read(const int &group_ID, const QString &client_ID, const QString &time)
{
    _socket->sendBinaryMessage(_protocol->set_group_last_message_read(group_ID, client_ID, time));
}

void ClientManager::send_request_data_message(const int &ID, const QString &UTC_time, const QString &type)
{
    _socket->sendBinaryMessage(_protocol->set_request_data_message(ID, UTC_time, type));
}