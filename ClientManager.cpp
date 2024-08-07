#include "ClientManager.h"

QWebSocket *ClientManager::_socket = nullptr;

ClientManager::ClientManager(QObject *parent)
    : QObject(parent)
{
    if (!_socket)
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

        mount_audio_IDBFS();
        mount_file_IDBFS();
    }
}

void ClientManager::on_binary_message_received(const QByteArray &data)
{
}

void ClientManager::on_disconnected()
{
}
/*-------------------------------------------------------------------- Functions --------------------------------------------------------------*/

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
        // _file_name = audio_name;

        // _socket->sendBinaryMessage(_protocol->set_request_data_message(conversation_ID, UTC_time, type));

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
        // _file_name = file_name;

        // _socket->sendBinaryMessage(_protocol->set_request_data_message(conversation_ID, UTC_time, type));

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