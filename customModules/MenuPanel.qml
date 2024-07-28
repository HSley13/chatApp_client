import QtQuick

Rectangle
{
    id: root;

    property string option1: "";
    property string option2: "";
    property string option3: "";

    property bool hidden: true;
    width: 160;
    height: 120;

    ListView 
    {
        anchors.fill: parent;

        model: ListModel 
        {
            id: listModel;
        }

        delegate: Item 
        {
            width: parent.width;
            height: 40;

            Rectangle 
            {
                width: parent.width;
                height: parent.height;
                color: index % 2 === 0 ? "lightgrey" : "white";
                border.color: "grey";

                Text 
                {
                    anchors.centerIn: parent;
                    text: model.text;
                }

                MouseArea 
                {
                    anchors.fill: parent;
                    onClicked: 
                    {
                        console.log("Selected: " + listModel.text);
                    }
                }
            }
        }
    }

    Behavior on x
    {
        PropertyAnimation
        {
            easing.type: Easing.InOutQuad;
            duration: 200;
        }
    }

    function update_options(options)
    {
        listModel.clear();
        
        for (var i = 0; i < options.length; i++)
            listModel.append({"text": options[i]});
    }
}