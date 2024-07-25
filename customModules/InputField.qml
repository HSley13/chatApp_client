import QtQuick
import QtQuick.Controls
import QtQuick.Window

Rectangle
{
    id: root;
    
    property alias inputField: textInput.text;
    required property string image1Source;
    property string image2Source;
    required property string placeHolder;
    required property int echoMode;

    signal accepted(string value);

    height: 50;

    radius: 5;
    border.color: "black"
    border.width: 2

    opacity:  enabled ? 1 : 0.6;

    TextField
    {
        id: textInput;

        anchors.fill: parent;

        font.pixelSize: 14;

        color: "black";
        
        placeholderText: root.placeHolder;
        placeholderTextColor: "black";

        echoMode: root.echoMode;

        leftPadding: 30;
        verticalAlignment: TextField.AlignVCenter;

        Image
        {
            id: toggleImage;
            anchors.left: parent.left;
            anchors.leftMargin: 5;
            anchors.verticalCenter: parent.verticalCenter;

            width: 20;
            height: 20;

            mipmap: true;
            source: image1Source;

            MouseArea
            {
                anchors.fill: parent;

                onClicked: 
                {
                    textInput.echoMode = textInput.echoMode === TextInput.Normal ? TextInput.Password : TextInput.Normal;
                    
                    toggleImage.source = textInput.echoMode === TextInput.Normal ? image2Source : image1Source;
                }
            }
        }
    }
}