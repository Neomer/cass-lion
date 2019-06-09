//
// Created by kir on 29.05.19.
//

#ifndef CASS_LION_QUERYEXECUTEEXCEPTION_H
#define CASS_LION_QUERYEXECUTEEXCEPTION_H

#include "../../Exceptions/Exception.h"

class QueryExecuteException : public Exception
{
public:
    QueryExecuteException(std::string_view sql, std::string_view message);

    QueryExecuteException(std::string_view message);

    std::string_view getSql() const;

private:
    std::string _sql;
};


#endif //CASS_LION_QUERYEXECUTEEXCEPTION_H
