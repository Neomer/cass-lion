//
// Created by kir on 21.05.19.
//

#include "PostgreSqlDriver.h"
#include <libpq-fe.h>

PostgreSqlDriver::PostgreSqlDriver(const AbstractDatabaseConfiguration &&configuration) : AbstractDatabaseDriver(
        configuration) {

}

PostgreSqlDriver::~PostgreSqlDriver() {

}

void PostgreSqlDriver::open() {
    PQsetdbLogin()
}

void PostgreSqlDriver::close() {

}
