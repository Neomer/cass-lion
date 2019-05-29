//
// Created by kir on 29.05.19.
//

#include "AbstractDatabasePatcher.h"

AbstractDatabasePatcher::AbstractDatabasePatcher(AbstractDatabaseConnectionPool &abstractDatabaseConnectionPool) :
    _connection{ abstractDatabaseConnectionPool.getOrAddConnection() }
{

}

AbstractDatabasePatcher::AbstractDatabasePatcher(std::shared_ptr<AbstractDatabaseConnection> &connection) :
    _connection{ connection }
{

}

AbstractDatabasePatcher::~AbstractDatabasePatcher()
{

}

std::shared_ptr<AbstractDatabaseConnection> &AbstractDatabasePatcher::getConnection()
{
    return _connection;
}

