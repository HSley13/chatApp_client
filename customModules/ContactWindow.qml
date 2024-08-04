import QtQuick;
import QtQuick.Controls;
import QtQuick.Layouts;

Rectangle
{
    id: root;
    property Item groupListObject: groupList.createObject(stackView2);

    Rectangle
    {
        id: contactHeader;
        width: parent.width;
        height: 50;

        InputField
        {
            id: contactSearch;
            image1Source: "qrc:/QML/ClientApp/icons/search_icon.png";
            echoMode: TextInput.Normal;
            placeHolder: "Search...";
            width: parent.width * 0.6;
            height: 40;
            isSearching: true;

            anchors.top: parent.top;
            anchors.topMargin: 10;
            anchors.horizontalCenter: parent.horizontalCenter;
        }

        IconText
        {
            id: menu;
            imageSource1: "qrc:/QML/ClientApp/icons/menu_icon.png";
            imageSource2: "qrc:/QML/ClientApp/icons/cancel_menu.png";
            height: parent.height * 0.5;
            width: height;

            onItemClicked: menuPanel.hidden = !menuPanel.hidden;

            anchors.verticalCenter: parent.verticalCenter;
            anchors.right: parent.right;
            anchors.rightMargin: menuPanel.hidden ? 10 : menuPanel.width;
        }
    }

    Rectangle
    {
        width: parent.width;
        anchors.top: contactHeader.bottom;
        anchors.bottom: contactBottom.top;

        StackView
        {
            id: stackView2;
            anchors.fill: parent;

            initialItem: contactList;

            ListDialog
            {
                id: newConversation_dialog;
                title: "New Conversation, Select a Person";
                checkable: true;
                
                names: contact_list_model.contact_proxy_list;

                onDialogAccepted:
                {
                    contact_list_model.active_chat = contact_list_model.contact_proxy_list.get(index);
                    stackView.push(chatWindow);
                }
            }

            ListDialog
            {
                id: group_dialog;
                input: true;
                title: "New Group";
                checkable: true;
                placeHolder: "Enter Group Name";

                names: contact_list_model.contact_proxy_list;

                onDialogAccepted:
                {
                     group_list_model.add_group(inputField, selectedItems);
                    // FIXME: notify the server
                }
            }

            ListDialog
            {
                id: addFriend_dialog;
                input: true;
                title: "Add New Friend";
                placeHolder: "Enter Phone number";

                onDialogAccepted:
                {
                    // FIXME: notify the server
                    console.log("input: " + inputField);
                }
            }
        }
    }

    Rectangle 
    {
        id: contactBottom;
        width: parent.width;
        height: 50;

        gradient: Gradient
        {
            GradientStop { position: 0.0; color: "gray"; }
            GradientStop { position: 1.0; color: "white"; }
        }

        IconText
        {
            id: chatList;
            imageSource1: "qrc:/QML/ClientApp/icons/chat_icon.png";
            label: "Chats";
            height: parent.height * 0.9;
            width: height;

            onItemClicked: stackView2.pop();

            anchors.left: parent.left;
            anchors.leftMargin: 10;
            anchors.verticalCenter: parent.verticalCenter;
        }

        IconText 
        {
            id: chatGroup;
            imageSource1: "qrc:/QML/ClientApp/icons/group_icon.png";
            label: "Groups";
            height: parent.height * 0.9;
            width: height;

            onItemClicked: 
            {
                if (stackView2.currentItem !== groupListObject)
                    stackView2.push(groupListObject)
            }

            anchors.centerIn: parent;
        }

        IconText
        {
            id: profile;
            imageSource1: "qrc:/QML/ClientApp/icons/settings_icon.png";
            label: "Profile";
            height: parent.height * 0.9;
            width: height;

            onItemClicked: stackView.push(settingWindow);

            anchors.right: parent.right;
            anchors.rightMargin: 10;
            anchors.verticalCenter: parent.verticalCenter;
        }

        anchors.bottom: parent.bottom;
    }

    MenuPanel 
    {
        id: menuPanel;
        anchors.right: menu.left;
        anchors.top: menu.bottom;

        Component.onCompleted:
        {
            var options = [
                {text: "New Conversation", image_source: "qrc:/QML/ClientApp/icons/chat_icon.png"},
                {text: "New Group", image_source: "qrc:/QML/ClientApp/icons/group_icon.png"},
                {text: "Add Friend", image_source: "qrc:/QML/ClientApp/icons/phone_icon.png"}
            ];
            
            menuPanel.update_options(options);
        }

        x: hidden ? parent.width : parent.width - width;
    }
}