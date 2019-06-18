//
// Created by kir on 22.05.19.
//
#include <stdexcept>
#include "../../ApplicationContext.h"
#include "PostgreSqlQuery.h"
#include "PostgreSqlQueryValue.h"

using namespace std::string_literals;

PostgreSqlQuery::PostgreSqlQuery(PGresult *result) :
        AbstractDatabaseQuery(),
        _result{ result }
{
    if (valid())
    {
        _rowCount = PQntuples(result);
        _columnCount = PQnfields(result);
        _currentRow = 0;
    }
}

PostgreSqlQuery::~PostgreSqlQuery()
{
    close();
}

bool PostgreSqlQuery::first()
{
    if (!valid() || _rowCount == 0)
    {
        return false;
    }
    _currentRow = 0;
    return true;
}

bool PostgreSqlQuery::eof() const
{
    return !valid() || (_currentRow >= _rowCount);
}

void PostgreSqlQuery::close() noexcept
{
    if (_result != nullptr)
    {
        PQclear(_result);
        _result = nullptr;
    }
}

bool PostgreSqlQuery::valid() const noexcept
{
    auto status = PQresultStatus(_result);
    return status != PGRES_FATAL_ERROR &&
            status != PGRES_NONFATAL_ERROR &&
            status != PGRES_BAD_RESPONSE;
}

bool PostgreSqlQuery::next()
{
    ++_currentRow;
    return !eof();
}

size_t PostgreSqlQuery::rows() const
{
    return _rowCount;
}

uint16_t PostgreSqlQuery::columns() const
{
    return _columnCount;
}

std::optional<uint16_t> PostgreSqlQuery::columnByName(std::string_view name) const
{
    auto idx = PQfnumber(_result, ("\""s + name.data() + "\"").c_str());
    return idx < 0 ? std::nullopt : std::optional<uint16_t>{ idx };
}

std::shared_ptr<AbstractQueryValue> PostgreSqlQuery::value(uint16_t column) const
{
    return std::shared_ptr<AbstractQueryValue>(
            new PostgreSqlQueryValue(
                    PQgetvalue(_result, _currentRow, column),
                    PQftype(_result, column)));
}

