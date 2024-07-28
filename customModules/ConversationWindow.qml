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
        }

        Rectangle
        {
            id: iconNameStatus;
            width: 40;
            height: 40;

            IconText
            {
                id: customImage;
                imageSource: root.source;
                text: "";
                cWidth: 40;

                onItemClicked:
                {
                    // FIXME: Handle this click properly;
                    console.log("Chat Icon Clicked");
                }

                anchors.fill: parent;
            }

            Column
            {
                spacing: 2;
                width: parent.width * 0.6; 

                Text 
                {
                    id: name;
                    text: root.name;
                    color: "black";
                    font.pixelSize: 16;
                    font.bold: true;
                    elide: Text.ElideRight;
                }

                Text 
                {
                    id: onOffline;
                    text: root.onOffline;
                    color: (text === "Online") ? "green" : "red";
                    font.pixelSize: 10;
                    elide: Text.ElideRight;
                    font.bold: true;
                }

                anchors.left: customImage.right;
                anchors.right: parent.right;
            }

            anchors.verticalCenter: parent.verticalCenter;
            anchors.left: returnImage.right;
            anchors.leftMargin: 5;
        }

        Image
        {
            id: chatSettings;
            source: "qrc:/QML_modules/ClientApp/icons/menu_icon.png";
            property string source2: "qrc:/QML_modules/ClientApp/icons/cancel_menu.png";
            mipmap: true;
            fillMode: Image.PreserveAspectFit;
            width: parent.height * 0.4;
            height: parent.height * 0.4;

            MouseArea
            {
                anchors.fill: parent;

                onClicked: 
                {
                    parent.source = (parent.source.toString() === parent.source2) ? "qrc:/QML_modules/ClientApp/icons/menu_icon.png" : parent.source2;
                    menuPanel.hidden = !menuPanel.hidden;

                    // FIXME: handle click button correctly
                    console.log("Menu Button Click");
                    
                }
            }

            anchors.verticalCenter: parent.verticalCenter;
            anchors.right: parent.right;
            anchors.rightMargin: menuPanel.hidden ? 10 : menuPanel.width;
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
        anchors.bottom: conversationBottomSection.bottom;
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
            cWidth: parent.width * .2;

            onItemClicked:
            {
                // FIXME: Handle this click Properly;
                console.log("Plus Icon Clicked");
            }

            anchors.left: parent.left;     
            anchors.verticalCenter: parent.verticalCenter;
        }

        InputField
        {
            id: new_message;
            image1Source: "";
            echoMode: 0;
            placeHolder: "Type message...";
            width: parent.width * 0.6;

            anchors.centerIn: parent;
            anchors.verticalCenter: parent.verticalCenter;
        }

        IconText
        {
            id: sendMessage;
            imageSource: "qrc:/QML_modules/ClientApp/icons/send_icon.png";
            text: "";
            cWidth: parent.width * .2;

            onItemClicked:
            {
                // FIXME: Handle this click Properly;
                console.log("Send Icon Clicked");
            }

            anchors.right: parent.right;
            anchors.verticalCenter: parent.verticalCenter;
        }

        anchors.bottom: parent.bottom;
    }

    MenuPanel 
    {
        id: menuPanel;

        anchors.right: chatSettings.left
        anchors.top: chatSettings.bottom;


        Component.onCompleted:
        {
            var options = ["Call", "Video Call", "Block"];
            menuPanel.update_options(options);
        }

        x: hidden ? parent.width : parent.width - width;
    }
}