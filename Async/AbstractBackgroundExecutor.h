//
// Created by kir on 22.05.19.
//

#ifndef CASS_LION_ABSTRACTBACKGROUNDEXECUTOR_H
#define CASS_LION_ABSTRACTBACKGROUNDEXECUTOR_H


#include <thread>
#include <condition_variable>
#include <mutex>
#include <atomic>
#include "AbstractTask.h"

class AbstractBackgroundExecutor
{
public:
    AbstractBackgroundExecutor();

    virtual ~AbstractBackgroundExecutor();

    bool busy() const noexcept;

    /// Поставить новую задачу на выполнение
    /// \param task задача для фонового выполнения
    /// \throws BackgroundExecutorAlreadyBusy попытка добавить задачу, пока не была завершена предыдущая
    void addTask(AbstractTask *task);

private:
    void taskProc();

    std::atomic_bool _run;
    std::thread _thread;
    std::mutex _lockMtx;
    std::condition_variable _condVar;
    std::atomic<AbstractTask *>_task;
};


#endif //CASS_LION_ABSTRACTBACKGROUNDEXECUTOR_H
