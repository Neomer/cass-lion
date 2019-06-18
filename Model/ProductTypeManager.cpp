//
// Created by kir on 16.06.19.
//

#include <string>
#include "ProductTypeManager.h"
#include "../ApplicationContext.h"
#include "EntityMetadata.h"
#include "ProductType.h"

ProductTypeManager::ProductTypeManager(const EntityMetadata *metadata) :
    AbstractEntityManager(metadata)
{

}

ProductTypeManager::~ProductTypeManager()
{

}
