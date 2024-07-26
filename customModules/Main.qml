import QtQuick;
import QtQuick.Controls;
import QtQuick.Window;
import ClientApp;

ApplicationWindow
{
    id: root;
    width: 400;
    height: 500
    visible: true;
    title: "Chat App";

    ChatListModel
    {id: chatListModel}

    ChatInfo
    {id: chatInfo}

    ChatProtocol
    {id: chatProtocol}

    ClientManager
    {id: clientManager}

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
        id: chatListWindow;
        ChatListWindow{}
    }

    StackView
    {
        id: stackView;

        anchors.fill: parent;

        initialItem: loginWindow;
        // initialItem: chatListWindow;
        // initialItem: conversationWindow;
        // initialItem: chatMainSection;
    }
}
