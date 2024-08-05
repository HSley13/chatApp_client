import QtQuick;
import QtQuick.Controls;
import QtQuick.Controls.Basic;

Rectangle
{
    id: root;

    property alias inputField: textInput.text;
    property string image1Source;
    property string image2Source;
    property string placeHolder;
    property alias echoMode: textInput.echoMode;
    property bool isMessage: false;
    property bool isSearching: false;

    signal accepted(string value);  

    radius: 20;
    border.color: textInput.focus ? "#a10e7a" : "black";
    border.width: textInput.focus ? 4 : 2;
    opacity: enabled ? 1 : 0.6;

    TextField
    {
        id: textInput;

        anchors.fill: parent;
        anchors.margins: 2;

        clip: true;
        wrapMode: Text.Wrap;
        font.pixelSize: 14;
        color: "black";

        placeholderText: root.placeHolder;
        placeholderTextColor: "black";

        leftPadding: toggleImage.width + 10;
        rightPadding: sendMessageButton.width;
        verticalAlignment: TextField.AlignVCenter;

        onTextChanged: isSearching ? contact_list_model.contact_proxy_list.setFilterFixedString(text) : "";

        onAccepted:
        {
            root.accepted(text);
            sendMessage();
        }
        
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

        IconText
        {
            id: sendMessageButton;
            visible: root.isMessage;
            imageSource1: "qrc:/QML/ClientApp/icons/send_icon.png";
            width: 30;
            height: 30;

            onItemClicked: sendMessage();
            
            anchors.right: parent.right;
            anchors.verticalCenter: parent.verticalCenter;
        }
    }

    function sendMessage()
    {
        if (textInput.text === "")
            return;

        group_list_model.group_send_message(textInput.text);
        contact_list_model.send_message(textInput.text);

        textInput.text = "";
    }

    Component.onCompleted: textInput.focus = false;
}