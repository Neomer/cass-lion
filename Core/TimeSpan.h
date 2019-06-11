//
// Created by kir on 10.06.19.
//

#ifndef CASS_LION_TIMESPAN_H
#define CASS_LION_TIMESPAN_H

#include "IStringable.h"

class TimeSpan
{
public:
    TimeSpan();

    TimeSpan(int64_t seconds);

    ~TimeSpan();

    int64_t getTotalSeconds() const;

    bool isFuture() const;

private:
    int64_t _seconds;
};


#endif //CASS_LION_TIMESPAN_H
