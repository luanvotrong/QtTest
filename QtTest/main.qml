import QtQuick 2.6
import QtQuick.Window 2.2
import QtGraphicalEffects 1.0

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

        Rectangle {
            id: sourceMask
            x: 74
            y: 127
            width: 150
            height: 150
            visible: false
            clip: true

            Image {
                id: image
                x: 0
                y: -40
                width: 150
                height: 224
                visible: true
                fillMode: Image.PreserveAspectCrop
                source: "son_lead.jpg"
            }
        }

        Rectangle {
            id: destMask
            x: 74
            y: 127
            width: 150
            height: 150
            color: "#000000"
            radius: 75
            border.color: "#ffffff"
            border.width: 3
        }

        OpacityMask {
            visible: true
            anchors.fill: destMask
            source: sourceMask
            maskSource: destMask
        }
    }
}
