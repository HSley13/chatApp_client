#pragma once

#include <QtQuick>

class GroupMessageInfo : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QString text READ text CONSTANT)
    Q_PROPERTY(QString audio_source READ audio_source CONSTANT)
    Q_PROPERTY(QString file_source READ file_source CONSTANT)
    Q_PROPERTY(QString time READ time CONSTANT)
    Q_PROPERTY(int sender_ID READ sender_ID CONSTANT)
    Q_PROPERTY(QString sender_name READ sender_name CONSTANT)

public:
    GroupMessageInfo(QObject *parent = nullptr);
    GroupMessageInfo(const QString &text, const QString &audio_source, const QString &file_source, const int &sender_ID, const QString &sender_name, const QString &time, QObject *parent = nullptr);

    const QString &text();
    const QString &audio_source();
    const QString &file_source();
    const QString &time();
    const int &sender_ID();
    const QString &sender_name();

    const QString &full_time() const;

private:
    QString _text{};
    QString _audio_source{};
    QString _file_source{};
    const QString _time{};
    const int _sender_ID{0};
    const QString _sender_name{};

    QString _full_time{};
};
