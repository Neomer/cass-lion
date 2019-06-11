//
// Created by kir on 10.06.19.
//
#include <string>
#include "DateTime.h"

DateTime::DateTime() :
    _timestamp{ 0 }
{

}


DateTime::DateTime(int64_t timestamp) :
        _timestamp(timestamp)
{

}

DateTime::~DateTime()
{

}

DateTime &DateTime::add(const TimeSpan &timeSpan)
{
    _timestamp += timeSpan.getTotalSeconds();
    return *this;
}

DateTime &DateTime::addDays(int32_t days)
{
    _timestamp += days * 86400;
    return *this;
}

DateTime &DateTime::addMinutes(int32_t minutes)
{
    _timestamp += minutes * 60;
    return *this;
}

DateTime &DateTime::addHours(int32_t hours)
{
    _timestamp += hours * 3600;
    return *this;
}

DateTime &DateTime::addSeconds(int64_t seconds)
{
    _timestamp += seconds;
    return *this;
}

std::string DateTime::toString() const
{
    return std::to_string(_timestamp);
}

void DateTime::toString(std::string &buffer) const
{
    buffer = std::to_string(_timestamp);
}
