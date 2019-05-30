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
    void createAdminUser(std::shared_ptr<AbstractDatabaseConnection> &connection) const;
    void createDatabaseInfo(std::shared_ptr<AbstractDatabaseConnection> &connection) const;
};


#endif //CASS_LION_INITIALPATCH_H
