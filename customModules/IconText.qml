import QtQuick;
import QtQuick.Controls;

Column
{
    id: root;

    required property string imageSource;
    required property string text;

    signal itemClicked();

    spacing: 2;
    width: chatBottomBar.width / 3;

    Rectangle
    {
        id: circle;

        height: chatBottomBar.height * 0.8;
        width: height;
        radius: width / 2;

        color: "transparent";
        
        anchors.horizontalCenter: parent.horizontalCenter;

        Image
        {
            id: profile;

            source: root.imageSource;
            mipmap: true;
            fillMode: Image.PreserveAspectFit;

            width: parent.width * 0.9;
            height: parent.height * 0.9;
            anchors.centerIn: parent;
        }

        MouseArea
        {
            anchors.fill: parent;

            onPressed: circle.color = "gray";
            onReleased: circle.color = "transparent";
            onClicked: root.itemClicked();

        }
    }

    Text
    {
        id: label;
        text: root.text;

        color: "black";
        font.pixelSize: 10;

        anchors.horizontalCenter: parent.horizontalCenter;
    }
}