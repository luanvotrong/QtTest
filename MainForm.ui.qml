import QtQuick 2.7

Rectangle {
    property alias mouseArea: mouseArea

    anchors.fill: parent

    MouseArea {
        id: mouseArea
        width: 640
        anchors.fill: parent
    }

    Text {
        anchors.centerIn: parent
        text: "Hello World"
    }
}
