import QtQuick;
import QtQuick.Controls;

Rectangle
{
    id: root;

    anchors.fill: parent;

    Rectangle
    {
        id: chatHeader;
        width: parent.width;
        height: 50;

        anchors.top: parent.top;
        anchors.left: parent.left;
        anchors.right: parent.right;

        Image
        {
            id: returnImage;
            source: "qrc:/QML/ClientApp/icons/back_icon.png";
            mipmap: true;
            fillMode: Image.PreserveAspectFit;
            width: parent.height * 0.4;
            height: parent.height * 0.4;

            MouseArea
            {
                anchors.fill: parent;
                onClicked: stackView.pop();
            }

            anchors.verticalCenter: parent.verticalCenter;
            anchors.left: parent.left;
            anchors.leftMargin: 10;
            anchors.rightMargin: 10;
            anchors.topMargin: 30;
        }

        Rectangle
        {
            width: parent.width - returnImage.width;
            height: parent.height;

            ImageText
            {
                id: iconNameStatus;
                source: (contact_list.open_chat_user === null) ? "qrc:/QML/ClientApp/icons/name_icon.png" :  contact_list.open_chat_user.image_url;
                name: (contact_list.open_chat_user === null) ? "" : contact_list.open_chat_user.name;
                onOffLine: (contact_list.open_chat_user === null) ? false : contact_list.open_chat_user.status; 

                anchors.fill: parent;
            }

            anchors.left: returnImage.right;
            anchors.leftMargin: 5;
            anchors.verticalCenter: parent.verticalCenter;
        }
    }

    Rectangle 
    {
        width: parent.width;

        ChatList { id: chatList; }

        anchors.top: chatHeader.bottom;
        anchors.bottom: chatBottom.top;
    }

    Rectangle 
    {
        id: chatBottom;
        width: parent.width;
        height: 50;

        gradient: Gradient
        {
            GradientStop { position: 0.0; color: "white";}
            GradientStop { position: 1.0; color: "gray";}
        }

        IconText
        {
            id: plus;
            imageSource: "qrc:/QML/ClientApp/icons/plus_icon.png";
            image2Source: "qrc:/QML/ClientApp/icons/cancel_icon.png";
            text: "";
            cWidth: parent.width * 0.1;

            onItemClicked:
            {
                console.log("Plus Icon Clicked");
            }

            anchors.left: parent.left;
            anchors.verticalCenter: parent.verticalCenter;
            anchors.rightMargin: 10;
        }

        InputField
        {
            id: new_message;
            image1Source: "";
            echoMode: 0;
            placeHolder: "Type message...";
            width: parent.width * 0.6;
            customHeight: 40;
            message: true;

            anchors.left: plus.right;
            anchors.verticalCenter: parent.verticalCenter;
            anchors.rightMargin: 5;
        }

        IconText
        {
            id: sendVoice;
            imageSource: "qrc:/QML/ClientApp/icons/voice_icon.png";
            text: "";

            onItemClicked:
            {
                console.log("Send Voice Icon Clicked");
            }

            anchors.verticalCenter: parent.verticalCenter;
            anchors.right: parent.right;
        }

        anchors.bottom: parent.bottom;
    }
}