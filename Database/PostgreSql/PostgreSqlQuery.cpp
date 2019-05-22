//
// Created by kir on 22.05.19.
//
#include <stdexcept>
#include "PostgreSqlQuery.h"

PostgreSqlQuery::PostgreSqlQuery(PGresult *result) :
        AbstractDatabaseQuery(),
        _result{ result }
{

}

PostgreSqlQuery::~PostgreSqlQuery()
{
    close();
}

bool PostgreSqlQuery::first()
{
    return false;
}

bool PostgreSqlQuery::eof() const
{
    return false;
}

void PostgreSqlQuery::close() noexcept
{
    if (_result != nullptr) {
        PQclear(_result);
        _result = nullptr;
    }
}

bool PostgreSqlQuery::valid() const noexcept
{
    return _result != nullptr;
}
