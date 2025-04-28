import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15
import QtGraphicalEffects 1.15

Dialog {
    id: warningDialog
    title: "系统关机"
    modal: true
    // closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside
    closePolicy: Popup.NoAutoClose
    padding: 20

    x: (Screen.width - width) / 2
    y: (Screen.height - height) / 2

    // 设置背景
    background: Rectangle {
        color: "#2c3e50"
        radius: 15
        border.color: "#34495e"
        border.width: 2

        // 添加渐变效果
        gradient: Gradient {
            GradientStop { position: 0.0; color: "#2c3e50" }
            GradientStop { position: 1.0; color: "#34495e" }
        }

        // 添加阴影效果
        layer.enabled: true
        layer.effect: DropShadow {
            transparentBorder: true
            horizontalOffset: 3
            verticalOffset: 3
            radius: 8.0
            samples: 17
            color: "#80000000"
        }
    }

    property int countdown: 3
    property int countdownValue: 3
    property var timer: countdownTimer

    Timer {
        id: countdownTimer
        interval: 1000
        repeat: true
        onTriggered: {
            if (countdown > 0) {
                countdown--
            } else {
                shutdownSystem()
            }
        }
    }

    contentItem: ColumnLayout {
        spacing: 30

        // 添加图标
        Image {
            Layout.alignment: Qt.AlignHCenter
            source: "qrc:/icons/shutdown.png"  // 确保添加对应的图标资源
            width: 64
            height: 64
            visible: false // 如果没有图标资源，设置为 false
        }

        // 倒计时文本
        Label {
            Layout.fillWidth: true
            horizontalAlignment: Text.AlignHCenter
            text: "系统将在 " + countdown + " 秒后关机"
            font.pixelSize: 18
            font.bold: true
            color: "white"

            // 添加动画效果
            SequentialAnimation on opacity {
                running: countdown <= 10
                loops: Animation.Infinite
                NumberAnimation { to: 0.3; duration: 500 }
                NumberAnimation { to: 1.0; duration: 500 }
            }
        }

        // 进度条
        ProgressBar {
            Layout.fillWidth: true
            Layout.preferredHeight: 6
            value: countdown
            from: 60
            to: 0

            background: Rectangle {
                implicitHeight: 6
                color: "#3498db"
                radius: 3
                opacity: 0.3
            }

            contentItem: Item {
                implicitHeight: 6

                Rectangle {
                    width: parent.width * shutdownDialog.countdown / countdownValue
                    height: parent.height
                    radius: 3
                    color: {
                        if (countdown <= countdownValue/2) return "#e74c3c"
                        if (countdown <= countdownValue/6) return "#f1c40f"
                        return "#2ecc71"
                    }

                    Behavior on color {
                        ColorAnimation { duration: 200 }
                    }
                }
            }
        }

        // 按钮容器
        RowLayout {
            Layout.alignment: Qt.AlignHCenter
            spacing: 20

            // 立即关机按钮
            Button {
                text: "立即关机"
                implicitWidth: 120
                implicitHeight: 40

                background: Rectangle {
                    radius: 20
                    color: parent.pressed ? "#c0392b" : parent.hovered ? "#e74c3c" : "#e74c3c"

                    Behavior on color {
                        ColorAnimation { duration: 100 }
                    }
                }

                contentItem: Text {
                    text: parent.text
                    color: "white"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                }

                onClicked: shutdownSystem()
            }

            // 取消按钮
            Button {
                text: "取消"
                implicitWidth: 120
                implicitHeight: 40

                background: Rectangle {
                    radius: 20
                    color: parent.pressed ? "#2980b9" : parent.hovered ? "#3498db" : "#3498db"

                    Behavior on color {
                        ColorAnimation { duration: 100 }
                    }
                }

                contentItem: Text {
                    text: parent.text
                    color: "white"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                }

                onClicked: {
                    countdownTimer.stop()
                    shutdownDialog.close()
                }
            }
        }
    }

    function shutdownSystem() {
        // console.log("执行关机操作")
        // Qt.quit()
        reboot()
    }

    onOpened: {
        countdown = countdownValue
        countdownTimer.start()
    }

    onClosed: {
        countdownTimer.stop()
    }

    // 打开/关闭动画
    enter: Transition {
        NumberAnimation { property: "opacity"; from: 0.0; to: 1.0; duration: 200 }
        NumberAnimation { property: "scale"; from: 0.9; to: 1.0; duration: 200 }
    }

    exit: Transition {
        NumberAnimation { property: "opacity"; from: 1.0; to: 0.0; duration: 200 }
        NumberAnimation { property: "scale"; from: 1.0; to: 0.9; duration: 200 }
    }

}
