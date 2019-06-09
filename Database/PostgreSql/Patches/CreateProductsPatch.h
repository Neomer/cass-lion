//
// Created by kir on 30.05.19.
//

#ifndef CASS_LION_CREATEPRODUCTSPATCH_H
#define CASS_LION_CREATEPRODUCTSPATCH_H

#include "../../AbstractDatabasePatch.h"

class CreateProductsPatch : public AbstractDatabasePatch
{
public:
    CreateProductsPatch();

    virtual ~CreateProductsPatch();

    void execute(std::shared_ptr<AbstractDatabaseConnection> &connection) override;

    uint32_t version() const override;

private:
    static void createProductTable(std::shared_ptr<AbstractDatabaseConnection> &connection);
    static void createProductTypeTable(std::shared_ptr<AbstractDatabaseConnection> &connection);

};


#endif //CASS_LION_CREATEPRODUCTSPATCH_H
