//
// Created by kir on 21.05.19.
//

#ifndef CASS_LION_ABSTRACTDATABASECONNECTION_H
#define CASS_LION_ABSTRACTDATABASECONNECTION_H

#include <memory>
#include <string_view>
#include "AbstractDatabaseQuery.h"
#include "QueryResultCallback.h"

class AbstractDatabaseConnection {
public:
    AbstractDatabaseConnection();
    virtual ~AbstractDatabaseConnection();

    virtual std::shared_ptr<AbstractDatabaseQuery> execute(std::string_view sql) const = 0;

    virtual void close() noexcept = 0;
};


#endif //CASS_LION_ABSTRACTDATABASECONNECTION_H
