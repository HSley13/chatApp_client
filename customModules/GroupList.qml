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

        spacing: 5;
        clip: true;

        model: 20;

        delegate: GroupListDelegate
        {
            width: parent.width;
            height: 50;
        }
    }
}