//
// Created by kir on 23.05.19.
//

#include <utility>
#include "ApplicationContext.h"
#include "Logs/ConsoleLogger.h"
#include "Core/RandomGenerator.h"
#include "Database/PostgreSql/PostgreSqlDriver.h"
#include "Database/PostgreSql/PostgreSqlDatabaseConfiguration.h"

ApplicationContext &ApplicationContext::getInstance()
{
    static  ApplicationContext ctxt;
    return ctxt;
}

ApplicationContext::ApplicationContext() :
    _logger{ new ConsoleLogger{ } },
    _randomGenerator{ new RandomGenerator{ } },
    _metadataService{ new MetadataService{ } }
{
    _metadataService->start();
}

ApplicationContext::~ApplicationContext()
{
    delete _randomGenerator;
    delete _connectionPool;
}

void ApplicationContext::load(std::string_view filename)
{
    std::unique_ptr<AbstractDatabaseConfiguration> cfg(new PostgreSqlDatabaseConfiguration());

    loadDatabaseConfig(cfg.get());
    _connectionPool = new AbstractDatabaseConnectionPool(
            new PostgreSqlDriver(std::move(cfg)));

}

void ApplicationContext::unload(std::string_view filename) const
{

}

const std::shared_ptr<AbstractLogger> &ApplicationContext::logger() const
{
    return _logger;
}

const AbstractRandomGenerator *ApplicationContext::getDefaultRandomGenerator() const
{
    return _randomGenerator;
}

AbstractDatabaseConnectionPool *ApplicationContext::getDatabaseConnectionPool()
{
    return _connectionPool;
}

void ApplicationContext::loadDatabaseConfig(AbstractDatabaseConfiguration *configuration)
{
    auto pgConfig = static_cast<PostgreSqlDatabaseConfiguration *>(configuration);
    pgConfig->setHost("localhost");
    pgConfig->setPort("5432");
    pgConfig->setUsername("postgres");
    pgConfig->setPassword("123456");
    pgConfig->setDbname("Cass");
}

MetadataService *ApplicationContext::getMetadataService() const
{
    return _metadataService->isStarted() ? _metadataService : nullptr;
}
