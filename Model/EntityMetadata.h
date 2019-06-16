//
// Created by kir on 16.06.19.
//

#ifndef CASS_LION_ENTITYMETADATA_H
#define CASS_LION_ENTITYMETADATA_H

#include <vector>
#include <memory>
#include "../Core/ClassMetadata.h"
#include "AbstractEntityManager.h"

class AbstractEntity;

class EntityMetadata : public ClassMetadata
{
public:
    EntityMetadata();

    explicit EntityMetadata(const Uuid &typeUid);

    ~EntityMetadata() override;

    virtual const char *getTableName() const = 0;

    virtual const std::vector<const char *> &getFields() const = 0;

    virtual std::shared_ptr<AbstractEntity> createInstance() const = 0;

    virtual const AbstractEntityManager *getManager() const = 0;

    virtual const char * getUidField() const = 0;
};


#endif //CASS_LION_ENTITYMETADATA_H
