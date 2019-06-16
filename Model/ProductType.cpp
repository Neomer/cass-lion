//
// Created by kir on 13.06.19.
//
#include "../ApplicationContext.h"
#include "ProductType.h"
#include "ProductTypeManager.h"

#define TYPE_UID        Uuid{ 10, 0, 0, 1 }

ProductType::ProductType(const Uuid &id, std::string_view name) :
        AbstractEntity(id, TYPE_UID),
        _name{ name }
{

}

ProductType::ProductType() :
        AbstractEntity(TYPE_UID)
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

void ProductType::fromQuery(std::shared_ptr<AbstractDatabaseQuery> query)
{
    AbstractEntity::fromQuery(query);
    setName(query->value(query->columnByName("Name").value())->toString());
}

ProductTypeMetadata::ProductTypeMetadata() :
        BaseEntityMetadata(TYPE_UID,
                { "Name" },
                new ProductTypeManager(this))
{

}

const char *ProductTypeMetadata::getClassName() const
{
    return "ProductType";
}

const char *ProductTypeMetadata::getTableName() const
{
    return "public.\"ProductType\"";
}

const std::vector<const char *> &ProductTypeMetadata::getFields() const
{
    return _fields;
}

std::shared_ptr<AbstractEntity> ProductTypeMetadata::createInstance() const
{
    return std::shared_ptr<AbstractEntity>(new ProductType());
}
