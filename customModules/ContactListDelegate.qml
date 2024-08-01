import QtQuick;
import QtQuick.Layouts;

Rectangle
{
    color: "transparent";
    radius: 100;

    property string statusIconSource: status ? "qrc:/QML/ClientApp/icons/online_icon.png" : "qrc:/QML/ClientApp/icons/offline_icon.png";

    Rectangle
    {
        id: hoverBackground;
        width: mouseArea.containsMouse ? parent.width : 0;
        height: parent.height;

        anchors.left: parent.left;
        anchors.leftMargin: profileImage.width / 2;

        Behavior on width { SmoothedAnimation { duration: 450; } }

        gradient: Gradient
        {
            orientation: Gradient.Horizontal;

            GradientStop { position: 0.0; color: "transparent"; }
            GradientStop { position: 0.5; color: "#ed7bb4"; }
            GradientStop { position: 1.0; color: "transparent"; }
        }
    }

    RowLayout
    {
        width: parent.width;
        height: parent.height;
        spacing: 10;

        Item
        {
            width: 50;
            height: 50;

            Image
            {
                id: profileImage;
                source: image_url;
                width: parent.width;
                height: parent.height;
                fillMode: Image.PreserveAspectFit;
                mipmap: true;
            }

            Image
            {
                id: statusDot;
                source: statusIconSource;
                width: 15;
                height: 15;
                anchors.bottom: profileImage.bottom;
                anchors.right: profileImage.right;
                anchors.margins: 2;
            }
        }

        ColumnLayout
        {
            Layout.fillWidth: true;
            Layout.preferredHeight: parent.height;
            Layout.leftMargin: 4;
            spacing: 2;
            Layout.topMargin: 3;

            Text
            {
                text: name;
                color: "black";
                font.pixelSize: 14;
                Layout.fillWidth: true;
                Layout.fillHeight: true;
                verticalAlignment: Text.AlignTop;
            }

            Text
            {
                text: (messages.count === 0) ? " " : messages.at(contact_list_model.contact_proxy_list.get(index).messages.count - 1).contents;
                color: "black";
                font.pixelSize: 12;
                Layout.fillWidth: true;
                Layout.fillHeight: true;
                verticalAlignment: Text.AlignTop;
                elide: Text.ElideRight;
            }
        }

        ColumnLayout
        {
            Layout.fillWidth: true;
            Layout.alignment: Qt.AlignRight;
            Layout.preferredHeight: parent.height;
            spacing: 5;

            Rectangle 
            {
                width: 30;
                height: 30;
                radius: 15;
                color: "#e6e8e8";

                Text
                {
                    id: count;
                    text: unread_message > 0 ? unread_message.toString() : "";
                    color: "#ed7bb4";
                    font.pixelSize: 12;
                    font.bold: true;
                    visible: unread_message > 0;

                    anchors.centerIn: parent;
                }
            }

            Text
            {
                text: (messages.count === 0) ? " " : messages.at(contact_list_model.contact_proxy_list.get(index).messages.count - 1).time;
                color: "gray";
                font.bold: true;
                font.pixelSize: 12;
                horizontalAlignment: Text.AlignRight;
            }
        }
    }

    MouseArea
    {
        id: mouseArea;
        anchors.fill: parent;
        hoverEnabled: true;

        onClicked:
        {
            contact_list_model.active_chat = contact_list_model.contact_proxy_list.get(index);
            stackView.push(chatWindow);
        }
    }
}
