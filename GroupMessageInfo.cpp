#include "GroupMessageInfo.h"

GroupMessageInfo::GroupMessageInfo(QObject *parent) {}

GroupMessageInfo::GroupMessageInfo(const QString &contents, const int &sender_ID, const QString &sender_name, QObject *parent)
    : QObject(parent),
      _contents(contents),
      _time(QTime::currentTime().toString("HH:mm")),
      _sender_ID(sender_ID),
      _sender_name(sender_name) {}

const QString &GroupMessageInfo::contents()
{
    return _contents;
}

const QString &GroupMessageInfo::time()
{
    return _time;
}

const int &GroupMessageInfo::sender_ID()
{
    return _sender_ID;
}

const QString &GroupMessageInfo::sender_name()
{
    return _sender_name;
}