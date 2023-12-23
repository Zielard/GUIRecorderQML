import QtQuick
import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls
import "./content/RecorderTab"

ApplicationWindow {
    title: "GUIRecorder"
    width: 640
    height: 480
    minimumWidth: 400
    minimumHeight: 400
    visible: true
//src/qml/content/RecorderTab/RecorderTab.qml
    menuBar: MenuBar {
            Menu {
                title: qsTr("&File")
                Action { text: qsTr("&New...") }
                Action { text: qsTr("&Open...") }
                Action { text: qsTr("&Save") }
                Action { text: qsTr("Save &As...") }
                MenuSeparator { }
                Action { text: qsTr("&Quit") }
            }
            Menu {
                title: qsTr("&Edit")
                Action { text: qsTr("Cu&t") }
                Action { text: qsTr("&Copy") }
                Action { text: qsTr("&Paste") }
            }
            Menu {
                title: qsTr("&Help")
                Action { text: qsTr("&About") }
            }
        }

    header : TabBar {
        id: bar
        width: parent.width
        TabButton {
            id: outputTabButton
            text: qsTr("Record test")
        }
        TabButton {
            id: outputTabButton1
            text: qsTr("Run test")
        }
        TabButton {
            id: outputTabButton2
            text: qsTr("Inspect")
        }
    }

    StackLayout {
           anchors.fill: parent
           currentIndex: bar.currentIndex
           RecorderTab{}

           Rectangle {
               id: "out2"
               color: 'plum'
               implicitWidth: 300
               implicitHeight: 200
           }
           Rectangle {
               id: "out3"
               color: 'lightblue'
               implicitWidth: 300
               implicitHeight: 200
           }
       }
}
