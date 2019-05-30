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
    enum IsolationLevel
    {
        Serializable,
        RepeatableRead,
        ReadCommitted,
        ReadUncommitted
    };

    /**
     *
     * @param sql
     * @return
     * @throws QueryExecuteException
     */
    virtual std::shared_ptr<AbstractDatabaseQuery> execute(std::string_view sql) const = 0;
    virtual void beginExecute(std::string_view sql, AsyncCallback<std::shared_ptr<AbstractDatabaseQuery>> &callback) const = 0;

    virtual void beginTransaction(IsolationLevel isolationLevel = ReadCommitted) = 0;

    /**
     * \throws QueryExecuteException
     */
    virtual void commitTransaction() = 0;
    virtual void rollbackTransaction() = 0;
    virtual bool isInTransaction() const noexcept = 0;


    virtual void close() noexcept = 0;
};


#endif //CASS_LION_ABSTRACTDATABASECONNECTION_H
