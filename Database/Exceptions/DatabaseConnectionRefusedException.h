//
// Created by kir on 22.05.19.
//

#ifndef CASS_LION_DATABASECONNECTIONREFUSEDEXCEPTION_H
#define CASS_LION_DATABASECONNECTIONREFUSEDEXCEPTION_H

#include "DatabaseDriverException.h"

class DatabaseConnectionRefusedException : public DatabaseDriverException
{
public:
    explicit DatabaseConnectionRefusedException(const AbstractDatabaseDriver *driver);

    explicit DatabaseConnectionRefusedException(const AbstractDatabaseDriver *driver, std::string_view message);

    ~DatabaseConnectionRefusedException() override;
};


#endif //CASS_LION_DATABASECONNECTIONREFUSEDEXCEPTION_H
