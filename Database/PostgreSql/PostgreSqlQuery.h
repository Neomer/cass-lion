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

    ~PostgreSqlQuery();

    bool first() override;

    inline bool eof() const override;

    void close() noexcept override;

    bool valid() const noexcept override;

    bool next() override;

    size_t rows() const override;

    uint16_t columns() const override;

    std::optional<uint16_t> columnByName(std::string_view name) const override;

    std::shared_ptr<AbstractQueryValue> value(uint16_t column) const override;

private:
    PGresult *_result;
    size_t _currentRow, _rowCount;
    uint16_t _columnCount;
};


#endif //CASS_LION_POSTGRESQLQUERY_H
