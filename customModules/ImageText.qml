import QtQuick;
import QtQuick.Window;

Rectangle
{
    id: root;
    color: "white";

    required property string source;
    property string onOffLine: "";
    required property string name;
    required property string last_message;
    property string last_seen: "";
    property string message_count: "";
    property string colorM: "gray";

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

    Rectangle
    {
        anchors.left: container.right;
        anchors.right: parent.right;
        anchors.top: parent.top;
        anchors.bottom: parent.bottom;
        anchors.margins: 5;

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
                color: root.colorM;
                font.pixelSize: 10;
                elide: Text.ElideRight;
                width: parent.width; 
            }

            anchors.left: parent.left;
        }

        Column
        {
            spacing: 5;

            Text
            {
                id: text_seen;

                text: root.last_seen;
                color: "#DE02B5";
                font.pixelSize: 10;
                font.bold: true;
                elide: Text.ElideRight;
            }

            Rectangle 
            {
                width: text_count.width * 2;
                height: width;
                color: "#DE02B5";
                radius: width / 2;

                Text 
                {
                    id: text_count;
                    text: root.message_count;
                    color: "white";
                    font.pixelSize: 10;
                    font.bold: true;
                    elide: Text.ElideRight;
                    anchors.centerIn: parent;
                }

                anchors.horizontalCenter: text_seen.horizontalCenter;
            }

            anchors.right: parent.right;
        }
    }
}