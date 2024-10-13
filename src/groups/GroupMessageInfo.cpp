#include "GroupMessageInfo.hpp"

GroupMessageInfo::GroupMessageInfo(QObject *parent) {}

GroupMessageInfo::GroupMessageInfo(const QString &text, const QString &audio_source, const QString &file_source, const int &sender_ID, const QString &sender_name, const QString &time, QObject *parent)
    : QObject(parent),
      _text(text),
      _audio_source(audio_source),
      _file_source(file_source),
      _time(time.split(" ").last()),
      _full_time(time),
      _sender_ID(sender_ID),
      _sender_name(sender_name) {}

const QString &GroupMessageInfo::text() {
    return _text;
}

const QString &GroupMessageInfo::audio_source() {
    return _audio_source;
}

const QString &GroupMessageInfo::file_source() {
    return _file_source;
}

const QString &GroupMessageInfo::time() {
    return _time;
}

const int &GroupMessageInfo::sender_ID() {
    return _sender_ID;
}

const QString &GroupMessageInfo::sender_name() {
    return _sender_name;
}

const QString &GroupMessageInfo::full_time() const {
    return _full_time;
}
