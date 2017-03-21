import QtQuick 2.4

Item {
    width: 400
    height: 400
    property alias quitButton: quitButton
    property alias quitRectangle: quitRectangle

    Rectangle {
        id: rectangle
        anchors.fill: parent
        color: gameBoard.colorsList[3]
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        radius: 10

        Rectangle {
            id: quitRectangle
            width: 30
            height: 30
            color: gameBoard.colorsList[2]
            radius: 5
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.right: parent.right
            anchors.rightMargin: 10

            Text {
                id: text1
                color: gameBoard.colorsList[5]
                text: qsTr("X")
                font.weight: Font.ExtraBold
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.fill: parent
                font.pixelSize: 22
            }

            MouseArea {
                id: quitButton
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
            }
        }

        Text {
            id: infoText
            color: gameBoard.colorsList[5]
            text: "Informations"
            font.bold: true
            font.pointSize: 19
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.left: parent.left
            anchors.leftMargin: 10
        }

        Text {
            id: infosText
            x: 5
            width: 362
            height: 44
            color: gameBoard.colorsList[5]
            text: "Project created for the Centrale's \nsubject : C++ Graphical \ninterfaces programming with C++"
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.top: infoText.bottom
            anchors.topMargin: 20
            font.family: "Verdana"
            fontSizeMode: Text.FixedSize
            font.pixelSize: 19
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            id: studentsText
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.top: infosText.bottom
            anchors.topMargin: 50
            color: gameBoard.colorsList[5]
            text: "Students"
            font.pointSize: 19
            font.bold: true
        }

        Text {
            id: alexandreName
            color: gameBoard.colorsList[5]
            text: "Alexandre Teixeira da Silva"
            anchors.top: studentsText.bottom
            anchors.topMargin: 10
            anchors.left: parent.left
            anchors.leftMargin: 10
            font.family: "Verdana"
            font.pixelSize: 17
        }

        Text {
            id: juliaName
            color: gameBoard.colorsList[5]
            text: "Julia Coelho Santos"
            anchors.top: alexandreName.bottom
            anchors.topMargin: 5
            anchors.left: parent.left
            anchors.leftMargin: 10
            font.family: "Verdana"
            font.pixelSize: 17
        }

        Text {
            id: professorsText
            color: gameBoard.colorsList[5]
            text: "Professors"
            font.pointSize: 19
            font.bold: true
            anchors.top: juliaName.bottom
            anchors.topMargin: 20
            anchors.right: parent.right
            anchors.rightMargin: 10
        }

        Text {
            id: stephaneName
            color: gameBoard.colorsList[5]
            text: "Stephane Derrode"
            font.family: "Verdana"
            font.pixelSize: 17
            anchors.right: parent.right
            anchors.rightMargin: 10
            anchors.top: professorsText.bottom
            anchors.topMargin: 10
        }

        Text {
            id: emmanuelName
            color: gameBoard.colorsList[5]
            text: "Emmanuel Dellandrea"
            font.family: "Verdana"
            font.pixelSize: 17
            anchors.right: parent.right
            anchors.rightMargin: 10
            anchors.top: stephaneName.bottom
            anchors.topMargin: 5
        }
    }
}
