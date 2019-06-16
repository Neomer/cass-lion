//
// Created by kir on 15.06.19.
//

#include "Metadata.h"

Metadata::Metadata() :
    _typeUid{ Uuid::Empty() }
{

}

Metadata::Metadata(const Uuid &typeUid) :
        _typeUid{ typeUid }
{

}

Metadata::~Metadata()
{

}

const Uuid &Metadata::getTypeUid() const
{
    return _typeUid;
}
