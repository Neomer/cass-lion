//
// Created by kir on 29.05.19.
//

#include "QueryExecuteException.h"

QueryExecuteException::QueryExecuteException()
{

}

QueryExecuteException::QueryExecuteException(const std::string_view &message) :
        Exception(message)
{

}
