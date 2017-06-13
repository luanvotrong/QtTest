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
