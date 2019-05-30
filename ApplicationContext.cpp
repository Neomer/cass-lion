//
// Created by kir on 23.05.19.
//

#include "ApplicationContext.h"
#include "Logs/ConsoleLogger.h"

ApplicationContext &ApplicationContext::getInstance()
{
    static  ApplicationContext ctxt;
    return ctxt;
}

ApplicationContext::ApplicationContext() :
    _logger{ new ConsoleLogger{ } }
{

}

ApplicationContext::~ApplicationContext()
{

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
