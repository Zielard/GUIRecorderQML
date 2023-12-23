import QtQuick.Controls
import QtQuick.Layouts

Item
{
    width: parent.width
    TabBar {
        id: root
        width: parent.width
        TabButton {
            id: outputTabButton
            text: qsTr("Output")
        }
        TabButton {
            id: outputTabButton1
            text: qsTr("Output")
        }
    }

    StackLayout {
        anchors.fill: parent
        currentIndex: 1
        Rectangle {
            color: 'teal'
            implicitWidth: 200
            implicitHeight: 200
        }
        Rectangle {
            color: 'plum'
            implicitWidth: 300
            implicitHeight: 200
        }
    }
}

