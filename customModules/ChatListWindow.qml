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
        height: 105; 

        Image
        {
            id: returnImage;
            source: "qrc:/QML_modules/ClientApp/icons/back_icon.png";
            mipmap: true;
            fillMode: Image.PreserveAspectFit;
            width: parent.height * 0.2;
            height: parent.height * 0.2;

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

        Text
        {
            id: chatText;

            text: "CHATS";
            color: "black";

            wrapMode: Text.WrapAtWordBoundaryOrAnywhere;
            font.bold: true;
            font.pixelSize: 20;

            leftPadding: 15;
            rightPadding: 15;

            anchors.top: parent.top;
            anchors.topMargin: 10;
            anchors.horizontalCenter: parent.horizontalCenter;
        }

        Rectangle
        {
            id: rectangle_new;
            color: "#f5daef";

            radius: 10;
            width: chatText.width * .6;
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
                    // FIXME: Handle this click Properly;
                    console.log("+ New Button Clicked");;
                }
            }

            anchors.top: parent.top;
            anchors.topMargin: 10;
            anchors.right: parent.right;
            anchors.rightMargin: 10;
        }

        InputField
        {
            id: chatWindowSearch;
            image1Source: "qrc:/QML_modules/ClientApp/icons/search_icon.png";

            echoMode: 2;
            placeHolder: "Search...";
            width: parent.width * 0.8;

            onAccepted: (value) => 
            {
                console.log("Text Searched: " + value);
            }

            anchors.top: chatText.bottom;
            anchors.topMargin: 20;
            anchors.horizontalCenter: parent.horizontalCenter;
        }

        anchors.top: parent.top;
        anchors.left: parent.left;
        anchors.right: parent.right;
    }

    Rectangle
    {
        id: chatMainSection;
        width: root.width;

        ChatMainSection
        { id: try_me; }

        anchors.top: chatHeaderSection.bottom;
        anchors.bottom: chatBottomSection.top;
    }

    Rectangle 
    {
        id: chatBottomSection;
        width: parent.width;
        height: 50; 

        Rectangle
        {
            id: rectan;
            width: parent.width;
            height: 2; 
            color: "#e3e1e2"; 

            anchors.top: parent.top;
            anchors.horizontalCenter: parent.horizontalCenter;
        }

        Rectangle
        {
            id: shadowEffect;
            width: parent.width;
            height: 10;

            gradient: Gradient
            {
                GradientStop
                {
                    position: 0;
                    color: "#e3e1e2";
                }
                GradientStop
                {
                    position: 1;
                    color: "transparent";
                }
            }

            anchors.top: rectan.bottom;
            anchors.horizontalCenter: parent.horizontalCenter;
        }

        Row 
        {
            id: chatBottomBar;
            width: parent.width;
            height: 50; 

            spacing: 10;

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
            }

            anchors.top: rectan.bottom;
            anchors.topMargin: 5; 
        }

        anchors.bottom: parent.bottom;
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.bottomMargin: 10;
    }
}
