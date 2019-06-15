//
// Created by kir on 13.06.19.
//

#include "ConnectionLimitExceededException.h"

ConnectionLimitExceededException::ConnectionLimitExceededException(const AbstractDatabaseDriver *driver) :
        DatabaseDriverException(driver)
{ }

ConnectionLimitExceededException::ConnectionLimitExceededException(const AbstractDatabaseDriver *driver,
                                                                   const std::string_view &message) :
        DatabaseDriverException(driver, message)
{ }

