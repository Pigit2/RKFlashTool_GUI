#ifndef FLASHTOOL_H
#define FLASHTOOL_H

#include <QObject>
#include <QProcess>
#include <QDebug>
#include <QRegularExpression>
#include "detectthread.h"

class DetectThread;

enum class DeviceMode {
    UNKNOWN,
    ADB,
    LOADER,
    MASKROM
};


class FlashTool : public QObject
{
    Q_OBJECT
public:
    explicit FlashTool(QObject *parent = nullptr);
    ~FlashTool();

    Q_INVOKABLE void detectDevices();
    Q_INVOKABLE void rebootToLoader();
    Q_INVOKABLE void flashFirmware(const QString &firmwarePath);

    DeviceMode currentMode() const { return m_currentMode; }

    enum FlashStatus {
        Idle,
        Flashing,
        Success,
        Failed
    };
    Q_ENUM(FlashStatus)

private:
    DetectThread *m_detectThread;
    DeviceMode m_currentMode = DeviceMode::UNKNOWN;

    void startDetecting();
    void updateCurrentMode(const QString &modeString);

    QProcess* m_flashProcess = nullptr;

signals:
    void updateLog(const QString &message);
    void addDevice(const QString &device);
    void showWarning(const QString &title, const QString &message);
    void flashProgressChanged(float progress);
    void flashStatus(FlashStatus status);
};

#endif // FLASHTOOL_H
