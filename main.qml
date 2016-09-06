import QtQuick 2.7
import QtQuick.Window 2.2
import QtWebEngine 1.3

Window {
    visible: true
    visibility: "Maximized"
    title: qsTr("Hello World")

    WebEngineView{
        anchors.fill: parent
        url: "http://www.google.com"
    }
}
