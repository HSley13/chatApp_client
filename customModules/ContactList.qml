import QtQuick;
import QtQuick.Window;
import QtQuick.Controls;

Rectangle
{
    anchors.fill: parent;

    ListView
    {
        id: contactListView;
        anchors.fill: parent;

        anchors.margins: 5;

        spacing: 5;
        clip: true;

        model: contact_list.contact_proxy_list;

        delegate: ContactListDelegate 
        {
            width: parent.width;
            height: 50;
        }
    }
}
