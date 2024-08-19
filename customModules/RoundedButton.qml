import QtQuick;
import QtQuick.Controls.Basic;

Button
{
    id: root;
    required property string color;
    property string borderColor: "#DE02B5";

    contentItem: Text 
    {
        text: root.text
        opacity: enabled ? 1.0 : 0.3;
        color: root.down ? "black" : root.borderColor;
        horizontalAlignment: Text.AlignHCenter;
        verticalAlignment: Text.AlignVCenter;
        elide: Text.ElideRight;
    }

    background: Rectangle 
    {
        width: root.width;
        height: root.height;    
        opacity: enabled ? 1 : 0.3;
        color: root.color;
        border.color: root.down ? "black" : root.borderColor;
        border.width: 2;
        radius: 10;
    }
}