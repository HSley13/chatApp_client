#pragma once

#include "ContactInfo.hpp"

class ContactProxyList : public QSortFilterProxyModel {
    Q_OBJECT
    QML_ELEMENT

  public:
    ContactProxyList(QObject *parent = nullptr);

    Q_INVOKABLE ContactInfo *get(const int &index);

    void set_custom_sort_role(int role);

    bool lessThan(const QModelIndex &left, const QModelIndex &right) const override;

  private:
    int _custom_sort_role;
};
