import QtQuick 2.6

Rectangle {
    id: gameWindow

    width: 360
    height: 360
    color: "#d0e2ca"
    radius: 13
    property alias gameTable: gameTable
    property alias rect1: rect1
    property alias gameTitle: gameTitle

    Text {
        id: gameTitle
        x: 8
        width: 50
        height: 30
        text: qsTr("2048")
        font.family: "Verdana"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 10
        font.pixelSize: 18
    }

    Rectangle {
        id: gameTable
        x: 60
        y: 60
        width: 240
        height: 240
        color: "#00000000"
        radius: 5
        border.color: "#57cd57"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        Rectangle {
            id: rect1
            x: 10
            y: 10
            width: 50
            height: 50
            color: "#5ceb54"
            radius: 3
            focus: true

            Keys.onPressed: {
                switch (event.key) {
                  case Qt.Key_Up:
                    y:10
                    break;
                  case Qt.Key_Down:
                    y:50
                    break;
            }
            }
        }
    }
}
