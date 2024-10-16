import QtQuick;
import QtQuick.Controls;

Rectangle
{
    ListView
    {
        id: contactListView;

        anchors.fill: parent;

        anchors.margins: 5;

        spacing: 10;
        clip: true;

        model: contact_list_model.contact_proxy_list_chat;

        delegate: ContactListDelegate 
        {
            width: parent.width;
            height: 50;
        }
    }
}
