//
// Created by kir on 13.06.19.
//

#ifndef CASS_LION_CONNECTIONLIMITEXCEEDEDEXCEPTION_H
#define CASS_LION_CONNECTIONLIMITEXCEEDEDEXCEPTION_H


#include "DatabaseDriverException.h"

class ConnectionLimitExceededException : public DatabaseDriverException
{
public:
    ConnectionLimitExceededException(const AbstractDatabaseDriver *driver);

    ConnectionLimitExceededException(const AbstractDatabaseDriver *driver, const std::string_view &message);
};


#endif //CASS_LION_CONNECTIONLIMITEXCEEDEDEXCEPTION_H
