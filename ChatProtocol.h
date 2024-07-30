#pragma once

#include <QtQuick>
class ChatProtocol : public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:
    ChatProtocol(QObject *parent = nullptr);

public slots:

private:
signals:
};
