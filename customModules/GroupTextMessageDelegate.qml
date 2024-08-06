import QtQuick;
import QtQuick.Controls;

Item
{
    height: bubble.height + 24;
    width: bubble.width;

    property var model;
    readonly property bool sender: model.sender_ID === contact_list_model.main_user.phone_number;

    Rectangle
    {
        id: bubble;

        width: Math.min(messageText.implicitWidth + 24, groupChatListView.width * 0.8);
        height: messageText.implicitHeight + 24;

        x: sender ? groupChatListView.width - width : 0;

        color: "white";
        radius: 10;

        gradient: Gradient
        {
            orientation: Gradient.Horizontal;
            GradientStop { position: 0.0; color: sender ? "#ed7bb4" : "white"; }
            GradientStop { position: 1.0; color: sender ? "gray" : "gray"; }
        }

        Text
        {
            id: messageText;
            text: model.text;

            anchors.fill: parent;
            anchors.margins: 12;
            wrapMode: Text.Wrap;

            color: "black";
            font.pixelSize: 12;

            verticalAlignment: Text.AlignVCenter;
            horizontalAlignment: sender ? Text.AlignRight : Text.AlignLeft;
        }

        Text
        {
            id: timeText;
            text: model.time;

            anchors.top: bubble.bottom;
            anchors.topMargin: 5;
            anchors.right: sender ? parent.right : undefined;
            horizontalAlignment: sender ? Text.AlignRight : Text.AlignLeft;

            color: "black";
            font.pixelSize: 10;

            width: bubble.width;
        }
    }

    Text
    {
        id: senderNameText;
        text: model.sender_name;
        visible: model.sender_name !== "";

        anchors.left: bubble.left;
        anchors.leftMargin: 12;
        anchors.top: bubble.top;

        color: "#DE02B5";
        font.pixelSize: 10;
        font.bold: true;
    }
}
