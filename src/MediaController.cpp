#include "MediaController.h"
#include "GroupListModel.h"
#include "ContactListModel.h"

MediaController::MediaController(QObject *parent)
    : QObject(parent),
      _session(new QMediaCaptureSession(this)),
      _audio_input(new QAudioInput(this)),
      _recorder(new QMediaRecorder(this))
{
    _session->setAudioInput(_audio_input);
    _session->setRecorder(_recorder);

    _recorder->setQuality(QMediaRecorder::VeryHighQuality);
    _recorder->setEncodingMode(QMediaRecorder::ConstantQualityEncoding);

    connect(_recorder, &QMediaRecorder::durationChanged, this, &MediaController::on_duration_changed);

    _client_manager = ClientManager::instance();
}

const QString &MediaController::time_display() const
{
    return _time_display;
}

void MediaController::set_time_display(QString new_time)
{
    if (_time_display != new_time)
    {
        _time_display = new_time;
        emit time_display_changed();
    }
}

const QString &MediaController::audio_source() const
{
    return _audio_source;
}

void MediaController::set_audio_source(QString new_source)
{
    if (_audio_source != new_source)
    {
        _audio_source = new_source;
        emit audio_source_changed();
    }
}

void MediaController::start_recording()
{
    QMicrophonePermission microphonePermission;

    switch (qApp->checkPermission(microphonePermission))
    {
    case Qt::PermissionStatus::Undetermined:
        qApp->requestPermission(microphonePermission, this, [=]()
                                {
    qDebug() << "Microphone permission granted!";
                setup_recording(); });
        break;

    case Qt::PermissionStatus::Denied:
        qDebug() << "Microphone permission denied.";
        break;

    case Qt::PermissionStatus::Granted:
        setup_recording();
        break;
    }
}

void MediaController::setup_recording()
{
    QString audio_path = QCoreApplication::applicationDirPath() + "/" + QDateTime::currentDateTime().toString("yyyy-MM-dd_HH-mm-ss") + "_audio.m4a";
    _recorder->setOutputLocation(QUrl::fromLocalFile(audio_path));

    _recorder->record();
}

void MediaController::stop_recording()
{
    if (_recorder)
    {
        _recorder->stop();

        QString audio_path = _recorder->outputLocation().toLocalFile();

        set_audio_source(audio_path);
        set_time_display("00:00");
    }
}

void MediaController::on_duration_changed(qint64 duration)
{
    if (_recorder->error() != QMediaRecorder::NoError || duration < 1000)
        return;

    QString duration_str = QString("%1:%2")
                               .arg(duration / 60000, 2, 10, QChar('0'))
                               .arg((duration % 60000) / 1000, 2, 10, QChar('0'));

    set_time_display(duration_str);
}

void MediaController::view_file(const QString &file_path)
{
    QDesktopServices::openUrl(file_path);
}

void MediaController::send_file(const int &value)
{
    std::function<void(const QString &, const QByteArray &)> file_content_ready = [=](const QString &file_name, const QByteArray &file_data)
    {
        if (!file_name.isEmpty())
        {
            switch (value)
            {
            case 1:
                _client_manager->update_profile(QFileInfo(file_name).fileName(), file_data);
                break;
            case 2:
                _client_manager->update_group_profile(GroupListModel::active_group_chat()->group_ID(), QFileInfo(file_name).fileName(), file_data);
                break;
            case 3:
                _client_manager->send_file(ContactListModel::active_chat()->chat_ID(), ContactListModel::active_chat()->phone_number(), QFileInfo(file_name).fileName(), file_data);
                break;
            case 4:
                _client_manager->send_group_file(GroupListModel::active_group_chat()->group_ID(), ContactListModel::main_user()->first_name(), QFileInfo(file_name).fileName(), file_data);
                break;
            default:
                break;
            }
        }
    };

    QFileDialog::getOpenFileContent("All Files (*)", file_content_ready);
}

// void MediaController::play_audio(const QUrl &source)
// {
//     if (!_player)
//     {
//         _player = new QMediaPlayer(this);
//         _audio_output = new QAudioOutput(this);
//         _player->setAudioOutput(_audio_output);

//         connect(_player, &QMediaPlayer::playbackStateChanged, this, [=](QMediaPlayer::PlaybackState state)
//                 {
//                     if (state == QMediaPlayer::StoppedState)
//                     {
//                         _paused_position = 0;
//                         _is_playing = false;
//                     } });
//     }

//     if (!_is_playing)
//     {
//         _player->setSource(source);
//         _audio_output->setVolume(0.5); // Volume can be adjusted as needed
//         _player->play();

//         _is_playing = true;
//     }
//     else
//     {
//         _player->pause();
//         _is_playing = false;
//     }
// }