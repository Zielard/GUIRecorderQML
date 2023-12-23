import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import "./TreeViewStepsList"
ColumnLayout {
    id: recorderTabId
    Layout.fillHeight: true
    Layout.fillWidth: true
    RowLayout
    {
        Layout.preferredHeight: (parent.height/4)*3
        TreeViewStepsList{
            Layout.fillHeight: true
            Layout.fillWidth: true
            //Layout.preferredWidth: (parent.width/5)*1
        }
        Rectangle {
            color: 'lightblue'
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredWidth: (parent.width/5)*1
        }
        Rectangle {
            color: 'lightgreen'
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredWidth: (parent.width/5)*1
        }
    }
    LogOutput {}
}
