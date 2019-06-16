//
// Created by kir on 15.06.19.
//

#include "AbstractBackgroundService.h"

AbstractBackgroundService::AbstractBackgroundService() :
    _started{ false }
{

}

AbstractBackgroundService::~AbstractBackgroundService()
{
    if (_startThread.joinable()) {
        _startThread.join();
    }
}

bool AbstractBackgroundService::isStarted() const
{
    return _started.load();
}

void AbstractBackgroundService::start()
{
    _startThread = std::thread([this]() -> void {
        initialize();
        _started = true;
    });
    _startThread.detach();
}
