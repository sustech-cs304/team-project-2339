import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Dialogs
import MyObj 1.0
import Qt.labs.platform 1.0

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("CPUDebugger")
    color:"lightgray"

    MyObject1{
        id:myobj
        value: 10
        string:"aaa"
        value1: 0
//        myList1: ["Apple", "Banana", "Cherry"]
//        myList2: ["Orange", "melon"]
//        myList41:["1","0","1","0"]

        Component.onCompleted:  {
            console.log(value,string)
        }
    }

    Rectangle{
        width: parent.width
        height: 40
        color: "#F0F8FF"
        Rectangle{
            id:rect11
            width: parent.width/2+5
            height: 30
            color: "lightgrey"
            radius: 5
            anchors.centerIn: parent

            Rectangle{
                width: parent.width-5
                height: 25
                color: "#F0F8FF"
                radius: 5
                anchors.centerIn: parent

                TabBar {
                    id: bar
                    width: parent.width
                    height: 25
                    anchors.centerIn: parent

                    TabButton {
                        id: btn1

                        height: parent.height
                        anchors.verticalCenter: parent.verticalCenter

                        Rectangle{
                            anchors.fill: parent
                            radius: 5
                            color: btn1.checked ? "white" : "#F0F8FF"
//                            border.color: btn1.checked ?"lightgrey":"#F0F8FF"
//                            border.width: 2
                        }

                        Text{
                            text: "Import"
                            color: btn1.checked ? "black" : "lightgrey"
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            anchors.centerIn: parent
                        }

                        background:Rectangle {
                            color: "#00F0F8FF"
                        }

                        Rectangle {
                                id: line1
                                width: 3
                                height: parent.height * 0.8
                                color: "lightgrey"
                                anchors {
                                    right: parent.right
                                    verticalCenter: parent.verticalCenter
                                }
                            }


                        onClicked: {
                            btn2.enabled=false
                            btn3.enabled=false
                            btn4.enabled=false
                        }
                        }
                    TabButton {
                        id:btn2
                        enabled: false

                        height: parent.height
                        anchors.verticalCenter: parent.verticalCenter

                        Rectangle{
                            anchors.fill: parent
                            radius: 5
                            color: btn2.checked ? "white" : "#F0F8FF"
//                            border.color: btn2.checked ?"lightgrey":"#F0F8FF"
//                            border.width: 2
                        }

                        Text{
                            text: "Signal"
                            color: btn2.checked ? "black" : "lightgrey"
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            anchors.centerIn: parent
                        }

                        background:Rectangle {
                            color: "#00F0F8FF"
                        }

                        Rectangle {
                                id: line2
                                width: 3
                                height: parent.height * 0.8
                                color: "lightgrey"
                                anchors {
                                    right: parent.right
                                    verticalCenter: parent.verticalCenter
                                }
                            }

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
                        enabled: false

                        height: parent.height
                        anchors.verticalCenter: parent.verticalCenter

                        Rectangle{
                            anchors.fill: parent
                            radius: 5
                            color: btn3.checked ? "white" : "#F0F8FF"
//                            border.color: btn3.checked ?"lightgrey":"#F0F8FF"
//                            border.width: 2
                        }

                        Text{
                            text: "Export"
                            color: btn3.checked ? "black" : "lightgrey"
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            anchors.centerIn: parent
                        }

                        background:Rectangle {
                            color: "#00F0F8FF"
                        }

                        Rectangle {
                                id: line3
                                width: 3
                                height: parent.height * 0.8
                                color: "lightgrey"
                                anchors {
                                    right: parent.right
                                    verticalCenter: parent.verticalCenter
                                }
                            }

                        onClicked: {
                            btn1.enabled=true
                            btn2.enabled=true
                            btn4.enabled=false
                        }
                    }
                    TabButton {
                        id:btn4
                        enabled: false

                        height: parent.height
                        anchors.verticalCenter: parent.verticalCenter
                        Rectangle{
                            anchors.fill: parent
                            radius: 5
                            color: btn4.checked ? "white" : "#F0F8FF"
//                            border.color: btn4.checked ?"lightgrey":"#F0F8FF"
//                            border.width: 2
                        }

                        Text{
                            text: "Debug"
                            color: btn4.checked ? "black" : "lightgrey"
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            anchors.centerIn: parent
                        }

                        background:Rectangle {
                            color: "#00F0F8FF"
                        }

                        onClicked: {
                            btn1.enabled=true
                            btn2.enabled=true
                            btn3.enabled=true
                        }
                    }
                }

            }

        }
    }

    StackLayout {   //栈布局管理器
        id:view
        y:40
        width: parent.width
        height: parent.height-40
        currentIndex: bar.currentIndex  //当前视图的索引
        Item {
            id:window1
            width: root.width
            height: root.height-20

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
                                width: parent.width/6*5
                                text: "CPU Top Module"
                                font.pixelSize: 25 * root.height/480
                                font.bold: true
                            }

                            Text {
                                id:text12
                                y:text11.height+10*root.height/480
                                width: parent.width/6*5
                                text: "The CPU top module must be a Verilog file which interconnects different components of the CPU. The debugger wil analyze the wires and some signals can be selected to be listened to during debugging."
                                font.pixelSize: 14  * root.height/480
                                font.bold: false
                                wrapMode: Text.WordWrap
                            }

                            Rectangle{
                                width: parent.width-text12.width-10
                                height: parent.height
                                anchors.verticalCenter: parent.verticalCenter
                                x:text11.width+10

                                FolderDialog {
                                    id: folderDialog1
                                    folder: StandardPaths.standardLocations(StandardPaths.PicturesLocation)[0] //默认打开Pictures文件夹

                                    onAccepted: {
                                        console.log("已选择的文件：", folder)
                                        if (folder!==null){
                                            console.log("fileDialog11: "+folder)
                                            button11.isSelected = true
                                            text14.show=false
                                            console.log(button11.isSelected)
                                        }
                                    }
                                    }

                                Button {
                                    id:button11
                                    width: height*3
                                    height: parent.height/4
                                    anchors.right:parent.right

                                    anchors.verticalCenter: parent.verticalCenter

                                    property bool isSelected: false

                                    contentItem: Text {
                                        text: qsTr("confirm")
                                        font.pixelSize: 15  * root.height/480
                                        horizontalAlignment: Text.AlignHCenter
                                        verticalAlignment: Text.AlignVCenter
                                        font.bold: button11.isSelected
                                    }

                                    background: Rectangle {
                                        color: button11.isSelected?"yellow":"lightgrey"
                                        radius: height/5
                                    }

                                    onClicked: {
                                        if(button11.isSelected){
                                            btn2.enabled=true
                                            bar.currentIndex=1
                                            myobj.confirm1()
                                            console.log("Confirm1")
                                            myobj.makeList1()
                                            myobj.makeList2()
                                            listView21.model=myobj.myList1
                                            listView22.model=myobj.myList2
                                            myobj.string=folderDialog1.folder

                                        }else{
                                            text14.show=true
                                        }
                                    }


                                }

                                Text {
                                    id: text14
                                    text: qsTr("Please check the file folder")
                                    visible: text14.show
                                    anchors.top: button11.bottom
                                    font.pixelSize: 10  * root.height/480
                                    color: "red"

                                    anchors.horizontalCenter: button11.horizontalCenter

                                    property bool show: false
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

                            MouseArea{
                                id:ma1
                                property bool entered: false
                                hoverEnabled: true
                                anchors.fill: parent
                                onEntered: {
                                    entered = true
                                }

                                onExited: {
                                    entered = false
                                }

                                onClicked: {
                                    console.log("Select Top")
                                    folderDialog1.open()
                                }

                                ToolTip{
                                    visible: button11.isSelected?parent.entered:false
                                    text: folderDialog1.folder
                                    x: ma1.mouseX+2
                                    y: ma1.mouseY-height-2
                                    delay: 200
                                }

                                Image {
                                    id:image11
                                    anchors.centerIn: bottom1.Center
                                    source: button11.isSelected?"qrc:/images/image12.svg":"qrc:/images/image11.svg"
                                    width: 50
                                    x:bottom1.width/2-25
                                    y:bottom1.height/2-25
                                    fillMode: Image.PreserveAspectFit
                                }

                                Text {
                                    id: text15
                                    text: qsTr("Please choose filefolder")
                                    visible: !button11.isSelected
                                    anchors.bottom: parent.bottom
                                    anchors.right: parent.right
                                    font.pixelSize: 18  * root.height/480
                                    color: "#99000000"
                                }
                            }
                        }
                    }
                }
            }
        }

        Item {
            id:window2
            width: root.width
            height: root.height-20

            Rectangle{
                anchors.fill: parent

                Rectangle {
                    id:left2
                    height: parent.height
                    width: middle2.x
                    visible: right2.showSignals

                    Rectangle {
                        id:left20
                        height: 30
                        width: left2.width
                        visible: right2.showSignals

                        Rectangle {
                            id:rect23
                            width: left2-60
                            height: 30
                            color: "white"
                            border.color: "lightgrey"
                            border.width: 3
                            radius: 10

                            TextInput {
                                id:ti2
                                x:10
                                y:5
                                anchors.margins: 2
                                font.pointSize: 15
                                focus: true
                                font.pixelSize: 16
                                activeFocusOnTab: true
                                selectByMouse: true
                                selectedTextColor: "white" //设置选择文本的字体颜色
                                selectionColor: "#4A6DBC" //设置选择框的颜色
                                verticalAlignment: TextInput.AlignVCenter
                                horizontalAlignment: TextInput.AlignLeft
                                leftPadding: 3
                                rightPadding: 3
                                maximumLength: 21

                                onEditingFinished: {
                                    console.log(ti2.text)
                                }
                            }

                        }

                        Button {
                            id:button26
                            width: 30
                            height: width
                            x:left2.width-60

                            background: Rectangle {
                                color: "white"
                                radius: 5
                                Image {
                                    source: "qrc:/images/image26.svg"
                                    fillMode: Image.PreserveAspectCrop
                                    anchors.fill: parent
                                }
                            }

                            onClicked: {
                                ti2.clear()
                            }
                        }

                        Button {
                            id:button27
                            width: 30
                            height: width
                            x:left2.width-30

                            background: Rectangle {
                                color: "white"
                                radius: 5
                                Image {
                                    source: "qrc:/images/image27.svg"
                                    fillMode: Image.PreserveAspectCrop
                                    anchors.fill: parent
                                }
                            }

                            onClicked: {
                                console.log(ti2.text)
                            }
                        }


                    }

                    Rectangle {
                        id:left21
                        height: parent.height-left20.height
                        width: left2.width/2
                        y:left20.height

                        visible: right2.showSignals

                        Rectangle {
                            id:rect21
                            height: 30
                            width: listView21.width
                            color: "white"
                            border.color: "#AA008000"
                            border.width: 2
                            radius:1

                            Text {
                                id:text26
                                text: "signal not chosen"
                                visible: true
                                font.pixelSize: 15
                                font.bold: true
                                anchors.centerIn: parent
                            }
                        }

                        ListView {
                            id: listView21
                            y:rect21.height
                            height: parent.height-rect21.height
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
                                        console.log(root.width+" "+root.height)
                                    }
                                }
                            }
                        }
                    }

                    Rectangle {
                        id:middle21
                        height: parent.height-left20.height
                        width: left2.width/2
                        x:left21.width
                        y:left20.height

                        Rectangle {
                            id:rect22
                            height: rect21.height
                            width: listView21.width
                            color: "white"
                            border.color: "#AA008080"
                            border.width: 2
                            radius:2

                            Text {
                                id:text27
                                text: "signal chosen"
                                visible: true
                                font.pixelSize: 15
                                font.bold: true
                                anchors.centerIn: parent
                            }
                        }


                        ListView {
                            id: listView22
                            y:rect22.height
                            height: parent.height-rect22.height
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

                }

                Rectangle {
                    id: middle2
                    width: 3
                    height: root.height
                    color: "grey"
                    x:280

                    MouseArea {
                        id: mouseArea
                        anchors.fill: parent // 将mouseArea的锚点设置为与rect完全对齐
                        drag.target: middle2 // 将rect设置为拖动的目标
                        drag.axis: Drag.XAxis // 只允许在X轴上拖动
                        drag.minimumX: 280 // 设置拖动的最小X坐标为0
                        drag.maximumX: root.width-200// 设置拖动的最大X坐标为父容器的宽度减去rect的宽度
                    }
                }

                Rectangle {
                    color: "lightblue"
                    id:right2
                    height: parent.height
                    width: right2.showSignals?parent.width-left2.width:parent.width-middle2.width
                    clip: true
                    x:middle2.x+middle2.width

                    property bool showSignals: true

                    Image {
                        id: image
                        source: name
                        fillMode: Image.PreserveAspectFit
                        clip: true

                        property real scale: 1.0
                        property real offsetX: 0.0
                        property real offsetY: 0.0

                        property string name: "qrc:/images/aabb.svg"

                        MouseArea {
                            anchors.fill: parent
                            drag.target: image
                            onPositionChanged: {
                                image.offsetX += drag.x / image.scale;
                                image.offsetY += drag.y / image.scale;
                                image.x = image.offsetX;
                                image.y = image.offsetY;
                            }
                        }


                        function scaleImage(factor) { // 定义一个function，参数是缩放因子
                            var newFactor = (factor-1)/20+1
                            var newWidth = width * factor; // 计算缩放后的宽度
                            var newHeight = height * factor; // 计算缩放后的高度
                            if (newWidth < right2.width || newWidth>image.sourceSize.width) { // 如果缩放后的宽度或高度低于最小值
                                return; // 不进行缩放，直接返回
                            }
                            if (newHeight < right2.height || newWidth>image.sourceSize.height) { // 如果缩放后的宽度或高度低于最小值
                                return; // 不进行缩放，直接返回
                            }
                            image.width = newWidth; // 否则，将图片的宽度设置为缩放后的宽度
                            image.height = newHeight; // 同时，将图片的高度设置为缩放后的高度

                            button28.count()
                            console.log( "aaa"+image.sourceSize.width + " "+image.sourceSize.height)
                        }

                        PinchArea {
                            anchors.fill: parent
                            onPinchUpdated: {
                                image.scaleImage(pinch.scale)
        //                            image.scale *= ((pinch.scale-1)/4+1);
        //                            image.width = image.sourceSize.width * image.scale;
        //                            image.height = image.sourceSize.height * image.scale;
                                console.log(pinch.scale)
                            }
                        }

                    }

                    Button {
                        id:button28
                        width: 70
                        height: 25
                        x:parent.width-width-150
                        y:20
                        z:1

                        property int number: 100

                        function count() {
                            var w = image.sourceSize.width/right2.width;
                            var h = image.sourceSize.height/right2.height;
                            if (w<h) {
                                button28.number=image.width*100/right2.width
                            }else{
                                button28.number=image.height*100/right2.height
                            }
                        }

                        contentItem: Text {
                            text: button28.number+qsTr("%")
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }

                        background: Rectangle {
                            color: "lightblue"
                            radius: height/5
                        }

                        onClicked: {
                            image.width = image.sourceSize.width; // 否则，将图片的宽度设置为缩放后的宽度
                            image.height = image.sourceSize.height; // 同时，将图片的高度设置为缩放后的高度
                            count()
                        }

                        Component.onCompleted:  {
                            count()
                        }

                    }

                    Button {
                        id:button25
                        width: rect21.height
                        height: width
                        anchors.left:parent.left
                        anchors.top:parent.top

                        background: Rectangle {
                            color: "white"
                            radius: 5
                            Image {
                                source: right2.showSignals?"qrc:/images/image25.svg":"qrc:/images/image24.svg"
                                fillMode: Image.PreserveAspectCrop
                                anchors.fill: parent
                            }
                        }

                        onClicked: {
                            right2.showSignals=!right2.showSignals
                        }
                    }

                    Button {
                        id:button22
                        width: 70
                        height: 25
                        x:parent.width-width-50
                        y:20
                        z:1

                        contentItem: Text {
                            text: qsTr("Confirm")
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }

                        background: Rectangle {
                            color: "orange"
                            radius: height/5
                        }

                        onClicked: {
                            console.log("myob")
                            myobj.loadSvgPath()
                            console.log(myobj.string)
                            image.name=myobj.string
                            console.log("myob1")
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
                        anchors.right: button23.right
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

        Item {
            id:window3
            width: root.width
            height: root.height-20

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
                                    y:20 * root.height/480
                                    source: "qrc:/images/image31.png"
                                    width: 25 * root.height/480
                                    height: width
                                    fillMode: Image.PreserveAspectFit
                                }

                                Text {
                                    id:text31
                                    x:20+image31.width
                                    y:20 * root.height/480
                                    width: parent.width-image31.width
                                    text: "Export UART Module"
                                    font.pixelSize: 20 * root.height/480
                                    font.bold: true
                                }

                                Text {
                                    id:text32
                                    anchors.top: text31.bottom
                                    anchors.left: text31.left
                                    width: parent.width-image31.width
                                    text: "Select a directory to export the UART debug module to, it must be under the main directory together with the top module. Note that other modules cannot be using UART."
                                    font.pixelSize: 12 * root.height/480
                                    font.bold: false
                                    wrapMode: Text.WordWrap
                                }

                                Rectangle {
                                    id: piece31
                                    anchors.top: text32.bottom
                                    height: 20 * root.height/480
                                    anchors.right: parent.right
                                }

                                Rectangle{
                                    id: folderChoose
                                    width: text32.width
                                    height: button31.height
                                    anchors.left: text31.left
                                    anchors.top: piece31.bottom

                                    Rectangle {
                                        id:rect31
                                        width: parent.width-button31.width+10
                                        height: parent.height
                                        color: "#F3F6FA"
                                        clip: true
                                        border.width: 1
                                        border.color: "#DFE0E4"
                                        radius: 5

                                        Flickable {
                                            anchors.fill: parent
                                            contentWidth: inputBoxInput.width
                                            clip: true
                                            interactive: true


                                        TextInput {
                                            id: inputBoxInput
                                            text:folderDialog.folder
                                            color: "#707070"
                                            font.pixelSize: 16 * root.height/480
                                            activeFocusOnTab: true
                                            selectByMouse: true //是否可以选择文本
                                            selectedTextColor: "white" //设置选择文本的字体颜色
                                            selectionColor: "#4A6DBC" //设置选择框的颜色
                                            verticalAlignment: TextInput.AlignVCenter
                                            horizontalAlignment: TextInput.AlignLeft
                                            leftPadding: 3
                                            rightPadding: 3
                                            anchors.centerIn:parent
                                        }
                                        }
                                    }

                                    Button{
                                        id:button35
                                        x:rect31.width+10
                                        height: button31.height
                                        width: button31.width/2
                                        anchors.left: rect31.right

                                        contentItem: Text {
                                            text: qsTr("Path")
                                            color: "white"
                                            font.pixelSize: 13 * root.height/480
                                            horizontalAlignment: Text.AlignHCenter
                                            verticalAlignment: Text.AlignVCenter
                                        }

                                        background: Rectangle {
                                            color: "#AA0055ff"
                                            radius: height/5
                                        }

                                        MouseArea{
                                            anchors.fill: parent
                                            onClicked: {
                                                folderDialog.open()
                                                console.log(inputBoxInput.text)
                                            }
                                        }
                                    }

                                }

                                FolderDialog {
                                    id: folderDialog
                                    folder: StandardPaths.standardLocations(StandardPaths.PicturesLocation)[0] //默认打开Pictures文件夹
                                }

                                Rectangle {
                                    id: piece32
                                    anchors.top: folderChoose.bottom
                                    height: 20 * root.height/480
                                    anchors.right: parent.right
                                }

                                Image {
                                    id:image32
                                    anchors.top: piece32.bottom
                                    x:10
                                    source: "qrc:/images/image32.png"
                                    width: 25 * root.height/480
                                    height: width
                                    fillMode: Image.PreserveAspectFit
                                }

                                Text {
                                    id:text33
                                    anchors.top: piece32.bottom
                                    x:20+image32.width
                                    width: parent.width-image32.width
                                    text: "Burn to Board"
                                    font.pixelSize: 20 * root.height/480
                                    font.bold: true
                                }

                                Text {
                                    id:text34
                                    anchors.top: text33.bottom
                                    anchors.left: text33.left
                                    width: parent.width-image32.width
                                    text: "Generate bitstream and program the FPGA using VIVADO."
                                    font.pixelSize: 12 * root.height/480
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
                                y:20 * root.height/480+image31.height+text32.height+piece31.height

                                anchors.horizontalCenter: parent.horizontalCenter
                                anchors.bottom: folderChoose.bottom

                                contentItem: Text {
                                    text: qsTr("Export to")
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                    color: "white"
                                    font.pixelSize: 13 * root.height/480
                                }

                                background: Rectangle {
                                    color: "#AA0077ff"
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
                                anchors.top: controlB.bottom
                                y:button31.y+60 * root.height/480

                                anchors.horizontalCenter: parent.horizontalCenter

                                contentItem: Text {
                                    text: qsTr("Complete")
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                    color: "white"
                                    font.pixelSize: 13 * root.height/480
                                }

                                background: Rectangle {
                                    color: "#AA0099ff"
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
                                y:button32.y+60 * root.height/480

                                anchors.horizontalCenter: parent.horizontalCenter

                                contentItem: Text {
                                    text: qsTr("Detect")
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                    color: "white"
                                    font.pixelSize: 13 * root.height/480
                                }

                                background: Rectangle {
                                    color: "#AA00bbff"
                                    radius: height/5
                                }

                                onClicked: {
                                    console.log("detect")
                                    button34.isClicked=true
                                    myobj.detect()
                                }
                            }

                            Button {
                                id:button34
                                width:  parent.width/2+4
                                height: width/3+2
                                y:button33.y+60 * root.height/480
                                enabled: button34.isClicked

                                property bool isClicked: false

                                anchors.horizontalCenter: parent.horizontalCenter

                                contentItem: Text {
                                    text: qsTr("Confirm")
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                    color: "white"
                                    font.pixelSize: 13 * root.height/480
                                }

                                background: Rectangle {
                                    color: button34.isClicked? "orange":"lightgrey"
                                    radius: height/5
                                }

                                onClicked: {
                                    console.log("Confirm3")
                                    btn4.enabled=true
                                    bar.currentIndex=3
                                    listView3.model=myobj.myList2
                                }
                            }
                        }
                    }
                }
            }
        }

        Item {
            id:window4
            width: root.width
            height: root.height-20

            Rectangle{

                anchors.fill: parent

                Grid {
                    rows: 1
                    columns: 5
                    spacing: 0
                    anchors.fill: parent

                    Rectangle {
                        id:left4
                        color: "lightgrey"
                        height: parent.height
                        width: parent.width/2

                        Flickable {
                            id: flickable1
                            height: parent.height
                            width: parent.width
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
                                    color: "lightgrey"

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

                    }


                    Rectangle {
                        id:piece2
                        color: "gray"
                        width: 3
                        height: parent.height
                    }

                    Rectangle {
                        color: "#f8f4e7"
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
                            }

                            ListView {
                                id: listView3
                                height: parent.height-buttons4.height
                                width: parent.width-125
                                model:myobj.myList2
                                delegate: Rectangle {
                                    height: 20
                                    width: parent.width
                                    color: "#f8f4e7"

                                    Text {
                                        id:text3
                                        text: index
                                        anchors.verticalCenter: parent.verticalCenter
                                        width:20
                                    }

                                    Text {
                                        id:text4
                                        text: modelData
                                        anchors.verticalCenter: parent.verticalCenter
                                        anchors.left: text3.right
                                        width:100
                                    }

                                }
                            }

                            ListView {
                                id: listView4
                                height: listView3.height
                                width: 125
                                model:myModel42
                                anchors.right: parent.right
                                anchors.top:parent.top
                                delegate: Rectangle {
                                    height: 20
                                    width: parent.width
                                    color: "#f8f4e7"

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
                                anchors.bottom: parent.bottom

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
                                        myobj.sendResume()
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
                                        myobj.sendStep()
                                        listView2.model = null
                                        listView2.model = myobj.myList41
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
                                        color: "lightgrey"
                                        radius: height/5
                                    }

                                    onClicked: {
                                        console.log("pause")
                                        myobj.sendPause()
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
                                        text: qsTr("Select File")
                                        horizontalAlignment: Text.AlignHCenter
                                        verticalAlignment: Text.AlignVCenter
                                        font.pixelSize: 13*root.width/640
                                        font.bold: false
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

