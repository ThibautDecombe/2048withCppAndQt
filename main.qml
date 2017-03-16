import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    property int numberOfTiles: gameBoard.numberOfTiles
    property int widthWindow: (60*numberOfTiles + 50)
    property int heightWindow: (60*numberOfTiles + 160)

    visible: true
    width: widthWindow
    height: heightWindow
    title: qsTr("2048")
    property bool a: true

    MainForm {
        anchors.fill: parent
        id: gameWindow
        //property variant window;

        newGameButton{
            onClicked: gameBoard.newGame()
        }

        optionsButton{
            onClicked: {
                a = false;
                var component = Qt.createComponent("Options.qml");
                console.log("Component Status:", component.status, component.errorString());
                var window = component.createObject(gameWindow, {"x": 10, "y": 10});

            }
        }

        }

    }
