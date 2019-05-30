//
// Created by kir on 29.05.19.
//

#include <string.h>
#include "PostgreSqlQueryValue.h"

PostgreSqlQueryValue::PostgreSqlQueryValue(std::string_view value, int oid) :
    _value{ value },
    _oid{ oid }
{

}

PostgreSqlQueryValue::~PostgreSqlQueryValue() = default;


uint8_t PostgreSqlQueryValue::toUInt8() const
{
    return static_cast<uint8_t >(std::strtoul(_value.data(), nullptr, 10));
}

uint16_t PostgreSqlQueryValue::toUInt16() const
{
    return static_cast<uint16_t >(std::strtoul(_value.data(), nullptr, 10));
}

uint32_t PostgreSqlQueryValue::toUInt32() const
{
    return static_cast<uint32_t >(std::strtoul(_value.data(), nullptr, 10));
}

uint64_t PostgreSqlQueryValue::toUInt64() const
{
    return static_cast<uint64_t >(std::strtoull(_value.data(), nullptr, 10));
}

int8_t PostgreSqlQueryValue::toInt8() const
{
    return static_cast<uint8_t >(std::strtol(_value.data(), nullptr, 10));
}

int16_t PostgreSqlQueryValue::toInt16() const
{
    return static_cast<int16_t >(std::strtol(_value.data(), nullptr, 10));
}

int32_t PostgreSqlQueryValue::toInt32() const
{
    return static_cast<int32_t >(std::strtol(_value.data(), nullptr, 10));
}

int64_t PostgreSqlQueryValue::toInt64() const
{
    return static_cast<int64_t >(std::strtol(_value.data(), nullptr, 10));
}

std::string PostgreSqlQueryValue::toString() const
{
    return _value.data();
}

bool PostgreSqlQueryValue::toBool() const
{
    return !strcasecmp(_value.data(), "t") || !strcasecmp(_value.data(), "1") || !strcasecmp(_value.data(), "true");
}
