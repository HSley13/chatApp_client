import QtQuick
import QtQuick.Layouts

Rectangle
{
    color: "transparent";
    radius: 100;

    property var contactData: contactListView.model[index];

    Rectangle
    {
        id: hoverBackground;

        width: mouseAra.containsMouse ? parent.width : 0;
        height: parent.height;

        anchors.left: parent.left;
        anchors.leftMargin: profileImage.width / 2;

        Behavior on width {SmoothedAnimation {duration: 450;}}

        gradient: Gradient
        {
            orientation: Gradient.Horizontal;

            GradientStop {position: 0.0; color: "transparent"}
            GradientStop {position: 0.5; color: "#ed7bb4"}
            GradientStop {position: 1.0; color: "transparent"}
        }
    }

    RowLayout
    {
        width: parent.width;
        height: parent.height;

        spacing: 2;

        Image
        {
            id: profileImage;
            source: contactData.image_url;
            Layout.preferredHeight: parent.height
            Layout.preferredWidth: parent.width * 0.15;

            asynchronous: true;
            fillMode: Image.PreserveAspectFit;
            mipmap: true;
        }

        ColumnLayout
        {
            Layout.fillWidth: true;
            Layout.preferredHeight: parent.height;
            Layout.leftMargin: 4;
            spacing: 0;
            Layout.topMargin: 3;

            Text
            {
                text: contactData.name;
                color: "black";
                font.pixelSize: 14;
                Layout.fillWidth: true;
                Layout.fillHeight: true;
                verticalAlignment: Qt.AlignTop;
            }

            Text
            {
                text: contactData.messages.length === 0 ? " " : contactData.messages[contactData.messages.length - 1].contents;
                color: "black";
                font.pixelSize: 12;
                Layout.fillWidth: true;
                Layout.fillHeight: true;
                verticalAlignment: Qt.AlignTop;
                elide: Text.ElideRight;
            }
        }
    }

    MouseArea
    {
        id: mouseAra;
        hoverEnabled: true;
        anchors.fill: parent;

        onClicked:
        {
            contact_list.open_chat_user = contactData;
            stackView.push(chatWindow);
        } 
    }
}