import QtQuick;
import QtQuick.Controls;
import QtQuick.Window;
import ClientApp;

ApplicationWindow
{
    id: root;
    width: 480;
    height: 700
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

    ChatWindow
    {id: chatWindow}

    ConversationWindow
    {id: conversationWindow}

    StackView
    {
        id: stackView;

        anchors.fill: parent;

        initialItem: loginWindow;
    }
}
