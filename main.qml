import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    property int numberOfTiles: gameBoard.numberOfTiles
    property int widthWindow: (85*numberOfTiles + 50)
    property int heightWindow: (85*numberOfTiles + 175)
    property int tileTextSize: 35
    property string textType: "Verdana"
    property bool gameModeBool: true

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

        undoButton{
            onClicked: gameBoard.undoGame()
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
