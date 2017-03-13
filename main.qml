import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 290
    height: 400
    title: qsTr("2048")

    MainForm {
        anchors.fill: parent
        id: gameWindow

        newGameButton{
            onClicked: gameBoard.newGame()
        }
        }

    }
