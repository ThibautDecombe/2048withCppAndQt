import QtQuick 2.4
import QtQuick.Window 2.0

GameoverForm {

    id: gameoverWindow
    width: (widthWindow - 20)
    height: (heightWindow - 20)
    property int textTypeInt: 0
    property bool optionsButtons: true


    quitButton.onClicked: {
        gameBoard.newGame()
        gameoverWindow.destroy();
                    mainButtons = true;
    }


}
