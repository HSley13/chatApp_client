import QtQuick;
import QtQuick.Window;
import QtQuick.Controls;

Rectangle
{
    id: root
    anchors.fill: parent;

    ListView
    {
        id: listView
        anchors.fill: parent;
        anchors.margins: 5;

        spacing: 5;
        clip: true;
        model: chatListModel;
        visible: true;

        delegate: Rectangle
        {
            id: chatListDelegate;

            required property string conversation_ID;
            required property string phone_number;
            required property string image;
            required property string name;
            required property string last_message;
            required property string message_count;
            required property string status;
            property string onOffline: (chatListDelegate.status === "qrc:/QML/ClientApp/icons/online_icon.png") ? "Online" : "Offline";

            width: listView.width;
            height: 50;

            ImageText
            {
                id: item;
                source: chatListDelegate.image;
                onOffLine: chatListDelegate.status;
                name: chatListDelegate.name;
                last_message: chatListDelegate.last_message;
                message_count: chatListDelegate.message_count;

                anchors.fill: parent;
            }

            MouseArea
            {
                id: mouseArea;

                anchors.fill: parent;

                onClicked: 
                {
                    var qmlCode =   'ConversationWindow ' +
                                    '{' +
                                    '  source: "' + chatListDelegate.image + '"; ' +
                                    '  name: "' + chatListDelegate.name + '"; ' +
                                    '  onOffline: "' +chatListDelegate.onOffline + '"; ' +
                                    ' conversation_ID:  "' + chatListDelegate.conversation_ID + '";  ' +
                                    '}';
                                    
                    var convWindow = Qt.createQmlObject(qmlCode, stackView);

                    stackView.push(convWindow);
                }
            }
        }
    }

    function loadConversation(conversation_ID)
    {
        var existingLoader = clientManager.get_conversation_loader(conversation_ID);
        
        if (!existingLoader)
        {
            var qmlCode =   'ConversationWindow ' +
                                    '{' +
                                    '  source: "' + chatListDelegate.image + '"; ' +
                                    '  name: "' + chatListDelegate.name + '"; ' +
                                    '  onOffline: "' +chatListDelegate.onOffline + '"; ' +
                                    ' conversation_ID:  "' + chatListDelegate.conversation_ID + '";  ' +
                                    '}';
                                    
            var loader = Qt.createQmlObject(qmlCode, stackView);

            clientManager.add_conversation_loader(conversation_ID, loader);

            loader.statusChanged.connect(function() {
                if (loader.status === Loader.Ready) 
                    stackView.push(loader.item);
            });
        }
        else
            stackView.push(existingLoader);
    }
}
