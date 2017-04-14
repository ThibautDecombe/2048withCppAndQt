import QtQuick 2.4
import QtQuick.Window 2.0

YouWonForm {

    id: youWonWindow
    width: (widthWindow - 20)
    height: (heightWindow - 20)
    property int textTypeInt: 0
    property bool optionsButtons: true


    quitButton.onClicked: {
        youWonWindow.destroy();
                    mainButtons = true;
    }


}
