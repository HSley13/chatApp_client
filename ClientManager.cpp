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

QObject *ClientManager::get_conversation_loader(const QString &conversationID) const
{
    if (conversation_loaders.contains(conversationID))
        return conversation_loaders[conversationID]->create();

    return nullptr;
}

void ClientManager::add_conversation_loader(const QString &conversation_ID, QQmlComponent *loader)
{
    if (!conversation_loaders.contains(conversation_ID))
        conversation_loaders.insert(conversation_ID, loader);
}