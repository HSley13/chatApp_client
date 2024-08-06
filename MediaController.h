#pragma once

#include <QtQml>
#include <QtQuick>
#include <QMediaRecorder>
#include <QAudioInput>
#include <QMediaCaptureSession>
#include <QtWidgets>
#include "ClientManager.h"
class MediaController : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QString time_display READ time_display WRITE set_time_display NOTIFY time_display_changed)
    Q_PROPERTY(QString audio_source READ audio_source WRITE set_audio_source NOTIFY audio_source_changed)

public:
    MediaController(QObject *parent = nullptr);

    const QString &time_display() const;
    const QString &audio_source() const;

    void setup_recording();

    Q_INVOKABLE void start_recording();
    Q_INVOKABLE void stop_recording();

    Q_INVOKABLE void send_file();

    void ask_microphone_permission();

public:
    static QString _file_path;
    static QString _audio_path;

private:
    QString _time_display{"00:00"};
    QString _audio_source{""};

    QMediaRecorder *_recorder;
    QMediaCaptureSession *_session{nullptr};
    QAudioInput *_audio_input{nullptr};

    qint64 _record_start_time{0};

    ClientManager *_client{nullptr};

public slots:
    void set_time_display(QString new_time);
    void set_audio_source(QString new_source);

    void view_file(const QString &filePath);

private slots:
    void on_duration_changed(qint64 duration);

signals:
    void time_display_changed();
    void audio_source_changed();
    void is_recording_changed();
};