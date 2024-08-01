#pragma once

#include <QtQml>
#include <QtQuick>
class AudioController : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QString time_display READ time_display WRITE set_time_display NOTIFY time_display_changed)

public:
    AudioController(QObject *parent = nullptr);

    const QString &time_display() const;

    Q_INVOKABLE void record();
    Q_INVOKABLE void stop();

public slots:
    void set_time_display(QString new_time);

    void tikTak_tikTak();

private:
    QString _time_display{"00:00"};

    int _seconds{0};

    QTimer *_timer{nullptr};

signals:
    void time_display_changed();
};