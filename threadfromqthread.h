#ifndef THREADFROMQTHREAD_H
#define THREADFROMQTHREAD_H

#include <QMutex>
#include <QWaitCondition>
#include <QThread>

class ThreadFromQThread : public QThread
{
    Q_OBJECT
public:
    ThreadFromQThread(QObject *parent = nullptr);
    ~ThreadFromQThread() override;

    // wake on waitting thread
    void wakeOneThread();
    // block thread
    void threadWait();

protected:
    void run() override;

private:
    QMutex m_mutex;
    QWaitCondition m_waitCondition;
};

#endif // THREADFROMQTHREAD_H
