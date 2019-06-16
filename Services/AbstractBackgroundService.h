//
// Created by kir on 15.06.19.
//

#ifndef CASS_LION_ABSTRACTBACKGROUNDSERVICE_H
#define CASS_LION_ABSTRACTBACKGROUNDSERVICE_H

#include <thread>
#include <atomic>

class AbstractBackgroundService
{
public:
    AbstractBackgroundService();

    virtual ~AbstractBackgroundService();

    void start();

    bool isStarted() const;

protected:
    virtual void initialize() = 0;

private:
    std::atomic_bool _started;
    std::thread _startThread;
};


#endif //CASS_LION_ABSTRACTBACKGROUNDSERVICE_H
