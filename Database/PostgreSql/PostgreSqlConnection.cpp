//
// Created by kir on 22.05.19.
//

#include "PostgreSqlConnection.h"
#include "PostgreSqlQuery.h"

PostgreSqlConnection::PostgreSqlConnection(PGconn *conn) :
        AbstractDatabaseConnection(),
        _connection{ conn },
        _inTransaction{ false }
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

void PostgreSqlConnection::beginTransaction(IsolationLevel isolationLevel)
{
    std::string sql = "BEGIN TRANSACTION ISOLATION LEVEL ";
    switch (isolationLevel)
    {
        case ReadCommitted: sql += "READ COMMITTED;"; break;

        case ReadUncommitted: sql += "READ UNCOMMITTED;"; break;

        case RepeatableRead: sql += "REPEATABLE READ;"; break;

        case Serializable: sql += "SERIALIZABLE;"; break;
    }
    PQexec(_connection, sql.c_str());
    _inTransaction = true;
}

void PostgreSqlConnection::commitTransaction()
{

}

void PostgreSqlConnection::rollbackTransaction()
{

}

bool PostgreSqlConnection::isInTransaction() const noexcept
{
    return _inTransaction;
}
