import QtQuick;
import QtQuick.Layouts;

Rectangle
{
    id: root;
    property bool hidden: true;

    RowLayout
    {
        id: buttons;
        anchors.top: parent.top;
        anchors.topMargin: 10;
        anchors.horizontalCenter: parent.horizontalCenter;
        Layout.fillWidth: true;
        
        spacing: 10;

        RoundedButton
        {
            text: "+ Add";
            color: "white";
            Layout.fillWidth: true;
            height: 10;

            onClicked:
            {
                // FIXME: 
                console.log("Add Member Button clicked");
            }
        }

        RoundedButton
        {
            text: "- Remove";
            color: "white";
            Layout.fillWidth: true;
            height: 10;

            onClicked:
            {
                // FIXME: 
                console.log("Remove Member Button clicked");
            }
        }
    }

    ListView
    {
        id: membersList;

        anchors.top: buttons.bottom;
        anchors.topMargin: 20;
        anchors.right: parent.right;
        anchors.left: parent.left;
        anchors.bottom: parent.bottom;
        anchors.horizontalCenter: parent.horizontalCenter;

        anchors.margins: 5;

        spacing: 10;
        clip: true;

        model: group_list_model.active_group_chat.group_members;

        delegate: Rectangle 
        {
            width: parent.width;
            height: 40;


            color: "transparent";

            property string statusIconSource: modelData.status ? "qrc:/QML/ClientApp/icons/online_icon.png" : "qrc:/QML/ClientApp/icons/offline_icon.png";

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
                    width: 40;
                    height: width;

                    RoundedImage
                    {
                        id: profileImage;
                        imageSource: modelData.image_url;
                        width: parent.width;
                        height: parent.height;
                    }

                    Image
                    {
                        id: statusDot;
                        source: statusIconSource;
                        width: 10;
                        height: 10;
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
                        text: modelData.name;
                        color: "black";
                        font.pixelSize: 12;
                        Layout.fillWidth: true;
                        Layout.fillHeight: true;
                        verticalAlignment: Text.AlignTop;
                    }

                    Text
                    {
                        text: modelData.phone_number;
                        color: "black";
                        font.pixelSize: 10;
                        Layout.fillWidth: true;
                        Layout.fillHeight: true;
                        verticalAlignment: Text.AlignTop;
                        elide: Text.ElideRight;
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
    }
}