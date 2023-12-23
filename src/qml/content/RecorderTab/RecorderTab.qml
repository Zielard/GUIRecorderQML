import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import "./TreeViewStepsList"
ColumnLayout {
    id: recorderTabId
    Layout.fillHeight: true
    Layout.fillWidth: true
    SplitView
    {
        Layout.fillHeight: true
        Layout.fillWidth: true
        orientation: Qt.Horizontal
        Layout.preferredHeight: (parent.height/4)*3
        Rectangle {
            SplitView.minimumWidth: (parent.width/5)*1
            SplitView.maximumWidth: (parent.width/5)*4
            SplitView.preferredWidth: (parent.width/5)*1
            TreeViewStepsList{
                SplitView.fillHeight: true
                SplitView.fillWidth: true
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
