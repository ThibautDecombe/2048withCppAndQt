import QtQuick 2.6

Rectangle {
    id: gameWindow
    width: 270
    height: 270
    color: "#98fb83"
    property alias textTile1: textTile1
    property alias rectangle: rectangle
    property alias tile1: tile1
    property alias tile2: tile2

    Rectangle {
        id: rectangle
        x: 80
        y: 80
        width: 250
        height: 250
        color: "#007615"
        radius: 15
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        Rectangle {
            id: tile1
            x: gameBoard.posX
            y: gameBoard.posY
            Behavior on x { PropertyAnimation { duration: 100}}
            Behavior on y { PropertyAnimation { duration: 100}}
            width: 50
            height: 50
            color: "#04f211"
            radius: 5
            z: 1
            focus: true

            Text {
                id: textTile1
                color: "#0a4403"
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

        Rectangle {
            id: tile2
            x: gameBoard.posX
            y: gameBoard.posY
            Behavior on x { PropertyAnimation { duration: 100}}
            Behavior on y { PropertyAnimation { duration: 100}}
            width: 50
            height: 50
            color: "#04f211"
            radius: 5
            z: 2
            focus: true

            Text {
                id: textTile2
                color: "#0a4403"
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

        Rectangle {
            id: rectBack1
            x: 10
            y: 10
            width: 50
            height: 50
            color: "#054c0b"
            radius: 5
        }

        Rectangle {
            id: rectBack2
            x: 10
            y: 70
            width: 50
            height: 50
            color: "#054c0b"
            radius: 5
        }

        Rectangle {
            id: rectBack3
            x: 10
            y: 130
            width: 50
            height: 50
            color: "#054c0b"
            radius: 5
        }

        Rectangle {
            id: rectBack4
            x: 10
            y: 190
            width: 50
            height: 50
            color: "#054c0b"
            radius: 5
        }

        Rectangle {
            id: rectBack5
            x: 70
            y: 10
            width: 50
            height: 50
            color: "#054c0b"
            radius: 5
        }

        Rectangle {
            id: rectBack6
            x: 70
            y: 70
            width: 50
            height: 50
            color: "#054c0b"
            radius: 5
        }

        Rectangle {
            id: rectBack7
            x: 70
            y: 130
            width: 50
            height: 50
            color: "#054c0b"
            radius: 5
        }

        Rectangle {
            id: rectBack8
            x: 70
            y: 190
            width: 50
            height: 50
            color: "#054c0b"
            radius: 5
        }

        Rectangle {
            id: rectBack9
            x: 130
            y: 10
            width: 50
            height: 50
            color: "#054c0b"
            radius: 5
        }

        Rectangle {
            id: rectBack10
            x: 130
            y: 70
            width: 50
            height: 50
            color: "#054c0b"
            radius: 5
        }

        Rectangle {
            id: rectBack11
            x: 130
            y: 130
            width: 50
            height: 50
            color: "#054c0b"
            radius: 5
        }

        Rectangle {
            id: rectBack12
            x: 130
            y: 190
            width: 50
            height: 50
            color: "#054c0b"
            radius: 5
        }

        Rectangle {
            id: rectBack13
            x: 190
            y: 10
            width: 50
            height: 50
            color: "#054c0b"
            radius: 5
        }

        Rectangle {
            id: rectBack14
            x: 190
            y: 70
            width: 50
            height: 50
            color: "#054c0b"
            radius: 5
        }

        Rectangle {
            id: rectBack15
            x: 190
            y: 130
            width: 50
            height: 50
            color: "#054c0b"
            radius: 5
        }

        Rectangle {
            id: rectBack16
            x: 190
            y: 190
            width: 50
            height: 50
            color: "#054c0b"
            radius: 5
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
}
