import QtQuick
import QtQuick.Controls

MenuBar 
{
    Menu {
        title: qsTr("&File OFF")
        Action { text: qsTr("&New... OFF") }
        Action { text: qsTr("&Open...") 
                 onTriggered: window.activeFocusItem.copy()}
        Action { text: qsTr("&Save OFF") }
        Action { text: qsTr("Save &As... OFF") }
        MenuSeparator { }
        Action { text: qsTr("&Quit") 
                 onTriggered: Qt.quit()}
    }
    Menu {
        title: qsTr("&Edit OFF")
        Action { text: qsTr("Cu&t OFF") }
        Action { text: qsTr("&Copy OFF") }
        Action { text: qsTr("&Paste OFF") }
    }
    Menu {
        title: qsTr("&Help OFF")
        Action { text: qsTr("&About OFF") }
    }
}
