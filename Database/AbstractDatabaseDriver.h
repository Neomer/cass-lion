//
// Created by kir on 21.05.19.
//

#ifndef CASS_LION_ABSTRACTDATABASEDRIVER_H
#define CASS_LION_ABSTRACTDATABASEDRIVER_H

#include <memory>
#include "AbstractDatabaseConfiguration.h"
#include "AbstractDatabaseConnection.h"

class AbstractDatabaseDriver {
public:
    AbstractDatabaseDriver(std::unique_ptr<AbstractDatabaseConfiguration> configuration);
    virtual ~AbstractDatabaseDriver() = default;

    /// Создает новое подключение к базе данных. Подключается к базе данных, используя переданную конфигурацию.
    /// \return Указатель на новое подключение
    /// \throws DatabaseConnectionRefusedException Не удалось подключиться к базе данных
    virtual std::shared_ptr<AbstractDatabaseConnection> open() = 0;

    virtual const char *getDatabaseDriverName() = 0;

protected:
    const AbstractDatabaseConfiguration *getConfiguration() const;

private:
    std::unique_ptr<AbstractDatabaseConfiguration> _configuration;
};


#endif //CASS_LION_ABSTRACTDATABASEDRIVER_H
