import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtGraphicalEffects 1.0
import QtQuick.Dialogs 1.2

ApplicationWindow  {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    menuBar:MenuBar {
        Menu {
            title: "File"
            MenuItem {
                text: "Load Picture"
                onTriggered: {
                    fileDialog.open();
                }
            }
            MenuItem {
                text: "Save"
                onTriggered: {
                    imageBlur.visible = false;
                    mainForm.grabToImage(function(result)
                    {
                        imageBlur.visible = true;
                        result.saveToFile("./test.jpg");
                        console.log(result.url);
                    });
                }
            }
        }
    }

    MainForm {
        id: mainForm
        width: 300
        anchors.rightMargin: 171
        anchors.bottomMargin: 0
        anchors.leftMargin: 171
        anchors.topMargin: 0
        anchors.fill: parent

        Image {
            id: imageBlur
            visible: true
            x: sourceMask.x + image.x
            y: sourceMask.y + image.y
            property real scaleFactor: 1
            width: sourceSize.width * scaleFactor
            height: sourceSize.height * scaleFactor
            opacity: 0.2
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
                y: 0
                property real scaleFactor: 1
                width: sourceSize.width * scaleFactor
                height: sourceSize.height * scaleFactor
                visible: true
                fillMode: Image.PreserveAspectCrop
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
            smooth: true
            onWheel: {
                image.scaleFactor += 0.2 * wheel.angleDelta.y / 120;
                if (image.scaleFactor < 0)
                    image.scaleFactor = 0;
                imageBlur.scaleFactor += 0.2 * wheel.angleDelta.y / 120;
                if(imageBlur.scaleFactor < 0)
                    imageBlur.scaleFactor = 0;
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

        FileDialog {
            id: fileDialog
            title: "Please choose a file"
            folder: shortcuts.home
            Component.onCompleted: visible = false
            onAccepted: {
                image.source = fileDialog.fileUrl;
                imageBlur.source = fileDialog.fileUrl;
            }
        }
    }
}
