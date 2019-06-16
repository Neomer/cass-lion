//
// Created by kir on 16.06.19.
//

#include "EntityMetadata.h"

EntityMetadata::EntityMetadata()
{

}

EntityMetadata::EntityMetadata(const Uuid &typeUid) :
        ClassMetadata(typeUid)
{

}

EntityMetadata::~EntityMetadata()
{

}
