//
// Created by kir on 22.05.19.
//

#include "PostgresqlDatabaseConfiguration.h"

PostgresqlDatabaseConfiguration::PostgresqlDatabaseConfiguration() : AbstractDatabaseConfiguration() {

}

PostgresqlDatabaseConfiguration::~PostgresqlDatabaseConfiguration() {

}

const char *PostgresqlDatabaseConfiguration::getHost() const {
    return _host;
}

void PostgresqlDatabaseConfiguration::setHost(const char *host) {
    _host = host;
}

const char *PostgresqlDatabaseConfiguration::getPort() const {
    return _port;
}

void PostgresqlDatabaseConfiguration::setPort(const char *port) {
    _port = port;
}

const char *PostgresqlDatabaseConfiguration::getUsername() const {
    return _username;
}

void PostgresqlDatabaseConfiguration::setUsername(const char *username) {
    _username = username;
}

const char *PostgresqlDatabaseConfiguration::getPassword() const {
    return _password;
}

void PostgresqlDatabaseConfiguration::setPassword(const char *password) {
    _password = password;
}

const char *PostgresqlDatabaseConfiguration::getDbname() const {
    return _dbname;
}

void PostgresqlDatabaseConfiguration::setDbname(const char *dbname) {
    _dbname = dbname;
}
