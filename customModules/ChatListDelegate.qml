import QtQuick;
import QtQuick.Controls;
import QtQuick.Layouts;

Item
{
    height: showTime ? bubble.height + 24 : bubble.height;
    width: bubble.width;

    property bool showTime: chatListView.count - 1 === index ? true : chatListView.model.at(index + 1).phone_number !== contact_list_model.main_user.phone_number;

    readonly property bool sender: phone_number === contact_list_model.main_user.phone_number;

    Rectangle
    {
        id: bubble;
        
        width: Math.min(messageText.implicitWidth + 24, chatListView.width * 0.8);
        height: messageText.implicitHeight + 24;
        
        x: sender ? 0 : chatListView.width - width;

        color: "white";
        radius: 10;

        gradient: Gradient
        {
            orientation: Gradient.Horizontal;
            GradientStop {position: -0.2; color: sender ? "white" : "gray"; }
            GradientStop {position: 1.0; color: sender ? "white" : "#ed7bb4";}
        }

        Text
        {
            id: messageText;
            text: contents;

            anchors.fill: parent;
            anchors.margins: 12;
            wrapMode: Text.Wrap;

            color: "black";
            font.pixelSize: 12;

            verticalAlignment: Text.AlignVCenter;
            horizontalAlignment: sender ? Text.AlignLeft : Text.AlignRight;
        }

        Text
        {
            id: timeText;
            text: time;

            anchors.top: bubble.bottom;
            anchors.topMargin: 5;
            anchors.right: sender ? undefined : parent.right
            horizontalAlignment: sender ? Text.AlignLeft : Text.AlignRight;

            color: "black";
            font.pixelSize: 10;

            width: bubble.width;
            visible: showTime;
        }
    }
}