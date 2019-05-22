//
// Created by kir on 22.05.19.
//

#ifndef CASS_LION_POSTGRESQLDATABASECONFIGURATION_H
#define CASS_LION_POSTGRESQLDATABASECONFIGURATION_H

#include "../AbstractDatabaseConfiguration.h"

class PostgreSqlDatabaseConfiguration : public AbstractDatabaseConfiguration {
public:
    PostgreSqlDatabaseConfiguration();
    ~PostgreSqlDatabaseConfiguration() override;

    const char *getHost() const;

    void setHost(const char *host);

    const char *getPort() const;

    void setPort(const char *port);

    const char *getUsername() const;

    void setUsername(const char *username);

    const char *getPassword() const;

    void setPassword(const char *password);

    const char *getDbname() const;

    void setDbname(const char *dbname);

private:
    const char *_host, *_port, *_username, *_password, *_dbname;
};


#endif //CASS_LION_POSTGRESQLDATABASECONFIGURATION_H
