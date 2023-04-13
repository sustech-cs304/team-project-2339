import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Dialogs
import MyObj 1.0

Window {
    id: root
    objectName: window
    visible: true
    width: 640
    height: 480
    title: qsTr("test")
    color:"lightgray"

    MyObject1{
        id:myobj
        value: 10
        string:"aaa"
        value1: 3
//        myList1: ["Apple", "Banana", "Cherry"]
//        myList2: ["Orange", "melon"]

        Component.onCompleted:  {
            console.log(value,string)
        }
    }

    TabBar {
        id: bar
        width: parent.width
        TabButton {
            id: btn1
            text: qsTr("Import")
            onClicked: {
                btn2.enabled=false
                btn3.enabled=false
                btn4.enabled=false
            }
        }
        TabButton {
            id:btn2
            text: qsTr("Signal")
            enabled: false
            onClicked: {
                btn1.enabled=true
                btn3.enabled=false
                btn4.enabled=false

                listView21.model=myobj.myList1
                listView22.model=myobj.myList2
            }
        }
        TabButton {
            id:btn3
            text: qsTr("Export")
            enabled: false
            onClicked: {
                btn1.enabled=true
                btn2.enabled=true
                btn4.enabled=false
            }
        }
        TabButton {
            id:btn4
            text: qsTr("Debug")
            enabled: false
            onClicked: {
                btn1.enabled=true
                btn2.enabled=true
                btn3.enabled=true
            }
        }
    }

    StackLayout {   //栈布局管理器
        id:view
        y:20
        width: parent.width
        currentIndex: bar.currentIndex  //当前视图的索引
        Item {
            id:window1
            width: 640
            height: 460

            Rectangle{
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
                                        button12.enabled=true
                                    }
                                }

                                Button {
                                    id:button12
                                    width: height*3
                                    height: parent.height/4
                                    x:button11.width+10
                                    enabled: false

                                    anchors.verticalCenter: parent.verticalCenter

                                    contentItem: Text {
                                        text: qsTr("  Confirm")
                                        anchors.centerIn: parent
                                    }

                                    background: Rectangle {
                                        color: "yellow"
                                        radius: height/5
                                    }

                                    onClicked: {
                                        btn2.enabled=true
                                        bar.currentIndex=1
                                        console.log("Comfirm1")
                                        myobj.makeList1()
                                        myobj.makeList2()
                                        listView21.model=myobj.myList1
                                        listView22.model=myobj.myList2
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

        Item {
            id:window2
            width: 640
            height: 460

            Rectangle{
                color: "lightblue"
                anchors.fill: parent

                Grid{
                    rows: 1
                    columns: 3
                    spacing: 0
                    anchors.fill: parent

                    Rectangle {
                        id:left2
                        height: parent.height
                        width: parent.width/4

                        ListView {
                            id: listView21
                            height: parent.height
                            width: parent.width
                            model:myobj.myList1
                            delegate: Rectangle {
                                height: 30
                                width: listView21.width
                                color: index % 2 === 0 ? "lightgray" : "white"

                                Text {
                                    id:text21
                                    text: " "+index
                                    width:20
                                    anchors.verticalCenter: parent.verticalCenter
                                    visible: true
                                }

                                Text {
                                    id:text22
                                    text: modelData
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
                                    visible: true

                                    contentItem: Image {
                                        source: "qrc:/images/image23.png"
                                        fillMode: Image.PreserveAspectFit
                                    }

                                    background: Rectangle {
                                        color: "white"
                                        radius: height/5
                                    }

                                    onClicked: {
                                        console.log("add"+modelData)
                                        myobj.addMyList2(modelData)
                                        listView22.model=myobj.myList2
                                        myobj.removeMyList1(index)
                                        listView21.model=myobj.myList1
                                    }
                                }

                            }

                        }


                    }

                    Rectangle {
                        id:middle2
                        height: parent.height
                        width: parent.width/4

                        ListView {
                            id: listView22
                            height: parent.height
                            width: parent.width
                            model:myobj.myList2
                            delegate: Rectangle {
                                height: 30
                                width: listView21.width
                                color: index % 2 === 0 ? "lightgray" : "white"

                                Text {
                                    id:text24
                                    text: " "+index
                                    width:20
                                    anchors.verticalCenter: parent.verticalCenter
                                    visible: true
                                }

                                Text {
                                    id:text25
                                    text: modelData
                                    width:100
                                    anchors.left: text24.right
                                    anchors.verticalCenter: parent.verticalCenter
                                }

                                Button {
                                    id:button24
                                    width: height
                                    height: text25.height*1.5
                                    anchors.right: parent.right
                                    anchors.verticalCenter: parent.verticalCenter
                                    visible: true

                                    contentItem: Image {
                                        source: "qrc:/images/image21.png"
                                        fillMode: Image.PreserveAspectFit
                                    }

                                    background: Rectangle {
                                        color: "white"
                                        radius: height/5
                                    }

                                    onClicked: {
                                        console.log("delete"+modelData)
                                        myobj.myList1.push(modelData)
                                        myobj.removeMyList2(index)
                                        listView21.model=myobj.myList1
                                        listView22.model=myobj.myList2
                                    }
                                }
                            }
                        }
                    }


                    Rectangle {
                        color: "lightblue"
                        id:right2
                        height: parent.height
                        width: parent.width-left2.width-middle2.width

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
                                btn3.enabled=true
                                bar.currentIndex=2
                            }
                        }

                        Button {
                            id:button23
                            width: button22.height
                            height: width
                            x:parent.width-45
                            anchors.verticalCenter: button22.verticalCenter

                            contentItem: Image {
                                source: "qrc:/images/image22.png"
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

        Item {
            id:window3
            width: 640
            height: 460

            Rectangle{
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
                                    source: "qrc:/images/image31.png"
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
                                    source: "qrc:/images/image32.png"
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
                                    btn4.enabled=true
                                    bar.currentIndex=3
                                }
                            }

                        }


                    }

                }


            }
        }

        Item {
            id:window4
            width: 640
            height: 460

            Rectangle{

                anchors.fill: parent

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

                        ListView {
                            id: listView1
                            height: parent.height
                            width: 60
                            model:myobj.myList41
                            anchors.verticalCenter: parent.verticalCenter
                            delegate: Rectangle {
                                height: 20
                                width: parent.width
                                color: "grey"

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
                                    color: "#555555"

                                    property bool isClicked: false

                                    MouseArea {
                                        anchors.fill: parent
                                        onClicked:  {
                                            button1.isClicked = !button1.isClicked
                                            button1.color = button1.isClicked ? "red" : "#555555"
                                            myobj.value=index+1
                                            myobj.makeBreakPoint()
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
                                model: myobj.myList41
                                delegate: Rectangle {
                                    id:rect1
                                    height: 20
                                    width: parent.width*6
                                    color: index+1 === myobj.value1 ? "lightblue":"lightgray"
                                    Text {
                                        id:text2
                                        text: modelData
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
                                id: myModel42
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
                                height: parent.height-buttons4.height
                                width: parent.width
                                model:myModel42
                                delegate: Rectangle {
                                    height: 20
                                    width: parent.width
                                    color: "white"

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
                                id:buttons4
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
                                        source: "qrc:/images/image1.png"
                                        fillMode: Image.PreserveAspectFit
                                    }

                                    background: Rectangle {
                                        color: "lightgreen"
                                        radius: height/5
                                    }

                                    onClicked: {
                                        console.log("play")
                                        myobj.asmRun()
                                    }
                                }

                                Button {
                                    id:button42
                                    width: height
                                    height: parent.height/3*2
                                    anchors.left: button41.right

                                    anchors.verticalCenter: parent.verticalCenter

                                    contentItem: Image {
                                        source: "qrc:/images/image2.png"
                                        fillMode: Image.PreserveAspectFit
                                    }

                                    background: Rectangle {
                                        color: "lightblue"
                                        radius: height/5
                                    }

                                    onClicked: {
                                        console.log("next")
                                        myobj.asmStep()
                                        console.log(myobj.value1)
                                    }
                                }

                                Button {
                                    id:button43
                                    width: height
                                    height: parent.height/3*2
                                    anchors.left: button42.right

                                    anchors.verticalCenter: parent.verticalCenter

                                    contentItem: Image {
                                        source: "qrc:/images/image3.png"
                                        fillMode: Image.PreserveAspectFit
                                    }

                                    background: Rectangle {
                                        color: "grey"
                                        radius: height/5
                                    }

                                    onClicked: {
                                        console.log("pause")
                                        myobj.asmPause()
                                    }
                                }

                                FileDialog {
                                    id: fileDialog4
                                    title: "选择文件"

                                    onAccepted: {
                                        console.log("已选择的文件：", currentFile)
                                        myobj.string=currentFile
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
                                        text: qsTr("   Select File")
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
                                        source: "qrc:/images/image4.png"
                                        fillMode: Image.PreserveAspectFit
                                    }

                                    background: Rectangle {
                                        color: "orange"
                                        radius: height/5
                                    }

                                    onClicked: {
                                        myobj.getAsmFile()
                                        listView1.model=myobj.myList41
                                        listView2.model=myobj.myList41
                                        console.log("update")
                                    }
                                }

                            }

                        }

                    }

                }

            }

        }
    }

}

