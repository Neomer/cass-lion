//
// Created by kir on 10.06.19.
//

#include "TimeSpan.h"

TimeSpan::TimeSpan(int64_t seconds) :
        _seconds(seconds)
{

}

TimeSpan::TimeSpan() :
    _seconds{ 0 }
{

}

TimeSpan::~TimeSpan()
{

}

int64_t TimeSpan::getTotalSeconds() const
{
    return _seconds;
}

bool TimeSpan::isFuture() const
{
    return _seconds > 0;
}
