#pragma once

#include <QtQuick>
#include "ChatInfo.h"

class ContactProxyList : public QSortFilterProxyModel
{
    Q_OBJECT
    QML_ELEMENT

public:
    ContactProxyList(QObject *parent = nullptr);

    Q_INVOKABLE ChatInfo *get(const int &index);

private:
signals:
};