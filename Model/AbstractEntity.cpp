//
// Created by kir on 11.06.19.
//

#include "AbstractEntity.h"
#include "../ApplicationContext.h"
#include "EntityMetadata.h"

AbstractEntity::AbstractEntity(const Uuid &id, const Uuid &typeUid) :
        _id(id),
        _typeUid{ typeUid }
{

}

AbstractEntity::AbstractEntity(const Uuid &typeUid) :
    _id(Uuid::Empty()),
    _typeUid{ typeUid }
{

}

bool AbstractEntity::isNew() const
{
    return _id.isEmpty();
}

void AbstractEntity::save() const
{
    auto metadata = dynamic_cast<const EntityMetadata *>(ApplicationContext::getInstance().getMetadataService()->findMetadata(getTypeUid()));
    if (metadata == nullptr) {
        throw std::runtime_error("Метаданные для класса сущности не зарегистрированы!");
    }
    auto manager = metadata->getManager();
    if (manager == nullptr) {
        throw std::runtime_error("Менеджер для сущности не зарегистрирован!");
    }
}

std::future<void> AbstractEntity::beginSave() const
{
    std::packaged_task<void(void)> queryTask(
            [this]() -> void {
                save();
            });

    auto future = queryTask.get_future();
    std::thread thread(std::move(queryTask));
    thread.detach();

    return future;
}

const Uuid &AbstractEntity::getTypeUid() const noexcept
{
    return _typeUid;
}

const Uuid &AbstractEntity::getUid() const
{
    return _id;
}

void AbstractEntity::setUid(const Uuid &uid)
{
    _id = uid;
}

void AbstractEntity::fromQuery(std::shared_ptr<AbstractDatabaseQuery> query)
{
    setUid(query->value(query->columnByName("Uid").value())->toUuid());
}

BaseEntityMetadata::BaseEntityMetadata(const Uuid &typeUid,
        std::vector<const char *> fields,
        AbstractEntityManager *manager) :
        EntityMetadata(typeUid),
        _manager{ manager }
{
    _fields.swap(fields);
    _fields.push_back("Uid");
}

const std::vector<const char *> &BaseEntityMetadata::getFields() const
{
    return _fields;
}

const AbstractEntityManager *BaseEntityMetadata::getManager() const
{
    return _manager;
}

const char *BaseEntityMetadata::getUidField() const
{
    return "Uid";
}
