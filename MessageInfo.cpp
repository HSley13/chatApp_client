#include "MessageInfo.h"

MessageInfo::MessageInfo(const QString &contents, const int &sender_ID, QObject *parent)
    : QObject(parent),
      _contents(contents),
      _time(QTime::currentTime().toString("HH:mm")),
      _sender_ID(sender_ID) {}

const QString &MessageInfo::contents()
{
    return _contents;
}

const QString &MessageInfo::time()
{
    return _time;
}
const int &MessageInfo::sender_ID()
{
    return _sender_ID;
}