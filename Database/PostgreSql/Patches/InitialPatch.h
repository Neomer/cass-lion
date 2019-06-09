//
// Created by kir on 29.05.19.
//

#ifndef CASS_LION_INITIALPATCH_H
#define CASS_LION_INITIALPATCH_H

#include "../../AbstractDatabasePatch.h"

class InitialPatch : public AbstractDatabasePatch
{
public:
    InitialPatch();

    virtual ~InitialPatch();

    /**
     * Создает пользователя cass_admin
     * Создает таблицу DatabaseInformation
     * @param connection Подключение к базе данных.
     */
    void execute(std::shared_ptr<AbstractDatabaseConnection> &connection) override;

    uint32_t version() const override;

private:
    static void createAdminUser(std::shared_ptr<AbstractDatabaseConnection> &connection);
    static void createDatabaseInfo(std::shared_ptr<AbstractDatabaseConnection> &connection);
};


#endif //CASS_LION_INITIALPATCH_H
