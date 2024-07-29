import QtQuick;
import QtQuick.Controls;
import QtQuick.Window;
import ClientApp;

Rectangle
{
    id: root;
    visible: true;
    required property string source;
    required property string name;
    required property string onOffline;
    required property string conversation_ID;

    Rectangle
    {
        id: conversationHeaderSection;
        width: parent.width;
        height: 50;

        Image
        {
            id: returnImage;
            source: "qrc:/QML_modules/ClientApp/icons/back_icon.png";
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
                source: root.source;
                name: root.name;
                last_message: root.onOffline; 
                colorM: (last_message === "Online") ? "green" : "red";

                anchors.fill: parent;
            }

            anchors.left: returnImage.right;
            anchors.leftMargin: 5;
            anchors.verticalCenter: parent.verticalCenter;
        }

        anchors.top: parent.top;
        anchors.left: parent.left;
        anchors.right: parent.right;
    }

    Rectangle 
    {
        id: conversationMainSection;
        width: root.width;

        ConversationMainSection { conversation_ID: root.conversation_ID }

        anchors.top: conversationHeaderSection.bottom;
        anchors.bottom: conversationBottomSection.top;
    }

    Rectangle 
    {
        id: conversationBottomSection;
        width: parent.width;
        height: 50;

        // FIXME: add columns --> insert & send message / files / audio  

        IconText
        {
            id: plus;
            imageSource: "qrc:/QML_modules/ClientApp/icons/plus_icon.png";
            image2Source: "qrc:/QML_modules/ClientApp/icons/cancel_icon.png";
            text: "";
            cWidth: parent.width * 0.1;

            onItemClicked:
            {
                // FIXME: Handle this click Properly;
                console.log("Plus Icon Clicked");
            }

            anchors.left: parent.left;
            anchors.verticalCenter: parent.verticalCenter;
            anchors.rightMargin: 5;
        }

        InputField
        {
            id: new_message;
            image1Source: "";
            echoMode: 0;
            placeHolder: "Type message...";
            width: parent.width * 0.6;
            customHeight: 40;

            anchors.left: plus.right;
            anchors.verticalCenter: parent.verticalCenter;
            anchors.rightMargin: 5;
        }

        IconText
        {
            id: sendMessage;
            imageSource: "qrc:/QML_modules/ClientApp/icons/send_icon.png";
            text: "";
            cWidth: parent.width * 0.1;

            onItemClicked:
            {
                // FIXME: Handle this click Properly;
                console.log("Send Icon Clicked");
            }

            anchors.left: new_message.right;
            anchors.verticalCenter: parent.verticalCenter;
            anchors.rightMargin: 5;
        }

        IconText
        {
            id: sendVoice;
            imageSource: "qrc:/QML_modules/ClientApp/icons/voice_icon.png";
            text: "";
            cWidth: parent.width * 0.2;

            onItemClicked:
            {
                voiceCounter.visible = !voiceCounter.visible;
                voiceCounter.record = !voiceCounter.record;

                if(voiceCounter.visible)
                {
                    voiceCounter.anchors.left = sendVoice.right;
                    voiceCounter.anchors.verticalCenter = parent.verticalCenter;

                    sendVoice.anchors.right = parent.right;
                    sendVoice.anchors.rightMargin = voiceCounter.width + 5;
                }
                else
                {
                    sendVoice.anchors.right = parent.right;
                    sendVoice.anchors.rightMargin = 5;
                }

                voiceCounter.record ? audioController.record() : audioController.stop();

                // FIXME: Handle this click properly
                console.log("Send Icon Clicked");
            }

            anchors.left: sendMessage.right;
            anchors.verticalCenter: parent.verticalCenter;
            anchors.right: parent.right;
        }

        Text
        {
            property bool record: false;

            id: voiceCounter;

            text: audioController.time_display;
            color: "black";
            visible: false;

            width: 40;
            height: parent.height * 0.5;
            anchors.verticalCenter: parent.verticalCenter;
        }

        anchors.bottom: parent.bottom;
    }
}