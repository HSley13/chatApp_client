import QtQuick;
import QtQuick.Controls;
import QtQuick.Layouts;

Item
{
    property bool fieldsVisible: false

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
        width: parent.width * 0.6;

        spacing: 10;

        Text
        {
            text: "What is Your name? ";
            font.pixelSize: 14;
            visible: !fieldsVisible;
        }

        InputField
        {
            id: loginPassword;
            image1Source: "qrc:/QML/ClientApp/icons/answer_icon.png";
            visible: !fieldsVisible;

            echoMode: TextInput.Normal;
            placeHolder: "Answer";
            width: parent.width;
            height: 40;
        }

        InputField
        {
            id: newPasswordField;
            visible: fieldsVisible;
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
            visible: fieldsVisible;
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

        width: parent.width * 0.6;
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
                // FIXME: Check wherther the answer is correct or not, then for password
                console.log("Login Button Click");
                fieldsVisible = !fieldsVisible;
            }
        }

        anchors.top: forgottenInfo.bottom;
        anchors.topMargin: 20;
        anchors.horizontalCenter: parent.horizontalCenter;
    }
}
