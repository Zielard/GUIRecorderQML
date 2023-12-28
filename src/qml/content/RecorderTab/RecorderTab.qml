import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import "./TreeViewStepsList"
ColumnLayout {
    id: recorderTabId
    property alias refImage : refImageViewer
    Layout.fillHeight: true
    Layout.fillWidth: true

    SplitView
    {
        Layout.fillHeight: true
        Layout.fillWidth: true
        orientation: Qt.Horizontal
        Layout.preferredHeight: (parent.height/4)*3

        Item {
            SplitView.minimumWidth: (parent.width/5)*1
            SplitView.maximumWidth: (parent.width/5)*4
            SplitView.preferredWidth: (parent.width/5)*1


//            Rectangle {
//                id: bottomButtons
//                anchors.left: parent.left
//                anchors.right: parent.right
//                anchors.bottom: parent.right
//                implicitHeight: 50
//                implicitWidth: parent.width
//                radius: 20
//                color: "lightblue"

//                Text {
//                    anchors.centerIn: parent
//                    text: parent.width + 'x' + parent.height
//                    font.pointSize: 24
//                }
//            }
            TreeViewStepsList{
                id: treeViewStepsList
                anchors.right: bottomButtons.bottom
                anchors.bottom: parent.bottom
                //SplitView.minimumWidth: (parent.width/5)*1
                //SplitView.maximumWidth: (parent.width/5)*4
                //SplitView.preferredWidth: (parent.width/5)*1
            }

        }
        Rectangle {
            id: centerItem
            color: 'lightblue'
            SplitView.fillHeight: true
            SplitView.fillWidth: true
            SplitView.minimumWidth: (parent.width/5)*1
            SplitView.maximumWidth: (parent.width/5)*4
            SplitView.preferredWidth: (parent.width/5)*1
            Image {
                id: refImageViewer
                anchors.fill: parent
                source: ""
            }
        }
        Rectangle {
            color: 'lightgreen'
            //SplitView.fillHeight: true
            //SplitView.fillWidth: true
            SplitView.minimumWidth: (parent.width/5)*1
            SplitView.maximumWidth: (parent.width/5)*4
            SplitView.preferredWidth: (parent.width/5)*1
        }
    }
}
