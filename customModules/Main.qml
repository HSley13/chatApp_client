import QtQuick;
import QtQuick.Controls;
import QtQuick.Window;
import ClientApp;

ScrollView
{
    id: mainWindow;
    anchors.fill: parent;

    MediaController
    {id: media_controller}

    ContactListModel
    {id: contact_list_model}

    GroupListModel
    {id: group_list_model}

    ClientManager
    {id: client_manager}

    Component
    {
        id: loginWindow;
        LoginWindow{}
    }

    Component
    {
        id: signUpWindow;
        SignUpWindow{}
    }

    Component
    {
        id: chatWindow;
        ChatWindow{}
    }

    Component
    {
        id: contactWindow
        ContactWindow{}
    }

    Component
    {
        id: contactList;
        ContactList{}
    }

    Component
    {
        id: groupList;
        GroupList{}
    }

    Component
    {
        id: groupChatWindow
        GroupChatWindow{}
    }

    Component
    {
        id: settingWindow;
        SettingWindow{}
    }

    Component
    {
        id: forgottenPassword;
        ForgottenPassword{}
    }

    StackView
    {
        id: stackView;

        anchors.fill: parent;

        initialItem: loginWindow;

        Popup 
        {
            id: popup;
            modal: false;
            focus: false;
            property alias text: txt.text;

            closePolicy: Popup.NoAutoClose;

            margins: 5;

            Timer 
            {
                id: timer;
                interval: 3000;
                running: true;
                repeat: false;
                onTriggered: popup.close();
            }

            contentItem: Rectangle 
            {
                implicitWidth: txt.implicitWidth;
                implicitHeight: txt.implicitHeight;

                radius: 10;
                color: "lightgray";

                anchors.fill: parent;

                Text 
                {
                    id: txt;
                    color: "#DE02B5";
                    anchors.centerIn: parent;
                }

                MouseArea 
                {
                    anchors.fill: parent;
                    onClicked: popup.close();
                }
            }

            onOpened:  timer.start();
        }

        Component.onCompleted: 
        {
            contact_list_model.main_user.popup_message_changed.connect(() => {
                popup.text = contact_list_model.main_user.popup_message;
                popup.open();
            });
        }
    }
}