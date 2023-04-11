//page4.ver1
import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.12
import QtQuick.Dialogs


ApplicationWindow {
    id:window4
    visible: true
    width: 400
    height: 400
    title: "Grid Example"

    Grid {
        rows: 1
        columns: 5
        spacing: 0
        anchors.fill: parent

        Flickable {
            id: flickable1
            height: parent.height
            width: parent.width/2
            contentHeight:flickable1.height
            contentWidth: parent.width
            flickableDirection: Flickable.VerticalFlick
            clip: true

            ListModel {
                id: myModel1
                ListElement { context:"Colomn 1 123456789012345678901234567890123456789012345678901234567890" }
                ListElement { context:"Colomn 2" }
                ListElement { context:"Colomn 3" }
                ListElement { context:"Colomn 1 dweffwekhrwkejfhkwjefkjwbekfdbwkejbfkwjebfkwbekfbwkefjbwkejbfkwejbf" }
                ListElement { context:"Colomn 2" }
                ListElement { context:"Colomn 3" }
                ListElement { context:"Colomn 1 dweffwekhrwkejfhkwjefkjwbekfdbwkejbfkwjebfkwbekfbwkefjbwkejbfkwejbf" }
                ListElement { context:"Colomn 2" }
                ListElement { context:"Colomn 3" }
                ListElement { context:"Colomn 1 dweffwekhrwkejfhkwjefkjwbekfdbwkejbfkwjebfkwbekfbwkefjbwkejbfkwejbf" }
                ListElement { context:"Colomn 2" }
                ListElement { context:"Colomn 3" }
                ListElement { context:"Colomn 1 dweffwekhrwkejfhkwjefkjwbekfdbwkejbfkwjebfkwbekfbwkefjbwkejbfkwejbf" }
                ListElement { context:"Colomn 2" }
                ListElement { context:"Colomn 3" }
                ListElement { context:"Colomn 1 dweffwekhrwkejfhkwjefkjwbekfdbwkejbfkwjebfkwbekfbwkefjbwkejbfkwejbf" }
                ListElement { context:"Colomn 2" }
                ListElement { context:"Colomn 3" }
                ListElement { context:"Colomn 1 dweffwekhrwkejfhkwjefkjwbekfdbwkejbfkwjebfkwbekfbwkefjbwkejbfkwejbf" }
                ListElement { context:"Colomn 2" }
                ListElement { context:"Colomn 3" }
                ListElement { context:"Colomn 1 dweffwekhrwkejfhkwjefkjwbekfdbwkejbfkwjebfkwbekfbwkefjbwkejbfkwejbf" }
                ListElement { context:"Colomn 2" }
                ListElement { context:"Colomn 3" }
                ListElement { context:"Colomn 1 dweffwekhrwkejfhkwjefkjwbekfdbwkejbfkwjebfkwbekfbwkefjbwkejbfkwejbf" }
                ListElement { context:"Colomn 2" }
                ListElement { context:"Colomn 3" }
            }

            ListView {
                id: listView1
                height: parent.height
                width: 60
                model:myModel1
                anchors.verticalCenter: parent.verticalCenter
                delegate: Rectangle {
                    height: 20
                    width: parent.width
                    color: index % 2 === 0 ? "lightgray" : "white"

                    Text {
                        id:text1
                        text: index+1
                        anchors.verticalCenter: parent.verticalCenter
                        width:20
                    }

                    Rectangle {
                        id: button1
                        width: text1.width/2
                        height: text1.width/2
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.right: piece1.left

                        radius: width/2
                        color: "grey"

                        property bool isClicked: false

                        MouseArea {
                            anchors.fill: parent
                            onClicked:  {
                                button1.isClicked = !button1.isClicked
                                button1.color = button1.isClicked ? "red" : "grey"
                            }
                        }
                    }

                    Rectangle {
                        id: piece1
                        width: 10
                        anchors.right: parent.right

                    }


                }
                onContentYChanged: {
                    listView2.contentY = contentY
                }
            }

            Flickable {
                id: innerFlickable
                height: parent.height
                width: parent.width -listView1.width
                contentHeight: 200
                contentWidth: parent.width*6
                clip: true
                x:listView1.width

                ListView {
                    id: listView2
                    height: window4.height
                    width: window4.width /3*2
                    model: myModel1
                    delegate: Rectangle {
                        height: 20
                        width: parent.width*6
                        color: index % 2 === 0 ? "lightgray" : "white"
                        Text {
                            id:text2
                            text: context
                            anchors.verticalCenter: parent.verticalCenter
                        }
                    }
                    onContentYChanged: {
                        listView1.contentY = contentY
                    }
                }
            }
        }

        Rectangle {
            id:piece2
            color: "white"
            width: parent.width / 80
            height: parent.height
        }


        Rectangle {
            color: "white"
            width: parent.width -flickable1.width-piece2.width
            height: parent.height
            clip:true

            Grid {
                rows: 2
                columns: 1
                spacing: 0
                anchors.fill: parent

                ListModel {
                    id: myModel2
                    ListElement { signal:"s1" ;value:"1100 1100 0011 0011"}
                    ListElement { signal:"s2" ;value:"1100 1100 0011 0011"}
                    ListElement { signal:"s3" ;value:"1100 1100 0011 0011"}
                    ListElement { signal:"s4" ;value:"1100 1100 0011 0011"}
                    ListElement { signal:"s5" ;value:"1100 1100 0011 0011"}
                    ListElement { signal:"s6" ;value:"1100 1100 0011 0011"}
                    ListElement { signal:"s7" ;value:"1100 1100 0011 0011"}
                    ListElement { signal:"s8" ;value:"1100 1100 0011 0011"}
                    ListElement { signal:"s9" ;value:"1100 1100 0011 0011"}
                    ListElement { signal:"s10" ;value:"1100 1100 0011 0011"}
                    ListElement { signal:"s11" ;value:"1100 1100 0011 0011"}
                    ListElement { signal:"s1" ;value:"1100 1100 0011 0011"}
                    ListElement { signal:"s2" ;value:"1100 1100 0011 0011"}
                    ListElement { signal:"s3" ;value:"1100 1100 0011 0011"}
                    ListElement { signal:"s4" ;value:"1100 1100 0011 0011"}
                    ListElement { signal:"s5" ;value:"1100 1100 0011 0011"}
                    ListElement { signal:"s6" ;value:"1100 1100 0011 0011"}
                    ListElement { signal:"s7" ;value:"1100 1100 0011 0011"}
                    ListElement { signal:"s8" ;value:"1100 1100 0011 0011"}
                    ListElement { signal:"s9" ;value:"1100 1100 0011 0011"}
                    ListElement { signal:"s10" ;value:"1100 1100 0011 0011"}
                    ListElement { signal:"s11" ;value:"1100 1100 0011 0011"}
                }

                ListView {
                    id: listView3
                    height: parent.height-buttons1.height
                    width: parent.width
                    model:myModel2
                    delegate: Rectangle {
                        height: 20
                        width: parent.width
                        color: index % 2 === 0 ? "lightgray" : "white"

                        Text {
                            id:text3
                            text: index
                            anchors.verticalCenter: parent.verticalCenter
                            width:20
                        }

                        Text {
                            id:text4
                            text: signal
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.left: text3.right
                            width:100
                        }

                        Text {
                            id:text5
                            text: value
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.right: parent.right
                            width:125
                        }

                    }
                }

                Rectangle {
                    id:buttons1
                    height: parent.height/10
                    width: parent.width
                    color: "lightgray"

                    Button {
                        id:button41
                        width: height
                        height: parent.height/3*2
                        x:5
                        anchors.verticalCenter: parent.verticalCenter

                        contentItem: Image {
                            source: "qrc:/qresource/image1.png"
                            fillMode: Image.PreserveAspectFit
                        }

                        background: Rectangle {
                            color: "lightgreen"
                            radius: height/5
                        }

                        onClicked: {
                            console.log("play")
                        }
                    }

                    Button {
                        id:button42
                        width: height
                        height: parent.height/3*2
                        anchors.left: button41.right

                        anchors.verticalCenter: parent.verticalCenter

                        contentItem: Image {
                            source: "qrc:/qresource/image2.png"
                            fillMode: Image.PreserveAspectFit
                        }

                        background: Rectangle {
                            color: "lightblue"
                            radius: height/5
                        }

                        onClicked: {
                            console.log("next")
                        }
                    }

                    Button {
                        id:button43
                        width: height
                        height: parent.height/3*2
                        anchors.left: button42.right

                        anchors.verticalCenter: parent.verticalCenter

                        contentItem: Image {
                            source: "qrc:/qresource/image3.png"
                            fillMode: Image.PreserveAspectFit
                        }

                        background: Rectangle {
                            color: "grey"
                            radius: height/5
                        }

                        onClicked: {
                            console.log("pause")
                        }
                    }

                    FileDialog {
                        id: fileDialog4
                        title: "选择文件"

                        onAccepted: {
                            console.log("已选择的文件：", currentFiles)
                        }
                    }

                    Button {
                        id:button44
                        width: height*3
                        height: parent.height/3*2
                        anchors.right:  button45.left

                        anchors.verticalCenter: parent.verticalCenter

                        contentItem: Text {
                            id: name
                            text: qsTr("Select File")
                        }

                        background: Rectangle {
                            color: "lightblue"
                            radius: height/5
                        }

                        onClicked: {
                            console.log("Select File")
                            fileDialog4.open()
                        }
                    }


                    Button {
                        id:button45
                        width: height
                        height: parent.height/3*2
                        anchors.right: parent.right

                        anchors.verticalCenter: parent.verticalCenter

                        contentItem: Image {
                            source: "qrc:/qresource/image4.png"
                            fillMode: Image.PreserveAspectFit
                        }

                        background: Rectangle {
                            color: "orange"
                            radius: height/5
                        }

                        onClicked: {
                            console.log("update")
                        }
                    }

                }

            }


        }

    }

}
