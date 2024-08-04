#pragma once

#include <QtQuick>
#include "ContactInfo.h"
class ContactProxyList : public QSortFilterProxyModel
{
    Q_OBJECT
    QML_ELEMENT

public:
    ContactProxyList(QObject *parent = nullptr);

    Q_INVOKABLE ContactInfo *get(const int &index);

    Q_INVOKABLE ContactInfo *get_by_ID(const int &id);

    // bool lessThan(const QModelIndex &left, const QModelIndex &right) const override;

private:
    QHash<int, ContactInfo *> _contacts_by_ID;
};