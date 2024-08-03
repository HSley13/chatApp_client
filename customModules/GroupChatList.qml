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

        anchors.margins: 10;

        model: group_list_model.active_group_chat.group_messages;

        spacing: 8;
        clip: true;
        highlightFollowsCurrentItem: true;

        delegate: GroupChatListDelegate {}

        onCountChanged: groupChatListView.currentIndex = count - 1;

        add: Transition
        {
            NumberAnimation {properties: "x"; from: groupChatListView.width / 2; duration: 500; easing.type: Easing.OutBounce;}
        }
    }
}