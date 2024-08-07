#pragma once

#include <QtQuick>
#include <QTimeZone>
#include <QWebSocket>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif
class ClientManager : public QObject
{
    Q_OBJECT
public:
    ClientManager(QObject *parent = nullptr);

    void mount_audio_IDBFS();
    void mount_file_IDBFS();
    void IDBFS_save_audio(const QString &audio_name, const QByteArray &audio_data, const int &size);
    void IDBFS_save_file(const QString &file_name, const QByteArray &file_data, const int &size);
    QUrl get_audio_url(const QString &audio_name);
    QUrl get_file_url(const QString &file_name);

    void get_user_time();

public slots:
    void on_binary_message_received(const QByteArray &data);
    void on_disconnected();

private:
    static QWebSocket *_socket;
    QString _time_zone;
};