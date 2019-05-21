//
// Created by kir on 21.05.19.
//

#ifndef CASS_LION_ABSTRACTDATABASEDRIVER_H
#define CASS_LION_ABSTRACTDATABASEDRIVER_H

#include <memory>
#include "AbstractDatabaseConfiguration.h"
#include "AbstractDatabaseConnection.h"

class AbstractDatabaseDriver {
public:
    AbstractDatabaseDriver(const AbstractDatabaseConfiguration &&configuration);
    virtual ~AbstractDatabaseDriver() = default;

    virtual std::shared_ptr<AbstractDatabaseConnection> open() = 0;
    virtual void close() = 0;

protected:
    const AbstractDatabaseConfiguration &_configuration;
};


#endif //CASS_LION_ABSTRACTDATABASEDRIVER_H
