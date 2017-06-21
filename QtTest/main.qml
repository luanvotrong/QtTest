import QtQuick 2.6
import QtQuick.Window 2.2
import QtGraphicalEffects 1.0
import QtQuick.Dialogs 1.2

Window {
    id: window
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
                property real scaleFactor: 1
                width: 150 * scaleFactor
                height: 224 * scaleFactor
                visible: true
                fillMode: Image.PreserveAspectCrop
                source: "son_lead.JPG"
                states: State {
                    when: mouseArea.drag.active
                    ParentChange { target: tile; parent: root }
                    AnchorChanges { target: tile; anchors.verticalCenter: undefined; anchors.horizontalCenter: undefined }
                }
            }
        }

        MouseArea {
            id: dragArea
            anchors.fill: parent
            drag.target: image
            onWheel: {
                image.scaleFactor += 0.2 * wheel.angleDelta.y / 120;
                if (image.scaleFactor < 0)
                    image.scaleFactor = 0;
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

        Text {
            id: text1
            x: -162
            y: 372
            width: 100
            height: 100
            text: qsTr("Load picture")
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 15

            MouseArea {
                id: loadPicture
                x: 0
                y: 0
                width: 100
                height: 100
                onClicked: function() {
                    fileDialog.open();
                }
            }
        }

        FileDialog {
            id: fileDialog
            title: "Please choose a file"
            folder: shortcuts.home
            Component.onCompleted: visible = true
            onAccepted: {
                image.source = fileDialog.fileUrl;
            }
        }
    }
}
