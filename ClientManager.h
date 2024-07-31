#pragma once

#include <QtQuick>
class ClientManager : public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:
    ClientManager(QObject *parent = nullptr);
    ~ClientManager();

    Q_INVOKABLE void open_file(const QString &file_path);

private:
signals:
};