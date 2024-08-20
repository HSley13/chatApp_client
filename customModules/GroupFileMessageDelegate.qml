import QtQuick;
import QtQuick.Controls;
import QtQuick.Layouts;

Item
{
    height: file_bubble.height + 10;
    width: file_bubble.width;

    property var model;
    readonly property bool sender: model.sender_ID === contact_list_model.main_user.phone_number;

    Rectangle
    {
        id: file_bubble;
        width: Math.min(Math.max(image.width, senderNameText.implicitWidth) + 10, groupChatListView.width * 0.8);
        height: image.height + 15;
        radius: 10;

        x: sender ? groupChatListView.width - width : 0;

        color: "white";

        gradient: Gradient
        {
            orientation: Gradient.Horizontal;
            GradientStop { position: 0.0; color: sender ? "#ed7bb4" : "white"; }
            GradientStop { position: 1.0; color: sender ? "gray" : "gray"; }
        }

        Image
        {
            id: image;
            source: "qrc:/QML/ClientApp/icons/file_icon.png";
            anchors.centerIn: parent;
            width: 50; 
            height: 50;
        }

        Text
        {
            id: timeText;
            text: model.time;

            anchors.top: file_bubble.bottom;
            anchors.margins: 5;
            anchors.right: sender ? parent.right : undefined;
            horizontalAlignment: sender ? Text.AlignRight : Text.AlignLeft;

            color: "black";
            font.pixelSize: 10;

            width: file_bubble.width;
        }

        MouseArea 
        {
            anchors.fill: parent;
            acceptedButtons: Qt.LeftButton | Qt.RightButton;
    
            onClicked: (mouse) => 
            {
                if (mouse.button === Qt.RightButton && sender)
                    contextMenu.popup();
                else if (mouse.button === Qt.LeftButton)
                    media_controller.view_file(model.file_source);
            }
    
            onPressAndHold: (mouse) => 
            {
                if (mouse.source === Qt.MouseEventNotSynthesized && sender)
                    contextMenu.popup();
            }
    
            Menu 
            {
                id: contextMenu;
                Action 
                { 
                    text: "Delete For all of us"; 
                    onTriggered: client_manager.delete_group_message(group_list_model.active_group_chat.group_ID, model.full_time);
                }
            }
        }
    }

    Text
    {
        id: senderNameText;
        text: model.sender_name;
        visible: model.sender_name !== contact_list_model.main_user.first_name;

        anchors.left: file_bubble.left;
        anchors.leftMargin: 12;
        anchors.top: file_bubble.top;

        color: "#DE02B5";
        font.pixelSize: 10;
        font.bold: true;
    }
}