//
// Created by kir on 22.05.19.
//

#include "DatabaseDriverException.h"

DatabaseDriverException::~DatabaseDriverException()
{

}

DatabaseDriverException::DatabaseDriverException(const AbstractDatabaseDriver *driver) :
        Exception(),
        _driver{ driver }
{

}

DatabaseDriverException::DatabaseDriverException(const AbstractDatabaseDriver *driver, std::string_view message) :
        Exception(message),
        _driver{ driver }
{

}

const AbstractDatabaseDriver *DatabaseDriverException::getDriver() const
{
    return _driver;
}
