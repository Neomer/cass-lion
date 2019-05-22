//
// Created by kir on 22.05.19.
//

#include "PostgreSqlConnection.h"

PostgreSqlConnection::PostgreSqlConnection(PGconn *conn) :
        AbstractDatabaseConnection(),
        _connection{ conn }
{

}

PostgreSqlConnection::~PostgreSqlConnection()
{

}

void PostgreSqlConnection::close() noexcept
{
    PQfinish(_connection);
}

std::shared_ptr<AbstractDatabaseQuery> PostgreSqlConnection::execute(std::string_view sql) const
{
    return std::shared_ptr<AbstractDatabaseQuery>();
}
