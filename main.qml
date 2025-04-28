import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.VirtualKeyboard 2.15
import Qt.labs.platform 1.1
import QtQuick.Controls 2.15
import Qt.labs.settings 1.0
// import QtQuick.Dialogs 1.3
// import Qt.labs.platform 1.1
// import "./"


import QtQuick.Layouts 1.15

ApplicationWindow {
    id: root
    visible: true
    width: 640
    height: 720
    title: "刷机工具"

    property string firmwarePath: ""
    property bool flashDone: false
    property bool flashFailed: false
    property bool isFlashing: false

    Settings {
        id: settings
        property string lastFilePath: "" // 保存上次选择的路径
    }

    ListModel {
        id: deviceModel
    }

    ColumnLayout {
        anchors.fill: parent
        spacing: 10
        // padding: 10

        RowLayout {
            spacing: 10
            Layout.fillWidth: true


            Button {
                text: "切换刷机模式"
                enabled: !isFlashing
                onClicked: tool.rebootToLoader()
            }
            Button {
                text: "选择固件文件"
                enabled: !isFlashing
                onClicked: fileDialog.open()
            }
            Button {
                text: "开始刷机"
                enabled: !isFlashing
                onClicked: {
                    if (firmwarePath) {
                        tool.flashFirmware(firmwarePath)
                    } else {
                        warningDialog.title = "警告"
                        messgeLable.text = "请先选择固件文件"
                        warningDialog.open()
                    }
                }
            }
        }

        TextArea {
            id: filePath
            text: "固件：未选择"
            readOnly: true
            wrapMode: TextArea.Wrap
            Layout.fillWidth: true
            // Layout.preferredHeight: 40
            // implicitHeight: contentHeight + 10
        }

        // Rectangle {
        //     Layout.fillWidth: true
        //     Layout.preferredHeight: 120
        //     border.color: "gray"
        //     border.width: 1

        //     ListView {
        //         id: deviceList
        //         anchors.fill: parent
        //         model: deviceModel
        //         delegate: Text {
        //             text: modelData
        //             font.pixelSize: 14
        //             padding: 4
        //         }
        //     }
        // }

        TextArea {
            id: devStatus
            readOnly: true
            wrapMode: TextArea.Wrap
            Layout.fillWidth: true
            // Layout.preferredHeight: 100
            implicitHeight: contentHeight + 10
        }


        ProgressBar {
            id: flashProgress
            Layout.alignment: Qt.AlignHCenter
            Layout.preferredWidth: parent.width * 0.8
            from: 0
            to: 1
            value: 0.0

            contentItem: Rectangle {
                width: parent.width * flashProgress.value
                height: parent.height
                radius: 3
                color: flashFailed ? "crimson" :
                       flashDone   ? "mediumseagreen" :
                                     "gray"
            }
        }

        Text {
            Layout.alignment: Qt.AlignHCenter
            text: flashFailed ? "刷写失败" :
                  flashDone   ? "刷写完成" :
                                Math.round(flashProgress.value * 100) + "%"
            font.pixelSize: 16
            color: flashFailed ? "crimson" :
                   flashDone   ? "mediumseagreen" :
                                 "black"
        }

        TextArea {
            id: logArea
            readOnly: true
            wrapMode: TextArea.Wrap
            Layout.fillWidth: true
            // Layout.preferredHeight: 120
        }
    }

    FileDialog {
        id: fileDialog
        title: "选择固件 (.img)"
        nameFilters: ["(*.img)"]

        // 在打开时恢复上次路径
        folder: settings.lastFilePath ? "file:///" + settings.lastFilePath : ""

        onAccepted: {
            if (fileDialog.currentFile) {
                firmwarePath = fileDialog.currentFile.toString().substring(7)
                filePath.text = "固件: " + firmwarePath
                // 保存选择的路径（去掉文件名，只保留目录）
                settings.lastFilePath = firmwarePath.substring(0, firmwarePath.lastIndexOf("/"))
            } else {
                logArea.text += "未选择文件或路径无效\n"
            }
        }
        onRejected: {
            logArea.text += "取消选择固件文件\n"
        }
    }

    Dialog {
        id: warningDialog
        title: "警告"
        standardButtons: Dialog.Ok
        anchors.centerIn: parent

        Label {
            id: messgeLable
            width: parent.width
            wrapMode: Text.Wrap
            text: "默认消息"
        }
    }

    Connections {
        target: tool

        function onUpdateLog(message) {
            logArea.text += message + "\n"
            if (message.indexOf("刷写完成") !== -1) {
                flashDone = true
            } else if (message.indexOf("错误") !== -1 || message.indexOf("失败") !== -1 || message.indexOf("fail") !== -1) {
                flashFailed = true
            }
        }

        function onAddDevice(device) {
            devStatus.text = device
        }

        function onShowWarning(title, message) {
            warningDialog.title = title
            messgeLable.text = message
            warningDialog.open()
        }

        function onFlashProgressChanged(progress) {
            flashProgress.value = progress
            flashDone = false
            flashFailed = false
        }


    }
}
