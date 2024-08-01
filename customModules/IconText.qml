import QtQuick;
import QtQuick.Controls;

Rectangle
{
    id: root;

    required property string imageSource1;
    property string imageSource2: "";
    property string label: "";

    signal itemClicked();

    radius: width / 2;
    color: mouseArea.pressed ? "gray" : "transparent";
    
    anchors.top: parent.top;
    anchors.topMargin: 5;

    Image
    {
        id: profile;
        source: root.imageSource1;
        mipmap: true;

        fillMode: Image.PreserveAspectFit;
        asynchronous: true;

        width: parent.width * 0.8;
        height: parent.height * 0.8;

        anchors.centerIn: parent;
    }

    MouseArea
    {
        id: mouseArea;
        anchors.fill: parent;

        onClicked: 
        {
            if(root.imageSource2 !== "")
                profile.source = (profile.source.toString() === root.imageSource1) ? root.imageSource2 : root.imageSource1;

            root.itemClicked();
        }
    }
}