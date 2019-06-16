//
// Created by kir on 13.06.19.
//

#ifndef CASS_LION_PRODUCTTYPE_H
#define CASS_LION_PRODUCTTYPE_H

#include "AbstractEntity.h"

class ProductType : public AbstractEntity
{
public:
    ProductType(const Uuid &id, std::string_view name);

    ProductType();

    const std::string &getName() const;

    void setName(const std::string &name);

    void fromQuery(std::shared_ptr<AbstractDatabaseQuery> query) override;

private:
    std::string _name;
};

//@metadata ProductType
class ProductTypeMetadata : public BaseEntityMetadata
{
public:
    ProductTypeMetadata();

    ~ProductTypeMetadata() override = default;

    const char *getClassName() const override;

    const char *getTableName() const override;

    const std::vector<const char *> &getFields() const override;

    std::shared_ptr<AbstractEntity> createInstance() const override;

private:
    std::vector <const char *> _fields;
};
//@endmetadata

#endif //CASS_LION_PRODUCTTYPE_H
