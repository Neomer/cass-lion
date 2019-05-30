//
// Created by kir on 29.05.19.
//

#ifndef CASS_LION_POSTGRESQLDATABASEPATCHER_H
#define CASS_LION_POSTGRESQLDATABASEPATCHER_H

#include <vector>
#include "../AbstractDatabasePatch.h"
#include "../AbstractDatabasePatcher.h"

class PostgreSqlDatabasePatcher : public AbstractDatabasePatcher
{
public:
    PostgreSqlDatabasePatcher(AbstractDatabaseConnectionPool &abstractDatabaseConnectionPool);

    PostgreSqlDatabasePatcher(std::shared_ptr<AbstractDatabaseConnection> &connection);

    virtual ~PostgreSqlDatabasePatcher();

    void patch() override;

    const std::vector<std::shared_ptr<AbstractDatabasePatch>> patchList() const noexcept override;
};


#endif //CASS_LION_POSTGRESQLDATABASEPATCHER_H
