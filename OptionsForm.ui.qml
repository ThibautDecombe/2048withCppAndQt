import QtQuick 2.4

Item {
    width: 370 //(widthWindow - 20)
    height: 495
    property alias practiceButton: practiceButton
    property alias normalButton: normalButton
    property alias fontTypeButton: fontTypeButton
    property alias fontSizeButton: fontSizeButton
    property alias classicButton: classicButton
    property alias greenButton: greenButton //(heightWindow - 20)
    property alias x4Button: x4Button
    property alias quitButton: quitButton

    Rectangle {
        id: optionsRect
        width: 270
        height: 380

        anchors.fill: parent
        color: "#bbffa9"

        Text {
            id: textOptions
            color: "#044e08"

            text: "Game Options"
            font.bold: true
            //font.family: "Verdana"
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
            color: "#73d216"
            radius: 5
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.right: parent.right
            anchors.rightMargin: 10

            Text {
                id: text1
                color: "#044e08"
                text: qsTr("X")
                font.weight: Font.ExtraBold
                font.bold: true
                font.family: "Verdana"
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
            id: textGameMode
            x: -7
            y: 6
            width: 173
            height: 25
            color: "#044e08"
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
            color: "#73d216"
            radius: 5
            anchors.right: parent.horizontalCenter
            anchors.rightMargin: 10
            anchors.topMargin: 10
            Text {
                id: normalText
                color: "#044e08"
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
            }
            anchors.top: textGameMode.bottom
        }

        Rectangle {
            id: practiceButtonRect
            width: 120
            height: 40
            color: "#73d216"
            radius: 5
            anchors.left: parent.horizontalCenter
            anchors.leftMargin: 10
            anchors.topMargin: 10
            Text {
                id: practiceText
                width: 80
                height: 40
                color: "#044e08"
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
            }
            anchors.top: textGameMode.bottom
        }

        Text {
            id: textColorScheme
            x: -4
            width: 173
            height: 25
            color: "#044e08"
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
            color: "#73d216"
            radius: 5
            anchors.right: parent.horizontalCenter
            anchors.rightMargin: 10
            anchors.top: textColorScheme.bottom
            anchors.topMargin: 10
            Text {
                id: greenText
                width: 80
                height: 40
                color: "#044e08"
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
            }
        }

        Rectangle {
            id: classicButtonRect
            width: 120
            height: 40
            color: "#73d216"
            radius: 5
            anchors.left: parent.horizontalCenter
            anchors.leftMargin: 10
            anchors.top: textColorScheme.bottom
            anchors.topMargin: 10
            Text {
                id: classicText
                width: 80
                height: 40
                color: "#044e08"
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
            }
        }

        Rectangle {
            id: otherButtonRect
            y: 7
            width: 120
            height: 40
            color: "#73d216"
            radius: 5
            anchors.left: parent.horizontalCenter
            anchors.leftMargin: 10
            anchors.topMargin: 10
            Text {
                id: otherText
                width: 80
                height: 40
                color: "#044e08"
                text: qsTr("Other")
                anchors.fill: parent
                fontSizeMode: Text.HorizontalFit
                font.bold: true
                font.pixelSize: 19
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            MouseArea {
                id: otherButton
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
            }
            anchors.top: greenButtonRect.bottom
        }

        Rectangle {
            id: neonButtonRect
            x: 7
            width: 120
            height: 40
            color: "#73d216"
            radius: 5
            anchors.right: parent.horizontalCenter
            anchors.rightMargin: 10
            anchors.top: greenButtonRect.bottom
            anchors.topMargin: 10
            Text {
                id: neonText
                width: 80
                height: 40
                color: "#044e08"
                text: qsTr("Neon")
                anchors.fill: parent
                fontSizeMode: Text.HorizontalFit
                font.bold: true
                font.pixelSize: 19
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            MouseArea {
                id: neonButton
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
            }
        }

        Text {
            id: textSize
            color: "#044e08"
            text: qsTr("Size")
            anchors.top: neonButtonRect.bottom
            anchors.topMargin: 10
            anchors.horizontalCenter: parent.horizontalCenter
            font.family: "Verdana"
            fontSizeMode: Text.FixedSize
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 22
        }

        Rectangle {
            id: x4ButtonRect
            width: 120 //(widthWindow - 50)/2
            height: 40
            color: "#73d216"
            radius: 5
            anchors.right: parent.horizontalCenter
            anchors.rightMargin: 10
            anchors.top: textSize.bottom
            anchors.topMargin: 10

            Text {
                id: x4Text
                width: 80
                height: 40
                color: "#044e08"
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
            }
        }

        Rectangle {
            id: x5ButtonRect
            width: 120 //(widthWindow - 50)/2
            height: 40
            color: "#73d216"
            radius: 5
            anchors.left: parent.horizontalCenter
            anchors.leftMargin: 10
            anchors.top: textSize.bottom
            anchors.topMargin: 10
            Text {
                id: x5Text
                width: 80
                height: 40
                color: "#044e08"
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
            }
        }

        Rectangle {
            id: x6ButtonRect
            x: 8
            width: 120
            //(widthWindow - 50)/2
            height: 40
            color: "#73d216"
            radius: 5
            anchors.right: parent.horizontalCenter
            anchors.rightMargin: 10
            anchors.top: x4ButtonRect.bottom
            anchors.topMargin: 10
            Text {
                id: x6Text
                width: 80
                height: 40
                color: "#044e08"
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
            }
        }

        Rectangle {
            id: x10ButtonRect
            width: 120 //(widthWindow - 50)/2
            height: 40
            color: "#73d216"
            radius: 5
            anchors.left: parent.horizontalCenter
            anchors.leftMargin: 10
            anchors.top: x5ButtonRect.bottom
            anchors.topMargin: 10
            Text {
                id: x10Text
                width: 80
                height: 40
                color: "#044e08"
                text: qsTr("10x10")
                font.pixelSize: 19
                horizontalAlignment: Text.AlignHCenter
                fontSizeMode: Text.HorizontalFit
                anchors.fill: parent
                font.bold: true
                verticalAlignment: Text.AlignVCenter
            }

            MouseArea {
                id: x10Button
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
            }
        }

        Text {
            id: fontSizeText
            x: 4
            color: "#044e08"
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
            color: "#73d216"
            radius: 5
            anchors.right: parent.horizontalCenter
            anchors.rightMargin: 10
            anchors.top: fontSizeText.bottom
            anchors.topMargin: 10
            Text {
                id: fontBSizeText
                width: 80
                height: 40
                color: "#044e08"
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
            }
        }

        Text {
            id: fontTypeText
            x: 5
            color: "#044e08"
            text: qsTr("Font Type")
            anchors.horizontalCenter: fontTypeButtonRect.horizontalCenter
            anchors.top: x10ButtonRect.bottom
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
            color: "#73d216"
            radius: 5
            anchors.left: parent.horizontalCenter
            anchors.leftMargin: 10
            anchors.top: fontTypeText.bottom
            anchors.topMargin: 10
            Text {
                id: fontBTypeText
                width: 80
                height: 40
                color: "#044e08"
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
            }
        }
    }
}
