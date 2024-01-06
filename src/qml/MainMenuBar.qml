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

    Dialog {
        id: testRunDialog
        title: "run test"
        modal: true
        standardButtons: Dialog.Ok | Dialog.Cancel

        onAccepted: console.log("Ok clicked")
        onRejected: console.log("Cancel clicked")
    }

    Dialog {
        id: reportGeneratorDialog
        title: "Report generator"
        modal: true
        standardButtons: Dialog.Ok | Dialog.Cancel

        onAccepted: console.log("Ok clicked")
        onRejected: console.log("Cancel clicked")
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
        Action { text: qsTr("&Generating HTML report")
                 onTriggered: reportGeneratorDialog.open()
                }
        Action { text: qsTr("&Run test OFF")
            onTriggered: testRunDialog.open()
           }
    }
    Menu {
        title: qsTr("&Help OFF")
        Action { text: qsTr("&About OFF") }
    }
}
