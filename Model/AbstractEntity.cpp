//
// Created by kir on 11.06.19.
//

#include "AbstractEntity.h"

AbstractEntity::AbstractEntity(const Uuid &id) :
        _id(id)
{

}

AbstractEntity::AbstractEntity() :
    _id(Uuid::Empty())
{

}

bool AbstractEntity::isNew() const
{
    return _id.isEmpty();
}

void AbstractEntity::save() const
{
    isNew() ? this->databaseInsert() : this->databaseUpdate();
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
