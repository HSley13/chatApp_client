#pragma once

#include <QtQuick>
#include <QTime>

class GroupMessageInfo : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QString contents READ contents CONSTANT)
    Q_PROPERTY(QString time READ time CONSTANT)
    Q_PROPERTY(int sender_ID READ sender_ID CONSTANT)
    Q_PROPERTY(QString sender_name READ sender_name CONSTANT)

public:
    GroupMessageInfo(QObject *parent = nullptr);
    GroupMessageInfo(const QString &contents, const int &sender_ID, const QString &sender_name, QObject *parent = nullptr);

    const QString &contents();
    const QString &time();
    const int &sender_ID();
    const QString &sender_name();

private:
    const QString _contents{};
    const QString _time{};
    const int _sender_ID{0};
    const QString _sender_name{};
};