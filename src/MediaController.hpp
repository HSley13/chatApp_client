#pragma once

#include <QMediaRecorder>
#include <QAudioInput>
#include <QAudioOutput>
#include <QMediaCaptureSession>
#include <QFileDialog>
#include <QMediaPlayer>

#include "ClientManager.hpp"
class MediaController : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QString time_display READ time_display WRITE set_time_display NOTIFY time_display_changed)

public:
    MediaController(QObject *parent = nullptr);

    const QString &time_display() const;

    void setup_recording();

    Q_INVOKABLE void start_recording();
    Q_INVOKABLE void stop_recording();

    Q_INVOKABLE void send_file(const int &value);
    Q_INVOKABLE void view_file(const QString &file_path);

    void ask_microphone_permission();
public slots:
    void set_time_display(QString new_time);

private slots:
    void on_duration_changed(qint64 duration);

private:
    QString _time_display{"00:00"};

    QMediaRecorder *_recorder;
    QMediaCaptureSession *_session{nullptr};
    QAudioInput *_audio_input{nullptr};

    qint64 _record_start_time{0};
    std::shared_ptr<ClientManager> _client_manager{nullptr};

    QMediaPlayer *_player{nullptr};
    QAudioOutput *_audio_output{nullptr};

    bool _is_playing{false};

signals:
    void
    time_display_changed();
    void is_recording_changed();
};