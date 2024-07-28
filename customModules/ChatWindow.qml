import QtQuick;
import QtQuick.Window;
import QtQuick.Controls;

Rectangle
{
    id: root;
    visible: true;

    Rectangle
    {
        id: chatHeaderSection;
        width: parent.width;
        height: 60; 

        Image
        {
            id: returnImage;
            source: "qrc:/QML_modules/ClientApp/icons/back_icon.png";
            mipmap: true;
            fillMode: Image.PreserveAspectFit;
            width: parent.height * 0.4;
            height: width;

            MouseArea
            {
                anchors.fill: parent;
                onClicked: stackView.pop();
            }

            anchors.top: parent.top;
            anchors.topMargin: 10;
            anchors.left: parent.left;
            anchors.leftMargin: 10;
        }

        InputField
        {
            id: chatWindowSearch;
            image1Source: "qrc:/QML_modules/ClientApp/icons/search_icon.png";

            echoMode: 0;
            placeHolder: "Search...";
            width: parent.width * 0.6;

            onAccepted: (value) => 
            {
                console.log("Text Searched: " + value);
            }

            anchors.top: parent.top;
            anchors.topMargin: 10;
            anchors.horizontalCenter: parent.horizontalCenter;
        }

        Rectangle
        {
            id: rectangle_new;
            color: "#f5daef";

            radius: 10;
            width: rectangle_new_text.width * 1.2;
            height: 30;

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
                anchors.fill: parent;

                onPressed: rectangle_new.color = "#ed7bb4";
                onReleased: rectangle_new.color = "#f5daef";


                onClicked:
                {
                     menuPanel.hidden = !menuPanel.hidden;
                    // FIXME: Handle this click Properly;
                    console.log("+ New Button Clicked");;
                }
            }

            anchors.top: parent.top;
            anchors.topMargin: 10;
            anchors.right: parent.right;
            anchors.rightMargin: menuPanel.hidden ? 10 : menuPanel.width;
        }

        anchors.top: parent.top;
        anchors.left: parent.left;
        anchors.right: parent.right;
    }

    Rectangle
    {
        id: chatMainSection;
        width: root.width;

        ChatMainSection {}

        anchors.top: chatHeaderSection.bottom;
        anchors.bottom: chatBottomSection.top;
    }

    Rectangle 
    {
        id: chatBottomSection;
        width: parent.width;
        height: 50; 

        color: "#dedede";

        IconText
        {
            id: chatList;
            imageSource: "qrc:/QML_modules/ClientApp/icons/chat_icon.png";
            text: "Chats";
            onItemClicked:
            {
                // FIXME: Handle this click Properly;
                console.log("Chat Icon Clicked");
            }
            anchors.left: parent.left;
            anchors.verticalCenter: parent.verticalCenter;
        }

        IconText
        {
            id: chatGroup;
            imageSource: "qrc:/QML_modules/ClientApp/icons/group_icon.png";
            text: "Groups";

            onItemClicked:
            {
                // FIXME: Handle this click Properly;
                console.log("Group Icon Clicked");
            }

            anchors.centerIn: parent;
        }

        IconText
        {
            id: profile;
            imageSource: "qrc:/QML_modules/ClientApp/icons/name_icon.png";
            text: "Profile";

            onItemClicked:
            {
                // FIXME: Handle this click Properly;
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

        anchors.right: rectangle_new.left
        anchors.top: rectangle_new.bottom;

        Component.onCompleted:
        {
            var options = ["New Conversation", "New Group", "Chat with An Agent"];
            menuPanel.update_options(options);
        }

        x: hidden ? parent.width : parent.width - width;
    }
}