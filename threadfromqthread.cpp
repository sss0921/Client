#include "threadfromqthread.h"

#include <QLoggingCategory>

Q_LOGGING_CATEGORY(threadFromQThread, "Client.ThreadFromQThread")

ThreadFromQThread::ThreadFromQThread(QObject *parent)
    : QThread(parent)
{
}

void ThreadFromQThread::run()
{
    int a = 0;
    qCWarning(threadFromQThread) << "Thread begin";
    while (1) {
        a++;
        qCWarning(threadFromQThread) << "Thread wait %d" << a;
        m_mutex.lock();
        threadWait();
        m_mutex.unlock();
        qCWarning(threadFromQThread) << "Thread start";
    }
    qCWarning(threadFromQThread) << "Thread end";
}

void ThreadFromQThread::wakeOneThread()
{
    m_mutex.lock();
    m_waitCondition.wakeOne();
    m_mutex.unlock();
}

void ThreadFromQThread::threadWait()
{
    m_mutex.lock();
    m_waitCondition.wait(&m_mutex);
    m_mutex.unlock();
}
