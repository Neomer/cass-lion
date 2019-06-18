//
// Created by kir on 16.06.19.
//

#ifndef CASS_LION_PRODUCTTYPEMANAGER_H
#define CASS_LION_PRODUCTTYPEMANAGER_H

#include "AbstractEntityManager.h"

class ProductTypeManager : public AbstractEntityManager
{
public:
    ProductTypeManager(const EntityMetadata *metadata);

    virtual ~ProductTypeManager();
};


#endif //CASS_LION_PRODUCTTYPEMANAGER_H
