//page4.ver1
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

        Grid{
            rows: 1
            columns: 2
            spacing: 0
            anchors.fill: parent

            Rectangle {
                id:left2
                height: parent.height
                width: parent.width/4

                ListModel {
                    id: myModel2
                    ListElement { signal:"signal1" }
                    ListElement { signal:"signal2" }
                    ListElement { signal:"signal3" }
                    ListElement { signal:"signal4" }
                    ListElement { signal:"signal5" }
                    ListElement { signal:"signal6" }
                    ListElement { signal:"signal7" }
                    ListElement { signal:"signal8" }
                    ListElement { signal:"signal9" }
                    ListElement { signal:"signal10" }

                }

                ListView {
                    id: listView21
                    height: parent.height
                    width: parent.width
                    model:myModel2
                    delegate: Rectangle {
                        height: 30
                        width: listView21.width
                        color: index % 2 === 0 ? "lightgray" : "white"

                        Text {
                            id:text21
                            text: " "+index
                            width:20
                            anchors.verticalCenter: parent.verticalCenter
                        }

                        Text {
                            id:text22
                            text: signal
                            width:100
                            anchors.left: text21.right
                            anchors.verticalCenter: parent.verticalCenter
                        }

                        Button {
                            id:button21
                            width: height
                            height: text22.height*1.5
                            anchors.right: parent.right
                            anchors.verticalCenter: parent.verticalCenter

                            contentItem: Image {
                                source: "qrc:/qresource/image21.png"
                                fillMode: Image.PreserveAspectFit
                            }

                            background: Rectangle {
                                color: "white"
                                radius: height/5
                            }

                            onClicked: {
                                console.log("delete"+index)
                                myModel2.remove(index)
                            }
                        }

                    }

                }


            }

            Rectangle {
                color: "lightblue"
                id:right2
                height: parent.height
                width: parent.width-left2.width

                Button {
                    id:button22
                    width: 70
                    height: 25
                    x:parent.width-width-50
                    y:20
                    z:1

                    contentItem: Text {
                        text: qsTr("  Confirm")
                        anchors.centerIn: parent
                    }

                    background: Rectangle {
                        color: "orange"
                        radius: height/5
                    }

                    onClicked: {
                        console.log("Comfirm2")
                    }
                }

                Button {
                    id:button23
                    width: button22.height
                    height: width
                    x:parent.width-45
                    anchors.verticalCenter: button22.verticalCenter

                    contentItem: Image {
                        source: "qrc:/qresource/image22.png"
                        fillMode: Image.PreserveAspectFit
                    }

                    background: Rectangle {
                        color: "white"
                        radius: height/5
                    }

                    onClicked: {
                        console.log(text23.infoV)
                        text23.infoV = !text23.infoV
                        text23.visible = text23.infoV
                    }

                }

                Text {
                    z:1
                    id: text23
                    y: button22.height+30
                    x:150
                    width: 300
                    text: qsTr("infomations Yesterday was a beautiful day with clear blue skies and a gentle breeze. I went for a walk in the park and enjoyed the colorful flowers and green trees. As I strolled, I listened to the birds chirping and watched children playing. ")
                    wrapMode: Text.WordWrap
                    visible: false
                    property bool infoV: false

                    Rectangle {
                        color: "lightgrey"
                        radius: 5
                        anchors.fill: parent
                        opacity:0.5
                        z:-1
                    }
                }
            }


        }

    }


}
