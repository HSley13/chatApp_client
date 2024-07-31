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

    ContactList
    {id: contact_list}

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

    StackView
    {
        id: stackView;

        anchors.fill: parent;
        
        initialItem: loginWindow;
    }
}
