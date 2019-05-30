//
// Created by kir on 22.05.19.
//

#ifndef CASS_LION_DATABASEDRIVEREXCEPTION_H
#define CASS_LION_DATABASEDRIVEREXCEPTION_H

#include "../../Exceptions/Exception.h"
#include "../AbstractDatabaseDriver.h"

class DatabaseDriverException : public Exception
{
public:
    explicit DatabaseDriverException(const AbstractDatabaseDriver *driver);

    explicit DatabaseDriverException(const AbstractDatabaseDriver *driver, std::string_view message);

    virtual ~DatabaseDriverException() override;

    const AbstractDatabaseDriver *getDriver() const;

private:
    const AbstractDatabaseDriver *_driver;
};


#endif //CASS_LION_DATABASEDRIVEREXCEPTION_H
