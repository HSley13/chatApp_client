#pragma once

#include <QtQuick>
class ChatInfo : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QString conversation_ID READ conversation_ID WRITE set_conversation_ID NOTIFY conversation_ID_changed)
    Q_PROPERTY(QString name READ name WRITE set_name NOTIFY name_changed)
    Q_PROPERTY(int phone_number READ phone_number WRITE set_phone_number NOTIFY phone_number_changed)
    Q_PROPERTY(QString status READ status WRITE set_status NOTIFY status_changed)
    Q_PROPERTY(QString image READ image WRITE set_image NOTIFY image_changed)
    Q_PROPERTY(QString message_count READ message_count WRITE set_message_count NOTIFY message_count_changed)
    Q_PROPERTY(QString last_message READ last_message WRITE set_last_message NOTIFY last_message_changed)
    Q_PROPERTY(QString message READ message WRITE set_message NOTIFY message_changed)

public:
    explicit ChatInfo(QObject *parent = nullptr);

    const QString &conversation_ID() const;
    void set_conversation_ID(const QString &new_ID);

    const QString &name() const;
    void set_name(const QString &new_name);

    const int &phone_number() const;
    void set_phone_number(const int &new_phone_number);

    const QString &status() const;
    void set_status(const QString &new_status);

    const QString &image() const;
    void set_image(const QString &new_image);

    const QString &message_count() const;
    void set_message_count(const QString &new_message_count);

    const QString &last_message() const;
    void set_last_message(const QString &new_last_message);

    const QString &message() const;
    void set_message(const QString &new_message);

    QStringList message_list() const;
    void set_message_list(const QStringList &list);

private:
    QString _name{};
    int _phone_number{0};
    QString _status{};
    QString _image{};
    QString _message_count{};
    QString _last_message{};
    QString _conversation_ID{};
    QString _message{};

    QStringList _message_list{};

signals:
    void name_changed();
    void phone_number_changed();
    void status_changed();
    void image_changed();
    void message_count_changed();
    void last_message_changed();
    void conversation_ID_changed();
    void message_changed();

    void message_list_changed();
};