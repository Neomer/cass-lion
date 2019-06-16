//
// Created by kir on 16.06.19.
//

#include "AbstractEntityManager.h"

AbstractEntityManager::AbstractEntityManager(const EntityMetadata *metadata) :
    _metadata{ metadata }
{

}

const EntityMetadata *AbstractEntityManager::getEntityMetadata() const
{
    return _metadata;
}
