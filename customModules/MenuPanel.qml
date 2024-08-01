import QtQuick;

Rectangle
{
    id: root;

    property bool hidden: true;
    width: 160;
    height: 120;

    ListView 
    {
        anchors.fill: parent;

        model: ListModel 
        { id: listModel; }

        delegate: Item 
        {
            width: parent.width;
            height: 40;

            Rectangle 
            {
                width: parent.width;
                height: parent.height;
                color: index % 2 === 0 ? "lightgray" : "white";
                border.color: "gray";

                Row
                {
                    anchors.fill: parent;
                    spacing: 10;
                    anchors.margins: 5;

                    Text 
                    {
                        text: model.text;
                        verticalAlignment: Text.AlignVCenter;
                        anchors.verticalCenter: parent.verticalCenter;
                    }

                    Rectangle
                    {
                        width: 30;
                        height: 30;
                        radius: 15; 
                        color: "transparent";
                        
                        Image 
                        {
                            id: itemImage;

                            source: model.image_source;
                            visible: model.image_source !== "";

                            fillMode: Image.PreserveAspectFit;
                            clip: true;
                            mipmap: true;
                            asynchronous: true;

                            width: parent.width * 0.9;
                            height: parent.height * 0.9;
                            anchors.centerIn: parent;
                        }
                    }
                }

                MouseArea 
                {
                    anchors.fill: parent;
                    onClicked: 
                    {
                        console.log("Selected: " + model.text);
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
        {
            var text = options[i].text || "";
            var image_source = options[i].image_source || "";

            listModel.append({"text": text, "image_source": image_source});
        }
    }
}
