import QtQuick;
import QtQuick.Controls;
import Qt.labs.platform

Item
{
    id: root;

    property bool isRecording: false;
    property bool onOffLine: (contact_list_model.active_chat === null) ? false : contact_list_model.active_chat.status; 

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

        Row
        {
            anchors.left: returnImage.right;
            anchors.top: parent.top;
            anchors.bottom: parent.bottom;
            anchors.margins: 5;

            height: parent.height;
            spacing: 10;

            RoundedImage
            {
                imageSource: (contact_list_model.active_chat === null) ? "qrc:/QML/ClientApp/icons/name_icon.png" :  contact_list_model.active_chat.image_url;
                width: 45;
                height: 45;
            }
            
            Column
            {
                spacing: 5;
                Text
                {
                    id: userName;
                    text: (contact_list_model.active_chat === null) ? "" : contact_list_model.active_chat.name;
                    color: "black";
                    font.pixelSize: 16;
                    font.bold: true;
                    verticalAlignment: Text.AlignVCenter;
                    elide: Text.ElideRight;
                }
                Text
                {
                    id: statusText;
                    text: root.onOffLine ? "Online" : "Offline";
                    color: root.onOffLine ? "green" : "red";
                    font.pixelSize: 12;
                    verticalAlignment: Text.AlignVCenter;
                }
            }
        }
    }

    Rectangle 
    {
        width: parent.width;
        color: "gray";

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
            height: parent.width * 0.1;
            width: 40;

            onItemClicked: 
            {
                media_controller.send_file(true);
                contact_list_model.file_sent();
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
            width: 40;

            onItemClicked:
            {
                root.isRecording = !root.isRecording

                if(root.isRecording)
                {
                    media_controller.start_recording();

                    voiceCounter.anchors.left = sendVoice.right;

                    sendVoice.anchors.rightMargin = voiceCounter.width + 5;
                }
                else
                {
                    media_controller.stop_recording();

                    contact_list_model.audio_sent();

                    sendVoice.anchors.rightMargin = 5;
                }
            }

            anchors.verticalCenter: parent.verticalCenter;
            anchors.right: parent.right;
            anchors.rightMargin: 5;
        }

        Text
        {
            id: voiceCounter;

            text: media_controller.time_display;
            color: "black";
            visible: root.isRecording;

            width: 40;
            height: parent.height * 0.5;
            anchors.verticalCenter: parent.verticalCenter;
        }

        anchors.bottom: parent.bottom;
    }
}