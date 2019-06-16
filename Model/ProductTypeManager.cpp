//
// Created by kir on 16.06.19.
//

#include <string>
#include "ProductTypeManager.h"
#include "../ApplicationContext.h"
#include "EntityMetadata.h"
#include "ProductType.h"

using namespace std::string_literals;

ProductTypeManager::ProductTypeManager(const EntityMetadata *metadata) :
    AbstractEntityManager(metadata)
{

}

ProductTypeManager::~ProductTypeManager()
{

}

std::shared_ptr<AbstractEntity> ProductTypeManager::getByUid(const Uuid &uid) const
{
    auto connection = ApplicationContext::getInstance().getDatabaseConnectionPool()->getOrAddConnection();
    auto result = connection->execute("select * from "s + getEntityMetadata()->getTableName() + " where \"" + getEntityMetadata()->getUidField() + "\"='" + uid.toString() + "';");

    if (result->valid() && result->first()) {
        auto productType = std::shared_ptr<AbstractEntity>(new ProductType());
        productType->fromQuery(result);
        return productType;
    } else {
        return std::shared_ptr<AbstractEntity>(nullptr);
    }
}

