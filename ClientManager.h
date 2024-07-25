#pragma once

#include <QtQml>
#include <QtQuick>
#include <QtMultimedia>
#include <QWebSocket>

class ClientManager : public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:
    ClientManager(QObject *parent = nullptr);

public slots:

private:
signals:
};
