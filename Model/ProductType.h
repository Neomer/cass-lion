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

protected:
    void databaseInsert() const override;

    void databaseUpdate() const override;

private:
    std::string _name;
};


#endif //CASS_LION_PRODUCTTYPE_H
