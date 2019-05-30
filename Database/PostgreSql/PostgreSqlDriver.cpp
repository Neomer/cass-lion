//
// Created by kir on 21.05.19.
//
#include <libpq-fe.h>
#include "PostgreSqlDriver.h"
#include "PostgreSqlDatabaseConfiguration.h"
#include "PostgreSqlConnection.h"
#include "../Exceptions/DatabaseConnectionRefusedException.h"

PostgreSqlDriver::PostgreSqlDriver(AbstractDatabaseConfiguration *configuration) :
        AbstractDatabaseDriver(configuration)
{

}

PostgreSqlDriver::~PostgreSqlDriver() {

}

std::shared_ptr<AbstractDatabaseConnection> PostgreSqlDriver::open()
{
    const PostgreSqlDatabaseConfiguration *pg_conf = static_cast<const PostgreSqlDatabaseConfiguration *>(AbstractDatabaseDriver::getConfiguration());

    auto conn = PQsetdbLogin(
            pg_conf->getHost(),
            pg_conf->getPort(),
            nullptr,
            nullptr,
            pg_conf->getDbname(),
            pg_conf->getUsername(),
            pg_conf->getPassword());

    auto status = PQstatus(conn);
    if (status == CONNECTION_BAD)
    {
        throw DatabaseConnectionRefusedException(this, PQerrorMessage(conn));
    }

    return std::shared_ptr<AbstractDatabaseConnection>(new PostgreSqlConnection(conn));
}

const char *PostgreSqlDriver::getDatabaseDriverName()
{
    return "PostgreSQL";
}

