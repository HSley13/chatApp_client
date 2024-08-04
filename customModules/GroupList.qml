import QtQuick;
import QtQuick.Controls;

Rectangle
{
    ListView
    {
        id: groupListView

        width: parent.width;
        height: parent.height;

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