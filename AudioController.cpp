// #include "AudioController.h"

// AudioController::AudioController(QObject *parent)
//     : QObject(parent), _is_playing(false)
// {
//     // connect(&_player, &QMediaPlayer::stateChanged, this, &AudioController::on_state_changed);
// }

// void AudioController::set_time_display(QString new_time)
// {
//     if (!_time_display.compare(new_time))
//         return;

//     _time_display = new_time;

//     emit time_display_changed();
// }

// const QString &AudioController::time_display() const
// {
//     return _time_display;
// }

// void AudioController::tikTak_tikTak()
// {
//     _seconds++;

//     QString duration_str = QString("%1:%2")
//                                .arg(_seconds / 60, 2, 10, QChar('0'))
//                                .arg(_seconds % 60, 2, 10, QChar('0'));

//     set_time_display(duration_str);
// }

// void AudioController::record()
// {
//     _seconds = 0;

//     if (!_timer)
//     {
//         _timer = new QTimer(this);
//         _timer->setInterval(1000);

//         connect(_timer, &QTimer::timeout, this, &AudioController::tikTak_tikTak);
//     }

//     _timer->start();
// }

// void AudioController::stop()
// {
//     _timer->stop();

//     set_time_display("00:00");
// }

// bool AudioController::is_playing() const
// {
//     return _is_playing;
// }

// QString AudioController::current_source() const
// {
//     return _current_source;
// }

// void AudioController::play(const QString &source)
// {
//     if (_current_source != source)
//     {
//         _current_source = source;
//         // _player.setMedia(QUrl::fromLocalFile(source));
//     }

//     _player.play();
//     _is_playing = true;

//     emit is_playing_changed();
//     emit current_source_changed();
// }

// void AudioController::pause()
// {
//     _player.pause();
//     _is_playing = false;

//     emit is_playing_changed();
// }

// // void AudioController::on_state_changed(QMediaPlayer::State state)
// // {
// //     _is_playing = (state == QMediaPlayer::PlayingState);
// //     emit is_playing_changed();
// // }
