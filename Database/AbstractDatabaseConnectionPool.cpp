//
// Created by kir on 21.05.19.
//

#define CONNECTION_DEFAULT_LIMIT        20      // Максимально возможное количество подключений к базе данных по-умолчанию

#include <utility>
#include <algorithm>
#include "AbstractDatabaseConnectionPool.h"
#include "Exceptions/ConnectionLimitExceededException.h"

AbstractDatabaseConnectionPool::AbstractDatabaseConnectionPool(AbstractDatabaseDriver *driver) :
    _driver{ driver },
    _connectionCountLimit{ CONNECTION_DEFAULT_LIMIT }
{

}

AbstractDatabaseConnectionPool::~AbstractDatabaseConnectionPool()
{
    std::lock_guard guard(_connectionListMtx);
    std::for_each(_connectionList.begin(), _connectionList.end(),
                  [&](const std::shared_ptr<AbstractDatabaseConnection> &connection) {
                      connection->close();
                  });
}

std::shared_ptr<AbstractDatabaseConnection> AbstractDatabaseConnectionPool::getOrAddConnection()
{
    std::lock_guard guard(_connectionListMtx);

    auto it = std::find_if(_connectionList.begin(), _connectionList.end(),
            [&](const std::shared_ptr<AbstractDatabaseConnection> &connection) {
                return !connection->isBusy();
            });
    if (it != _connectionList.end()) {

        return *it;

    } else {

        if (_connectionList.size() >= _connectionCountLimit) {
            throw ConnectionLimitExceededException(_driver);
        }

        auto connection = std::shared_ptr<AbstractDatabaseConnection>(_driver->open());
        _connectionList.push_back(connection);

        return connection;
    }
}

uint8_t AbstractDatabaseConnectionPool::getConnectionCountLimit() const
{
    return _connectionCountLimit;
}

void AbstractDatabaseConnectionPool::setConnectionCountLimit(uint8_t connectionCountLimit)
{
    _connectionCountLimit = connectionCountLimit;
}
