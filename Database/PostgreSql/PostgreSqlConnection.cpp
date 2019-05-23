//
// Created by kir on 22.05.19.
//

#include "PostgreSqlConnection.h"
#include "PostgreSqlQuery.h"

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
    auto query = PQexec(_connection, sql.data());
    return std::shared_ptr<AbstractDatabaseQuery>(new PostgreSqlQuery(query));
}

void PostgreSqlConnection::beginExecute(std::string_view sql,
                                        AsyncCallback<std::shared_ptr<AbstractDatabaseQuery>> &callback) const
{

}
