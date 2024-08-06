#include "MediaController.h"
#include <QCoreApplication>
#include <QDebug>
#include <QDateTime>

QMediaRecorder *MediaController::_recorder = nullptr;
QString MediaController::_file_name;

MediaController::MediaController(QObject *parent)
    : QObject(parent) {}

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
    _session = new QMediaCaptureSession(this);
    _audio_input = new QAudioInput(this);
    _session->setAudioInput(_audio_input);

    _recorder = new QMediaRecorder(this);
    connect(_recorder, &QMediaRecorder::durationChanged, this, &MediaController::on_duration_changed);

    _session->setRecorder(_recorder);

    QString file_path = QCoreApplication::applicationDirPath() + "/" + QDateTime::currentDateTime().toString("yyyy-MM-dd_HH-mm-ss") + "_audio.m4a";
    _recorder->setOutputLocation(QUrl::fromLocalFile(file_path));
    _recorder->setQuality(QMediaRecorder::HighQuality);
    _recorder->setEncodingMode(QMediaRecorder::ConstantQualityEncoding);

    _recorder->record();
}

void MediaController::stop_recording()
{
    if (_recorder)
    {
        _recorder->stop();
        set_audio_source(_recorder->outputLocation().toLocalFile());
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

void MediaController::view_file(const QString &filePath)
{
    QUrl fileUrl = QUrl::fromLocalFile(filePath);
    if (fileUrl.isValid())
        QDesktopServices::openUrl(fileUrl);
}

// void MediaController::send_file()
// {
//     std::function<void(const QString &, const QByteArray &)> file_content_ready = [=](const QString &file_name, const QByteArray &file_data)
//     {
//         qDebug() << "file system open";
//         _file_name = QFileInfo(file_name).absoluteFilePath();
//     };

//     QFileDialog::getOpenFileContent("All Files (*)", file_content_ready);
// }

void MediaController::send_file()
{
    QString file_name = QFileDialog::getOpenFileName(nullptr, "Open File", "", "All Files (*)");

    if (!file_name.isEmpty())
    {
        _file_name = QFileInfo(file_name).absoluteFilePath();
        qDebug() << "Selected file:" << _file_name;
    }
}