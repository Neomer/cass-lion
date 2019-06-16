//
// Created by kir on 16.06.19.
//

#ifndef CASS_LION_ABSTRACTENTITYMANAGER_H
#define CASS_LION_ABSTRACTENTITYMANAGER_H

#include <memory>
#include "../Core/Uuid.h"

class AbstractEntity;

class EntityMetadata;

class AbstractEntityManager
{
public:
    explicit AbstractEntityManager(const EntityMetadata *metadata);

    const EntityMetadata *getEntityMetadata() const;

    virtual std::shared_ptr<AbstractEntity> getByUid(const Uuid &uid) const = 0;

private:
    const EntityMetadata *_metadata;
};


#endif //CASS_LION_ABSTRACTENTITYMANAGER_H
