//
// Created by kir on 21.05.19.
//

#ifndef CASS_LION_ABSTRACTDATABASECONNECTION_H
#define CASS_LION_ABSTRACTDATABASECONNECTION_H

#include <memory>
#include <string_view>
#include <future>
#include <functional>
#include "AbstractDatabaseQuery.h"
#include "QueryResultCallback.h"

class AbstractDatabaseConnection {
public:
    using QueryExecutionTask = std::function<std::shared_ptr<AbstractDatabaseQuery>(std::string_view)>;

    /**
     * Уровень изоляции транзакции
     */
    enum IsolationLevel
    {
        Serializable,
        RepeatableRead,
        ReadCommitted,
        ReadUncommitted
    };

    /**
     * Синхронно выполняет SQL-запрос в базе данных. Не использовать, если запрос тяжелый, либо, если результат запроса не нужен сразу.
     * @param sql SQL-запрос, который необходимо выполнить в базе данных.
     * @return Указатель на результат выполнения запроса.
     * @throws QueryExecuteException Не удалосьт выполнить SQL-запрос.
     */
    virtual std::shared_ptr<AbstractDatabaseQuery> execute(std::string_view sql) = 0;

    /**
     * Асинхронное выполнение SQL-запроса.
     * @param sql
     * @return Возвращает std::future с указателем на результат выполнения запроса.
     */
    virtual std::future<std::shared_ptr<AbstractDatabaseQuery>> beginExecute(std::string_view sql) = 0;

    /**
     * Открывает новую транзакцию для текущего подключения.
     * @param isolationLevel
     */
    virtual void beginTransaction(IsolationLevel isolationLevel = ReadCommitted) = 0;

    /**
     * Применяет изменения, полученные во время транзакции.
     * \throws QueryExecuteException
     */
    virtual void commitTransaction() = 0;

    /**
     * Откатывает изменения, полученные во время транзакции.
     */
    virtual void rollbackTransaction() = 0;

    /**
     * @return TRUE, если открыта транзакция.
     */
    virtual bool isInTransaction() const noexcept = 0;

    /**
     * Закрывает соединение.
     */
    virtual void close() noexcept = 0;

    /**
     * Возвращает TRUE, если соединение уже выполняет запрос.
     */
    virtual bool isBusy() const noexcept = 0;
};


#endif //CASS_LION_ABSTRACTDATABASECONNECTION_H
