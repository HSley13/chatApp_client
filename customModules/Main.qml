import QtQuick;
import QtQuick.Controls;
import QtQuick.Window;
import ClientApp;

Rectangle
{
    id: mainWindow;
    anchors.fill: parent;

    MediaController
    {id: media_controller}

    ContactListModel
    {id: contact_list_model}

    GroupListModel
    {id: group_list_model}

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

    StackView
    {
        id: stackView;

        anchors.fill: parent;
        
        initialItem: contactWindow;
    }
}