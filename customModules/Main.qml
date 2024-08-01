import QtQuick;
import QtQuick.Controls;
import QtQuick.Window;
import ClientApp;

ApplicationWindow
{
    id: mainWindow;
    width: 400;
    height: 700;
    visible: true;
    title: "Chat App";
    color: "transparent";

    AudioController
    {id: audio_controller}

    ContactListModel
    {id: contact_list_model}

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
        id: settingWindow;
        SettingWindow{}
    }

    StackView
    {
        id: stackView;

        anchors.fill: parent;
        
        initialItem: loginWindow;
    }
}
