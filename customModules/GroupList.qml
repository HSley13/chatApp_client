import QtQuick;
import QtQuick.Controls;

Rectangle
{
    ListView
    {
        id: groupListView

        anchors.fill: parent;

        anchors.margins: 5;

        spacing: 10;
        clip: true;

        model: group_list_model.group_proxy_list;

        delegate: GroupListDelegate
        {
            width: parent.width;
            height: 50;
        }
    }
}
