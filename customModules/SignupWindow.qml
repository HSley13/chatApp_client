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
        anchors.topMargin: 5;
        anchors.horizontalCenter: parent.horizontalCenter;

        width: 250;
        height: 250;

        source: "qrc:/QML/ClientApp/icons/hi_icon.png";
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

    Column
    {
        id: signupInfo;

        anchors.top: textAboutUs.bottom;
        anchors.topMargin: 10;
        anchors.horizontalCenter: parent.horizontalCenter;
        width: parent.width * 0.6; 

        spacing: 10;

        InputField 
        {
            id: signUpFirstName;
            image1Source: "qrc:/QML/ClientApp/icons/name_icon.png";

            echoMode: TextInput.Normal;
            placeHolder: "First Name";
            width: parent.width;
            height: 40;
        }

        InputField 
        {
            id: signUpLastName;
            image1Source: "qrc:/QML/ClientApp/icons/name_icon.png";

            echoMode: TextInput.Normal;
            placeHolder: "Last Name";
            width: parent.width;
            height: 40;
        }

        InputField 
        {
            id: signUpPhoneNumber;
            image1Source: "qrc:/QML/ClientApp/icons/phone_icon.png";

            echoMode: TextInput.Normal;
            placeHolder: "Phone Number";
            width: parent.width;
            height: 40;
        }

        InputField 
        {
            id: signUpPassword;
            image1Source: "qrc:/QML/ClientApp/icons/hide_icon.png";
            image2Source: "qrc:/QML/ClientApp/icons/see_icon.png";

            echoMode: TextInput.Password;
            placeHolder: "Password";
            width: parent.width;
            height: 40;
        }

        InputField 
        {
            id: signUpPasswordConfirmation;
            image1Source: "qrc:/QML/ClientApp/icons/hide_icon.png";
            image2Source: "qrc:/QML/ClientApp/icons/see_icon.png";

            echoMode: TextInput.Password;
            placeHolder: "Password Confirmation";
            width: parent.width;
            height: 40;
        }
    }

    Rectangle 
    {
        id: signUpButton;
        color: mouseArea.pressed ? "#ed7bb4" : "black";

        width: parent.width * 0.6;
        height: 50;
        radius: 15;

        Text 
        {
            text: "SIGN UP";
            color: "white";

            anchors.centerIn: parent;
        }

        MouseArea 
        {
            id: mouseArea;
            anchors.fill: parent;

            // FIXME: handle click button correctly
            onClicked: console.log("Sign Up Button Click");
        }

        anchors.top: signupInfo.bottom;
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

            width: question.width * 0.5;
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
        anchors.topMargin: 10;
        anchors.horizontalCenter: parent.horizontalCenter;
    }
}
