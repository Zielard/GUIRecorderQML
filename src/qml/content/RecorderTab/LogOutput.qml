import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

Rectangle {
    property string logOutput: "<p><b>GUIRecorder</b> version 1.0.0 </p> <p>Author Piotr Zielinski</p>"
    color: 'white'
    Layout.fillHeight: true
    Layout.fillWidth: true
    Layout.preferredHeight: (parent.height/4)
    ScrollView {
        id: view
        anchors.fill: parent
        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
        ScrollBar.vertical.policy: ScrollBar.AlwaysOn
        Label {
            width: parent.width
            text: logOutput
        }
    }
    
    Rectangle
    {
        property bool commonBorder : true
        property int lBorderwidth : 1
        property int rBorderwidth : 1
        property int tBorderwidth : 1
        property int bBorderwidth : 1
        property int commonBorderWidth : 1
        z : -1
        property string borderColor : "black"
        color: borderColor
        anchors
        {
            left: parent.left
            right: parent.right
            top: parent.top
            bottom: parent.bottom
            topMargin    : commonBorder ? -commonBorderWidth : -tBorderwidth
            bottomMargin : commonBorder ? -commonBorderWidth : -bBorderwidth
            leftMargin   : commonBorder ? -commonBorderWidth : -lBorderwidth
            rightMargin  : commonBorder ? -commonBorderWidth : -rBorderwidth
        }
    }
}
