//
// Created by kir on 29.05.19.
//

#include "QueryExecuteException.h"

QueryExecuteException::QueryExecuteException(std::string_view message) :
        Exception(message)
{

}

QueryExecuteException::QueryExecuteException(std::string_view sql, std::string_view message) :
    Exception{ message },
    _sql{ sql }
{

}

std::string_view QueryExecuteException::getSql() const
{
    return std::string_view(_sql);
}
