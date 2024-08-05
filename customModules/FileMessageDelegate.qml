import QtQuick;
import QtQuick.Controls;
import QtQuick.Layouts;

Item
{
    property var model;
    property string phoneNumber;
    property string fileUrl;

    id: root;
    height: bubble.height + 24;
    width: bubble.width;

    readonly property bool sender: phoneNumber === contact_list_model.main_user.phone_number;

    Rectangle
    {
        id: bubble;
        width: Math.min(image.width + 24, chatListView.width * 0.8);
        height: image.height + 24;
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

            MouseArea
            {
                id: imageMouseArea;
                anchors.fill: parent;
                onClicked: media_controller.open_file(fileUrl);
            }
        }

        Text
        {
            id: timeText;
            text: model.time;

            anchors.bottom: parent.bottom;
            anchors.bottomMargin: 5;
            anchors.right: sender ? parent.right : undefined;
            horizontalAlignment: sender ? Text.AlignRight : Text.AlignLeft;

            color: "black";
            font.pixelSize: 10;
            width: parent.width;
        }

        Text
        {
            id: fileSizeText;
            text: `${(model.file_size / 1024 / 1024).toFixed(2)} MB`;

            anchors.right: parent.right;
            anchors.rightMargin: 10;
            anchors.verticalCenter: parent.verticalCenter;

            color: "black";
            font.pixelSize: 12;
        }
    }
}
