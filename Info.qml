import QtQuick 2.0

InfoForm {
    id: infoWindow
    x: 10
    y: 10
    width: (widthWindow - 30)
    height: (heightWindow - 30)

    quitButton.onClicked: {
        infoWindow.destroy();
        optionsButtons = true;
    }
}
