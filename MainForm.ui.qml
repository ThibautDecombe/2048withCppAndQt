import QtQuick 2.6
import QtGraphicalEffects 1.0

Rectangle {
    id: gameWindow
    width: (85*numberOfTiles + 160)//290
    height: (85*numberOfTiles + 160)
    color: gameBoard.colorsList[3]
    property alias optionsButton: optionsButton
    property alias newGameButton: newGameButton
    property alias undoButton: undoButton
    property alias rectangleTiles: rectangleTiles

    Rectangle {
        id: optionsButtonRect
        anchors.right: parent.right
        anchors.rightMargin: 20
        anchors.top: parent.top
        anchors.topMargin: 20
        width: 40
        height: 40
        color: gameBoard.colorsList[2]
        radius: 5

        Image {
            id: image
            anchors.fill: parent
            source: "gear.png"
        }

        ColorOverlay {
            anchors.fill:image
            source: image
            color: gameBoard.colorsList[5]
        }

        MouseArea {
            id: optionsButton
            anchors.fill: parent
            cursorShape: Qt.PointingHandCursor
            visible: mainButtons
        }
    }

    Text {
        id: title2048
        color: gameBoard.colorsList[5]
        text: qsTr("2048")
        font.bold: true
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 20
        font.pixelSize: 40
    }

    Rectangle {
        id: scoreRect
        anchors.left: title2048.right
        anchors.leftMargin: 20
        anchors.top: parent.top
        anchors.topMargin: 20
        width: 80
        height: 40
        color: gameBoard.colorsList[2]
        radius: 5

        Text {
            id: scoreText
            text: qsTr("SCORE")
            color: gameBoard.colorsList[4]
            anchors.top: parent.top
            anchors.topMargin: 5
            horizontalAlignment: Text.AlignHCenter
            anchors.fill: parent
            font.pixelSize: 10
        }

        Text {
            id: scoreValue
            text: qsTr("0")
            font.bold: true
            color:  gameBoard.colorsList[4]
            anchors.top: parent.top
            anchors.topMargin: 18
            horizontalAlignment: Text.AlignHCenter
            anchors.fill: parent
            font.pixelSize: 14
        }
    }

    Rectangle {
        id: bestScoreRect
        anchors.left: scoreRect.right
        anchors.leftMargin: 5
        anchors.top: parent.top
        anchors.topMargin: 20
        width: 80
        height: 40
        color: gameBoard.colorsList[2]
        radius: 5

        Text {
            id: bestScoreText
            text: qsTr("BEST")
            color: gameBoard.colorsList[4]
            anchors.top: parent.top
            anchors.topMargin: 5
            horizontalAlignment: Text.AlignHCenter
            anchors.fill: parent
            font.pixelSize: 10
        }

        Text {
            id: bestScoreValue
            text: qsTr("1000")
            font.bold: true
            color: gameBoard.colorsList[4]
            anchors.top: parent.top
            anchors.topMargin: 18
            horizontalAlignment: Text.AlignHCenter
            anchors.fill: parent
            font.pixelSize: 14
        }
    }

    Text {
        id: textExplaining
        color: gameBoard.colorsList[5]
        text: qsTr("Join the numbers and get to the 2048 tile!")
        anchors.left: title2048.left
        anchors.leftMargin: 5
        anchors.top: title2048.bottom
        anchors.topMargin: 5
        font.pixelSize: 12
    }

    Rectangle {
        id: newGameButtonRect
        x: 170
        width: 125
        height: 40
        anchors.bottom: rectangleTiles.top
        anchors.bottomMargin: 10
        anchors.left: rectangleTiles.left
        anchors.leftMargin: 5
        color:gameBoard.colorsList[7]
        radius: 5

        Text {
            id: textNewGame
            color: gameBoard.colorsList[4]
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
            visible: mainButtons
        }
    }

    Rectangle {
        id: undoButtonRect
        x: 170
        width: 125
        height: 40
        anchors.bottom: rectangleTiles.top
        anchors.bottomMargin: 10
        anchors.right: rectangleTiles.right
        anchors.rightMargin: 5
        color: gameBoard.colorsList[7]
        radius: 5
        visible: gameModeBool

        Text {
            id: undoText
            color: gameBoard.colorsList[4]
            text: qsTr("Undo")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 19
        }

        MouseArea {
            id: undoButton
            anchors.fill: parent
            cursorShape: Qt.PointingHandCursor
            visible: mainButtons
        }
    }

    Rectangle {
        id: rectangleTiles
        y: 80
        width: (85*numberOfTiles + 10)
        height: (85*numberOfTiles + 10)
        color:  gameBoard.colorsList[0]
        radius: 15
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.top: parent.top
        anchors.topMargin: 150

        Repeater {
            model: numberOfTiles*numberOfTiles
            Rectangle {
                x: gameBoard.posX
                y: gameBoard.posY
                Behavior on x { PropertyAnimation { duration: 100}}
                Behavior on y { PropertyAnimation { duration: 100}}
                width: 75
                height: 75
                color: gameBoard.tileColor
                Behavior on color { PropertyAnimation { duration: 100}}
                radius: 5
                z: 1
                focus: true

                Text {
                    color: gameBoard.tileTextColor
                    text: gameBoard.tileNb
                    z: 2
                    font.family: textType
                    fontSizeMode: Text.FixedSize
                    textFormat: Text.AutoText
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.pixelSize: tileTextSize
                }
            }
        }

        Grid {
            x: 10
            y: 10
            rows: numberOfTiles
            columns: numberOfTiles
            spacing: 10

            Repeater {
                model: numberOfTiles*numberOfTiles
                Rectangle {
                    width: 75
                    height: 75
                    color:  gameBoard.colorsList[1]
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
}
