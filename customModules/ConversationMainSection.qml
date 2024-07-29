import QtQuick;
import QtQuick.Controls;
import QtQuick.Layouts;

Rectangle
{
    id: root;

    anchors.fill: parent;
    color: "#dedede";

    required property string conversation_ID;

    property var messageModel: ListModel
    { id: messageModel; }

    Component.onCompleted:
    {
        var messages = chatListModel.get_messages(root.conversation_ID);
        messages.forEach((message) =>
        {
            messageModel.append({ time: message.time, isText: message.text, isAudio: message.isAudio, audioSource: message.audioSource, isFile: message.isFile, filePath: message.filePath });
        });
    }

    ListView
    {
        id: listView;
        anchors.fill: parent;
        anchors.margins: 5;
        spacing: 5;
        clip: true;
        model: messageModel;
        visible: true;

        delegate: Item
        {
            id: messageDelegate;
            width: listView.width;
            height: 40;
            property bool isPlaying: false;

            Rectangle
            {
                width: parent.width;
                height: parent.height;
                color: "#dedede";
                radius: 5;

                MouseArea
                {
                    id: mouseArea;
                    anchors.fill: parent;
                    onClicked: handleItemClicked(model.time, model.isText, model.isAudio, model.audioSource, model.isFile, model.filePath);
                    onPressed: item.color = "gray";
                    onReleased: item.color = "white";

                    Rectangle
                    {
                        id: item;
                        width: textMessage.width + 20;
                        height: 40;
                        radius: 15;
                        color: "white";

                        anchors.left: parent.left;
                        anchors.margins: 5;

                        Text
                        {
                            id: textMessage;
                            text: model.isText;
                            color: "black";
                            elide: Text.ElideRight;
                            wrapMode: Text.WrapAtWordBoundaryOrAnywhere;

                            font.pixelSize: 12;
                            font.bold: true;

                            anchors.top: parent.top;
                            anchors.left: parent.left;
                            anchors.margins: 5;
                        }

                        Text
                        {
                            id: time;
                            text: model.time;

                            color: "black";
                            elide: Text.ElideRight;
                            wrapMode: Text.WrapAtWordBoundaryOrAnywhere;

                            font.pixelSize: 8;
                            font.bold: true;

                            anchors.right: parent.right;
                            anchors.bottom: parent.bottom;
                            anchors.margins: 5;
                        }

                        Image
                        {
                            source: model.isAudio ? (isPlaying ? "qrc:/QML_modules/ClientApp/icons/pause_icon.png" : "qrc:/QML_modules/ClientApp/icons/play_icon.png") : (model.isFile ? "qrc:/QML_modules/ClientApp/icons/file_icon.png" : "");
                            visible: (model.isAudio || model.isFile) ? true : false;
                            width: 24;
                            height: 24;

                            anchors.left: parent.left;
                            anchors.verticalCenter: parent.verticalCenter;
                        }
                    }
                }
            }

            function handleItemClicked (time, isText, isAudio, audioSource, isFile, filePath)
            {
                if (isAudio)
                    (audioController.currentSource == audioSource && audioController.isPlaying) ? audioController.pause() : audioController.play(audioSource);
                else if (isFile)
                    clientManager.open_file(filePath);
                else
                    console.log("Message Clicked: " + isText + " and the time is: " + time);
            }
        }
    }

    Connections
    {
        target: chatListModel;

        function onNewTextReceived (conversation_ID, time, text)
        {
            if(conversation_ID === root.conversation_ID)
                messageModel.append({ time: time, isText: text});
        }

        function onNewAudioReceived (conversation_ID, time, is_audio, audio_source)
        {
            if(conversation_ID === root.conversation_ID)
                messageModel.append({ time: time,  isAudio: is_audio, audioSource: audio_source});
        }

        function onNewFileReceived (conversation_ID, time, text, is_file, file_path)
        {
            if(conversation_ID === root.conversation_ID)
                messageModel.append({ time: time, isFile: is_file, filePath: file_path });
        }
    }
}