#include "ContactProxyList.h"
#include "ContactListModel.h"

ContactProxyList::ContactProxyList(QObject *parent)
    : QSortFilterProxyModel(parent)
{
    setFilterRole(ContactListModel::ContactRoles::NameRole);
    setFilterCaseSensitivity(Qt::CaseInsensitive);
    setSortRole(ContactListModel::ContactRoles::NameRole);

    sort(0, Qt::AscendingOrder);
}

ContactInfo *ContactProxyList::get(const int &index)
{
    if (index < 0 || index >= rowCount())
        return nullptr;

    QModelIndex modelIndex = this->index(index, 0);
    QModelIndex sourceIndex = mapToSource(modelIndex);

    return sourceModel()->data(sourceIndex, ContactListModel::ContactRoles::ContactObjectRole).value<ContactInfo *>();
}