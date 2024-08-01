#include "AudioController.h"

AudioController::AudioController(QObject *parent)
    : QObject(parent),
      _timer(new QTimer(this)),
      _seconds(0)
{
    _timer->setInterval(1000);
    connect(_timer, &QTimer::timeout, this, &AudioController::tikTak_tikTak);
}

void AudioController::set_time_display(QString new_time)
{
    if (!_time_display.compare(new_time))
        return;

    _time_display = new_time;

    emit time_display_changed();
}

const QString &AudioController::time_display() const
{
    return _time_display;
}

void AudioController::tikTak_tikTak()
{
    _seconds++;

    QString duration_str = QString("%1:%2")
                               .arg(_seconds / 60, 2, 10, QChar('0'))
                               .arg(_seconds % 60, 2, 10, QChar('0'));

    set_time_display(duration_str);
}

void AudioController::record()
{
    _seconds = 0;

    _timer->start();
}

void AudioController::stop()
{
    _timer->stop();

    set_time_display("00:00");
}