import QtQuick;
import QtQuick.Layouts;
import QtQuick.Controls.Basic;
import Qt5Compat.GraphicalEffects;

Rectangle
{
    Row
    {
        id: message;
        anchors.top: parent.top;
        anchors.left: parent.left;
        anchors.right: parent.right;
        anchors.rightMargin: 20;
        anchors.leftMargin: 20;
        anchors.topMargin: 20;
        spacing: 10;

        height: 50;

        IconText
        {
            id: returnImage;
            imageSource1: "qrc:/QML/ClientApp/icons/back_icon.png";
            height: parent.height * 0.6;
            width: height;

            onItemClicked: stackView.pop();
        }

        Column
        {
            spacing: 3;

            Text
            {
                id: accountText;
                text: "Account";
                font.pixelSize: 16;
                font.bold: true;
                verticalAlignment: Text.AlignTop;
                elide: Text.ElideRight;
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

    Rectangle
    {
        anchors.right: parent.right;
        anchors.left: parent.left;
        anchors.bottom: parent.bottom;
        height: parent.height * 0.8;

        Column
        {
            id: profile;
            anchors.top: parent.top;
            anchors.right: parent.right;
            anchors.left: parent.left;
            anchors.rightMargin: 20;
            anchors.leftMargin: 20;
            anchors.topMargin: 20;
            anchors.bottomMargin: 100;
            height: 150;
            spacing: 15;

            Row
            {
                width: parent.width;
                spacing: 20;

                RoundedImage
                {
                    id: profileImage;
                    imageSource: "https://lumiere-a.akamaihd.net/v1/images/deadpool_wolverine_mobile_640x480_ad8020fd.png";
                    width: 100;
                    height: 100;
                }

                ColumnLayout
                {
                    Layout.fillWidth: true;
                    Layout.preferredHeight: parent.height;
                    Layout.leftMargin: 5;
                    Layout.topMargin: 5;
                    anchors.rightMargin: 5;
                    anchors.verticalCenter: parent.verticalCenter;
                    spacing: 10;

                    Text
                    {
                        text: "Profile Picture";
                        color: "black";
                        font.pixelSize: 14;
                        font.bold: true;
                        verticalAlignment: Text.AlignVCenter;
                    }

                    Text
                    {
                        text: "PNG, JPEG under 10 MB";
                        color: "black";
                        font.pixelSize: 12;
                        verticalAlignment: Text.AlignVCenter;
                        elide: Text.ElideRight;
                    }
                }

                Column
                {
                    anchors.verticalCenter: parent.verticalCenter;
                    spacing: 5;

                    Row
                    {
                        RoundedImage
                        {
                            imageSource: "qrc:/QML/ClientApp/icons/upload_icon.png";
                            width: 40;
                            height: 40;
                        }

                        RoundedButton
                        {
                            text: "Upload";
                            width: text.width;
                            height: 40;
                            color: "white";

                            onClicked:
                            {
                                // FIXME: 
                                console.log("Upload Picture Button Clicked");
                            }
                        }
                    }

                    Row
                    {
                        RoundedImage
                        {
                            imageSource: "qrc:/QML/ClientApp/icons/delete_icon.png";
                            width: 40;
                            height: 40;
                        }

                        RoundedButton
                        {
                            text: "Delete";
                            width: text.width;
                            height: 40;
                            color: "white";

                            onClicked:
                            {
                                // FIXME: 
                                console.log("Delete Picture Button Clicked");
                            }
                        }
                    }
                }
            }

            Row
            {
                width: parent.width * 0.9;
                height: 50;
                spacing: 20;

                InputField
                {
                    image1Source: "qrc:/QML/ClientApp/icons/name_icon.png";
                    echoMode: TextInput.Password;
                    placeHolder: "First Name";
                    width: parent.width * 0.5;
                    height: 40;
                }

                InputField
                {
                    image1Source: "qrc:/QML/ClientApp/icons/name_icon.png";
                    echoMode: TextInput.Password;
                    placeHolder: "Last Name";
                    width: parent.width * 0.5;
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

        Column
        {
            id: password;
            anchors.leftMargin: 20;
            anchors.topMargin: 20;
            anchors.bottomMargin: 100;
            anchors.top: profile.bottom;
            anchors.right: parent.right;
            anchors.left: parent.left;
            height: 80;
            spacing: 10;

            Column
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
                }
            }

            Row
            {
                id: newPassword;
                anchors.margins: 10;
                width: parent.width * 0.9;
                height: 50;
                spacing: 20;

                InputField
                {
                    image1Source: "qrc:/QML/ClientApp/icons/hide_icon.png";
                    image2Source: "qrc:/QML/ClientApp/icons/see_icon.png";
                    echoMode: TextInput.Normal;
                    placeHolder: "New Password";
                    width: parent.width * 0.5;
                    height: 40;
                }

                InputField
                {
                    image1Source: "qrc:/QML/ClientApp/icons/hide_icon.png";
                    image2Source: "qrc:/QML/ClientApp/icons/see_icon.png";
                    echoMode: TextInput.Normal;
                    placeHolder: "Confirmation";
                    width: parent.width * 0.5;
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

        Row
        {
            id: savingRow;
            anchors.top: password.bottom;
            anchors.right: parent.right;
            anchors.rightMargin: 20;
            anchors.topMargin: 20;
            anchors.bottomMargin: 100;
            spacing: 1;

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
                width: text.width;
                height: 40;

                onClicked:
                {
                    // FIXME: 
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

        Row
        {
            id: logoutRow;
            anchors.top: savingRow.bottom;
            anchors.topMargin: 50;
            anchors.horizontalCenter: parent.horizontalCenter;
            spacing: 1;

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
                width: text.width;
                height: 50;

                onClicked:
                {
                    // FIXME: 
                    console.log("Log out Button Clicked");
                }
            }
        }
    }
}