import QtQuick;
import QtQuick.Layouts;
import QtQuick.Controls.Basic;
import Qt5Compat.GraphicalEffects;

Rectangle
{
    anchors.fill: parent;

    RowLayout
    {
        id: message;
        anchors.top: parent.top;
        anchors.left: parent.left;
        anchors.right: parent.right;
        anchors.margins: 20;
        spacing: 10;

        IconText
        {
            id: returnImage;
            imageSource1: "qrc:/QML/ClientApp/icons/back_icon.png";
            height: 30
            width: height;

            onItemClicked: stackView.pop();
        }

        ColumnLayout
        {
            spacing: 3;
            Layout.fillWidth: true;

            Text
            {
                id: accountText;
                text: "Account";
                font.pixelSize: 16;
                font.bold: true;
                verticalAlignment: Text.AlignTop;
                elide: Text.ElideRight;
                Layout.fillWidth: true;
            }

            Text
            {
                id: text1;
                text: "Real Time information and Activities of your property";
                font.pixelSize: 12;
                color: "black";
                clip: true;
                wrapMode: Text.Wrap;
                verticalAlignment: Text.AlignTop;
                elide: Text.ElideRight;
                Layout.fillWidth: true;
            }
        }
    }

    Rectangle
    {
        width: parent.width;
        height: 1;
        color: "lightgray";
        anchors.top: message.bottom;
        anchors.left: parent.left;
        anchors.right: parent.right;
        anchors.margins: 10;

        DropShadow
        {
            anchors.fill: parent;
            color: "gray";
            radius: 2;
            samples: 16;
            horizontalOffset: 0;
            verticalOffset: 1;
        }
    }

    ColumnLayout
    {
        id: profile;
        anchors.top: message.bottom;
        anchors.left: parent.left;
        anchors.right: parent.right;
        anchors.margins: 20;
        spacing: 15;

        RowLayout
        {
            spacing: 20;
            Layout.fillWidth: true;

            RoundedImage
            {
                id: profileImage;
                imageSource: "https://lumiere-a.akamaihd.net/v1/images/deadpool_wolverine_mobile_640x480_ad8020fd.png";
                width: 100;
                height: 100;
            }

            ColumnLayout
            {
                spacing: 10;
                Layout.fillWidth: true;
                Layout.alignment: Qt.AlignVCenter;

                Text
                {
                    text: "Profile Picture";
                    color: "black";
                    font.pixelSize: 14;
                    font.bold: true;
                    Layout.fillWidth: true;
                }

                Text
                {
                    text: "PNG, JPEG under 10 MB";
                    color: "black";
                    font.pixelSize: 12;
                    elide: Text.ElideRight;
                    Layout.fillWidth: true;
                }
            }

            ColumnLayout
            {
                spacing: 5;
                Layout.fillWidth: true;
                Layout.alignment: Qt.AlignVCenter;

                RowLayout
                {
                    spacing: 10;

                    RoundedImage
                    {
                        imageSource: "qrc:/QML/ClientApp/icons/upload_icon.png";
                        width: 40;
                        height: 40;
                    }

                    RoundedButton
                    {
                        text: "Upload";
                        color: "white";
                        Layout.fillWidth: true;

                        onClicked:
                        {
                            console.log("Upload Picture Button Clicked");
                        }
                    }
                }

                RowLayout
                {
                    spacing: 10;

                    RoundedImage
                    {
                        imageSource: "qrc:/QML/ClientApp/icons/delete_icon.png";
                        width: 40;
                        height: 40;
                    }

                    RoundedButton
                    {
                        text: "Delete";
                        color: "white";
                        Layout.fillWidth: true;

                        onClicked:
                        {
                            console.log("Delete Picture Button Clicked");
                        }
                    }
                }
            }
        }

        RowLayout
        {
            spacing: 20;
            Layout.fillWidth: true;

            InputField
            {
                image1Source: "qrc:/QML/ClientApp/icons/name_icon.png";
                echoMode: TextInput.Normal;
                placeHolder: "First Name";
                Layout.fillWidth: true;
                height: 40;
            }

            InputField
            {
                image1Source: "qrc:/QML/ClientApp/icons/name_icon.png";
                echoMode: TextInput.Normal;
                placeHolder: "Last Name";
                Layout.fillWidth: true;
                height: 40;
            }
        }
    }

    Rectangle
    {
        width: parent.width;
        height: 1;
        color: "lightgray";
        anchors.top: profile.bottom;
        anchors.left: parent.left;
        anchors.right: parent.right;
        anchors.margins: 10;

        DropShadow
        {
            anchors.fill: parent;
            color: "gray";
            radius: 2;
            samples: 16;
            horizontalOffset: 0;
            verticalOffset: 1;
        }
    }

    ColumnLayout
    {
        id: password;
        spacing: 10;
        anchors.margins: 20;
        anchors.top: profile.bottom;
        anchors.left: parent.left;
        anchors.right: parent.right;
        Layout.fillWidth: true;

        ColumnLayout
        {
            spacing: 3;

            Text
            {
                id: passwordText;
                text: "Password";
                font.pixelSize: 16;
                font.bold: true;
                verticalAlignment: Text.AlignTop;
                elide: Text.ElideRight;
                Layout.fillWidth: true;
            }

            Text
            {
                id: text2;
                text: "Modify your current Password";
                font.pixelSize: 12;
                color: "black";
                clip: true;
                wrapMode: Text.Wrap;
                verticalAlignment: Text.AlignTop;
                elide: Text.ElideRight;
                Layout.fillWidth: true;
            }
        }

        RowLayout
        {
            spacing: 20;
            Layout.fillWidth: true;

            InputField
            {
                image1Source: "qrc:/QML/ClientApp/icons/hide_icon.png";
                image2Source: "qrc:/QML/ClientApp/icons/see_icon.png";
                echoMode: TextInput.Password;
                placeHolder: "New Password";
                Layout.fillWidth: true;
                height: 40;
            }

            InputField
            {
                image1Source: "qrc:/QML/ClientApp/icons/hide_icon.png";
                image2Source: "qrc:/QML/ClientApp/icons/see_icon.png";
                echoMode: TextInput.Password;
                placeHolder: "Confirmation";
                Layout.fillWidth: true;
                height: 40;
            }
        }
    }

    Rectangle
    {
        width: parent.width;
        height: 1;
        color: "lightgray";
        anchors.top: password.bottom;
        anchors.left: parent.left;
        anchors.right: parent.right;
        anchors.margins: 10;

        DropShadow
        {
            anchors.fill: parent;
            color: "gray";
            radius: 2;
            samples: 16;
            horizontalOffset: 0;
            verticalOffset: 1;
        }
    }

    RowLayout
    {
        id: savingRow;
        spacing: 10;
        anchors.top: password.bottom;
        anchors.right: parent.right;
        anchors.rightMargin: 20;
        anchors.topMargin: 20;
        anchors.bottomMargin: 100;
        Layout.fillWidth: true;

        RoundedImage
        {
            id: saveImage;
            imageSource: "qrc:/QML/ClientApp/icons/save_icon.png";
            width: 40;
            height: 40;
        }

        RoundedButton
        {
            id: saveInfo;
            text: "Save Info";
            color: "white";
            Layout.fillWidth: true;
            height: 40;

            onClicked:
            {
                console.log("Save Info Button Clicked");
            }
        }
    }

    Rectangle
    {
        width: parent.width;
        height: 1;
        color: "lightgray";
        anchors.top: savingRow.bottom;
        anchors.left: parent.left;
        anchors.right: parent.right;
        anchors.margins: 10;

        DropShadow
        {
            anchors.fill: parent;
            color: "gray";
            radius: 2;
            samples: 16;
            horizontalOffset: 0;
            verticalOffset: 1;
        }
    }

    RowLayout
    {
        id: logoutRow;
        spacing: 10;
        anchors.top: savingRow.bottom;
        anchors.topMargin: 50;
        anchors.horizontalCenter: parent.horizontalCenter;
        Layout.fillWidth: true;

        RoundedImage
        {
            id: logoutImage;
            imageSource: "qrc:/QML/ClientApp/icons/logout_icon.png";
            width: 50;
            height: 50;
        }

        RoundedButton
        {
            id: logout;
            text: "Log Out";
            color: "white";
            Layout.fillWidth: true;
            height: 50;

            onClicked:
            {
                console.log("Log out Button Clicked");
            }
        }
    }
}