import QtQuick 2.4

Item {
    width: 270
    height: 380
    property alias quitButton: quitButton

    Rectangle {
        id: optionsRect
        width: 270
        height: 380

        anchors.fill: parent
        color: "#bbffa9"

        Text {
            id: textOptions
            color: "#044e08"


            text: "Options"
            font.bold: true
            font.family: "Arial"
            font.pointSize: 19
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.left: parent.left
            anchors.leftMargin: 10
        }

        Rectangle {
            id: rectangle
            x: 232
            width: 30
            height: 30
            color: "#73d216"
            radius: 5
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.right: parent.right
            anchors.rightMargin: 10

            Text {
                id: text1
                color: "#044e08"
                text: qsTr("X")
                font.weight: Font.ExtraBold
                font.bold: true
                font.family: "Verdana"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.fill: parent
                font.pixelSize: 22
            }

            MouseArea {
                id: quitButton
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
            }
        }
    }
}
