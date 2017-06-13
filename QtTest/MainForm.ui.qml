import QtQuick 2.6

Rectangle {
    property alias mouseArea: mouseArea

    width: 300
    height: 480

    MouseArea {
        id: mouseArea
        anchors.fill: parent
    }

    Rectangle {
        id: header
        width: 300
        height: 200
        color: "#00a000"
        border.color: "#00a000"
    }

    Rectangle {
        id: footer
        x: 0
        y: 380
        width: 300
        height: 100
        color: "#00a000"
        border.color: "#00a000"
    }

    Rectangle {
        id: profileHolder
        x: 50
        y: 113
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

    Text {
        id: companyName
        x: 100
        y: 37
        width: 100
        height: 50
        color: "#ffffff"
        text: qsTr("TEST")
        verticalAlignment: Text.AlignTop
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 40
    }
}
