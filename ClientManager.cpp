#include "ClientManager.h"

ClientManager::ClientManager(QObject *parent)
    : QObject(parent) {}

void ClientManager::set_window_blur(QQuickWindow *excludeWindow, bool blur)
{
}

void ClientManager::open_file(const QString &file_path)
{
    QDesktopServices::openUrl(QUrl::fromLocalFile(file_path));
}