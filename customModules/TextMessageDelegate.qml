import QtQuick;
import QtQuick.Controls;

Item
{
    height: bubble.height + 24; 
    width: bubble.width;

    property var model;
    readonly property bool sender: model.phone_number === contact_list_model.main_user.phone_number;

    Rectangle
    {
        id: bubble;

        width: Math.min(messageText.implicitWidth + 24, chatListView.width * 0.8);
        height: messageText.implicitHeight + 24;

        x: sender ? chatListView.width - width : 0;

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
            anchors.right: sender ? parent.right : undefined;
            horizontalAlignment: sender ? Text.AlignRight : Text.AlignLeft;

            color: "black";
            font.pixelSize: 10;

            width: bubble.width;

            MouseArea 
            {
                id: messageMouseArea;
                anchors.fill: parent;
                acceptedButtons: Qt.RightButton;

                onClicked: (mouse) => 
                {
                    if (sender)
                        contextMenu.popup();
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
}
