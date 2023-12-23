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
            text: qsTr("General View")
        }
        TabButton {
            id: outputTabButton1
            text: qsTr("Record test")
        }
        TabButton {
            id: outputTabButton2
            text: qsTr("Run test")
        }
        TabButton {
            id: outputTabButton3
            text: qsTr("Inspect")
        }
    }

    SplitView
    {
        anchors.fill: parent
        orientation: Qt.Vertical
        Layout.preferredHeight: (parent.height/4)*3

        StackLayout {
               //SplitView.fillHeight: true
               SplitView.fillWidth: true
               SplitView.minimumHeight: (parent.height/6)*1
               SplitView.maximumHeight: parent.height
               SplitView.preferredHeight: (parent.height/6)*5
               currentIndex: bar.currentIndex
               RecorderTab{}

               Rectangle {
                   color: 'lightblue'
                   implicitWidth: 300
                   implicitHeight: 200
               }
               Rectangle {
                   color: 'lightgoldenrodyellow'
                   implicitWidth: 300
                   implicitHeight: 200
               }
               Rectangle {
                   color: 'lightgreen'
                   implicitWidth: 300
                   implicitHeight: 200
               }
           }
        FooterOutput {
            SplitView.minimumHeight: (parent.height/6)*1
            SplitView.maximumHeight: (parent.height/6)*3
            SplitView.preferredHeight: (parent.height/6)*1
        }
    }
}
