import QtQuick 2.4

Item {
    width: 370 //(widthWindow - 20)
    height: 495
    //(heightWindow - 20)
    property alias quitButton: quitButton

    Rectangle {
        id: optionsRect
        width: 270
        height: 380
        radius: 10

        anchors.fill: parent
        color: gameBoard.colorsList[6]

        Text {
            id: over
            x: -7
            y: 6
            width: 173
            height: 25
            color: gameBoard.colorsList[5]
            text: qsTr("GAME OVER")
            anchors.horizontalCenterOffset: 1
            anchors.topMargin: 145
            fontSizeMode: Text.FixedSize
            font.pixelSize: 22
            anchors.horizontalCenter: parent.horizontalCenter
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.top: parent.top
        }

        Text {
            id: cont
            x: 0
            y: 11
            width: 173
            height: 25
            color: gameBoard.colorsList[5]
            text: qsTr("Click to start a new game")
            anchors.horizontalCenterOffset: 1
            font.pixelSize: 22
            anchors.topMargin: 314
            fontSizeMode: Text.FixedSize
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
        }

        MouseArea {
            id: quitButton
            anchors.fill: parent
        }
    }
}
