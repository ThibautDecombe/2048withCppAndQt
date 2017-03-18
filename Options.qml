import QtQuick 2.4
import QtQuick.Window 2.0

OptionsForm {
    id: optionsWindow
    width: (widthWindow - 20)
    height: (heightWindow - 20)

    classicButton.onClicked: {
        gameBoard.defineSetOfColors(1)
    }

    greenButton.onClicked: {
        gameBoard.defineSetOfColors(0)
    }

    x4Button.onClicked: {
        heightWindow = 400;
        widthWindow = 290;
}

    quitButton{
        onClicked: {optionsWindow.destroy();
                    a = true;}
    }

}
