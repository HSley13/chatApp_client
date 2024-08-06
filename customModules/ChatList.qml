import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle
{
    anchors.fill: parent;
    color: "#dedede";

    ListView
    {
        id: chatListView;
        
        anchors.fill: parent;
        anchors.margins: 10;
        model: contact_list_model.active_chat.messages;

        spacing: 8;
        clip: true;
        highlightFollowsCurrentItem: true;

        delegate: Item
        {
            width: chatListView.width;
            height: (model.audio_source !== "" ? 75 : (model.text !== "" ? 60 : 60));

            Loader
            {
                id: contentLoader;
                sourceComponent: (model.text !== "") ? textMessageDelegate : (model.audio_source !== "") ? audioMessageDelegate : fileMessageDelegate;
                onLoaded:
                {
                    if (contentLoader.item)
                    {
                        contentLoader.item.model = model;
                        contentLoader.item.phone_number = model.phone_number;
                        contentLoader.item.file_url = model.file_source;
                    }
                }
            }
        }

        onCountChanged: chatListView.currentIndex = count - 1;

        add: Transition
        {
            NumberAnimation
            {
                properties: "x";
                from: chatListView.width / 2;
                duration: 500;
                easing.type: Easing.OutBounce;
            }
        }
    }

    Component
    {
        id: textMessageDelegate
        TextMessageDelegate { }
    }

    Component
    {
        id: audioMessageDelegate
        AudioMessageDelegate { }
    }

    Component
    {
        id: fileMessageDelegate
        FileMessageDelegate{}
    }
}
