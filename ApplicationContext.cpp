//
// Created by kir on 23.05.19.
//

#include "ApplicationContext.h"
#include "Logs/ConsoleLogger.h"
#include "Core/RandomGenerator.h"

ApplicationContext &ApplicationContext::getInstance()
{
    static  ApplicationContext ctxt;
    return ctxt;
}

ApplicationContext::ApplicationContext() :
    _logger{ new ConsoleLogger{ } },
    _randomGenerator{ new RandomGenerator{ } }
{

}

ApplicationContext::~ApplicationContext()
{
    delete _randomGenerator;
}

void ApplicationContext::load(std::string_view filename)
{

}

void ApplicationContext::unload(std::string_view filename) const
{

}

const std::shared_ptr<AbstractLogger> &ApplicationContext::logger() const
{
    return _logger;
}

const AbstractRandomGenerator *ApplicationContext::getDefaultRandomGenerator() const
{
    return _randomGenerator;
}
