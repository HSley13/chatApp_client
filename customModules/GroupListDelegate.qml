import QtQuick;
import QtQuick.Layouts;

Rectangle
{
    color: "transparent";

    Rectangle
    {
        id: hoverBackground;
        width: mouseArea.containsMouse ? parent.width : 0;
        height: parent.height;

        anchors.left: parent.left;
        anchors.leftMargin: groupImage.width / 2;


        Behavior on width { SmoothedAnimation {duration: 450;} }

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

        RoundedImage
        {
            id: groupImage;
            imageSource: "https://groupworkandcommunication2018.wordpress.com/wp-content/uploads/2018/10/group.png";
            width: 50;
            height: 50;
        }

        // ColumnLayout
        // {
        //     Layout.fillWidth: true;
        //     Layout.preferredHeight: parent.height;
        //     Layout.leftMargin: 4;
        //     spacing: 2;
        //     Layout.topMargin: 3;

        //     Text
        //     {
        //         text: group_name;
        //         color: "black";
        //         font.pixelSize: 14;
        //         Layout.fillWidth: true;
        //         Layout.fillHeight: true;
        //         verticalAlignment: Text.AlignTop;
        //     }

        //     Text
        //     {
        //         text: (group_messages.count === 0) ? " " : group_messages.at(group_list_model.group_proxy_list.get(index).group_messages.count - 1).contents;
        //         color: "black";
        //         font.pixelSize: 12;
        //         Layout.fillWidth: true;
        //         Layout.fillHeight: true;
        //         verticalAlignment: Text.AlignTop;
        //         elide: Text.ElideRight;
        //     }
        // }

        // ColumnLayout
        // {
        //     Layout.fillWidth: true;
        //     Layout.alignment: Qt.AlignRight;
        //     Layout.preferredHeight: parent.height;
        //     spacing: 5;

        //     Rectangle 
        //     {
        //         width: 30;
        //         height: 30;
        //         radius: 15;
        //         color: "#e6e8e8";

        //         Text
        //         {
        //             id: count;
        //             text: group_unread_message > 0 ? group_unread_message.toString() : "";
        //             color: "#ed7bb4";
        //             font.pixelSize: 12;
        //             font.bold: true;
        //             visible: group_unread_message > 0;

        //             anchors.centerIn: parent;
        //         }
        //     }

        //     Text
        //     {
        //         text: (group_messages.count === 0) ? " " : group_messages.at(group_list_model.group_proxy_list.get(index).group_messages.count - 1).time;
        //         color: "gray";
        //         font.bold: true;
        //         font.pixelSize: 12;
        //         horizontalAlignment: Text.AlignRight;
        //     }
        // }
    }

    MouseArea
    {
        id: mouseArea;
        anchors.fill: parent;
        hoverEnabled: true;

        // onClicked:
        // {
        //     group_list_model.active_group_chat = group_list_model.group_proxy_list.get(index);
        //     stackView.push(groupChatWindow);
        // }
    }
}