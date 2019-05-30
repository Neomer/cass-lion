//
// Created by kir on 21.05.19.
//

#ifndef CASS_LION_ABSTRACTDATABASECONNECTIONPOOL_H
#define CASS_LION_ABSTRACTDATABASECONNECTIONPOOL_H

#include <memory>
#include "AbstractDatabaseDriver.h"

class AbstractDatabaseConnectionPool {
public:
    AbstractDatabaseConnectionPool();

    virtual ~AbstractDatabaseConnectionPool();

    virtual std::shared_ptr<AbstractDatabaseConnection> getOrAddConnection() = 0;
};


#endif //CASS_LION_ABSTRACTDATABASECONNECTIONPOOL_H
