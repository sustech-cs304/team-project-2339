import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("test")
    color:"lightgray"

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
        anchors.centerIn: parent
        width: parent.width
        currentIndex: bar.currentIndex  //当前视图的索引
        Item {
            Text {
                anchors.centerIn: parent
                text: {
                    x:100
                    qsTr("Import")
                }
            }
            Button {
                onClicked: {
                    btn2.enabled=true
                    bar.currentIndex=1
                }
            }
        }
        Item {
            Text {
                anchors.centerIn: parent
                text: qsTr("Signal")
            }
            Button {
                onClicked: {
                    btn3.enabled=true
                    bar.currentIndex=2
                }
            }
        }
        Item {
            Text {
                anchors.centerIn: parent
                text: qsTr("Export")
            }
            Button {
                onClicked: {
                    btn4.enabled=true
                    bar.currentIndex=3
                }
            }
        }
        Item {
            Text {
                anchors.centerIn: parent
                text: qsTr("Debug")
            }
        }
    }

}

