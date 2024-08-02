import QtQuick;
import QtQuick.Controls;

Rectangle
{
    anchors.fill: parent;

    color: "#dedede";

    ListView
    {
        id: groupChatListView;

        anchors.fill: parent;

        anchors.margins: 5;
        // FIXME: replace it by the real model later
        model: 20;

        spacing: 8;
        clip: true;
        hightLightFollowCurrentItem: true;

        delegate: GroupChatListDelegate {}

        onCountChanged: groupChatList.currentIndex = count - 1;

        add: Transition
        {
            NumberAnimation {properties: "x"; from: groupChatList.width / 2; duration: 500; easing.type: Easing.OutBounce;}
        }
    }
}