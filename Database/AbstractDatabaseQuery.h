//
// Created by kir on 22.05.19.
//

#ifndef CASS_LION_ABSTRACTDATABASEQUERY_H
#define CASS_LION_ABSTRACTDATABASEQUERY_H

#include <inttypes.h>
#include <cstddef>
#include <string_view>
#include <memory>
#include "AbstractQueryValue.h"

class AbstractDatabaseQuery
{
public:

    virtual bool first() = 0;

    virtual bool next() = 0;

    virtual bool eof() const = 0;

    virtual bool valid() const noexcept = 0;

    virtual void close() noexcept = 0;

    virtual size_t rows() const = 0;

    virtual uint16_t columns() const = 0;

    virtual uint16_t columnByName(std::string_view name) const = 0;

    virtual std::shared_ptr<AbstractQueryValue> value(uint16_t column) const = 0;

};


#endif //CASS_LION_ABSTRACTDATABASEQUERY_H
