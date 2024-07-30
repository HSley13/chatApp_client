#pragma once

#include <QtQuick>
#include <QMediaPlayer>
class AudioController : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QString time_display READ time_display WRITE set_time_display NOTIFY time_display_changed)

    Q_PROPERTY(bool is_playing READ is_playing NOTIFY is_playing_changed)
    Q_PROPERTY(QString current_source READ current_source NOTIFY current_source_changed)

public:
    AudioController(QObject *parent = nullptr);

    const QString &time_display() const;

    Q_INVOKABLE void record();
    Q_INVOKABLE void stop();

    bool is_playing() const;
    QString current_source() const;

public slots:
    void set_time_display(QString new_time);
    void tikTak_tikTak();

    // void on_state_changed(QMediaPlayer::State state);

    void play(const QString &source);
    void pause();

private:
    QString _time_display{"00:00"};

    int _seconds{0};

    QTimer *_timer;

    QMediaPlayer _player;
    bool _is_playing;
    QString _current_source;

signals:
    void time_display_changed();

    void is_playing_changed();
    void current_source_changed();
};