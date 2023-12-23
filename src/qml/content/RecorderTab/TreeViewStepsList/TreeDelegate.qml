import QtQuick 2.0

Item {
    Text {
        anchors.fill: parent
        color:  "red" //"styleData.textColor"
        elide: Text.ElideRight
        //text: styleData.value.indentation + ": " + styleData.value.text
    }
}
