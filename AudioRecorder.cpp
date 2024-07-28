#include "AudioRecorder.h"

AudioRecorder::AudioRecorder(QObject *parent)
    : QObject(parent)
{
}

void AudioRecorder::set_time_display(QString new_time)
{
    if (!_time_display.compare(new_time))
        return;

    _time_display = new_time;

    emit time_display_changed();
}

const QString &AudioRecorder::time_display() const
{
    return _time_display;
}

void AudioRecorder::tikTak_tikTak()
{
    _seconds++;

    QString duration_str = QString("%1:%2")
                               .arg(_seconds / 60, 2, 10, QChar('0'))
                               .arg(_seconds % 60, 2, 10, QChar('0'));

    set_time_display(duration_str);
}

void AudioRecorder::record()
{
    _seconds = 0;

    if (!_timer)
    {
        _timer = new QTimer(this);
        _timer->setInterval(1000);

        connect(_timer, &QTimer::timeout, this, &AudioRecorder::tikTak_tikTak);
    }

    _timer->start();
}

void AudioRecorder::stop()
{
    _timer->stop();

    set_time_display("00:00");
}