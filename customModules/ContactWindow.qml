import QtQuick;
import QtQuick.Controls;
import QtQuick.Layouts;

Rectangle
{
    visible: true;
    anchors.fill: parent;

    Rectangle
    {
        id: contactHeader;
        width: parent.width;
        height: 60;

        Image
        {
            id: returnImage;
            source: "qrc:/QML/ClientApp/icons/back_icon.png";
            mipmap: true;
            fillMode: Image.PreserveAspectFit;
            width: height * 0.4;
            height: width;

            MouseArea
            {
                anchors.fill: parent;
                onClicked: stackView2.pop();
            }

            anchors.top: parent.top;
            anchors.topMargin: 10;
            anchors.left: parent.left;
            anchors.leftMargin: 10;
        }

        InputField
        {
            id: contactSearch;
            image1Source: "qrc:/QML/ClientApp/icons/search_icon.png";
            echoMode: TextInput.Normal;
            placeHolder: "Search...";
            width: parent.width * 0.6;
            customHeight: 40;

            anchors.top: parent.top;
            anchors.topMargin: 10;
            anchors.horizontalCenter: parent.horizontalCenter;

            onAccepted: (value) => 
            {
                console.log("Text Searched: " + value);
            }
        }

        Rectangle
        {
            id: rectangle_new;
            color: mouseArea.pressed ? "#ed7bb4" : "#f5daef";
            radius: 10;
            width: rectangle_new_text.width * 1.2;
            height: 30;

            anchors.top: parent.top;
            anchors.topMargin: 10;
            anchors.right: parent.right;
            anchors.rightMargin: menuPanel.hidden ? 10 : menuPanel.width;

            Text
            {
                id: rectangle_new_text;
                text: "+ New";
                color: "#DE02B5";
                font.bold: true;

                anchors.centerIn: parent;
            }

            MouseArea
            {
                id: mouseArea;
                anchors.fill: parent;

                onClicked:
                {
                    menuPanel.hidden = !menuPanel.hidden;
                    (dialog.open()) ? dialog.close() : dialog.open();
                    console.log("+ New Button Clicked");
                }
            }
        }
    }

    Rectangle
    {
        width: parent.width;
        anchors.top: contactHeader.bottom;
        anchors.bottom: contactBottom.top;

        StackView
        {
            id: stackView2;
            anchors.fill: parent;

            initialItem: Component
            {
                ContactList { id: contactList; }
            }

            ListDialog
            {
                id: dialog;
                input: true;
                title: "Hello World";
                width: 300;

                names: ["Are you sure you want to delete it?"];

                onDialogAccepted:
                {
                    console.log("Dialog Accepted");
                    console.log("input: " + dialog.inputField);
                }

                onDialogRejected:
                {
                    console.log("Dialog Rejected");
                    console.log("input: " + dialog.inputField);
                }

                anchors.centerIn: parent;
            }
        }
    }

    Rectangle 
    {
        id: contactBottom;
        width: parent.width;
        height: 50;

        gradient: Gradient
        {
            GradientStop { position: 0.0; color: "gray"; }
            GradientStop { position: 1.0; color: "white"; }
        }

        IconText
        {
            id: chatList;
            imageSource: "qrc:/QML/ClientApp/icons/chat_icon.png";
            text: "Chats";

            onItemClicked:
            {
                stackView2.push(chatSection);
                console.log("Chat Icon Clicked");
            }

            anchors.left: parent.left;
            anchors.verticalCenter: parent.verticalCenter;
        }

        IconText
        {
            id: chatGroup;
            imageSource: "qrc:/QML/ClientApp/icons/group_icon.png";
            text: "Groups";

            onItemClicked:
            {
                console.log("Group Icon Clicked");
            }

            anchors.centerIn: parent;
        }

        IconText
        {
            id: profile;
            imageSource: "qrc:/QML/ClientApp/icons/name_icon.png";
            text: "Profile";

            onItemClicked:
            {
                console.log("Profile Icon Clicked");
            }

            anchors.right: parent.right;
            anchors.verticalCenter: parent.verticalCenter;
        }

        anchors.bottom: parent.bottom;
    }

    MenuPanel 
    {
        id: menuPanel;
        anchors.right: rectangle_new.left;
        anchors.top: rectangle_new.bottom;

        Component.onCompleted:
        {
            var options = [
                {text: "New Conversation"},
                {text: "New Group"},
                {text: "Chat with An Agent"}
            ];
            menuPanel.update_options(options);
        }

        x: hidden ? parent.width : parent.width - width;
    }
}