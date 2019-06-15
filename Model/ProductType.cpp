//
// Created by kir on 13.06.19.
//

#include "ProductType.h"

ProductType::ProductType(const Uuid &id, std::string_view name) :
        AbstractEntity(id),
        _name{ name }
{

}

ProductType::ProductType() :
        AbstractEntity()
{

}

void ProductType::databaseInsert() const
{

}

void ProductType::databaseUpdate() const
{

}

const std::string &ProductType::getName() const
{
    return _name;
}

void ProductType::setName(const std::string &name)
{
    _name = name;
}
