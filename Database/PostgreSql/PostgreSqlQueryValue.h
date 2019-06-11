//
// Created by kir on 29.05.19.
//

#ifndef CASS_LION_POSTGRESQLQUERYVALUE_H
#define CASS_LION_POSTGRESQLQUERYVALUE_H

#include <string_view>
#include <string>
#include "../AbstractQueryValue.h"

class PostgreSqlQueryValue : public AbstractQueryValue
{
public:
    PostgreSqlQueryValue(std::string_view value, int oid);

    virtual ~PostgreSqlQueryValue();

    uint8_t toUInt8() const override;

    uint16_t toUInt16() const override;

    uint32_t toUInt32() const override;

    uint64_t toUInt64() const override;

    int8_t toInt8() const override;

    int16_t toInt16() const override;

    int32_t toInt32() const override;

    int64_t toInt64() const override;

    std::string toString() const override;

    bool toBool() const override;

    Uuid toUuid() const override;

    DateTime toDateTime() const override;

private:
    std::string_view _value;
    int _oid;
};


#endif //CASS_LION_POSTGRESQLQUERYVALUE_H
