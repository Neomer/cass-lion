//
// Created by kir on 22.05.19.
//

#include "DatabaseConnectionRefusedException.h"

DatabaseConnectionRefusedException::DatabaseConnectionRefusedException(const AbstractDatabaseDriver *driver) :
        DatabaseDriverException(driver, "Database connection failed. Connection refused.")
{

}

DatabaseConnectionRefusedException::DatabaseConnectionRefusedException(const AbstractDatabaseDriver *driver,
                                                                       std::string_view message) :
        DatabaseDriverException(driver, message)
{

}

DatabaseConnectionRefusedException::~DatabaseConnectionRefusedException()
{

}
