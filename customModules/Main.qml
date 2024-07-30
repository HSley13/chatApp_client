import QtQuick;
import QtQuick.Controls;
import QtQuick.Window;
import ClientApp;

ApplicationWindow
{
    id: root;
    width: 400;
    height: 500;
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

    AudioController
    {id: audioController}

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
        id: conversationWindow
        ConversationWindow{}
    }

    StackView
    {
        id: stackView;

        anchors.fill: parent;

        initialItem: loginWindow;
        // initialItem: chatWindow;
    }
}
