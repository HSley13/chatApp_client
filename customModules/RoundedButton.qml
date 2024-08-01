import QtQuick;
import QtQuick.Controls.Basic;

Button
{
    id: root;
    required property string color;

    contentItem: Text 
    {
        text: root.text
        opacity: enabled ? 1.0 : 0.3;
        color: root.down ? "#ed7bb4" : "black";
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
        border.color: root.down ? "#ed7bb4" : "black";
        border.width: 1;
        radius: 10;
    }
}