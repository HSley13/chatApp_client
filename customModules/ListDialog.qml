import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Dialog
{
    id: root;

    property string titles: "";
    property alias inputField: textInput.inputField;
    property bool input: false;
    property var selectedItems: [];
    property var model;
    property bool checkable: false;
    property string placeHolder: "";

    signal dialogAccepted();
    signal dialogRejected();

    onAccepted: dialogAccepted();
    onRejected: dialogRejected();

    title: titles;
    modal: true;
    width: 300;
    height: 400;
    anchors.centerIn: parent;

    background: Rectangle
    {
        color: "gray";
        radius: 15;
        border.color: "white";
    }

    contentItem: ColumnLayout
    {
        spacing: 10;

        InputField
        {
            id: textInput;
            image1Source: "";
            echoMode: TextInput.Normal;
            placeHolder: root.placeHolder;
            Layout.fillWidth: true;
            height: 30;
            visible: root.input;
        }

        ListView
        {
            id: membersList;
            Layout.fillWidth: true;
            Layout.fillHeight: true;
            model: root.model;
            clip: true;
            spacing: 10;

            delegate: Item
            {
                width: parent.width;
                height: 40;

                property string statusIconSource: status ? "qrc:/QML/ClientApp/icons/online_icon.png" : "qrc:/QML/ClientApp/icons/offline_icon.png";


                Rectangle
                {
                    id: hoverBackground;
                    width: mouseArea.containsMouse ? parent.width : 0;
                    height: parent.height;

                    anchors.left: parent.left;
                    anchors.leftMargin: profileImage.width / 2;

                    Behavior on width { SmoothedAnimation { duration: 450; } }

                    gradient: Gradient
                    {
                        orientation: Gradient.Horizontal;

                        GradientStop { position: 0.0; color: "transparent"; }
                        GradientStop { position: 0.5; color: "#ed7bb4"; }
                        GradientStop { position: 1.0; color: "transparent"; }
                    }
                }

                RowLayout
                {
                    width: parent.width;
                    height: parent.height;
                    spacing: 10;

                    CheckBox
                    {
                        id: checkBox;
                        visible: root.checkable;
                        checked: false;

                        onCheckedChanged: (checked) ? root.selectedItems.push(contact_info) : root.selectedItems.splice(root.selectedItems.indexOf(contact_info), 1);
                    }

                    RowLayout
                    {
                        width: parent.width * 0.8;
                        height: parent.height;
                        spacing: 5;

                        Item
                        {
                            width: 40;
                            height: width;

                            RoundedImage
                            {
                                id: profileImage;
                                imageSource: image_url;
                                width: parent.width;
                                height: parent.height;
                            }

                            Image
                            {
                                id: statusDot;
                                source: statusIconSource;
                                width: 10;
                                height: 10;
                                anchors.bottom: profileImage.bottom;
                                anchors.right: profileImage.right;
                                anchors.margins: 2;
                            }
                        }

                        ColumnLayout
                        {
                            Layout.fillWidth: true;
                            Layout.preferredHeight: parent.height;
                            Layout.leftMargin: 4;
                            spacing: 2;
                            Layout.topMargin: 3;

                            Text
                            {
                                text: name;
                                color: "black";
                                font.pixelSize: 12;
                                Layout.fillWidth: true;
                                Layout.fillHeight: true;
                                verticalAlignment: Text.AlignTop;
                            }

                            Text
                            {
                                text: phone_number;
                                color: "black";
                                font.pixelSize: 10;
                                Layout.fillWidth: true;
                                Layout.fillHeight: true;
                                verticalAlignment: Text.AlignTop;
                                elide: Text.ElideRight;
                            }
                        }

                        MouseArea
                        {
                            id: mouseArea;
                            anchors.fill: parent;
                            hoverEnabled: true;

                            onClicked:
                            {
                                contact_list_model.active_chat = contact_list_model.contact_proxy_list.get(index);
                                stackView.push(chatWindow);
                                root.accept();
                            }
                        }
                    }
                }
            }
        }   

        Rectangle
        {
            width: parent.width;
            height: 30;
            color: "transparent";

            Button
            {
                text: "OK";
                onClicked: root.accept();
                
                anchors.left: parent.left;
            }

            Button
            {
                text: "Cancel";
                onClicked: root.reject();

                anchors.right: parent.right;
            }
        }
    }
}