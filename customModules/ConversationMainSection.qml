import QtQuick;
import QtQuick.Window;
import QtQuick.Controls;

Rectangle
{
    id: root;
    anchors.fill: parent;
    color: "#dedede";
    required property string conversation_ID;
    property var messageModel: ListModel 
    {
        id: messageModel
    }

    Component.onCompleted: 
    {
        var messages = chatListModel.get_messages(root.conversation_ID);
        messages.forEach((message) =>
        {
            messageModel.append({ messageText: message });
        });
    }

    ListView
    {
        id: listView
        anchors.fill: parent;
        anchors.margins: 5;

        spacing: 5;
        clip: true;
        model: messageModel;
        visible: true;

        delegate: Rectangle
        {
            id: messageDelegate;

            width: listView.width;
            height: 30;
            color: "#dedede";

            Rectangle
            {
                width: textMessge.width;
                height: 30;
                radius: 15;

                color: "white";
                anchors.left: parent.left;

                Text
                {
                    anchors.centerIn: parent;

                    id: textMessge;
                    wrapMode: Text.WrapAtWordBoundaryOrAnywhere;

                    text: messageText;
                    color: "black";
                    font.pixelSize: 12;
                    font.bold: true;
                    elide: Text.ElideRight;
                }
            }
        }
    }
}