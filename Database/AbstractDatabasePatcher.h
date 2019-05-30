//
// Created by kir on 29.05.19.
//

#ifndef CASS_LION_ABSTRACTDATABASEPATCHER_H
#define CASS_LION_ABSTRACTDATABASEPATCHER_H

#include <vector>
#include "AbstractDatabasePatch.h"
#include "AbstractDatabaseConnectionPool.h"

class AbstractDatabasePatcher
{
public:
    AbstractDatabasePatcher(AbstractDatabaseConnectionPool &abstractDatabaseConnectionPool);
    AbstractDatabasePatcher(std::shared_ptr<AbstractDatabaseConnection> &connection);

    virtual ~AbstractDatabasePatcher();

    virtual void patch() = 0;

    virtual const std::vector<std::shared_ptr<AbstractDatabasePatch>> patchList() const noexcept = 0;

protected:
    std::shared_ptr<AbstractDatabaseConnection> &getConnection();

private:
    std::shared_ptr<AbstractDatabaseConnection> _connection;
};


#endif //CASS_LION_ABSTRACTDATABASEPATCHER_H
