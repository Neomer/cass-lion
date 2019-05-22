//
// Created by kir on 21.05.19.
//

#include "AbstractDatabaseDriver.h"

AbstractDatabaseDriver::AbstractDatabaseDriver(AbstractDatabaseConfiguration *configuration) :
    _configuration{ configuration }
{

}

const AbstractDatabaseConfiguration *AbstractDatabaseDriver::getConfiguration() const
{
    return _configuration;
}
