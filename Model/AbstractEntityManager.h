//
// Created by kir on 16.06.19.
//

#ifndef CASS_LION_ABSTRACTENTITYMANAGER_H
#define CASS_LION_ABSTRACTENTITYMANAGER_H

#include <memory>
#include <vector>
#include "../Core/Uuid.h"
#include "../Database/AbstractDatabaseConnection.h"
#include "EntityMetadata.h"

class AbstractEntity;

/**
 * Базовый класс для всех менеджеров сущностей.
 * Менеджер сущности используется загрузки/обновления/удаления сущностей из базы данных.
 */
class AbstractEntityManager
{
public:
    explicit AbstractEntityManager(const EntityMetadata *metadata);

    /**
     * Возвращает метаданные типа сущности, с которой работает данный менеджер.
     */
    const EntityMetadata *getEntityMetadata() const;

    /**
     * Загрузить сущность из базы данных по идентификатору.
     * @param uid Уникальный идентифактор сущности.
     * @return Указатель на загруженную сущность, либо nullptr, если сущность с указанный идентификатором не найдена.
     */
    virtual std::shared_ptr<AbstractEntity> getByUid(const Uuid &uid) const;

    /**
     * Загрузить все сущности данного типа.
     * @return Вектор всех сущностей текущего типа данных, находящихся в базе данных.
     */
    virtual std::vector<std::shared_ptr<AbstractEntity>> findAll() const;

    virtual void save(std::shared_ptr<AbstractEntity> entity) const;

protected:
    /**
     * Указатель на доступное подключение к базе данных.
     */
    std::shared_ptr<AbstractDatabaseConnection> getConnection() const;

private:
    const EntityMetadata *_metadata;
};


#endif //CASS_LION_ABSTRACTENTITYMANAGER_H
