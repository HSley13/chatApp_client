import QtQuick;
import QtQuick.Window;
import QtQuick.Controls;

Rectangle
{
    id: root;
    anchors.fill: parent;
    color: "white";

    ListView
    {
        id: listView
        anchors.fill: parent;
        anchors.margins: 5;


        spacing: 5;
        clip: true;
        model: chatListModel;
        visible: true;

        delegate: Rectangle
        {
            id: chatListDelegate;
            required property string message;


            width: listView.width;
            height: 30;
            color: "white";

            Rectangle
            {
                width: textMessge.width;
                height: 30;
                radius: 15;

                color: "gray";
                anchors.right: parent.right;

                Text
                {
                    id: textMessge;
                    anchors.centerIn: parent;

                    text: chatListDelegate.message;
                    color: "black";
                    font.pixelSize: 12;
                    font.bold: true;
                    elide: Text.ElideRight;
                }
            }
        }
    }
}