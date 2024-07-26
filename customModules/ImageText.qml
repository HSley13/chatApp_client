import QtQuick;
import QtQuick.Window;

Rectangle
{
    id: root;
    color: "white";
    anchors.fill: parent;

    required property string source;
    required property string onOffLine;
    required property string name;
    required property string last_message;
    property string last_seen: "Now";
    required property string message_count;

    Rectangle
    {
        id: container;
        anchors.left: parent.left;
        anchors.leftMargin: 5;
        anchors.verticalCenter: parent.verticalCenter;
        width: 40;
        height: 40;

        IconText
        {
            id: customImage;
            imageSource: root.source;
            text: "";
            cWidth: 40;

            onItemClicked:
            {
                // FIXME: Handle this click properly;
                console.log("Chat Icon Clicked");
            }

            anchors.fill: parent;
        }

        Image
        {
            id: onOffLine;
            source: root.onOffLine;
            mipmap: true;
            fillMode: Image.PreserveAspectFit;

            width: 15;
            height: 15;

            anchors.bottom: parent.bottom;
            anchors.right: parent.right;
        }
    }

    Row
    {
        anchors.left: container.right;
        anchors.right: parent.right;
        anchors.top: parent.top;
        anchors.bottom: parent.bottom;
        anchors.margins: 5;

        spacing: 50; 

        Column
        {
            spacing: 5;
            width: parent.width * 0.6; 

            Text 
            {
                id: name;
                text: root.name;
                color: "black";
                font.pixelSize: 16;
                font.bold: true;
                elide: Text.ElideRight;
            }

            Text 
            {
                id: last_message;
                text: root.last_message;
                color: "gray";
                font.pixelSize: 10;
                elide: Text.ElideRight;
                width: parent.width; 
            }
        }
    }
}