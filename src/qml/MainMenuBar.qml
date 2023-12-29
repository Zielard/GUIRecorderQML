import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs
MenuBar 
{
    FolderDialog {
        id: fileDialog
        //currentFolder: StandardPaths.standardLocations(StandardPaths.PicturesLocation)[0]
        onAccepted:   {
            theModel.loadScenarioTreeView(Qt.resolvedUrl(selectedFolder));
            templateModel.loadTemplateFile(Qt.resolvedUrl(selectedFolder));
        }
        //selectedNameFilter.index: 1
        //nameFilters: ["Json files (*.json)"]
    }

    Menu {
        title: qsTr("&File")
        Action { text: qsTr("&New... OFF") }
        Action { text: qsTr("&Open...") 
                 onTriggered: fileDialog.open()
                 }
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
        title: qsTr("&Tools")
        Action { text: qsTr("&Generating HTML report OFF") }
        Action { text: qsTr("&Run test OFF") }
    }
    Menu {
        title: qsTr("&Help OFF")
        Action { text: qsTr("&About OFF") }
    }
}
