#pragma once

#include <QtQml>
#include <QtQuick>

class ChatInfo : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QString name READ name WRITE set_name NOTIFY name_changed)
    Q_PROPERTY(int phone_number READ phone_number WRITE set_phone_number NOTIFY phone_number_changed)
    Q_PROPERTY(QString status READ status WRITE set_status NOTIFY status_changed)
    Q_PROPERTY(QUrl image READ image WRITE set_image NOTIFY image_changed)
    Q_PROPERTY(int message_count READ message_count WRITE set_message_count NOTIFY message_count_changed)
    Q_PROPERTY(QString last_message READ last_message WRITE set_last_message NOTIFY last_message_changed)

public:
    explicit ChatInfo(QObject *parent = nullptr);

    const QString &name() const;
    void set_name(const QString &new_name);

    const int &phone_number() const;
    void set_phone_number(const int &new_phone_number);

    const QString &status() const;
    void set_status(const QString &new_status);

    const QUrl &image() const;
    void set_image(const QUrl &new_image);

    const int &message_count() const;
    void set_message_count(const int &new_message_count);

    const QString &last_message() const;
    void set_last_message(const QString &new_last_message);

signals:
    void name_changed();
    void phone_number_changed();
    void status_changed();
    void image_changed();
    void message_count_changed();

    void last_message_changed();

private:
    QString _name{};
    int _phone_number{0};
    QString _status{};
    QUrl _image{};
    int _message_count{};
    QString _last_message{};
};
