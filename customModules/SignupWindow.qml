import QtQuick;
import QtQuick.Controls;
import QtQuick.Layouts;

Item
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

    ColumnLayout
    {
        id: signupInfo;
        anchors.top: textAboutUs.bottom;
        anchors.topMargin: 10;
        anchors.horizontalCenter: parent.horizontalCenter;
        width: 300;

        spacing: 10;

        InputField
        {
            id: signUpFirstName;
            image1Source: "qrc:/QML/ClientApp/icons/name_icon.png";

            echoMode: TextInput.Normal;
            placeHolder: "First Name";
            width: parent.width;
            height: 40;

            onFocusChanged: 
            {
                if (signUpFirstName.focus) 
                {
                    Qt.callLater(function() { Qt.callJS("scrollIntoView('" + signUpFirstName + "')");});
                }
            }
        }

        InputField
        {
            id: signUpLastName;
            image1Source: "qrc:/QML/ClientApp/icons/name_icon.png";

            echoMode: TextInput.Normal;
            placeHolder: "Last Name";
            width: parent.width;
            height: 40;

            onFocusChanged: 
            {
                if (signUpLastName.focus) 
                {
                    Qt.callLater(function() { Qt.callJS("scrollIntoView('" + signUpLastName + "')");});
                }
            }
        }

        InputField
        {
            id: signUpphone_number;
            image1Source: "qrc:/QML/ClientApp/icons/phone_icon.png";

            echoMode: TextInput.Normal;
            placeHolder: "Phone Number";
            width: parent.width;
            height: 40;

            onFocusChanged: 
            {
                if (signUpphone_number.focus) 
                {
                    Qt.callLater(function() { Qt.callJS("scrollIntoView('" + signUpphone_number + "')");});
                }
            }
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

            onFocusChanged: 
            {
                if (signUpPassword.focus) 
                {
                    Qt.callLater(function() { Qt.callJS("scrollIntoView('" + signUpPassword + "')");});
                }
            }
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

            onFocusChanged: 
            {
                if (signUpPasswordConfirmation.focus) 
                {
                    Qt.callLater(function() { Qt.callJS("scrollIntoView('" + signUpPasswordConfirmation + "')");});
                }
            }
        }

        InputField
        {
            id: secret_question;
            image1Source: "qrc:/QML/ClientApp/icons/question_icon.png";

            echoMode: TextInput.Normal;
            placeHolder: "Secret Question";
            width: parent.width;
            height: 40;

            onFocusChanged: 
            {
                if (secret_question.focus) 
                {
                    Qt.callLater(function() { Qt.callJS("scrollIntoView('" + secret_question + "')");});
                }
            }
        }

        InputField
        {
            id: secret_answer;
            image1Source: "qrc:/QML/ClientApp/icons/answer_icon.png";

            echoMode: TextInput.Normal;
            placeHolder: "Secret Answer";
            width: parent.width;
            height: 40;

            onFocusChanged: 
            {
                if (secret_answer.focus) 
                {
                    Qt.callLater(function() { Qt.callJS("scrollIntoView('" + secret_answer + "')");});
                }
            }
        }
    }

    Rectangle
    {
        id: signUpButton;
        color: mouseArea.pressed ? "#ed7bb4" : "black";
    
        height: 40;
        radius: 15;
        width: 300;

        anchors.top: signupInfo.bottom;
        anchors.topMargin: 10;
        anchors.horizontalCenter: parent.horizontalCenter;
    
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
    }

    RowLayout
    {
        spacing: 10;
        anchors.top: signUpButton.bottom;
        anchors.topMargin: 5;
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
