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

        text: "GET ON BOARD,";
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
        text: "Create your Profile and Start the Journey with US";

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
        id: signUpFirstName;
        image1Source: "qrc:/QML_modules/ClientApp/icons/name_icon.png";

        echoMode: 0;
        placeHolder: "First Name";
        width: parent.width * 0.6;

        anchors.top: textAboutUs.bottom;
        anchors.topMargin: 10;
        anchors.horizontalCenter: parent.horizontalCenter;
    }

    InputField 
    {
        id: signUpLastName;
        image1Source: "qrc:/QML_modules/ClientApp/icons/name_icon.png";

        echoMode: 0;
        placeHolder: "Last Name";
        width: parent.width * 0.6;

        anchors.top: signUpFirstName.bottom;
        anchors.topMargin: 10;
        anchors.horizontalCenter: parent.horizontalCenter;
    }

    InputField 
    {
        id: signUpPhoneNumber;
        image1Source: "qrc:/QML_modules/ClientApp/icons/phone_icon.png";

        echoMode: 0;
        placeHolder: "Phone Number";
        width: parent.width * 0.6;

        anchors.top: signUpLastName.bottom;
        anchors.topMargin: 10;
        anchors.horizontalCenter: parent.horizontalCenter;
    }

    InputField 
    {
        id: signUpPassword;
        image1Source: "qrc:/QML_modules/ClientApp/icons/hide_icon.png";
        image2Source: "qrc:/QML_modules/ClientApp/icons/see_icon.png";

        echoMode: 2;
        placeHolder: "Password";
        width: parent.width * 0.6;

        anchors.top: signUpPhoneNumber.bottom;
        anchors.topMargin: 10;
        anchors.horizontalCenter: parent.horizontalCenter;
    }

    InputField 
    {
        id: signUpPasswordConfirmation;
        image1Source: "qrc:/QML_modules/ClientApp/icons/hide_icon.png";
        image2Source: "qrc:/QML_modules/ClientApp/icons/see_icon.png";

        echoMode: 2;
        placeHolder: "Password Confirmation";
        width: parent.width * 0.6;

        anchors.top: signUpPassword.bottom;
        anchors.topMargin: 10;
        anchors.horizontalCenter: parent.horizontalCenter;
    }

    Rectangle 
    {
        id: signUpButton;
        color: "black";

        radius: 5;
        width: parent.width * 0.6;
        height: 50;

        Text 
        {
            text: "SIGN UP";
            color: "white";

            anchors.centerIn: parent;
        }

        MouseArea 
        {
            anchors.fill: parent;

            onPressed: parent.color = "#ed7bb4";
            onReleased: parent.color = "black";


            // FIXME: handle click button correctly
            onClicked: console.log("Sign Up Button Click");
        }

        anchors.top: signUpPasswordConfirmation.bottom;
        anchors.topMargin: 20;
        anchors.horizontalCenter: parent.horizontalCenter;
    }
 
    Row 
    {
        spacing: 10;

        Text 
        {
            id: question;
            text: "Already have an Account?";
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
                text: "LOGIN";
                color: "#DE02B5";
                font.bold: true;
                leftPadding: 5;

                anchors.centerIn: parent;
            }

            MouseArea 
            {
                anchors.fill: parent;

                onClicked: stackView.replace(loginWindow, StackView.PopTransition);
            }
        }

        anchors.top: signUpButton.bottom;
        anchors.topMargin: 20;
        anchors.horizontalCenter: parent.horizontalCenter;
    }
}