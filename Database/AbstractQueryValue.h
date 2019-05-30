//
// Created by kir on 29.05.19.
//

#ifndef CASS_LION_ABSTRACTQUERYVALUE_H
#define CASS_LION_ABSTRACTQUERYVALUE_H

#include <inttypes.h>
#include <string_view>
#include "../Core/Uuid.h"

class AbstractQueryValue
{
public:

    virtual uint8_t toUInt8() const = 0;

    virtual uint16_t toUInt16() const = 0;

    virtual uint32_t toUInt32() const = 0;

    virtual uint64_t toUInt64() const = 0;

    virtual int8_t toInt8() const = 0;

    virtual int16_t toInt16() const = 0;

    virtual int32_t toInt32() const = 0;

    virtual int64_t toInt64() const = 0;

    virtual std::string toString() const = 0;

    virtual bool toBool() const = 0;

    virtual Uuid toUuid() const = 0;
};


#endif //CASS_LION_ABSTRACTQUERYVALUE_H
