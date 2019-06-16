//
// Created by kir on 11.06.19.
//

#ifndef CASS_LION_ABSTRACTENTITY_H
#define CASS_LION_ABSTRACTENTITY_H

#include <future>
#include <vector>
#include "../Core/Uuid.h"
#include "EntityMetadata.h"
#include "../Database/AbstractDatabaseQuery.h"

class AbstractEntity
{
public:
    AbstractEntity(const Uuid &id, const Uuid &typeUid);

    explicit AbstractEntity(const Uuid &typeUid);

    const Uuid &getTypeUid() const noexcept;

    bool isNew() const;

    void save() const;

    std::future<void> beginSave() const;

    virtual void fromQuery(std::shared_ptr<AbstractDatabaseQuery> query);

    const Uuid &getUid() const;

    void setUid(const Uuid &id);

private:
    Uuid _id, _typeUid;
};

class BaseEntityMetadata : public EntityMetadata
{
public:
    BaseEntityMetadata(const Uuid &typeUid,
            std::vector<const char *> fields,
            AbstractEntityManager *manager);

    ~BaseEntityMetadata() = default;

    const std::vector<const char *> &getFields() const override;

    const AbstractEntityManager *getManager() const override;

    const char *getUidField() const override;

private:
    std::vector<const char *> _fields;
    AbstractEntityManager *_manager;
};


#endif //CASS_LION_ABSTRACTENTITY_H
