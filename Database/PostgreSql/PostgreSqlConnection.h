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
    explicit PostgreSqlConnection(PGconn *conn);
    ~PostgreSqlConnection();

    void close() noexcept override;

    std::shared_ptr<AbstractDatabaseQuery> execute(std::string_view sql) const override;

    std::future<std::shared_ptr<AbstractDatabaseQuery>> beginExecute(std::string_view sql) const override;

    void beginTransaction(IsolationLevel isolationLevel) override;

    void commitTransaction() override;

    void rollbackTransaction() override;

    bool isInTransaction() const noexcept override;

private:
    PGconn *_connection;
    bool _inTransaction;
};


#endif //CASS_LION_POSTGRESQLCONNECTION_H
