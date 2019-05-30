//
// Created by kir on 29.05.19.
//

#ifndef CASS_LION_QUERYEXECUTEEXCEPTION_H
#define CASS_LION_QUERYEXECUTEEXCEPTION_H

#include "../../Exceptions/Exception.h"

class QueryExecuteException : public Exception
{
public:
    QueryExecuteException();

    QueryExecuteException(const std::string_view &message);
};


#endif //CASS_LION_QUERYEXECUTEEXCEPTION_H
