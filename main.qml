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
        //property variant window;

        newGameButton{
            onClicked: gameBoard.newGame()
        }

        optionsButton{
            onClicked: {
                var component = Qt.createComponent("Options.qml");
                console.log("Component Status:", component.status, component.errorString());
                var window = component.createObject(gameWindow, {"x": 10, "y": 10});

            }
        }

        }

    }
