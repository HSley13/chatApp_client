#pragma once

#include "GroupInfo.h"
class GroupProxyList : public QSortFilterProxyModel
{
    Q_OBJECT
    QML_ELEMENT

public:
    GroupProxyList(QObject *parent = nullptr);

    Q_INVOKABLE GroupInfo *get(const int &index);
};