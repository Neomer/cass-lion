//
// Created by kir on 21.05.19.
//

#include "AbstractDatabaseDriver.h"
#include <exception>

AbstractDatabaseDriver::AbstractDatabaseDriver(AbstractDatabaseConfiguration *configuration) :
    _configuration{ configuration }
{
    if (configuration == nullptr) {
        throw std::invalid_argument("Configuration mustn't be null!");
    }
}

const AbstractDatabaseConfiguration *AbstractDatabaseDriver::getConfiguration() const
{
    return _configuration;
}
