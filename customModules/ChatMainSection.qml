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
        anchors.margins: 20;

        spacing: 10;
        clip: true;
        model: chatListModel;
        visible: true;

        delegate: Rectangle
        {
            id: chatListDelegate;

            required property string image;
            required property string name;
            required property string last_message;
            required property string message_count;
            required property string status;
            property string onOffline: (chatListDelegate.status.toString() === "qrc:/QML_modules/ClientApp/icons/online_icon.png") ? "Online" : "Offline";

            width: listView.width;
            height: 50;
            color: "white";

            ImageText
            {
                id: item;
                source: chatListDelegate.image;
                onOffLine: chatListDelegate.status;
                name: chatListDelegate.name;
                last_message: chatListDelegate.last_message;
                message_count: chatListDelegate.message_count;
            }

            MouseArea
            {
                anchors.fill: parent;

                onClicked: 
                {
                    var qmlCode =   'ConversationWindow ' +
                                    '{' +
                                    '  source: "' + chatListDelegate.image + '"; ' +
                                    '  name: "' + chatListDelegate.name + '"; ' +
                                    '  onOffline: "' +chatListDelegate.onOffline + '"; ' +
                                    '}';

                    var convWindow = Qt.createQmlObject(qmlCode, stackView);
            
                    stackView.push(convWindow);
                }
            }
        }
    }
}