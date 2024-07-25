#pragma once

#include <QtQml>
#include <QtQuick>

class ChatInfo : public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:
    ChatInfo(QObject *parent = nullptr);

public slots:

private:
signals:
};
