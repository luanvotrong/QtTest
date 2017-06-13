import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MainForm {
        width: 300
        anchors.rightMargin: 171
        anchors.bottomMargin: 0
        anchors.leftMargin: 171
        anchors.topMargin: 0
        anchors.fill: parent
        mouseArea.onClicked: {
            console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
        }
    }

    Rectangle {
        id: profileHolder
        x: 220
        y: 120
        width: 200
        height: 200
        color: "#ffffff"
        radius: 100
        border.color: "#ffffff"
        border.width: 0

        Rectangle {
            id: rectangle
            x: 5
            y: 5
            width: 190
            height: 190
            color: "#000000"
            radius: 92
            border.width: 0
        }
    }
}
