import QtQuick;
import QtQuick.Controls;
import QtQuick.Layouts;
import QtMultimedia;

Item
{
    property var model;
    property string phoneNumber;

    id: root;
    height: audio_bubble.height + 24;
    width: audio_bubble.width;

    readonly property bool sender: phoneNumber === contact_list_model.main_user.phone_number;

    Rectangle
    {
        id: audio_bubble;
        width: 200;
        height: 70;
        radius: 10;

        x: sender ? chatListView.width - width : 0;

        MediaPlayer
        {
            id: mediaPlayer;
            source: model.audio_source;
            autoPlay: false;
            audioOutput: audioOutput;
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
            spacing: 5;

            RowLayout
            {
                id: controlsRow;
                Layout.fillWidth: true;
                spacing: 5;

                IconText
                {
                    id: playButton;
                    imageSource1: "qrc:/QML/ClientApp/icons/play_icon.png";
                    imageSource2: "qrc:/QML/ClientApp/icons/pause_icon.png";
                    height: 30;
                    width: 30;

                    onItemClicked: (mediaPlayer.playbackState === MediaPlayer.PlayingState) ? mediaPlayer.pause() : mediaPlayer.play();
                }

                Slider
                {
                    id: progressSlider;
                    width: controlsRow.width - playButton.width;
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
                font.pixelSize: 12;
                width: parent.width;
                horizontalAlignment: Text.AlignHCenter;
            }
        }

        Text
        {
            id: timeText;
            text: model.time;

            anchors.top: controlsColumn.bottom;
            anchors.topMargin: 10;
            anchors.right: sender ? parent.right : undefined;
            horizontalAlignment: sender ? Text.AlignRight : Text.AlignLeft;

            color: "black";
            font.pixelSize: 10;
            width: controlsColumn.width;
        }

        Connections
        {
            target: mediaPlayer;

            onPositionChanged: progressSlider.value = mediaPlayer.position;
            onDurationChanged: progressSlider.to = mediaPlayer.duration;
        }
    }
}