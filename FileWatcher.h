#pragma once

#include <functional>
#include <QFileSystemWatcher>
#include <QObject>
#include <QDebug>
#include <QString>
#include <QDir>
#include <QDirIterator>
#include <QTimer>
class FileWatcher : public QObject
{
    Q_OBJECT

public:
    FileWatcher(std::function<void()> callback);

    void set_directory(const QString &path);
    QStringList find_files(const QString &path);

public slots:
    void on_directory_changed(const QString &path);
    void on_file_changed(const QString &path);

private:
    void add_paths();

private:
    std::function<void()> _callback;
    QFileSystemWatcher _watcher;
    QDir _dir;
    QTimer _timer;
};