#include "MessageInfo.h"

MessageInfo::MessageInfo(QObject *parent)
    : QObject(parent) {}

MessageInfo::MessageInfo(const QString &text, const QString &audio_source, const QString &file_source, const int &sender_ID, QObject *parent)
    : QObject(parent),
      _text(text),
      _audio_source(audio_source),
      _file_source(file_source),
      _time(QTime::currentTime().toString("HH:mm")),
      _sender_ID(sender_ID) {}

const QString &MessageInfo::text()
{
    return _text;
}

const QString &MessageInfo::audio_source()
{
    return _audio_source;
}

const QString &MessageInfo::file_source()
{
    return _file_source;
}

const QString &MessageInfo::time()
{
    return _time;
}

const int &MessageInfo::sender_ID()
{
    return _sender_ID;
}

const QDateTime MessageInfo::date_time() const
{
    return QDateTime::fromString(_time, Qt::ISODate);
}