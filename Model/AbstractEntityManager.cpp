//
// Created by kir on 16.06.19.
//

#include "AbstractEntityManager.h"
#include "../ApplicationContext.h"
#include "AbstractEntity.h"
#include "../Database/Exceptions/ConnectionLimitExceededException.h"

using namespace std::string_literals;

AbstractEntityManager::AbstractEntityManager(const EntityMetadata *metadata) :
    _metadata{ metadata }
{

}

const EntityMetadata *AbstractEntityManager::getEntityMetadata() const
{
    return _metadata;
}

std::shared_ptr<AbstractDatabaseConnection> AbstractEntityManager::getConnection() const
{
    try
    {
        return ApplicationContext::getInstance().getDatabaseConnectionPool()->getOrAddConnection();
    }
    catch (ConnectionLimitExceededException &ex)
    {
        ApplicationContext::getInstance().logger()->error(ex.what());
        throw ex;
    }
}

std::shared_ptr<AbstractEntity> AbstractEntityManager::getByUid(const Uuid &uid) const
{
    auto query = getConnection()->execute("select * from "s + getEntityMetadata()->getTableName() + " where \"" + getEntityMetadata()->getUidField() + "\"='" + uid.toString() + "';");
    if (!query->valid() || !query->first()) {
        return std::shared_ptr<AbstractEntity>(nullptr);
    }
    auto entity = getEntityMetadata()->createInstance();
    entity->fromQuery(query);
    return entity;
}

std::vector<std::shared_ptr<AbstractEntity>> AbstractEntityManager::findAll() const
{
    std::vector<std::shared_ptr<AbstractEntity>> result;
    auto query = getConnection()->execute("select * from "s + getEntityMetadata()->getTableName() + ";");

    if (query->valid() && query->first()) {
        while (!query->eof()) {
            auto entity = getEntityMetadata()->createInstance();
            entity->fromQuery(query);
            result.push_back(entity);
            query->next();
        }
    }
    return result;
}

void AbstractEntityManager::save(std::shared_ptr<AbstractEntity> entity) const
{

}
