#pragma once

#include <QtQml>
#include <QtQuick>
#include <QtMultimedia>
#include <QWebSocket>
#include <QtCore>
class ClientManager : public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:
    ClientManager(QObject *parent = nullptr);

    Q_INVOKABLE void set_window_blur(QQuickWindow *excludeWindow, bool blur);

    Q_INVOKABLE void open_file(const QString &file_path);

public slots:

private:
signals:
};