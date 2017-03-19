import QtQuick 2.6
import QtGraphicalEffects 1.0

Rectangle {
    id: gameWindow
    width: (85*numberOfTiles + 160)//290
    height: (85*numberOfTiles + 160)
    color: gameBoard.colorOptionsQml
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
        color: gameBoard.colorOptionsQml
        radius: 5

        Image {
            id: image
            anchors.fill: parent
            source: "gear.png"
        }

        ColorOverlay {
            anchors.fill:image
            source: image
            color: gameBoard.colorOptionsQml
        }

        MouseArea {
            id: optionsButton
            anchors.fill: parent
            cursorShape: Qt.PointingHandCursor
            visible: a
        }
    }

    Text {
        id: title2048
        color: gameBoard.colorOptionsQml
        text: qsTr("2048")
        font.bold: true
        font.family: "Verdana"
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
        color: "#00ff00"
        radius: 5

        Text {
            id: scoreText
            text: qsTr("SCORE")
            anchors.top: parent.top
            anchors.topMargin: 5
            horizontalAlignment: Text.AlignHCenter
            anchors.fill: parent
            font.pixelSize: 10
        }

        Text {
            id: scoreValue
            text: qsTr("0")
            font.family: "Verdana"
            font.bold: true
            color: "#ffffff"
            anchors.top: parent.top
            anchors.topMargin: 16
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
        color: "#00ff00"
        radius: 5

        Text {
            id: bestScoreText
            text: qsTr("BEST")
            anchors.top: parent.top
            anchors.topMargin: 5
            horizontalAlignment: Text.AlignHCenter
            anchors.fill: parent
            font.pixelSize: 10
        }

        Text {
            id: bestScoreValue
            text: qsTr("1000")
            font.family: "Verdana"
            font.bold: true
            color: "#ffffff"
            anchors.top: parent.top
            anchors.topMargin: 16
            horizontalAlignment: Text.AlignHCenter
            anchors.fill: parent
            font.pixelSize: 14
        }
    }

    Text {
        id: textExplaining
        color: "#044e08" //gameBoard.colorOptionsQml
        text: qsTr("Join the numbers and get to the 2048 tile!")
        font.family: "Verdana"
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
        color: gameBoard.colorOptionsQml
        radius: 5

        Text {
            id: textNewGame
            color: gameBoard.colorOptionsQml
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
            visible: a
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
        color: "#73d216" // gameBoard.colorOptionsQml
        radius: 5

        Text {
            id: undoText
            color: "#044e08" // gameBoard.colorOptionsQml
            text: qsTr("Undo")
            font.family: "Verdana"
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
            visible: a
        }
    }

    Rectangle {
        id: rectangleTiles
        y: 80
        width: (85*numberOfTiles + 10)
        height: (85*numberOfTiles + 10)
        color: gameBoard.colorOptionsQml //"#007615"
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
                    fontSizeMode: Text.FixedSize
                    textFormat: Text.AutoText
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.pixelSize: 35
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
                    color: gameBoard.colorOptionsQml //"#054c0b"
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
