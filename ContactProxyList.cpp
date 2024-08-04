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

ContactInfo *ContactProxyList::get_by_ID(const int &id)
{
    return _contacts_by_ID.value(id, nullptr);
}

// bool ContactProxyList::lessThan(const QModelIndex &left, const QModelIndex &right) const
// {
//     QModelIndex source_left = mapToSource(left);
//     QModelIndex source_right = mapToSource(right);

//     ContactInfo *contact_left = sourceModel()->data(source_left, ContactListModel::ContactRoles::ContactObjectRole).value<ContactInfo *>();
//     ContactInfo *contact_right = sourceModel()->data(source_right, ContactListModel::ContactRoles::ContactObjectRole).value<ContactInfo *>();

//     if (contact_left && contact_right)
//         return contact_left->most_recent_message_date() > contact_right->most_recent_message_date();

//     return false;
// }