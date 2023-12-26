import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

ScrollView {
    id: view
    anchors.fill: parent
    ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
    ScrollBar.vertical.policy: ScrollBar.AlwaysOn
    TreeView {
        Layout.fillWidth: true
        Layout.fillHeight: true
        Layout.preferredWidth: parent.width/5

        model: theModel
        delegate: Item {
            id: treeDelegate

            required property string title
            required property string summary

            implicitWidth: padding + label.x + label.implicitWidth + padding
            implicitHeight: label.implicitHeight

            readonly property real indent: 20
            readonly property real padding: 1

            // Assigned to by TreeView:
            required property TreeView treeView
            required property bool isTreeNode
            required property bool expanded
            required property int hasChildren
            required property int depth

            TapHandler {
                onTapped: treeView.toggleExpanded(row)
            }
            Rectangle {
                color: 'lightgreen'
                radius: 25
                width: padding + label.x + label.implicitWidth + padding
                height: label.implicitHeight
                Text {
                    id: indicator
                    visible: treeDelegate.isTreeNode && treeDelegate.hasChildren
                    x: padding + (treeDelegate.depth * treeDelegate.indent)
                    anchors.verticalCenter: label.verticalCenter
                    text: "▸"
                    rotation: treeDelegate.expanded ? 90 : 0
                }
    //            Component.onCompleted:
    //            {
    //                console.log(title)
    //                console.log(summary)
    //                //console.log(dataDescription)
    //            }
                Text {
                    id: label
                    x: padding + (treeDelegate.isTreeNode ? (treeDelegate.depth + 1) * treeDelegate.indent : 0)
                    width: treeDelegate.width - treeDelegate.padding - x
                    clip: true
                    text: summary
                }
            }
        }
    }
}


//   TreeView {
//           Layout.fillHeight: true
//           Layout.fillWidth: true
//           Layout.preferredWidth: parent.width/5
//         // The model needs to be a QAbstractItemModel
//         // model: yourTreeModel

//         delegate: Item {
//             id: treeDelegate

//             implicitWidth: padding + label.x + label.implicitWidth + padding
//             implicitHeight: label.implicitHeight * 1.5

//             readonly property real indent: 20
//             readonly property real padding: 5

//             // Assigned to by TreeView:
//             required property TreeView treeView
//             required property bool isTreeNode
//             required property bool expanded
//             required property int hasChildren
//             required property int depth

//             TapHandler {
//                 onTapped: treeView.toggleExpanded(row)
//             }

//             Text {
//                 id: indicator
//                 visible: treeDelegate.isTreeNode && treeDelegate.hasChildren
//                 x: padding + (treeDelegate.depth * treeDelegate.indent)
//                 anchors.verticalCenter: label.verticalCenter
//                 text: "▸"
//                 rotation: treeDelegate.expanded ? 90 : 0
//             }

//             Text {
//                 id: label
//                 x: padding + (treeDelegate.isTreeNode ? (treeDelegate.depth + 1) * treeDelegate.indent : 0)
//                 width: treeDelegate.width - treeDelegate.padding - x
//                 clip: true
//                 text: model.display
//             }
//         }
//     }
