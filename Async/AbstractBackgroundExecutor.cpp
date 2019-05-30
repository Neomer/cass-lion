//
// Created by kir on 22.05.19.
//

#include <functional>
#include "AbstractBackgroundExecutor.h"
#include "Exceptions/BackgroundExecutorAlreadyBusy.h"

AbstractBackgroundExecutor::AbstractBackgroundExecutor() :
    _run{ true },
    _thread{ std::bind(&AbstractBackgroundExecutor::taskProc, this) },
    _task{ nullptr }
{

}

AbstractBackgroundExecutor::~AbstractBackgroundExecutor()
{
    _run = false;
    _condVar.notify_one();
    if (_thread.joinable()) {
        _thread.join();
    }
}

void AbstractBackgroundExecutor::taskProc()
{
    std::unique_lock<std::mutex> uniq(_lockMtx);
    while (_run.load()) {
        _condVar.wait(uniq);
        if (_task.load() != nullptr) {
            try
            {
                _task.load()->execute();
            }
            catch (Exception &e)
            {

            }
        }
    }
}

void AbstractBackgroundExecutor::addTask(AbstractTask *task)
{
    if (busy()) {
        throw BackgroundExecutorAlreadyBusy();
    }
    _task = task;

}

bool AbstractBackgroundExecutor::busy() const noexcept
{
    return _task.load() != nullptr;
}
