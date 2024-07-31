import QtQuick;
import QtQuick.Window;

Rectangle
{
    id: root;
    width: 200;
    height: 50;
    color: "white";

    property string source;
    property bool onOffLine: false;
    property string name;

    Row
    {
        anchors.fill: parent;
        anchors.margins: 5;
        spacing: 10;

        Rectangle
        {
            id: container;
            width: 40;
            height: 40;
            radius: 20;
            clip: true;

            Image
            {
                id: profileImage;
                source: root.source;
                anchors.fill: parent;
                fillMode: Image.PreserveAspectFit;
                asynchronous: true;
            }
        }

        Column
        {
            spacing: 5;

            Text
            {
                id: userName;
                text: root.name;
                color: "black";
                font.pixelSize: 16;
                font.bold: true;
                verticalAlignment: Text.AlignVCenter;
                elide: Text.ElideRight;
            }

            Text
            {
                id: statusText;
                text: root.onOffLine ? "Online" : "Offline";
                color: root.onOffLine ? "green" : "red";
                font.pixelSize: 12;
                verticalAlignment: Text.AlignVCenter;
            }
        }
    }
}