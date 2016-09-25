import QtQuick 2.4

ListView {
    id: listView1
    x: 75
    y: 117
    width: 110
    height: 160
    delegate: Item {
        x: 5
        width: 80
        height: 40
        Row {
            id: row1
            spacing: 10
            Rectangle {
                width: 40
                height: 40
                color: "#000000"
            }

            Text {
                color: "#000000"
                text: "Test"
                styleColor: "#000000"
                font.bold: true
                anchors.verticalCenter: parent.verticalCenter
            }
        }
    }
}
