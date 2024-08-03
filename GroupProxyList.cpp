#include "GroupProxyList.h"
#include "GroupListModel.h"

GroupProxyList::GroupProxyList(QObject *parent)
    : QSortFilterProxyModel(parent)
{
    setFilterRole(GroupListModel::GroupRoles::GroupNameRole);
    setFilterCaseSensitivity(Qt::CaseInsensitive);
    setSortRole(GroupListModel::GroupRoles::GroupNameRole);

    sort(0, Qt::AscendingOrder);
}

GroupInfo *GroupProxyList::get(const int &index)
{
    if (index < 0 || index >= rowCount())
        return nullptr;

    QModelIndex modelIndex = this->index(index, 0);
    QModelIndex sourceIndex = mapToSource(modelIndex);

    return sourceModel()->data(sourceIndex, GroupListModel::GroupRoles::GroupObjectRole).value<GroupInfo *>();
}