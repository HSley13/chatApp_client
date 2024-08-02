import QtQuick;
import QtQuick.Controls;

Rectangle
{
    anchors.fill: parent;

    color: "#dedede";

    ListView
    {
        id: chatListView;
        
        anchors.fill: parent;

        anchors.margins: 5;
        model: contact_list_model.active_chat.messages;

        spacing: 8;
        clip: true;
        highlightFollowsCurrentItem: true;

        delegate: ChatListDelegate {}

        onCountChanged: chatListView.currentIndex = count - 1;

        add: Transition
        {
            NumberAnimation {properties: "x"; from: chatListView.width / 2; duration: 500; easing.type: Easing.OutBounce;}  
        }
    }
}
