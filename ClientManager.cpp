#include "ClientManager.h"

ClientManager::ClientManager(QObject *parent)
    : QObject(parent) {}

ClientManager::~ClientManager() {}

void ClientManager::open_file(const QString &file_path)
{
    QDesktopServices::openUrl(QUrl::fromLocalFile(file_path));
}