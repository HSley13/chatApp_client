#include "MediaController.h"
#include <QDebug>
#include <QDateTime>

QString MediaController::_file_path;
QString MediaController::_audio_path;

MediaController::MediaController(QObject *parent)
    : QObject(parent),
      _client(new ClientManager(this))
{
    _session = new QMediaCaptureSession(this);
    _audio_input = new QAudioInput(this);
    _session->setAudioInput(_audio_input);

    _recorder = new QMediaRecorder(this);
    connect(_recorder, &QMediaRecorder::durationChanged, this, &MediaController::on_duration_changed);

    _session->setRecorder(_recorder);

    QString file_path = QCoreApplication::applicationDirPath() + "/" + QDateTime::currentDateTime().toString("yyyy-MM-dd_HH-mm-ss") + "_audio.m4a";
    _recorder->setOutputLocation(QUrl::fromLocalFile(file_path));
    _recorder->setQuality(QMediaRecorder::VeryHighQuality);
    _recorder->setEncodingMode(QMediaRecorder::ConstantQualityEncoding);
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
    _recorder->record();
}

void MediaController::stop_recording()
{
    if (_recorder)
    {
        _recorder->stop();

        QString audio_path = _recorder->outputLocation().toLocalFile();

#ifdef __EMSCRIPTEN__
        const QString &current_time = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
        const QString &audio_name = _client->my_ID() + "audio.m4a";

        QByteArray audio_data;
        QFile audio(audio_path);
        if (audio.open(QIODevice::ReadOnly))
        {
            audio_data = audio.readAll();
            audio.close();
        }

        const QString &IDBFS_audio_name = QString("%1_%2").arg(current_time, audio_name);
        _client->IDBFS_save_audio(IDBFS_audio_name, audio_data, static_cast<int>(audio_data.size()));

        _audio_path = _client->get_audio_url(IDBFS_audio_name, 1111, "", "").toString();
#else
        _audio_path = audio_path;
#endif

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
    if (!file_path.isEmpty())
    {
#ifdef __EMSCRIPTEN__
        QDesktopServices::openUrl(_client->get_file_url(file_path, 1111, "", ""));
#else
        QDesktopServices::openUrl(QUrl::fromLocalFile(file_path));
#endif
    }
}

void MediaController::send_file()
{
    std::function<void(const QString &, const QByteArray &)> file_content_ready = [=](const QString &file_name, const QByteArray &file_data)
    {
        if (!file_name.isEmpty())
        {
            QString current_time = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");

            // FIXME:
            // const QString &UTC_time = QDateTime::fromString(current_time, "yyyy-MM-dd HH:mm:ss")
            //                               .toUTC()
            //                               .toString();

#ifdef __EMSCRIPTEN__
            QString IDBFS_file_name = QString("%1_%2").arg(current_time, QFileInfo(file_name).fileName());
            _client->IDBFS_save_file(IDBFS_file_name, file_data, static_cast<int>(file_data.size()));

            _file_path = IDBFS_file_name;
#else
            _file_path = QFileInfo(file_name).absoluteFilePath();
#endif
        }
    };

    QFileDialog::getOpenFileContent("All Files (*)", file_content_ready);
}