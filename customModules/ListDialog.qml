import QtQuick;
import QtQuick.Controls;
import QtQuick.Layouts;

Dialog
{
    id: root;

    property string titles: "";
    property var names: [];
    property alias inputField: textInput.inputField;
    property bool input: false;
    property var selectedItems: [];
    property bool checkable: false;

    signal dialogAccepted();
    signal dialogRejected();

    onAccepted: dialogAccepted();
    onRejected: dialogRejected();

    title: titles;
    modal: true;

    background: Rectangle
    {
        color: "gray";
        radius: 15;
        border.color: "white";
    }

    contentItem: ColumnLayout
    {
        spacing: 10;

        ListView
        {
            id: listView;
            Layout.fillWidth: true;
            height: input ? 200 : 300;
            model: names;

            delegate: Item
            {
                width: parent.width;
                height: 40;

                RowLayout
                {
                    spacing: 5;

                    CheckBox
                    {
                        id: checkBox;
                        checked: false;
                        visible: root.checkable;

                        onCheckedChanged: (checked) ? root.selectedItems.push(modelData) : root.selectedItems.splice(root.selectedItems.indexOf(modelData), 1);
                    }

                    Rectangle
                    {
                        width: parent.width - checkBox.width - 10;
                        height: 30;
                        color: "transparent";  

                        Text
                        {
                            text: modelData;
                            font.pixelSize: 16;
                            color: "black";
                            wrapMode: Text.Wrap;  
                            elide: Text.ElideRight;  
                            anchors.left: parent.left;
                        }
                    }
                }
            }
        }

        InputField
        {
            id: textInput;
            image1Source: "";
            echoMode: TextInput.Normal;
            placeHolder: "Enter a Value ...";
            Layout.fillWidth: true;
            height: 30;
        }

        Rectangle
        {
            width: parent.width;
            height: 30;
            color: "transparent";

            Button
            {
                text: "OK";
                onClicked:
                {
                    console.log("Selected Items: " + root.selectedItems);
                    root.accept();
                }

                anchors.left: parent.left;
            }


            Button
            {
                text: "Cancel";
                onClicked: root.reject();

                anchors.right: parent.right;
            }
        }
    }
}
