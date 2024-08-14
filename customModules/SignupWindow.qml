import QtQuick;
import QtQuick.Controls;
import QtQuick.Layouts;

Item
{
    id: root;

    Rectangle
    {
        id: notificationBar;
        visible: false;
        height: 40;
        width:  120;
        color: "#DE02B5";
        opacity: 0.9;
        radius: 10;
    
        Text
        {
            id: notificationText;
            anchors.centerIn: parent;
            color: "white";
            font.bold: true;
            text: "";
        }
    
        Behavior on opacity
        {
            NumberAnimation
            {
                target: notificationBar;
                property: "opacity";
                from: 0;
                to: 0.9;
                duration: 300
            }
        }

        Timer
        {
            id: hideNotificationTimer;
            interval: 5000;
            repeat: false;
            onTriggered: notificationBar.visible = false;
        }
    
        anchors.top: parent.top;
        anchors.margins: 10;
        anchors.left: parent.left;
    }

    Component.onCompleted: 
    {
        client_manager.signup_message_changed.connect(() =>
        {
            notificationText.text = client_manager.signup_message;
            notificationBar.visible = true;
        });
    }

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

    ColumnLayout
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
            id: signUpphone_number;
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

        InputField
        {
            id: secret_question;
            image1Source: "qrc:/QML/ClientApp/icons/question_icon.png";

            echoMode: TextInput.Normal;
            placeHolder: "Secret Question";
            width: parent.width;
            height: 40;
        }

        InputField
        {
            id: secret_answer;
            image1Source: "qrc:/QML/ClientApp/icons/answer_icon.png";

            echoMode: TextInput.Normal;
            placeHolder: "Secret Answer";
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

        onClicked:
        {
            var valid = true;

            if (signUpphone_number.inputField === "")
            {
                signUpphone_number.borderColor = "red";
                valid = false;
            }
            else
                signUpphone_number.borderColor = signUpphone_number.inputField.focus ? "#a10e7a" : "black";

            if (signUpFirstName.inputField === "" || signUpLastName.inputField === "")
            {
                signUpFirstName.borderColor = signUpFirstName.inputField === "" ? "red" : signUpFirstName.inputField.focus ? "#a10e7a" : "black";
                signUpLastName.borderColor = signUpLastName.inputField === "" ? "red" : signUpLastName.inputField.focus ? "#a10e7a" : "black";
                valid = false;
            }
            else
            {
                signUpFirstName.borderColor = signUpFirstName.inputField.focus ? "#a10e7a" : "black";
                signUpLastName.borderColor = signUpLastName.inputField.focus ? "#a10e7a" : "black";
            }

            if (signUpPassword.inputField === "")
            {
                signUpPassword.borderColor = "red";
                valid = false;
            }
            else
                signUpPassword.borderColor = signUpPassword.inputField.focus ? "#a10e7a" : "black";

            if (signUpPasswordConfirmation.inputField === "" || signUpPassword.inputField !== signUpPasswordConfirmation.inputField)
            {
                signUpPasswordConfirmation.borderColor = "red";
                valid = false;
            }
            else
                signUpPasswordConfirmation.borderColor = signUpPasswordConfirmation.inputField.focus ? "#a10e7a" : "black";

            if (secret_question.inputField === "" || secret_answer.inputField === "")
            {
                secret_question.borderColor = secret_question.inputField === "" ? "red" : secret_question.inputField.focus ? "#a10e7a" : "black";
                secret_answer.borderColor = secret_answer.inputField === "" ? "red" : secret_answer.inputField.focus ? "#a10e7a" : "black";
                valid = false;
            }
            else
            {
                secret_question.borderColor = secret_question.inputField.focus ? "#a10e7a" : "black";
                secret_answer.borderColor = secret_answer.inputField.focus ? "#a10e7a" : "black";
            }

            if (valid)
            {
                client_manager.sign_up(signUpphone_number.inputField, signUpFirstName.inputField, signUpLastName.inputField, signUpPassword.inputField, signUpPasswordConfirmation.inputField, secret_question.inputField, secret_answer.inputField);

                signUpphone_number.inputField = "";
                signUpFirstName.inputField = "";
                signUpLastName.inputField = "";
                signUpPassword.inputField = "";
                signUpPasswordConfirmation.inputField = "";
                secret_question.inputField = "";
                secret_answer.inputField = "";
            }
        }
    }

    anchors.top: signupInfo.bottom;
    anchors.topMargin: 20;
    anchors.horizontalCenter: parent.horizontalCenter;
}


    RowLayout
    {
        spacing: 10;
        anchors.top: signUpButton.bottom;
        anchors.topMargin: 10;
        anchors.horizontalCenter: parent.horizontalCenter;
        Layout.fillWidth: true;

        Text
        {
            id: question;
            text: "Already have an Account?";
        }

        RoundedButton
        {
            id: saveInfo;
            text: "LOGIN";
            color: "white";
            Layout.fillWidth: true;
            height: 30;

            onClicked: stackView.replace(loginWindow, StackView.PopTransition);
        }
    }
}