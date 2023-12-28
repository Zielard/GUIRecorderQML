import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

ScrollView {
    id: view
    anchors.fill: parent
    ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
    ScrollBar.vertical.policy: ScrollBar.AlwaysOn

    TreeView {
        id: treeView
        Layout.fillWidth: true
        Layout.fillHeight: true
        Layout.preferredWidth: parent.width/5

        model: theModel
        delegate: Item {
            id: treeDelegate

            required property string content
            required property string imgReference

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
                onTapped:
                {
                    //console.log(tapCount)
                    if(imgReference)
                    {
                        refImage.source = Qt.resolvedUrl("file:///"+ imgReference);
                    }
                    if (tapCount%2 === 0)
                    {

                        treeView.toggleExpanded(row)
                    }
                }
                onDoubleTapped:
                {
                    //console.log("Double tap");
                    treeView.toggleExpanded(row)
                }
            }
            Rectangle {
                color: 'lightgreen'
                radius: 25
                width: padding + label.x + label.implicitWidth + padding
                x: padding + (treeDelegate.isTreeNode ? (treeDelegate.depth + 1) * treeDelegate.indent : 0)

                height: label.implicitHeight
                Text {
                    id: indicator
                    visible: treeDelegate.isTreeNode && treeDelegate.hasChildren
                    x: padding + (treeDelegate.depth * treeDelegate.indent)
                    anchors.verticalCenter: label.verticalCenter
                    text: "▸"
                    rotation: treeDelegate.expanded ? 90 : 0
                }
//                Component.onCompleted:
//                {
//                    console.log(content)
//                    console.log(imgReference)
//                    //console.log(dataDescription)
//                }
                Text {
                    id: label
                    x: padding + (treeDelegate.isTreeNode ? (treeDelegate.depth + 1) * treeDelegate.indent : 0)
                    width: treeDelegate.width - treeDelegate.padding - x
                    clip: true
                    text: content
                }
            }
        }
    }
}
