import QtQuick;
import QtQuick.Controls;
import QtQuick.Window;
import QtQuick.Controls.Basic;

Rectangle
{
    id: root;

    property alias inputField: textInput.text;
    required property string image1Source;
    property string image2Source;
    required property string placeHolder;
    property alias echoMode: textInput.echoMode;
    property int customHeight: 50;

    signal accepted(string value);

    height: customHeight;

    radius: 20;
    border.color: textInput.focus ? "#a10e7a" : "black";
    border.width: textInput.focus ? 4 : 2;

    opacity: enabled ? 1 : 0.6;

    TextField
    {
        id: textInput;

        anchors.fill: parent;
        anchors.margins: 2;

        font.pixelSize: 14;

        color: "black";

        placeholderText: root.placeHolder;
        placeholderTextColor: "black";

        leftPadding: 30;
        verticalAlignment: TextField.AlignVCenter;

        onAccepted: root.accepted(text);

        background: Rectangle 
        {
            radius: root.radius - 2;
            implicitWidth: 200;
            implicitHeight: 40;
            color: "#e6e8e8";
            border.color: "transparent";
        }

        Image
        {
            id: toggleImage;
            anchors.left: parent.left;
            anchors.leftMargin: 5;
            anchors.verticalCenter: parent.verticalCenter;

            width: 20;
            height: 20;

            mipmap: true;
            source: root.image1Source;

            MouseArea
            {
                anchors.fill: parent;

                onClicked: 
                {
                    textInput.echoMode = textInput.echoMode === TextInput.Normal ? TextInput.Password : TextInput.Normal;
                    
                    toggleImage.source = textInput.echoMode === TextInput.Normal ? root.image2Source : root.image1Source;
                }
            }
        }
    }
    
    Component.onCompleted: textInput.focus = false;
}