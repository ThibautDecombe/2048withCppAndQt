import QtQuick 2.6

Rectangle {
    id: gameWindow
    width: 290
    height: 400
    color: "#98fb83"
    property alias newGameButton: newGameButton
    property alias rectangle: rectangle

    Rectangle {
        id: rectangle
        y: 80
        width: 250
        height: 250
        color: "#007615"
        radius: 15
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20

        Repeater {
            model: 16
            Rectangle {
                x: gameBoard.posX
                y: gameBoard.posY
                Behavior on x { PropertyAnimation { duration: 100}}
                Behavior on y { PropertyAnimation { duration: 100}}
                width: 50
                height: 50
                color: gameBoard.tileColor
                radius: 5
                z: 1
                focus: true

                Text {
                    color: gameBoard.tileTextColor
                    text: gameBoard.tileNb
                    z: 2
                    fontSizeMode: Text.FixedSize
                    textFormat: Text.AutoText
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.pixelSize: 24
                }
            }
        }


        Grid {
            x: 10; y: 10
            rows: 4; columns: 4; spacing: 10

            Repeater { model:16
                Rectangle {width: 50; height: 50
                    color: "#054c0b"
                    radius: 5
                }
            }
        }

        Keys.onPressed: {
            switch (event.key) {
               case Qt.Key_Right:
                   console.log("KeyRight pressed");
                   gameBoard.moveRight();
                   break;
                case Qt.Key_Left:
                   console.log("KeyLeft pressed");
                   gameBoard.moveLeft();
                   break;
                case Qt.Key_Up:
                    console.log("KeyUp pressed");
                    gameBoard.moveUp();
                    break;
                case Qt.Key_Down:
                    console.log("KeyDown pressed");
                    gameBoard.moveDown();
                    break;
            }
        }
    }

    Text {
        id: title2048
        color: "#044e08"
        text: qsTr("2048")
        font.bold: true
        font.family: "Verdana"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 20
        font.pixelSize: 29
    }

    Rectangle {
        id: newGameButtonRect
        x: 170
        y: 67
        width: 100
        height: 40
        color: "#73d216"
        radius: 5

        Text {
            id: textNewGame
            color: "#044e08"
            text: qsTr("New Game")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 19
        }

        MouseArea {
            id: newGameButton
            anchors.fill: parent
            cursorShape: Qt.PointingHandCursor
        }
    }
}
