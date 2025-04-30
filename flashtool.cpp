#include "flashtool.h"

#define LOG_ON 0

FlashTool::FlashTool(QObject *parent)
    : QObject{parent}, m_detectThread(nullptr)
{
    startDetecting();

}

FlashTool::~FlashTool()
{
    if (m_detectThread) {
        m_detectThread->quit();
        m_detectThread->wait();
        delete m_detectThread;
    }
}


void FlashTool::startDetecting()
{
    if (!m_detectThread) {
        m_detectThread = new DetectThread(this);
        m_detectThread->start();
    }
}

void FlashTool::updateCurrentMode(const QString &modeString)
{
    if (modeString.contains("ADB")) {
        // qDebug() << "updateCurrentMode ADB";
        m_currentMode = DeviceMode::ADB;
    } else if (modeString.contains("Loader")) {
        // qDebug() << "updateCurrentMode Loader";
        m_currentMode = DeviceMode::LOADER;
    } else if (modeString.contains("Maskrom")) {
        // qDebug() << "updateCurrentMode Maskrom";
        m_currentMode = DeviceMode::MASKROM;
    } else {
        // qDebug() << "updateCurrentMode UNKNOWN";
        m_currentMode = DeviceMode::UNKNOWN;
    }
}

void FlashTool::detectDevices() {
    // qDebug() << "CurrentMode: " << int(m_currentMode);

    QProcess process;
    process.start("adb", {"devices"});
    process.waitForFinished();
    QString output = process.readAllStandardOutput() + process.readAllStandardError();
    // emit updateLog(output);

    // 解析adb设备
    QStringList lines = output.split('\n');
    for (const QString &line : lines) {
        if (line.contains("device") && !line.contains("List")) {
            emit addDevice("MODE: ADB " + line.split('\t').first());
            updateCurrentMode("ADB");
            return;
        }
    }

    // 解析loader设备
    process.start("tool/upgrade_tool", {"LD"});
    process.waitForFinished();
    output = process.readAllStandardOutput() + process.readAllStandardError();
    // emit updateLog(output);

    QStringList lines2 = output.split('\n');
    for (const QString &line : lines2) {
        if (line.contains("DevNo") && line.contains("Vid") && line.contains("Pid") && line.contains("LocationID") && line.contains("Mode")) {
            QString mode = line.split('\t').at(2).section('=', 1, 1);
            emit addDevice("MODE: " + mode);
            updateCurrentMode(mode);
            return;
        }
    }
    emit addDevice("No such device...");
    m_currentMode = DeviceMode::UNKNOWN;
}

void FlashTool::rebootToLoader() {
    if (m_currentMode == DeviceMode::LOADER || m_currentMode == DeviceMode::MASKROM) {
        qDebug() << "已在FLASH模式，无需切换";
        emit showWarning("警告", "已在FLASH模式，无需切换");
        return;
    }

    QProcess process;
    process.start("adb", {"reboot", "loader"});
    process.waitForFinished();
    emit updateLog(process.readAllStandardOutput() + process.readAllStandardError());

}

void FlashTool::flashFirmware(const QString &firmwarePath) {
    if (m_currentMode == DeviceMode::ADB || m_currentMode == DeviceMode::UNKNOWN) {
        qDebug() << "不在FLASH模式，无法刷写";
        emit showWarning("警告", "不在FLASH模式，无法刷写");
        return;
    }

#if LOG_ON
    emit updateLog("开始刷写固件: " + firmwarePath + "\n");
#endif

    if (m_flashProcess) {
        m_flashProcess->kill();
        m_flashProcess->deleteLater();
    }

    m_flashProcess = new QProcess(this);

    connect(m_flashProcess, &QProcess::readyReadStandardOutput, this, [this]() {
        QString output = m_flashProcess->readAllStandardOutput();

#if LOG_ON
        emit updateLog(output);
#endif

        // 提取进度信息
        QRegularExpression regex(R"(Total\((\d+)K\),Current\((\d+)K\))");
        QRegularExpressionMatch match = regex.match(output);
        if (match.hasMatch()) {
            bool ok1, ok2;
            double total = match.captured(1).toDouble(&ok1);
            double current = match.captured(2).toDouble(&ok2);
            if (ok1 && ok2 && total > 0) {
                float percent = current / total;
                emit flashProgressChanged(percent);
            }
        }
    });

    connect(m_flashProcess, &QProcess::readyReadStandardError, this, [this]() {
        QString error = m_flashProcess->readAllStandardError();
#if LOG_ON
        emit updateLog("错误: " + error);
#endif
    });

    connect(m_flashProcess, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            this, [this](int exitCode, QProcess::ExitStatus exitStatus) {
                emit updateLog(QString("刷写完成，退出码: %1\n").arg(exitCode));
                m_flashProcess->deleteLater();
                m_flashProcess = nullptr;
            });

    QStringList args = {"-c", "sudo tool/upgrade_tool uf \"" + firmwarePath + "\"" };
    m_flashProcess->start("script", args);
}
