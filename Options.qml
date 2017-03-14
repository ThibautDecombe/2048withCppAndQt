import QtQuick 2.4
import QtQuick.Window 2.0

OptionsForm {
    id: optionsWindow
    width: 270
    height: 380

    quitButton{
        onClicked: optionsWindow.destroy();
    }

}
