//
// Created by kir on 22.05.19.
//

#ifndef CASS_LION_POSTGRESQLCONNECTION_H
#define CASS_LION_POSTGRESQLCONNECTION_H

#include "../AbstractDatabaseConnection.h"
#include <libpq-fe.h>

class PostgreSqlConnection : public AbstractDatabaseConnection
{
public:
    PostgreSqlConnection(PGconn *conn);
    ~PostgreSqlConnection() override;
};


#endif //CASS_LION_POSTGRESQLCONNECTION_H
