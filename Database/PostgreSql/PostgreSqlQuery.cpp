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

bool PostgreSqlQuery::next()
{
    return false;
}

size_t PostgreSqlQuery::rows() const
{
    return 0;
}

uint16_t PostgreSqlQuery::columns() const
{
    return 0;
}

uint16_t PostgreSqlQuery::columnByName(std::string_view name) const
{
    return 0;
}

std::shared_ptr<AbstractQueryValue> PostgreSqlQuery::value(uint16_t column) const
{
    return std::shared_ptr<AbstractQueryValue>();
}
