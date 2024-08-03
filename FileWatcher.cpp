#include <QDebug>
#include <QString>
#include <QFileSystemWatcher>
#include <QDir>
#include <QDirIterator>
#include <QTimer>
#include <functional>
#include "FileWatcher.h"

FileWatcher::FileWatcher(std::function<void()> callback)
    : _callback(callback)
{
    QObject::connect(&_watcher, &QFileSystemWatcher::directoryChanged, this, &FileWatcher::on_directory_changed);
    QObject::connect(&_watcher, &QFileSystemWatcher::fileChanged, this, &FileWatcher::on_file_changed);

    _timer.setInterval(100);
    _timer.setSingleShot(true);

    QObject::connect(&_timer, &QTimer::timeout, _callback);
}

void FileWatcher::add_paths()
{
    QStringList files = find_files(_dir.path());
    _watcher.addPaths(files);
    _timer.start();
}

QStringList FileWatcher::find_files(const QString &path)
{
    QStringList files;

    QDirIterator it(path, QStringList() << "*.qml" << "*.cpp" << "*.h", QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext())
        files.append(it.next());

    return files;
}

void FileWatcher::set_directory(const QString &path)
{
    _watcher.removePaths(_watcher.files());
    _watcher.removePaths(_watcher.directories());

    if (!_watcher.addPath(path))
        qWarning() << "Could not add path:" << path;
    else
    {
        _dir.setPath(path);
        add_paths();
    }
}

void FileWatcher::on_directory_changed(const QString &)
{
    add_paths();
}

void FileWatcher::on_file_changed(const QString &)
{
    _timer.start();
}
