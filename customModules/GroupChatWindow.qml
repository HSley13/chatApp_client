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
                imageSource: (group_list_model.active_group_chat === null) ? "qrc:/QML/ClientApp/icons/name_icon.png" :  group_list_model.active_group_chat.group_image_url;
                width: 45;
                height: 45;
            }
            
            Column
            {
                spacing: 5;
                Text
                {
                    id: userName;
                    text: (group_list_model.active_group_chat === null) ? "" : group_list_model.active_group_chat.group_name;
                    color: "black";
                    font.pixelSize: 16;
                    font.bold: true;
                    verticalAlignment: Text.AlignVCenter;
                    elide: Text.ElideRight;
                }
            }
        }
    }

    Rectangle 
    {
        width: parent.width;

        GroupChatList { id: groupChatList; }

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
                media_controller.send_file();
                group_list_model.group_file_sent();
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
                    media_controller.start_recording();

                    voiceCounter.anchors.left = sendVoice.right;

                    sendVoice.anchors.rightMargin = voiceCounter.width + 5;
                }
                else
                {
                    media_controller.stop_recording();

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