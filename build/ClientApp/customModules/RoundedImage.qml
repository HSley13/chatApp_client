import QtQuick;
import Qt5Compat.GraphicalEffects;

Item
{
    id: root;
    property string imageSource;
    signal itemClicked();

    Image 
    {
        id: img;
        width: mask.width;
        height: mask.height;
        source: root.imageSource;
        fillMode: Image.PreserveAspectCrop;
        mipmap: true;
        asynchronous: true;
        
        layer.enabled: true;
        layer.effect: OpacityMask 
        {
            maskSource: mask;
        }

        MouseArea
        {
            anchors.fill: parent;
            onClicked: itemClicked;
        }
    }

    Rectangle 
    {
        id: mask;
        width: parent.width;
        height: parent.height;
        radius: width / 2;
        visible: false;
    }
}