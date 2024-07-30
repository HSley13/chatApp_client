#pragma once

#include <QtQuick>
class ClientManager : public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:
    ClientManager(QObject *parent = nullptr);

    Q_INVOKABLE void set_window_blur(QQuickWindow *excludeWindow, bool blur);

    Q_INVOKABLE void open_file(const QString &file_path);

    Q_INVOKABLE QObject *get_conversation_loader(const QString &conversation_ID) const;
    Q_INVOKABLE void add_conversation_loader(const QString &conversation_ID, QQmlComponent *loader);

public slots:

private:
    QHash<QString, QQmlComponent *> conversation_loaders;

signals:
};