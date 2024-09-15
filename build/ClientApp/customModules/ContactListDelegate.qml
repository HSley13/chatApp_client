import QtQuick;
import QtQuick.Layouts;

Rectangle
{
    color: "transparent";

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

            RoundedImage
            {
                id: profileImage;
                imageSource: image_url;
                width: parent.width;
                height: parent.height;
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
                text: first_name;
                color: "black";
                font.pixelSize: 14;
                Layout.fillWidth: true;
                Layout.fillHeight: true;
                verticalAlignment: Text.AlignTop;
            }

            Text
            {
                text: (is_typing !== "") ? is_typing : (messages.count > 0 ? messages.at(messages.count - 1).text : "file/audio");
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
                visible: unread_message > 0;

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
                text: (messages.count === 0) ? " " : message_time;
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
            contact_list_model.active_chat = contact_list_model.contact_proxy_list_chat.get(index);
            if(contact_list_model.active_chat)
                contact_list_model.update_unread_message(contact_list_model.active_chat.chat_ID);
            
            group_list_model.active_group_chat = null;
            stackView.push(chatWindow);
        }
    }
}
