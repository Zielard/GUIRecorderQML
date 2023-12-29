import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import "./TreeViewStepsList"
ColumnLayout {
    id: recorderTabId
    property alias refImage : refImageViewer
    property alias refTextStep : refTextViewer
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
            ColumnLayout {
            anchors.fill: parent
                TreeViewStepsList{
                    id: treeViewStepsList
                    Layout.fillHeight: true
                    Layout.fillWidth: true

                }
                Rectangle {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    //color: 'red'
                    Layout.minimumHeight: refTextViewer.font.pixelSize*2
                    Layout.maximumHeight: refTextViewer.font.pixelSize*2
                    Text {
                        id: refTextViewer
                        anchors.fill: parent
                        text : ""
                    }
                }
            }
        }
        Rectangle {
            id: centerItem
            //color: 'lightblue'
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
        Item {
            //color: 'lightgreen'
            //SplitView.fillHeight: true
            //SplitView.fillWidth: true
            SplitView.minimumWidth: (parent.width/5)*1
            SplitView.maximumWidth: (parent.width/5)*4
            SplitView.preferredWidth: (parent.width/5)*1
            TreeViewTemplate{

            }
        }
    }
}
