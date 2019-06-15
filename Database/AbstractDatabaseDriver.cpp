//
// Created by kir on 21.05.19.
//

#include "AbstractDatabaseDriver.h"
#include <exception>

AbstractDatabaseDriver::AbstractDatabaseDriver(std::unique_ptr<AbstractDatabaseConfiguration> configuration) :
    _configuration{ std::move(configuration) }
{
    if (_configuration.get() == nullptr) {
        throw std::invalid_argument("Configuration mustn't be null!");
    }
}

const AbstractDatabaseConfiguration *AbstractDatabaseDriver::getConfiguration() const
{
    return _configuration.get();
}
