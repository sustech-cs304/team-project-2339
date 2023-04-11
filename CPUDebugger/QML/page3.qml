//page3.ver1
import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.12
import QtQuick.Dialogs


ApplicationWindow {
    id:window1
    visible: true
    width: 640
    height: 480
    title: "Grid Example"

    Rectangle{
        color: "lightblue"
        anchors.fill: parent

        Rectangle{
            width: parent.width/8*7
            height: parent.height/8*7
            anchors.centerIn: parent

            Grid{
                rows: 1
                columns: 2
                spacing: 0
                anchors.fill: parent

                Rectangle {
                    id:left3
                    height: parent.height
                    width: parent.width/4*3

                    Rectangle {
                        height: parent.height/10
                        width: parent.width

                        Image {
                            id:image31
                            x:10
                            y:20
                            source: "qrc:/qresource/image31.png"
                            width: 25
                            height: 25
                            fillMode: Image.PreserveAspectFit
                        }

                        Text {
                            id:text31
                            x:20+image31.width
                            y:20
                            width: parent.width-image31.width
                            text: "Export UART Module"
                            font.pixelSize: 20
                            font.bold: true
                        }

                        Text {
                            id:text32
                            anchors.top: text31.bottom
                            anchors.left: text31.left
                            width: parent.width-image31.width
                            text: "Select a directory to export the UART debug module to, it must be under the main directory together with the top module. Note that other modules cannot be using UART."
                            font.pixelSize: 12
                            font.bold: false
                            wrapMode: Text.WordWrap
                        }

                        Rectangle {
                            id: piece3
                            anchors.top: text32.bottom
                            height: 20
                            anchors.right: parent.right

                        }

                        Image {
                            id:image32
                            anchors.top: piece3.bottom
                            x:10
                            source: "qrc:/qresource/image32.png"
                            width: 25
                            height: 25
                            fillMode: Image.PreserveAspectFit
                        }

                        Text {
                            id:text33
                            anchors.top: piece3.bottom
                            x:20+image32.width
                            width: parent.width-image32.width
                            text: "Burn to Board"
                            font.pixelSize: 20
                            font.bold: true
                        }

                        Text {
                            id:text34
                            anchors.top: text33.bottom
                            anchors.left: text33.left
                            width: parent.width-image32.width
                            text: "Generate bitstream and program the FPGA using VIVADO."
                            font.pixelSize: 12
                            font.bold: false
                            wrapMode: Text.WordWrap
                        }

                    }

                }

                Rectangle {
                    id:right3
                    height: parent.height
                    width: parent.width/4

                    Button {
                        id:button31
                        width:  parent.width/2+3
                        height: width/3+2
                        x:20
                        y:40

                        anchors.horizontalCenter: parent.horizontalCenter

                        contentItem: Text {
                            text: qsTr(" Export to")
                            anchors.centerIn: parent
                            color: "white"
                            font.pixelSize: 13
                        }

                        background: Rectangle {
                            color: "grey"
                            radius: height/5
                        }

                        onClicked: {
                            console.log("Export to")
                        }
                    }

                    Button {
                        id:button32
                        width:  parent.width/2+4
                        height: width/3+2
                        x:20
                        y:120

                        anchors.horizontalCenter: parent.horizontalCenter

                        contentItem: Text {
                            text: qsTr(" Complete")
                            anchors.centerIn: parent
                            color: "white"
                            font.pixelSize: 13
                        }

                        background: Rectangle {
                            color: "grey"
                            radius: height/5
                        }

                        onClicked: {
                            console.log("Complete")
                        }
                    }

                    Button {
                        id:button33
                        width:  parent.width/2+4
                        height: width/3+2
                        x:20
                        y:220

                        anchors.horizontalCenter: parent.horizontalCenter

                        contentItem: Text {
                            text: qsTr(" Compfirm")
                            anchors.centerIn: parent
                            color: "white"
                            font.pixelSize: 13
                        }

                        background: Rectangle {
                            color: "orange"
                            radius: height/5
                        }

                        onClicked: {
                            console.log("Comfirm3")
                        }
                    }

                }


            }

        }


    }


}
