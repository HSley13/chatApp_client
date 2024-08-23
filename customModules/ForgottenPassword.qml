import QtQuick;
import QtQuick.Controls;
import QtQuick.Layouts;

Item
{
    property int clickCount: 0;

    IconText
    {
        id: returnImage;
        imageSource1: "qrc:/QML/ClientApp/icons/back_icon.png";
        height: 30;
        width: height;
        onItemClicked: stackView.replace(loginWindow, StackView.PopTransition);

        anchors.top: parent.top;
        anchors.margins: 10;
        anchors.left: parent.left;
    }

    Image
    {
        id: forgottenIcon;
        mipmap: true;
        fillMode: Image.PreserveAspectFit;

        anchors.top: parent.top;
        anchors.topMargin: 10;
        anchors.horizontalCenter: parent.horizontalCenter;

        width: 250;
        height: 250;

        source: "qrc:/QML/ClientApp/icons/forgotten_icon.png";
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

        anchors.top: forgottenIcon.bottom;
        anchors.horizontalCenter: parent.horizontalCenter;
    }

    Text
    {
        id: textAboutUs;
        text: "Please Provide us with the following information to reset your password";

        wrapMode: Text.WrapAtWordBoundaryOrAnywhere;
        font.bold: true;
        font.pixelSize: 12;

        leftPadding: 15;
        rightPadding: 15;

        anchors.top: textWelcome.bottom;
        anchors.topMargin: 5;
        anchors.horizontalCenter: parent.horizontalCenter;
    }

    ColumnLayout
    {
        id: forgottenInfo;
        anchors.top: textAboutUs.bottom;
        anchors.topMargin: 10;
        anchors.horizontalCenter: parent.horizontalCenter;
        width: 300;

        spacing: 10;

        InputField
        {
            id: phoneNumber;
            image1Source: "qrc:/QML/ClientApp/icons/answer_icon.png";
            visible: clickCount === 0;

            echoMode: TextInput.Normal;
            placeHolder: "Phone Number";
            width: parent.width;
            height: 40;
        }

        Text
        {
            id: secretQuestion;
            text: contact_list_model.main_user.secret_question;
            font.pixelSize: 14;
            visible: clickCount === 1;
        }

        InputField
        {
            id: answer;
            image1Source: "qrc:/QML/ClientApp/icons/answer_icon.png";
            visible: clickCount === 1;

            echoMode: TextInput.Normal;
            placeHolder: "Answer";
            width: parent.width;
            height: 40;
        }

        InputField
        {
            id: newPasswordField;
            visible: clickCount === 2;
            image1Source: "qrc:/QML/ClientApp/icons/hide_icon.png";
            image2Source: "qrc:/QML/ClientApp/icons/see_icon.png";

            echoMode: TextInput.Password;
            placeHolder: "New Password";
            width: parent.width;
            height: 40;
        }

        InputField
        {
            id: confirmPasswordField;
            visible: clickCount === 2;
            image1Source: "qrc:/QML/ClientApp/icons/hide_icon.png";
            image2Source: "qrc:/QML/ClientApp/icons/see_icon.png";

            echoMode: TextInput.Password;
            placeHolder: "Confirm Password";
            width: parent.width;
            height: 40;
        }
    }

    Rectangle
    {
        id: loginButton;
        color: mouseArea.pressed ? "#ed7bb4" : "black";

        width: 300;
        height: 50;
        radius: 15;

        Text
        {
            text: "CONFIRM";
            color: "white";

            anchors.centerIn: parent;
        }

        MouseArea
        {
            id: mouseArea;
            anchors.fill: parent;

            onClicked: 
            {
                if (clickCount === 0 && phoneNumber.inputField !== "")
                {
                    client_manager.retrieve_question(phoneNumber.inputField);
                    clickCount = 1;
                }
                else if (clickCount === 1 && answer.inputField !== "")
                {
                    if (answer.inputField === contact_list_model.main_user.secret_answer)
                        clickCount = 2;
                    else
                        answer.borderColor =  "red";
                }
                else if (clickCount === 2)
                {
                    var valid = true;

                    if (newPasswordField.inputField === "")
                    {
                        newPasswordField.borderColor = "red";
                        valid = false;
                    }
                    else
                        newPasswordField.borderColor = newPasswordField.inputField.focus ? "#a10e7a" : "black";

                    if (confirmPasswordField.inputField === "" || newPasswordField.inputField !== confirmPasswordField.inputField)
                    {
                        confirmPasswordField.borderColor = "red";
                        valid = false;
                    }
                    else
                        confirmPasswordField.borderColor = confirmPasswordField.inputField.focus ? "#a10e7a" : "black";
                     
                    if(valid)
                        client_manager.update_password(phoneNumber.inputField, password.inputField);
                }
            }
        }

        anchors.top: forgottenInfo.bottom;
        anchors.topMargin: 20;
        anchors.horizontalCenter: parent.horizontalCenter;
    }
}