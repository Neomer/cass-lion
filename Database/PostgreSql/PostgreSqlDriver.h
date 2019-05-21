//
// Created by kir on 21.05.19.
//

#ifndef CASS_LION_POSTGRESQLDRIVER_H
#define CASS_LION_POSTGRESQLDRIVER_H

#include "../AbstractDatabaseDriver.h"

class PostgreSqlDriver : public AbstractDatabaseDriver {
public:
    PostgreSqlDriver(const AbstractDatabaseConfiguration &&configuration);

    ~PostgreSqlDriver() override;

    void open() override;

    void close() override;
};


#endif //CASS_LION_POSTGRESQLDRIVER_H
