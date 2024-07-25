import QtQuick;
import QtQuick.Controls;
import QtQuick.Window;
import ClientApp;

Rectangle
{

    id: root;
    visible: true;

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
            // FIXME: module to create
            id: iconNameStatus;
            color: "transparent";
            width: parent.width - returnImage.width - chatSettings.width - 40;
            height: parent.height;

            Text
            {
                text: "Icon/Name/Status";
                color: "black";
                anchors.centerIn: parent;
            }

            anchors.verticalCenter: parent.verticalCenter;
            anchors.left: returnImage.right;
            anchors.leftMargin: 10;
            anchors.right: chatSettings.left;
            anchors.rightMargin: 10;
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


                    // FIXME: handle click button correctly
                    console.log("Menu Button Click");
                    
                }
            }

            anchors.verticalCenter: parent.verticalCenter;
            anchors.right: parent.right;
            anchors.rightMargin: 10;
        }

        anchors.top: parent.top;
        anchors.left: parent.left;
        anchors.right: parent.right;
    }



    Rectangle 
    {
        id: conversationMainSection;

        Text
        {
            text: "Main Section";
            color: "black";

            anchors.centerIn: parent;
        }

        anchors.top: conversationHeaderSection.bottom;
        anchors.bottom: conversationBottomSection.bottom;
        anchors.horizontalCenter: parent.horizontalCenter;
    }

    Rectangle 
    {
        id: conversationBottomSection;
        width: parent.width;
        height: 50; 

        Rectangle
        {
            id: convRectan;
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

            anchors.top: convRectan.bottom;
            anchors.horizontalCenter: parent.horizontalCenter;
        }


        Row
        {
            id: conversationBottomBar;
            width: parent.width;
            height: 50;

            // FIXME: add columns --> insert & send message / files / audio  

            IconText
            {
                id: plus;
                imageSource: "qrc:/QML_modules/ClientApp/icons/plus_icon.png";
                image2Source: "qrc:/QML_modules/ClientApp/icons/cancel_icon.png";
                text: "";
                cWidth: parent.width * .2

                onItemClicked:
                {
                    // FIXME: Handle this click Properly;
                    console.log("Plus Icon Clicked");
                }
            }

            InputField
            {
                id: new_message;

                image1Source: "";

                echoMode: 0;
                placeHolder: "Type message...";
                width: parent.width * 0.6;
            }

            IconText
            {
                id: sendMessage;
                imageSource: "qrc:/QML_modules/ClientApp/icons/send_icon.png";
                text: "";
                cWidth: parent.width * .2

                onItemClicked:
                {
                    // FIXME: Handle this click Properly;
                    console.log("Send Icon Clicked");
                }
            }

            anchors.top: convRectan.bottom;
            anchors.topMargin: 5; 
        }

        anchors.bottom: parent.bottom;
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.bottomMargin: 10;
    }

}
