//
// Created by kir on 21.05.19.
//

#ifndef CASS_LION_ABSTRACTDATABASECONNECTIONPOOL_H
#define CASS_LION_ABSTRACTDATABASECONNECTIONPOOL_H

#include <memory>
#include <vector>
#include <mutex>
#include <inttypes.h>
#include "AbstractDatabaseDriver.h"

class AbstractDatabaseConnectionPool {
public:
    AbstractDatabaseConnectionPool(AbstractDatabaseDriver *driver);

    virtual ~AbstractDatabaseConnectionPool();

    uint8_t getConnectionCountLimit() const;

    void setConnectionCountLimit(uint8_t connectionCountLimit);

    /**
     * Пытается найти в списке уже открытых соединений свободное, проверяя флаг AbstractDatabaseConnection::isBusy().
     * Если все подключения заняты, то создается новое подключение, если не превышен установленный лимит.
     * Изменить лимит подключений можно с помощью метода setConnectionCountLimit().
     * @return Указатель на первое свободное подключение, либо создает новое.
     * @throws ConnectionLimitExceededException не удалось создать новое подлючение, так как превышено максимально допустимое количество.
     */
    virtual std::shared_ptr<AbstractDatabaseConnection> getOrAddConnection();

private:
    AbstractDatabaseDriver *_driver;
    std::mutex _connectionListMtx;
    std::vector<std::shared_ptr<AbstractDatabaseConnection>> _connectionList;
    std::uint8_t _connectionCountLimit;
};


#endif //CASS_LION_ABSTRACTDATABASECONNECTIONPOOL_H
