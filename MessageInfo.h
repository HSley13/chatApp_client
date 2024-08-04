#pragma once

#include <QtQuick>
#include <QTime>

class MessageInfo : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QString contents READ contents CONSTANT)
    Q_PROPERTY(QString time READ time CONSTANT)
    Q_PROPERTY(int sender_ID READ sender_ID CONSTANT)

public:
    MessageInfo(QObject *parent = nullptr);
    MessageInfo(const QString &contents, const int &sender_ID, QObject *parent = nullptr);

    const QString &contents();
    const QString &time();
    const int &sender_ID();

    const QDateTime date_time() const;

private:
    const QString _contents{};
    const QString _time{};
    const int _sender_ID{0};
};