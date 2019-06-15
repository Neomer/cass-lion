//
// Created by kir on 11.06.19.
//

#ifndef CASS_LION_ABSTRACTENTITY_H
#define CASS_LION_ABSTRACTENTITY_H

#include <future>
#include "../Database/AbstractDatabaseQuery.h"
#include "../Core/Uuid.h"

class AbstractEntity
{
public:
    AbstractEntity(const Uuid &id);

    AbstractEntity();

    bool isNew() const;

    virtual void loadFromQuery(std::shared_ptr<AbstractDatabaseQuery> query) = 0;

    void save() const;

    std::future<void> beginSave() const;

protected:
    virtual void databaseInsert() const = 0;

    virtual void databaseUpdate() const = 0;

private:
    Uuid _id;
};


#endif //CASS_LION_ABSTRACTENTITY_H
