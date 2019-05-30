//
// Created by kir on 22.05.19.
//

#include "../../ApplicationContext.h"
#include "PostgreSqlConnection.h"
#include "PostgreSqlQuery.h"

PostgreSqlConnection::PostgreSqlConnection(PGconn *conn) :
        AbstractDatabaseConnection(),
        _connection{ conn },
        _inTransaction{ false }
{

}

PostgreSqlConnection::~PostgreSqlConnection() = default;

void PostgreSqlConnection::close() noexcept
{
    PQfinish(_connection);
}

std::shared_ptr<AbstractDatabaseQuery> PostgreSqlConnection::execute(std::string_view sql) const
{
    std::shared_ptr<AbstractDatabaseQuery> query(
            new PostgreSqlQuery(
                    PQexec(_connection, sql.data())));

    if (!query->valid())
    {
        ApplicationContext::getInstance().logger()->error(PQerrorMessage(_connection));
    }

    return query;
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
    execute(sql.c_str());
    _inTransaction = true;
}

void PostgreSqlConnection::commitTransaction()
{
    execute("COMMIT;");
}

void PostgreSqlConnection::rollbackTransaction()
{
    execute("ROLLBACK;");
}

bool PostgreSqlConnection::isInTransaction() const noexcept
{
    return _inTransaction;
}
