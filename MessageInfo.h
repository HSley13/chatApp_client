#pragma once

#include <QDateTime>
#include <QtQuick>
class MessageInfo : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QString text READ text CONSTANT)
    Q_PROPERTY(QString audio_source READ audio_source CONSTANT)
    Q_PROPERTY(QString file_source READ file_source CONSTANT)
    Q_PROPERTY(QString time READ time CONSTANT)
    Q_PROPERTY(int sender_ID READ sender_ID CONSTANT)

public:
    MessageInfo(QObject *parent = nullptr);
    MessageInfo(const QString &text, const QString &audio_source, const QString &file_source, const int &sender_ID, const QString &time, QObject *parent = nullptr);

    const QString &text();
    const QString &audio_source();
    const QString &file_source();
    const QString &time();
    const int &sender_ID();

    const QDateTime date_time() const;

    void hello();

private:
    QString _text{};
    QString _audio_source{};
    QString _file_source{};
    QString _time{};
    int _sender_ID{0};
};
