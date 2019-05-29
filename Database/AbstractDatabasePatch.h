//
// Created by kir on 29.05.19.
//

#ifndef CASS_LION_ABSTRACTDATABASEPATCH_H
#define CASS_LION_ABSTRACTDATABASEPATCH_H

#include <inttypes.h>
#include <memory>
#include "AbstractDatabaseConnection.h"

class AbstractDatabasePatch
{
public:
    virtual void execute(std::shared_ptr<AbstractDatabaseConnection> &connection) = 0;

    virtual uint32_t version() const = 0;
};


#endif //CASS_LION_ABSTRACTDATABASEPATCH_H
