import QtQuick 2.4

Item {
    width: 370 //(widthWindow - 20)
    height: 495
    property alias brazilButton: brazilButton
    property alias franceButton: franceButton
    property alias infoButton: infoButton
    property alias practiceButton: practiceButton
    property alias normalButton: normalButton
    property alias fontTypeButton: fontTypeButton
    property alias fontSizeButton: fontSizeButton
    property alias classicButton: classicButton
    property alias greenButton: greenButton //(heightWindow - 20)
    property alias x4Button: x4Button
    property alias x5Button: x5Button
    property alias x6Button: x6Button
    property alias x7Button: x7Button
    property alias quitButton: quitButton

    Rectangle {
        id: optionsRect
        width: 270
        height: 380
        radius: 10

        anchors.fill: parent
        color: gameBoard.colorsList[6]

        Text {
            id: textOptions
            color: gameBoard.colorsList[5]
            text: "Game Options"
            font.bold: true
            font.pointSize: 19
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.left: parent.left
            anchors.leftMargin: 10
        }

        Rectangle {
            id: quitRectangle
            x: 232
            width: 30
            height: 30
            color: gameBoard.colorsList[7]
            radius: 5
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.right: parent.right
            anchors.rightMargin: 10

            Text {
                id: text1
                color: gameBoard.colorsList[4]
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
                visible: optionsButtons
            }
        }

        Text {
            id: textGameMode
            x: -7
            y: 6
            width: 173
            height: 25
            color: gameBoard.colorsList[5]
            text: qsTr("Game Mode")
            anchors.topMargin: 50
            fontSizeMode: Text.FixedSize
            font.pixelSize: 22
            anchors.horizontalCenter: parent.horizontalCenter
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.top: parent.top
        }

        Rectangle {
            id: normalButtonRect
            x: 17
            y: -1
            width: 120
            height: 40
            color: gameBoard.colorsList[7]
            radius: 5
            anchors.right: parent.horizontalCenter
            anchors.rightMargin: 10
            anchors.topMargin: 10
            Text {
                id: normalText
                color: gameBoard.colorsList[4]
                text: qsTr("Normal")
                anchors.fill: parent
                fontSizeMode: Text.HorizontalFit
                font.bold: true
                font.pixelSize: 19
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            MouseArea {
                id: normalButton
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                visible: optionsButtons
            }
            anchors.top: textGameMode.bottom
        }

        Rectangle {
            id: practiceButtonRect
            width: 120
            height: 40
            color: gameBoard.colorsList[7]
            radius: 5
            anchors.left: parent.horizontalCenter
            anchors.leftMargin: 10
            anchors.topMargin: 10
            Text {
                id: practiceText
                width: 80
                height: 40
                color: gameBoard.colorsList[4]
                text: qsTr("Practice")
                anchors.fill: parent
                fontSizeMode: Text.HorizontalFit
                font.bold: true
                font.pixelSize: 19
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            MouseArea {
                id: practiceButton
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                visible: optionsButtons
            }
            anchors.top: textGameMode.bottom
        }

        Text {
            id: textColorScheme
            x: -4
            width: 173
            height: 25
            color: gameBoard.colorsList[5]
            text: qsTr("Color Scheme")
            anchors.top: normalButtonRect.bottom
            anchors.topMargin: 10
            anchors.horizontalCenter: parent.horizontalCenter
            fontSizeMode: Text.FixedSize
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.family: "Verdana"
            font.pixelSize: 22
        }

        Rectangle {
            id: greenButtonRect
            x: 15
            width: 120
            height: 40
            color: gameBoard.colorsList[7]
            radius: 5
            anchors.right: parent.horizontalCenter
            anchors.rightMargin: 10
            anchors.top: textColorScheme.bottom
            anchors.topMargin: 10
            Text {
                id: greenText
                width: 80
                height: 40
                color: gameBoard.colorsList[4]
                text: qsTr("Green")
                font.bold: true
                fontSizeMode: Text.HorizontalFit
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 19
                anchors.fill: parent
            }

            MouseArea {
                id: greenButton
                cursorShape: Qt.PointingHandCursor
                anchors.fill: parent
                visible: optionsButtons
            }
        }

        Rectangle {
            id: classicButtonRect
            width: 120
            height: 40
            color: gameBoard.colorsList[7]
            radius: 5
            anchors.left: parent.horizontalCenter
            anchors.leftMargin: 10
            anchors.top: textColorScheme.bottom
            anchors.topMargin: 10
            Text {
                id: classicText
                width: 80
                height: 40
                color: gameBoard.colorsList[4]
                text: qsTr("Classic")
                font.bold: true
                fontSizeMode: Text.HorizontalFit
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 19
                anchors.fill: parent
            }

            MouseArea {
                id: classicButton
                cursorShape: Qt.PointingHandCursor
                anchors.fill: parent
                visible: optionsButtons
            }
        }

        Rectangle {
            id: franceButtonRect
            y: 7
            width: 120
            height: 40
            color: gameBoard.colorsList[7]
            radius: 5
            anchors.left: parent.horizontalCenter
            anchors.leftMargin: 10
            anchors.topMargin: 10
            Text {
                id: franceText
                width: 80
                height: 40
                color: gameBoard.colorsList[4]
                text: qsTr("France")
                anchors.fill: parent
                fontSizeMode: Text.HorizontalFit
                font.bold: true
                font.pixelSize: 19
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            MouseArea {
                id: franceButton
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                visible: optionsButtons
            }
            anchors.top: greenButtonRect.bottom
        }

        Rectangle {
            id: brazilButtonRect
            x: 7
            width: 120
            height: 40
            color: gameBoard.colorsList[7]
            radius: 5
            anchors.right: parent.horizontalCenter
            anchors.rightMargin: 10
            anchors.top: greenButtonRect.bottom
            anchors.topMargin: 10
            Text {
                id: brazilText
                width: 80
                height: 40
                color: gameBoard.colorsList[4]
                text: qsTr("Brazil")
                anchors.fill: parent
                fontSizeMode: Text.HorizontalFit
                font.bold: true
                font.pixelSize: 19
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            MouseArea {
                id: brazilButton
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                visible: optionsButtons
            }
        }

        Text {
            id: textSize
            color: gameBoard.colorsList[5]
            text: qsTr("Size")
            anchors.top: brazilButtonRect.bottom
            anchors.topMargin: 10
            anchors.horizontalCenter: parent.horizontalCenter
            fontSizeMode: Text.FixedSize
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 22
        }

        Rectangle {
            id: x4ButtonRect
            width: 120
            height: 40
            color: gameBoard.colorsList[7]
            radius: 5
            anchors.right: parent.horizontalCenter
            anchors.rightMargin: 10
            anchors.top: textSize.bottom
            anchors.topMargin: 10

            Text {
                id: x4Text
                width: 80
                height: 40
                color: gameBoard.colorsList[4]
                text: qsTr("4x4")
                font.bold: true
                anchors.fill: parent
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                fontSizeMode: Text.HorizontalFit
                font.pixelSize: 19
            }

            MouseArea {
                id: x4Button
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                visible: optionsButtons
            }
        }

        Rectangle {
            id: x5ButtonRect
            width: 120
            height: 40
            color: gameBoard.colorsList[7]
            radius: 5
            anchors.left: parent.horizontalCenter
            anchors.leftMargin: 10
            anchors.top: textSize.bottom
            anchors.topMargin: 10
            Text {
                id: x5Text
                width: 80
                height: 40
                color: gameBoard.colorsList[4]
                text: qsTr("5x5")
                font.pixelSize: 19
                horizontalAlignment: Text.AlignHCenter
                fontSizeMode: Text.HorizontalFit
                anchors.fill: parent
                font.bold: true
                verticalAlignment: Text.AlignVCenter
            }

            MouseArea {
                id: x5Button
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                visible: optionsButtons
            }
        }

        Rectangle {
            id: x6ButtonRect
            x: 8
            width: 120
            height: 40
            color: gameBoard.colorsList[7]
            radius: 5
            anchors.right: parent.horizontalCenter
            anchors.rightMargin: 10
            anchors.top: x4ButtonRect.bottom
            anchors.topMargin: 10
            Text {
                id: x6Text
                width: 80
                height: 40
                color: gameBoard.colorsList[4]
                text: qsTr("6x6")
                font.pixelSize: 19
                horizontalAlignment: Text.AlignHCenter
                fontSizeMode: Text.HorizontalFit
                anchors.fill: parent
                font.bold: true
                verticalAlignment: Text.AlignVCenter
            }

            MouseArea {
                id: x6Button
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                visible: optionsButtons
            }
        }

        Rectangle {
            id: x7ButtonRect
            width: 120
            height: 40
            color: gameBoard.colorsList[7]
            radius: 5
            anchors.left: parent.horizontalCenter
            anchors.leftMargin: 10
            anchors.top: x5ButtonRect.bottom
            anchors.topMargin: 10
            Text {
                id: x7Text
                width: 80
                height: 40
                color: gameBoard.colorsList[4]
                text: qsTr("7x7")
                font.pixelSize: 19
                horizontalAlignment: Text.AlignHCenter
                fontSizeMode: Text.HorizontalFit
                anchors.fill: parent
                font.bold: true
                verticalAlignment: Text.AlignVCenter
            }

            MouseArea {
                id: x7Button
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                visible: optionsButtons
            }
        }

        Text {
            id: fontSizeText
            x: 4
            color: gameBoard.colorsList[5]
            text: qsTr("Font Size")
            anchors.horizontalCenter: fontSizeButtonRect.horizontalCenter
            anchors.top: x6ButtonRect.bottom
            anchors.topMargin: 10
            font.family: "Verdana"
            fontSizeMode: Text.FixedSize
            font.pixelSize: 22
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        Rectangle {
            id: fontSizeButtonRect
            x: 6
            width: 120
            height: 40
            color: gameBoard.colorsList[7]
            radius: 5
            anchors.right: parent.horizontalCenter
            anchors.rightMargin: 10
            anchors.top: fontSizeText.bottom
            anchors.topMargin: 10
            Text {
                id: fontBSizeText
                width: 80
                height: 40
                color: gameBoard.colorsList[4]
                text: tileTextSize
                anchors.fill: parent
                fontSizeMode: Text.HorizontalFit
                font.bold: true
                font.pixelSize: 19
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            MouseArea {
                id: fontSizeButton
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                visible: optionsButtons
            }
        }

        Text {
            id: fontTypeText
            x: 5
            color: gameBoard.colorsList[5]
            text: qsTr("Font Type")
            anchors.horizontalCenter: fontTypeButtonRect.horizontalCenter
            anchors.top: x7ButtonRect.bottom
            anchors.topMargin: 10
            font.family: "Verdana"
            fontSizeMode: Text.FixedSize
            font.pixelSize: 22
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        Rectangle {
            id: fontTypeButtonRect
            width: 120
            height: 40
            color: gameBoard.colorsList[7]
            radius: 5
            anchors.left: parent.horizontalCenter
            anchors.leftMargin: 10
            anchors.top: fontTypeText.bottom
            anchors.topMargin: 10
            Text {
                id: fontBTypeText
                width: 80
                height: 40
                color: gameBoard.colorsList[4]
                text: textType
                anchors.fill: parent
                fontSizeMode: Text.HorizontalFit
                font.bold: true
                font.pixelSize: 19
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            MouseArea {
                id: fontTypeButton
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                visible: optionsButtons
            }
        }

        Rectangle {
            id: infoRectangle
            x: 232
            width: 30
            height: 30
            color: gameBoard.colorsList[7]
            radius: 5
            anchors.top: quitRectangle.top
            anchors.topMargin: 0
            anchors.right: quitRectangle.left
            anchors.rightMargin: 10

            Text {
                id: textInfo
                color: gameBoard.colorsList[4]
                text: qsTr("i")
                font.weight: Font.ExtraBold
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.fill: parent
                font.pixelSize: 22
            }

            MouseArea {
                id: infoButton
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                visible: optionsButtons
            }
        }
    }
}
