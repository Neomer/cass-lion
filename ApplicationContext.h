//
// Created by kir on 23.05.19.
//

#ifndef CASS_LION_APPLICATIONCONTEXT_H
#define CASS_LION_APPLICATIONCONTEXT_H

#include <string_view>
#include <memory>
#include "Logs/AbstractLogger.h"
#include "Core/AbstractRandomGenerator.h"
#include "Database/AbstractDatabaseConnectionPool.h"

class ApplicationContext
{
public:
    static ApplicationContext &getInstance();

    void load(std::string_view filename);

    void unload(std::string_view filename) const;

    const std::shared_ptr<AbstractLogger> &logger() const;

    const AbstractRandomGenerator *getDefaultRandomGenerator() const;

    AbstractDatabaseConnectionPool *getDatabaseConnectionPool();

private:
    ApplicationContext();
    ~ApplicationContext();
    ApplicationContext(const ApplicationContext &) = delete;
    ApplicationContext(const ApplicationContext &&) = delete;
    ApplicationContext& operator=(const ApplicationContext &) = delete;
    ApplicationContext& operator=(const ApplicationContext &&) = delete;

    static void loadDatabaseConfig(AbstractDatabaseConfiguration *configuration);

    std::shared_ptr<AbstractLogger> _logger;
    AbstractRandomGenerator *_randomGenerator;
    AbstractDatabaseConnectionPool *_connectionPool;
};


#endif //CASS_LION_APPLICATIONCONTEXT_H
