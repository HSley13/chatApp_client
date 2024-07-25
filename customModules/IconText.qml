
import QtQuick;

Column 
{
    id: root;

    required property string imageSource;
    required property string text;

    signal itemClicked();

    spacing: 2;
    width: chatBottomBar.width / 3;

    Image 
    {
        id: profile;
        source: root.imageSource;

        mipmap: true;
        fillMode: Image.PreserveAspectFit;
        width: parent.width;
        height: chatBottomBar.height * 0.8;

        MouseArea 
        {
            anchors.fill: parent;
            onClicked: root.itemClicked();
        }
    }

    Text 
    {
        text: text;
        color: "black";
        font.pixelSize: 10;
        anchors.horizontalCenter: parent.horizontalCenter;
    }
}