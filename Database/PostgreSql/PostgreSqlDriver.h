//
// Created by kir on 21.05.19.
//

#ifndef CASS_LION_POSTGRESQLDRIVER_H
#define CASS_LION_POSTGRESQLDRIVER_H

#include "../AbstractDatabaseDriver.h"

class PostgreSqlDriver : public AbstractDatabaseDriver {
public:
    PostgreSqlDriver(std::unique_ptr<AbstractDatabaseConfiguration> configuration);

    ~PostgreSqlDriver() override;

    std::shared_ptr<AbstractDatabaseConnection> open() override;

    const char *getDatabaseDriverName() override;
};


#endif //CASS_LION_POSTGRESQLDRIVER_H
