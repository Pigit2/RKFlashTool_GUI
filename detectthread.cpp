#include "detectthread.h"
#include "flashtool.h"

DetectThread::DetectThread(FlashTool *flashTool, QObject *parent)
    : QThread(parent), m_flashTool(flashTool), m_timer(nullptr) {}

DetectThread::~DetectThread() {
    if (m_timer) {
        m_timer->stop();
        delete m_timer;
    }
}

void DetectThread::run() {
    m_timer = new QTimer();
    m_timer->moveToThread(this);
    connect(m_timer, &QTimer::timeout, this, &DetectThread::detect);
    connect(this, &QThread::finished, m_timer, &QTimer::stop);

    m_timer->start(2000);  // 每2秒触发一次
    exec();  // 进入事件循环
}

void DetectThread::detect() {
    if (m_flashTool) {
        m_flashTool->detectDevices();
    }
}
