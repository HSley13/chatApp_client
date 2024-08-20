import QtQuick;
import QtQuick.Controls;
import QtQuick.Layouts;

Item
{
    height: file_bubble.height + 10;
    width: file_bubble.width;

    property var model;
    readonly property bool sender: model.phone_number === contact_list_model.main_user.phone_number;

    Rectangle
    {
        id: file_bubble;
        width: Math.min(image.width, chatListView.width * 0.8);
        height: image.height;
        radius: 10;

        x: sender ? chatListView.width - width : 0;
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
            anchors.topMargin: 5;
            anchors.right: sender ? parent.right : undefined;
            horizontalAlignment: sender ? Text.AlignRight : Text.AlignLeft;

            color: "black";
            font.pixelSize: 10;

            width: file_bubble.width;
        }

        MouseArea 
        {
            id: messageMouseArea;
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
                    text: "Delete For Both of us"; 
                    onTriggered: client_manager.delete_message(contact_list_model.active_chat.phone_number, contact_list_model.active_chat.chat_ID, model.full_time);
                }
            }
        }
    }
}
