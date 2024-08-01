import QtQuick;
import QtQuick.Controls;

Rectangle
{
    id: root;

    property bool isRecording: false;

    Rectangle
    {
        id: chatHeader;
        width: parent.width;
        height: 50;

        anchors.top: parent.top;
        anchors.left: parent.left;
        anchors.right: parent.right;

        IconText
        {
            id: returnImage;
            imageSource1:"qrc:/QML/ClientApp/icons/back_icon.png";
            height: parent.height * 0.5;
            width: height;

            onItemClicked: stackView.pop();

            anchors.verticalCenter: parent.verticalCenter;
            anchors.left: parent.left;
            anchors.leftMargin: 10;
        }

        Rectangle
        {
            width: parent.width - returnImage.width;
            height: parent.height;

            ImageText
            {
                id: iconNameStatus;
                source: (contact_list_model.active_chat === null) ? "qrc:/QML/ClientApp/icons/name_icon.png" :  contact_list_model.active_chat.image_url;
                name: (contact_list_model.active_chat === null) ? "" : contact_list_model.active_chat.name;
                onOffLine: (contact_list_model.active_chat === null) ? false : contact_list_model.active_chat.status; 

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
            imageSource1: "qrc:/QML/ClientApp/icons/plus_icon.png";
            imageSource2: "qrc:/QML/ClientApp/icons/cancel_icon.png";
            height: parent.width * 0.1;
            width: height * 0.8;

            onItemClicked:
            {
                console.log("Plus Icon Clicked");
            }

            anchors.left: parent.left;
            anchors.verticalCenter: parent.verticalCenter;
            anchors.leftMargin: 5;
        }

        InputField
        {
            id: new_message;
            echoMode: 0;
            placeHolder: "Type message...";
            width: parent.width * 0.6;
            height: 40;
            isMessage: true;

            anchors.verticalCenter: parent.verticalCenter;
            anchors.horizontalCenter: parent.horizontalCenter;
        }

        IconText
        {
            id: sendVoice;
            imageSource1: "qrc:/QML/ClientApp/icons/voice_icon.png";
            height: parent.width * 0.1;
            width: height * 0.8;

            onItemClicked:
            {
                root.isRecording = !root.isRecording

                if(root.isRecording)
                {
                    audio_controller.record();

                    voiceCounter.anchors.left = sendVoice.right;

                    sendVoice.anchors.rightMargin = voiceCounter.width + 5;
                }
                else
                {
                    audio_controller.stop();

                    sendVoice.anchors.rightMargin = 5;
                }

                // FIXME: Handle this click properly
                console.log("Send Icon Clicked");
            }

            anchors.verticalCenter: parent.verticalCenter;
            anchors.right: parent.right;
            anchors.rightMargin: 5;
        }

        Text
        {
            id: voiceCounter;

            text: audio_controller.time_display;
            color: "black";
            visible: root.isRecording;

            width: 40;
            height: parent.height * 0.5;
            anchors.verticalCenter: parent.verticalCenter;
        }

        anchors.bottom: parent.bottom;
    }
}