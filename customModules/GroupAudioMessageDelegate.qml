import QtQuick;
import QtQuick.Controls;
import QtQuick.Layouts;
import QtMultimedia;

Item
{
    height: audio_bubble.height + 10;
    width: audio_bubble.width;

    property var model;
    readonly property bool sender: model.sender_ID === contact_list_model.main_user.phone_number;

    Rectangle
    {
        id: audio_bubble;
        width: controlsRow.width + 20;
        height: 55;
        radius: 10;

        x: sender ? groupChatListView.width - width : 0;

        MediaPlayer
        {
            id: mediaPlayer;
            source: model.audio_source;
            autoPlay: false;
            audioOutput: audioOutput;

            onPositionChanged:
            {
                if (mediaPlayer.position >= duration)
                {
                    progressSlider.value = 0;
                    mediaPlayer.stop();
                }
                else
                    progressSlider.value = mediaPlayer.position;
            }
        }

        AudioOutput
        {
            id: audioOutput;
            volume: 1.0;
        }

        gradient: Gradient
        {
            orientation: Gradient.Horizontal;
            GradientStop { position: 0.0; color: sender ? "#ed7bb4" : "white"; }
            GradientStop { position: 1.0; color: sender ? "gray" : "gray"; }
        }

        ColumnLayout
        {
            id: controlsColumn;
            anchors.fill: parent;
            anchors.margins: 5;

            RowLayout
            {
                id: controlsRow;
                Layout.fillWidth: true;
                spacing: 5;

                IconText
                {
                    id: playButton;
                    imageSource1: (mediaPlayer.playbackState === MediaPlayer.PlayingState) ? "qrc:/QML/ClientApp/icons/pause_icon.png" : "qrc:/QML/ClientApp/icons/play_icon.png";
                    height: 30;
                    width: 30;

                    MouseArea
                    {
                        anchors.fill: parent;
                        onClicked: (mediaPlayer.playbackState === MediaPlayer.PlayingState) ? mediaPlayer.pause() : mediaPlayer.play();
                    }
                }

                Slider
                {
                    id: progressSlider;
                    width: controlsRow.width - playButton.width - 20;
                    from: 0;
                    to: mediaPlayer.duration;
                    value: mediaPlayer.position;
                    onMoved: if (pressed) mediaPlayer.position = value;
                }
            }

            Text
            {
                id: audio_duration;
                text:
                {
                    let duration = mediaPlayer.duration / 1000;
                    let currentTime = mediaPlayer.position / 1000;
                    return `${Math.floor(currentTime / 60)}:${Math.floor(currentTime % 60).toString().padStart(2, "0")} / ${Math.floor(duration / 60)}:${Math.floor(duration % 60).toString().padStart(2, "0")}`;
                }

                color: "black";
                font.pixelSize: 10;
                width: parent.width;
                horizontalAlignment: Text.AlignHCenter;
            }
        }

        Text
        {
            id: timeText;
            text: model.time;

            anchors.top: controlsColumn.bottom;
            anchors.topMargin: 5;
            anchors.right: sender ? parent.right : undefined;
            horizontalAlignment: sender ? Text.AlignRight : Text.AlignLeft;

            color: "black";
            font.pixelSize: 10;
            width: controlsColumn.width;

            MouseArea 
            {
                id: messageMouseArea;
                anchors.fill: parent;
                acceptedButtons: Qt.RightButton;

                onClicked: (mouse) => 
                {
                    if (sender)
                        contextMenu.popup();
                }

                onPressAndHold: (mouse) => 
                {
                    if (mouse.source === Qt.MouseEventNotSynthesized && sender)
                        contextMenu.popup();
                }

                Menu 
                {
                    id: contextMenu;
                    Action 
                    { 
                        text: "Delete For All"; 
                        onTriggered: client_manager.delete_group_message(group_list_model.active_group_chat.group_ID, model.full_time);
                    }
                }
            }
        }
    }

    Text
    {
        id: senderNameText;
        text: model.sender_name;
        visible: model.sender_name !== contact_list_model.main_user.first_name;

        anchors.left: audio_bubble.left;
        anchors.leftMargin: 12;
        anchors.top: audio_bubble.top;

        color: "#DE02B5";
        font.pixelSize: 10;
        font.bold: true;
    }
}