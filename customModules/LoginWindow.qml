import QtQuick;
import QtQuick.Controls;
import QtQuick.Window;

Rectangle 
{
    id: root;

    Image 
    {
        id: welcomeImage;

        mipmap: true;
        fillMode: Image.PreserveAspectFit;

        anchors.top: parent.top;
        anchors.topMargin: 10;
        anchors.horizontalCenter: parent.horizontalCenter;

        width: 300;
        height: 300;

        source: "qrc:/QML_modules/ClientApp/icons/hi_icon.png";
    }

    Text 
    {
        id: textWelcome;

        text: "WELCOME BACK,";
        wrapMode: Text.WrapAtWordBoundaryOrAnywhere;
        font.bold: true;
        font.pixelSize: 30;

        leftPadding: 15;
        rightPadding: 15;

        anchors.top: welcomeImage.bottom;
        anchors.horizontalCenter: parent.horizontalCenter;
    }

    Text 
    {
        id: textAboutUs;
        text: "Fast & Reliable: 2 Adjectives that best describe US";

        wrapMode: Text.WrapAtWordBoundaryOrAnywhere;
        font.bold: true;
        font.pixelSize: 10;

        leftPadding: 15;
        rightPadding: 15;

        anchors.top: textWelcome.bottom;
        anchors.topMargin: 5;
        anchors.horizontalCenter: parent.horizontalCenter;
    }

    InputField 
    {
        id: loginPhoneNumber;
        image1Source: "qrc:/QML_modules/ClientApp/icons/phone_icon.png";

        echoMode: 0;
        placeHolder: "Phone Number";
        width: parent.width * 0.6;

        anchors.top: textAboutUs.bottom;
        anchors.topMargin: 20;
        anchors.horizontalCenter: parent.horizontalCenter;
    }

    InputField 
    {
        id: loginPassword;
        image1Source: "qrc:/QML_modules/ClientApp/icons/hide_icon.png";
        image2Source: "qrc:/QML_modules/ClientApp/icons/see_icon.png";

        echoMode: 2;
        placeHolder: "Password";
        width: parent.width * 0.6;

        anchors.top: loginPhoneNumber.bottom;
        anchors.topMargin: 20;
        anchors.horizontalCenter: parent.horizontalCenter;
    }

    Rectangle 
    {
        id: passwordForgotten;
        color: "transparent";

        height: 30;
        width: parent.width * 0.6;

        Text 
        {
            anchors.centerIn: parent;
            text: "Forget Password";
            font.bold: true;
            color: "#DE02B5";
        }

        MouseArea 
        {
            anchors.fill: parent;

            // FIXME: handle click button correctly
            onClicked: console.log("Forget Password Button Click");
        }

        anchors.top: loginPassword.bottom;
        anchors.topMargin: 30;
        anchors.horizontalCenter: parent.horizontalCenter;
    }

    Rectangle 
    {
        id: loginButton;
        color: "black";

        radius: 20;
        width: parent.width * 0.6;
        height: 50;

        Text 
        {
            text: "LOGIN";
            color: "white";

            anchors.centerIn: parent;
        }

        MouseArea 
        {
            anchors.fill: parent;

            onPressed: parent.color = "#ed7bb4";
            onReleased: parent.color = "black";

            // FIXME: handle click button correctly
            onClicked: console.log("Login Button Click");
        }

        anchors.top: passwordForgotten.bottom;
        anchors.topMargin: 30;
        anchors.horizontalCenter: parent.horizontalCenter;
    }

 
    Row 
    {
        id: rowLayout;
        
        spacing: 10;

        Text 
        {
            id: question;
            text: "Don't have an Account?";
        }

        Rectangle 
        {
            id: signUp;
            color: "transparent";

            width: question.width * .5;
            height: 20;

            Text 
            {
                id: signUpText;
                text: "SIGN UP";
                color: "#DE02B5";
                font.bold: true;
                leftPadding: 5;

                anchors.centerIn: parent;
            }

            MouseArea 
            {
                anchors.fill: parent;
                onClicked: stackView.push(signUpWindow);
            }
        }

        anchors.top: loginButton.bottom;
        anchors.topMargin: 30;
        anchors.horizontalCenter: parent.horizontalCenter;
    }

    Rectangle 
    {
        id: chatWindowButton;
        color: "transparent";

        height: 20;
        width: question.width * .5;

        Text 
        {
            id: chatWindowText;
            text: "Chat Window";
            color: "#DE02B5";
            font.bold: true;
            leftPadding: 5;

            anchors.centerIn: parent;
        }

        MouseArea 
        {
            anchors.fill: parent;
            onClicked: stackView.push(chatListWindow);
        }

        anchors.top: rowLayout.bottom;
        anchors.topMargin: 10;
        anchors.left: rowLayout.left;
        anchors.right: rowLayout.right;
    }

}