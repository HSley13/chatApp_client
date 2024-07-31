#include "ContactProxyList.h"
#include "ContactList.h"

ContactProxyList::ContactProxyList(QObject *parent)
    : QSortFilterProxyModel(parent)
{
    setFilterRole(ContactList::ContactRoles::NameRole);
    setFilterCaseSensitivity(Qt::CaseInsensitive);
    setSortRole(ContactList::ContactRoles::NameRole);

    sort(0, Qt::AscendingOrder);
}

ChatInfo *ContactProxyList::get(const int &index)
{
    if (index < 0 || index >= rowCount())
        return nullptr;

    QModelIndex modelIndex = this->index(index, 0);
    QModelIndex sourceIndex = mapToSource(modelIndex);
    return sourceModel()->data(sourceIndex, ContactList::ContactRoles::ChatObjectRole).value<ChatInfo *>();
}