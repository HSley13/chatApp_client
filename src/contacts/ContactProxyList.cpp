#include "ContactProxyList.hpp"
#include "ContactListModel.hpp"

ContactProxyList::ContactProxyList(QObject *parent)
    : QSortFilterProxyModel(parent),
      _custom_sort_role(ContactListModel::ContactRoles::FirstNameRole)
{
    setFilterRole(ContactListModel::ContactRoles::FirstNameRole);
    setFilterCaseSensitivity(Qt::CaseInsensitive);
    setSortRole(_custom_sort_role);
    sort(0, Qt::AscendingOrder);
}

void ContactProxyList::set_custom_sort_role(int role)
{
    _custom_sort_role = role;
    setSortRole(_custom_sort_role);
    sort(0, Qt::AscendingOrder);
}

bool ContactProxyList::lessThan(const QModelIndex &left, const QModelIndex &right) const
{
    QDateTime leftDate = sourceModel()->data(left, _custom_sort_role).toDateTime();
    QDateTime rightDate = sourceModel()->data(right, _custom_sort_role).toDateTime();
    return leftDate > rightDate;
}

ContactInfo *ContactProxyList::get(const int &index)
{
    if (index < 0 || index >= rowCount())
        return nullptr;

    QModelIndex modelIndex = this->index(index, 0);
    QModelIndex sourceIndex = mapToSource(modelIndex);

    return sourceModel()->data(sourceIndex, ContactListModel::ContactRoles::ContactObjectRole).value<ContactInfo *>();
}