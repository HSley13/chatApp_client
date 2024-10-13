#include "GroupProxyList.hpp"
#include "GroupListModel.hpp"

GroupProxyList::GroupProxyList(QObject *parent)
    : QSortFilterProxyModel(parent) {
    setFilterRole(GroupListModel::GroupRoles::GroupNameRole);
    setFilterCaseSensitivity(Qt::CaseInsensitive);
    setSortRole(GroupListModel::GroupRoles::GroupNameRole);

    sort(0, Qt::AscendingOrder);
}

GroupInfo *GroupProxyList::get(const int &index) {
    if (index < 0 || index >= rowCount())
        return nullptr;

    QModelIndex modelIndex = this->index(index, 0);
    QModelIndex sourceIndex = mapToSource(modelIndex);

    return sourceModel()->data(sourceIndex, GroupListModel::GroupRoles::GroupObjectRole).value<GroupInfo *>();
}

bool GroupProxyList::lessThan(const QModelIndex &left, const QModelIndex &right) const {
    QDateTime leftDate = sourceModel()->data(left, GroupListModel::GroupRoles::LastMessageTimeRole).toDateTime();
    QDateTime rightDate = sourceModel()->data(right, GroupListModel::GroupRoles::LastMessageTimeRole).toDateTime();
    return leftDate > rightDate;
}
