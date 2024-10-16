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
        anchors.topMargin: 10;
        anchors.horizontalCenter: parent.horizontalCenter;

        width: 300;
        height: 300;
        
        source: "qrc:/QML/ClientApp/icons/hi_icon.png";
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

    ColumnLayout
    {
        id: loginInfo;
        anchors.top: textAboutUs.bottom;
        anchors.topMargin: 10;
        anchors.horizontalCenter: parent.horizontalCenter;
        width: 300;

        spacing: 10;

        InputField
        {
            id: loginPhoneNumber;
            image1Source: "qrc:/QML/ClientApp/icons/phone_icon.png";

            echoMode: TextInput.Normal;
            placeHolder: "Phone Number";
            width: parent.width;
            height: 40;
        }

        InputField
        {
            id: loginPassword;
            image1Source: "qrc:/QML/ClientApp/icons/hide_icon.png";
            image2Source: "qrc:/QML/ClientApp/icons/see_icon.png";

            echoMode: TextInput.Password;
            placeHolder: "Password";
            width: parent.width;
            height: 40;
        }
    }

    Rectangle
    {
        id: passwordForgotten;
        color: "transparent";

        height: 30;
        width: 300;

        Text
        {
            anchors.centerIn: parent;
            text: "Password Forgotten";
            font.bold: true;
            color: "#DE02B5";
        }

        MouseArea
        {
            anchors.fill: parent;

            onClicked: stackView.push(forgottenPassword);
        }

        anchors.top: loginInfo.bottom;
        anchors.topMargin: 10;
        anchors.horizontalCenter: parent.horizontalCenter;
    }

    Rectangle
    {
        id: loginButton;
        color: mouseArea.pressed ? "#ed7bb4" : "black";

        width: 300;
        height: 40;
        radius: 15;

        Text
        {
            text: "LOGIN";
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

                if(loginPhoneNumber.inputField === "")
                {
                   loginPhoneNumber.borderColor = "red";
                   valid = false;
                }
                else
                loginPhoneNumber.borderColor = loginPhoneNumber.inputField.focus ? "#a10e7a" : "black";

                if(loginPassword.inputField === "")
                {
                   loginPassword.borderColor = "red";
                   valid = false;
                }
                else
                loginPassword.borderColor = loginPassword.inputField.focus ? "#a10e7a" : "black";

                if(valid)
                {
                   client_manager.login_request(loginPhoneNumber.inputField, loginPassword.inputField);

                   loginPhoneNumber.inputField = "";
                   loginPassword.inputField = "";
                }
            }
        }

        anchors.top: passwordForgotten.bottom;
        anchors.topMargin: 20;
        anchors.horizontalCenter: parent.horizontalCenter;
    }

    RowLayout
    {
        id: rowLayout;
        spacing: 10;
        anchors.top: loginButton.bottom;
        anchors.topMargin: 10;
        anchors.horizontalCenter: parent.horizontalCenter;
        Layout.fillWidth: true;

        Text
        {
            id: question;
            text: "Don't have an Account?";
        }

        RoundedButton
        {
            id: saveInfo;
            text: "SIGN UP";
            color: "white";
            Layout.fillWidth: true;
            height: 30;

            onClicked: stackView.push(signUpWindow);
        }
    }

    Component.onCompleted: 
    {
        contact_list_model.main_user.login_status_changed.connect(() => {
            if(contact_list_model.main_user.login_status === true)
                stackView.push(contactWindow)
            else
            {
                loginPassword.borderColor = "red";
                loginPhoneNumber.borderColor = "red";
            }
        });
    }
}
