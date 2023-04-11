//page1.ver1
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
                rows: 2
                columns: 1
                spacing: 0
                anchors.fill: parent

                Rectangle {
                    id:top1
                    height: parent.height/4
                    width: parent.width

                    Text {
                        id:text11
                        width: parent.width/3*2
                        text: "CPU Top Module"
                        font.pixelSize: 20
                        font.bold: true
                    }

                    Text {
                        id:text12
                        anchors.top: text11.bottom
                        width: parent.width/3*2
                        text: "The CPU top module must be a Verilog file which interconnects different components of the CPU. The debugger wil analyze the wires and some signals can be selected to be listened to during debugging."
                        font.pixelSize: 12
                        font.bold: false
                        wrapMode: Text.WordWrap
                    }

                    Rectangle{
                        id:buttons1
                        width: parent.width-text12.width-10
                        height: parent.height
                        anchors.verticalCenter: parent.verticalCenter
                        x:text11.width+10

                        FileDialog {
                            id: fileDialog11
                            title: "选择文件"

                            onAccepted: {
                                console.log("已选择的文件：", currentFiles)
                            }
                        }

                        Button {
                            id:button11
                            width: height*3
                            height: parent.height/4

                            anchors.verticalCenter: parent.verticalCenter

                            contentItem: Text {
                                text: qsTr("Select Top")
                                anchors.centerIn: parent
                            }

                            background: Rectangle {
                                color: "grey"
                                radius: height/5
                            }

                            onClicked: {
                                console.log("Select Top")
                                fileDialog11.open()
                            }
                        }

                        Button {
                            id:button12
                            width: height*3
                            height: parent.height/4
                            x:button11.width+10

                            anchors.verticalCenter: parent.verticalCenter

                            contentItem: Text {
                                text: qsTr("Select Top")
                                anchors.centerIn: parent
                            }

                            background: Rectangle {
                                color: "yellow"
                                radius: height/5
                            }

                            onClicked: {
                                console.log("Comfirm1")
                            }
                        }


                    }

                }

                Rectangle{
                    id:bottom1
                    width: parent.width
                    height: parent.height-top1.height
                    radius: 10
                    Column{
                        width:1
                        height:parent.height
                        spacing: 5
                        clip: true
                        anchors.left: parent.left
                        Repeater{
                            anchors.fill: parent
                            model: parent.height/10
                            delegate:Rectangle{
                                width: 1
                                height: 10
                                color: "black"
                            }
                        }
                    }
                    Column{
                        width:1
                        height:parent.height
                        spacing: 5
                        clip: true
                        anchors.right: parent.right
                        Repeater{
                            anchors.fill: parent
                            model: parent.height/10
                            delegate:Rectangle{
                                width:1
                                height: 10
                                color: "black"
                            }
                        }
                    }
                    Row{
                        width: parent.width
                        height: 1
                        spacing: 5
                        clip: true
                        anchors.top: parent.top
                        Repeater{
                            anchors.fill: parent
                            model: parent.width/10
                            delegate:Rectangle{
                                width: 10
                                height: 1
                                color: "black"
                            }
                        }
                    }
                    Row{
                        width: parent.width
                        height: 1
                        spacing: 5
                        clip: true
                        anchors.bottom: parent.bottom
                        Repeater{
                            anchors.fill: parent
                            model: parent.width/10
                            delegate:Rectangle{
                                width: 10
                                height: 1
                                color: "black"
                            }
                        }
                    }

                    Text {
                        id:text13
                        text: "top.v"
                        font.pixelSize: 16
                        font.bold: false
                        anchors.centerIn: parent
                    }

                    FileDialog {
                        id: fileDialog12
                        title: "选择文件"

                        onAccepted: {
                            console.log("已选择的文件：", currentFiles)
                        }
                    }


                    Button {
                        id:button13
                        width: height*3
                        height: parent.height/12
                        x:parent.width-width-10
                        y:parent.height-height-10

                        contentItem: Text {
                            text: qsTr("Select Def")
                            anchors.centerIn: parent
                        }

                        background: Rectangle {
                            color: "lightgrey"
                            radius: height/5
                        }

                        onClicked: {
                            console.log("Select Def")
                            fileDialog12.open()
                        }
                    }



                }



            }

        }


    }


}
