//
// Created by kir on 22.05.19.
//

#ifndef CASS_LION_POSTGRESQLQUERY_H
#define CASS_LION_POSTGRESQLQUERY_H

#include <libpq-fe.h>
#include "../AbstractDatabaseQuery.h"

class PostgreSqlQuery : public AbstractDatabaseQuery
{
public:
    PostgreSqlQuery(PGresult *result);

    ~PostgreSqlQuery() override;

    bool first() override;

    bool eof() const override;

    void close() noexcept override;

    bool valid() const noexcept override;

private:
    PGresult *_result;
};


#endif //CASS_LION_POSTGRESQLQUERY_H
