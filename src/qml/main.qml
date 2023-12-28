import QtQuick
import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls
import "./content/RecorderTab"
import "../js/qmlfooterlog.js" as Logger

ApplicationWindow {

    Connections {
        target: theModel
        function onTreeModelChanged() {
            log(Logger.Info ,"Steps model has been updated");
        }
    }

    title: "GUIRecorder"
    width: 640
    height: 480
    minimumWidth: 400
    minimumHeight: 400
    visible: true
    menuBar: MainMenuBar{}

    header : TabBar {
        id: bar
        width: parent.width
        TabButton {
            id: outputTabButton
            text: qsTr("General View")
        }
        TabButton {
            id: outputTabButton1
            text: qsTr("Editing the test")
        }
        TabButton {
            id: outputTabButton2
            text: qsTr("Editing a template")
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
            id: footerOutputId
            SplitView.minimumHeight: (parent.height/6)*1
            SplitView.maximumHeight: (parent.height/6)*3
            SplitView.preferredHeight: (parent.height/6)*1
        }
    }

    //js code
    function log(logType, str)
    {
        footerOutputId.logOutput += Logger.create(logType, str);
    }
    Component.onCompleted:
    {
        if(initExtenalObj.loadReportLib())
        {
            log(Logger.Succ ,"Correctly loaded <b>GUIRecorderReportGen</b>");
        }
        else
        {
            log(Logger.Err ,"Not loaded <b>GUIRecorderReportGen</b>");
        }

        if(initExtenalObj.loadRecorderCoreLib())
        {
            log(Logger.Succ ,"Correctly loaded <b>GUIRecorderCore</b>");
        }
        else
        {
            log(Logger.Err ,"Not loaded <b>GUIRecorderCore</b>");
        }
    }
}
