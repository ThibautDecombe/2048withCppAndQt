import QtQuick 2.4
import QtQuick.Window 2.0

OptionsForm {
    id: optionsWindow
    width: (widthWindow - 20)
    height: (heightWindow - 20)

    x4Button.onClicked: {
        heightWindow = 400;
        widthWindow = 290;
}

    quitButton{
        onClicked: {optionsWindow.destroy();
                    a = true;}
    }

}
