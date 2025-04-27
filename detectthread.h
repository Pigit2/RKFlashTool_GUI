#ifndef DETECTTHREAD_H
#define DETECTTHREAD_H

#include <QThread>
#include <QTimer>

class FlashTool;

class DetectThread : public QThread {
    Q_OBJECT
public:
    explicit DetectThread(FlashTool *flashTool, QObject *parent = nullptr);
    ~DetectThread();

protected:
    void run() override;

signals:
    void finished();

private slots:
    void detect();

private:
    FlashTool *m_flashTool;
    QTimer *m_timer;
};

#endif // DETECTTHREAD_H
