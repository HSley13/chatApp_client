#pragma once

#include "ContactInfo.h"
class ContactProxyList : public QSortFilterProxyModel
{
    Q_OBJECT
    QML_ELEMENT

public:
    ContactProxyList(QObject *parent = nullptr);

    Q_INVOKABLE ContactInfo *get(const int &index);

    // bool lessThan(const QModelIndex &left, const QModelIndex &right) const override;

private:
};