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

          delegate: Item
        {
            width: groupChatListView.width;
            height: (model.audio_source !== "" ? 75 : (model.text !== "" ? 60 : 60));

            Loader
            {
                id: contentLoader;
                sourceComponent: (model.text !== "") ? groupTextMessageDelegate : (model.audio_source !== "") ? groupAudioMessageDelegate : groupFileMessageDelegate;
                onLoaded:
                {
                    if (contentLoader.item)
                        contentLoader.item.model = model;
                }
            }
        }

        onCountChanged: groupChatListView.currentIndex = count - 1;

        add: Transition
        {
            NumberAnimation {properties: "x"; 
            from: groupChatListView.width / 2; 
            duration: 500; easing.type: 
            Easing.OutBounce;}
        }
    }

    Component
    {
        id: groupTextMessageDelegate
        GroupTextMessageDelegate {}
    }

    Component
    {
        id: groupAudioMessageDelegate
        GroupAudioMessageDelegate {}
    }

    Component
    {
        id: groupFileMessageDelegate
        GroupFileMessageDelegate {}
    }
}