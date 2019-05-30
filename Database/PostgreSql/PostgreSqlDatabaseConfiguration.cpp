//
// Created by kir on 22.05.19.
//

#include "PostgreSqlDatabaseConfiguration.h"

PostgreSqlDatabaseConfiguration::PostgreSqlDatabaseConfiguration() :
    AbstractDatabaseConfiguration()
{

}

PostgreSqlDatabaseConfiguration::~PostgreSqlDatabaseConfiguration() = default;

const char *PostgreSqlDatabaseConfiguration::getHost() const {
    return _host;
}

void PostgreSqlDatabaseConfiguration::setHost(const char *host) {
    _host = host;
}

const char *PostgreSqlDatabaseConfiguration::getPort() const {
    return _port;
}

void PostgreSqlDatabaseConfiguration::setPort(const char *port) {
    _port = port;
}

const char *PostgreSqlDatabaseConfiguration::getUsername() const {
    return _username;
}

void PostgreSqlDatabaseConfiguration::setUsername(const char *username) {
    _username = username;
}

const char *PostgreSqlDatabaseConfiguration::getPassword() const {
    return _password;
}

void PostgreSqlDatabaseConfiguration::setPassword(const char *password) {
    _password = password;
}

const char *PostgreSqlDatabaseConfiguration::getDbname() const {
    return _dbname;
}

void PostgreSqlDatabaseConfiguration::setDbname(const char *dbname) {
    _dbname = dbname;
}
